#pragma once

/// \file
/// \brief This file contains the most basic utilities.

//
//
//
//
//
#if defined(__MINGW64_VERSION_MAJOR) && __MINGW64_VERSION_MAJOR < 7
  #error Your MinGW version is too old. Please update it to a newer version.
#endif

#include "detail/Macros.h"

#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#if _WIN32
  #include <Synchapi.h>
#else
  #include <unistd.h>
#endif

/// \brief An alias of `unsigned int`.
typedef unsigned uint;

typedef int8_t int8;
typedef uint8_t uint8;

typedef int64_t int64;
typedef uint64_t uint64;

/// \brief Randomly generate an `int` in `[0, n)`.
int Rand(int n) {
  TK_ASSERT(n <= RAND_MAX,
            "`n` is too large to be handled by `Rand`, please implement your own random number generator");
  return rand() % n;
}

/// \brief Randomly generate a `double` in `[0, 1)`.
double Rand01(void) {
  return (double)rand() / ((double)RAND_MAX + 1.0);
}

//
//
//
/// \brief A 2D vector which contains only `int`s.
typedef struct {
  int x, y;
} Vec;

bool Eq(Vec a, Vec b) {
  return a.x == b.x && a.y == b.y;
}

bool Neq(Vec a, Vec b) {
  return !Eq(a, b);
}

Vec Add(Vec a, Vec b) {
  return (Vec){a.x + b.x, a.y + b.y};
}

Vec Sub(Vec a, Vec b) {
  return (Vec){a.x - b.x, a.y - b.y};
}

Vec Mul(Vec a, int b) {
  return (Vec){a.x * b, a.y * b};
}

/// \brief Randomly generate a `Vec` in `[0, v.x) * [0, v.y)`.
Vec RandVec(Vec v) {
  TK_ASSERT(v.x <= RAND_MAX && v.y <= RAND_MAX,
            "`v` is too large to be handled by `RandVec`, please implement your own random number generator");
  return (Vec){rand() % v.x, rand() % v.y};
}

//
//
//
typedef const char *Color;
#define TK_RUNTIME_COLOR "%s"

#define TK_NORMAL        "0"
#define TK_BLACK         "30"
#define TK_RED           "31"
#define TK_GREEN         "32"
#define TK_YELLOW        "33"
#define TK_BLUE          "34"
#define TK_MAGENTA       "35"
#define TK_CYAN          "36"
#define TK_WHITE         "37"
#define TK_BRIGHT_YELLOW "93"
#define TK_BRIGHT_BLUE   "94"

#define __TK_SET_COLOR(color) "\033[" color "m"

#define __TK_TEXT1(text)        text
#define __TK_TEXT2(text, color) __TK_SET_COLOR(color) text __TK_SET_COLOR(TK_NORMAL)

/// \brief Get an optionally colored text.
///
/// \example ```c
/// // Colors can be specified at compile-time, by using `TK_RED`, etc.
/// printf(TK_TEXT("Hello World!\n"));
/// printf(TK_TEXT("Hello World!\n", TK_RED));
/// printf(TK_TEXT("Hello World%c\n", TK_YELLOW), '!');
/// printf(TK_TEXT("Hello World%s\n", TK_GREEN), "!");
///
/// // Colors can also be specified at runtime, by using `Color` and `TK_RUNTIME_COLOR`.
/// Color color = TK_BLUE;
/// printf(TK_TEXT("Hello World%c\n", TK_RUNTIME_COLOR), color, '!');
/// ```
#define TK_TEXT(...) __TK_EXPAND(__TK_EXPAND(TK_CONCAT(__TK_TEXT, TK_NUM_OF(__VA_ARGS__)))(__VA_ARGS__))

//
//
//
/// \brief Suspends the execution of the current thread until
/// the time-out interval (in milliseconds) elapses.
///
/// \example ```c
/// SleepMs(1000); // Sleep for 1000 milliseconds.
/// ```
void SleepMs(uint time) {
#ifdef _WIN32
  Sleep(time);
#else
  usleep(time * 1000);
#endif // _WIN32
}

/// \brief Suspends the execution of the current thread for
/// only several nanoseconds.
void Daze(void) {
#if TK_ICC || TK_MSVC
  _mm_pause();
#elif __arm__ || __aarch64__
  __builtin_arm_yield();
#else
  __builtin_ia32_pause();
#endif
}
