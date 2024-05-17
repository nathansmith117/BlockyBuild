#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include "raygui.h"

//#define PLATFORM_WEB

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#ifndef GAME_COMMON_H
#define GAME_COMMON_H

typedef struct Game Game;

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

// Memory management.
#define BB_MALLOC(size) malloc(size)
#define BB_CALLOC(nmemb, size) calloc(nmemb, size)
#define BB_REALLOC(ptr, size) realloc(ptr, size)
#define BB_REALLOCARRAY(ptr, nmemb, size) reallocarray(ptr, nmemb, size)
//#define BB_REALLOCARRAY(ptr, nmemb, size) realloc(ptr, nmemb * size)
#define BB_FREE(ptr) free(ptr)

#define ALLOCATION_ERROR TraceLog(LOG_ERROR, "Allocation error in %s:%d", __FILE__, __LINE__)

#endif
