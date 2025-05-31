ifeq ($(MOD),gkd2)
export CROSS=aarch64-linux-
export PATH=/opt/flip/bin:$(shell echo $$PATH)

CFLAGS  += -DGKD2
CFLAGS  += -I/opt/flip/aarch64-flip-linux-gnu/sysroot/usr/include/SDL2
LDFLAGS += -lSDL2
LDFLAGS += -lSDL2_image
endif

ifeq ($(MOD),brick)
export CROSS=aarch64-linux-gnu-
export PATH=/opt/brick/bin:$(shell echo $$PATH)

CFLAGS  += -DBRICK
CFLAGS  += -I/opt/brick/usr/include
CFLAGS  += -I/opt/brick/usr/include/SDL2
LDFLAGS += -lSDL2
LDFLAGS += -lSDL2_image
LDFLAGS += -lrt
LDFLAGS += -lusc
LDFLAGS += -lIMGegl
LDFLAGS += -lPVROCL
LDFLAGS += -lsrv_um
LDFLAGS += -lpthread
LDFLAGS += -lglslcompiler
LDFLAGS += -L/opt/brick/usr/lib
endif

export CC=${CROSS}gcc
export AR=${CROSS}ar
export AS=${CROSS}as
export LD=${CROSS}ld
export CXX=${CROSS}g++

TARGET   = runner
CFLAGS  += -DRUNNER
CFLAGS  += -O3
CFLAGS  += -I.
CFLAGS  += -I../common
LDFLAGS += -lrt
LDFLAGS += -lEGL
LDFLAGS += -lGLESv2
SOURCES  = runner.c

.PHONY: all
all:
	$(CC) $(SOURCES) -o $(TARGET) $(CFLAGS) $(LDFLAGS) $(MORE_CFLAGS) $(MORE_LDFLAGS)

.PHONY: clean
clean:
	rm -rf $(TARGET)
