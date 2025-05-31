#!/bin/bash
MYDIR=`dirname "$0"`
MYLIB=/media/Debian/bookworm/usr/lib/arm-linux-gnueabihf

export HOME=$MYDIR
export SDL_VIDEODRIVER=NDS

function kill_runner() {
    PID=`pidof runner`
    if [ "$PID" != "" ]; then
        kill -9 $PID
    fi
    rm -rf /tmp/shm
}

cd $MYDIR

sv=`cat /proc/sys/vm/swappiness`
echo 10 > /proc/sys/vm/swappiness
echo performance > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor

kill_runner
LD_LIBRARY_PATH=/usr/local/lib op_runfbapp ./runner&
sleep 1

$MYLIB/ld-linux-armhf.so.3 --library-path lib:$MYLIB ./drastic "$1"
sync

kill_runner

echo $sv > /proc/sys/vm/swappiness
echo ondemand > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
