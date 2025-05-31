// LGPL-2.1 License
// (C) 2025 Steward Fu <steward.fu@gmail.com>

#ifndef __RUNNER_H__
#define __RUNNER_H__

#include <EGL/egl.h>
#include <GLES2/gl2.h>

#include "common.h"

#if defined(UT)
#define R_LCD_W 640
#define R_LCD_H 480
#endif

#if defined(GKD2)
#define R_LCD_W 640
#define R_LCD_H 480
#endif

#if defined(BRICK)
#define R_LCD_W 1024
#define R_LCD_H 768
#endif

#if defined(PANDORA)
#define R_LCD_W 800
#define R_LCD_H 480
#endif

#define SHM_NAME "NDS_SHM"

typedef struct {
    int x;
    int y;
    int w;
    int h;
} shm_rect_t;

typedef enum {
    SHM_CMD_FLUSH = 0,
    SHM_CMD_FLIP,
    SHM_CMD_QUIT
} shm_cmd_t;

typedef struct {
    uint8_t valid;
    uint8_t cmd;
    uint8_t tex;
    uint8_t layout;
    uint8_t filter;
    uint32_t pitch;
    uint32_t alpha;

    uint32_t len;
    shm_rect_t srt;
    shm_rect_t drt;
    uint8_t buf[R_LCD_W * R_LCD_H * 4];
} shm_buf_t;
 
typedef struct {
#if defined(BRICK) || defined(GKD2)
    struct {
        SDL_Window *win;
    } sdl2;
#endif

    struct {
#if defined(PANDORA)
        EGLDisplay display;
        EGLSurface surface;
        EGLContext context;
        EGLConfig configs;
#endif

#if defined(BRICK) || defined(GKD2)
        SDL_GLContext ctx;
#endif
        GLuint vert_shader;
        GLuint frag_shader;
        GLuint program;

        GLint vert_pos;
        GLint vert_coord;
        GLint frag_sampler;
        GLint frag_rotate;
        GLint frag_aspect;
        GLint frag_alpha;
        GLuint tex_id[TEXTURE_MAX];

        struct {
            int w;
            int h;
            void *pixels;
        } bg;
    } gles;

    struct {
        int fd;
        shm_buf_t *buf;
    } shm;
} runner_t;

#endif

