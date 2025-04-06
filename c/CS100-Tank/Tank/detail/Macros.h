#pragma once

/// \file
/// \brief This file introduces a collection of commonly used macros.

//
//
//
//
//
// Compilers.

/// \brief Whether clang is compiling the code.
#ifdef __clang__
  #define TK_CLANG __clang_major__
#else
  #define TK_CLANG 0
#endif // __clang__

/// \brief Whether ICC (Intel C++ Compiler) is compiling the code.
#ifdef __INTEL_COMPILER
  #define TK_ICC __INTEL_COMPILER
#else
  #define TK_ICC 0
#endif // __INTEL_COMPILER

/// \brief Whether MSVC is compiling the code.
#if defined(_MSC_VER) && !TK_CLANG && !TK_ICC
  #define TK_MSVC _MSC_VER
#else
  #define TK_MSVC 0
#endif

/// \brief Whether gcc is compiling the code.
#if defined(__GNUC__) && !TK_CLANG && !TK_ICC
  #define TK_GCC __GNUC__
#else
  #define TK_GCC 0
#endif

//
//
//
#if TK_ICC || TK_MSVC
  #define _CRT_SECURE_NO_WARNINGS
#endif

#if _WIN32
  #include <windows.h>
#endif

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//
//
//
// Helper macros.
#define __TK_EXPAND(x) x

#define __TK_NUM_OF_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _, ...) _
#define __TK_CONCAT_HELPER(x, y)                                                                          x##y

#define __TK_COND_0(x, y)     y
#define __TK_COND_1(x, y)     x
#define __TK_COND_false(x, y) y
#define __TK_COND_true(x, y)  x

//
//
//
/// \brief Get number of the given args.
///
/// \example ```c
/// static_assert(TK_NUM_OF(a) == 1);
/// static_assert(TK_NUM_OF(a, b) == 2);
/// static_assert(TK_NUM_OF(a, b, c) == 3);
/// ```
///
/// \warning It is dangerous to call `TK_NUM_OF` with no arguments.
/// Never do that.
#define TK_NUM_OF(...)                                                                                                 \
  __TK_EXPAND(__TK_NUM_OF_HELPER(__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))

/// \brief Concatenate `x` and `y`.
///
/// \example ```c
/// static_assert(TK_CONCAT(233, 466) == 233466);
/// ```
#define TK_CONCAT(x, y) __TK_CONCAT_HELPER(x, y)

/// \brief Create an anonymous name based on x.
///
/// \example ```c
/// struct TK_ANON(Name) {
/// ...
/// };
/// ```
#define TK_ANON(x) TK_CONCAT(x, __LINE__)

/// \brief Create a precompile-time `cond ? x : y`.
///
/// \example ```c
/// static_assert(TK_COND(1, 5, 6) == 5);
/// static_assert(TK_COND(0, 5, 6) == 6);
/// static_assert(TK_COND(true, 5, 6) == 5);
/// static_assert(TK_COND(false, 5, 6) == 6);
/// ```
#define TK_COND(cond, x, y) __TK_EXPAND(TK_CONCAT(__TK_COND_, cond))(x, y)

/// \brief Create a precompile-time `if (cond) x`.
///
/// \example ```c
/// TK_IF(1, printf("This message will be printed\n"));
/// TK_IF(0, printf("This message will not be printed\n"));
/// TK_IF(true, printf("This message will be printed\n"));
/// TK_IF(false, printf("This message will not be printed\n"));
/// ```
#define TK_IF(cond, x) TK_COND(cond, x, )

//
//
//
/// \brief Mark unimplemented code.
///
/// \example ```c
/// void SomeUnimplementedFunction(void) {
///   TK_UNIMPLEMENTED;
/// }
/// ```
#define TK_UNIMPLEMENTED                                                                                               \
  do {                                                                                                                 \
    fprintf(stderr, "Reached unimplemented code at [%s:%d]\n", __FILE__, __LINE__);                                    \
    abort();                                                                                                           \
  } while (0)

#if !defined(NDEBUG)
  #define __TK_ASSERT1(cond)                                                                                           \
    do {                                                                                                               \
      if (!(cond)) {                                                                                                   \
        fprintf(stderr, "Assertion (%s) failed at [%s:%d]\n", #cond, __FILE__, __LINE__);                              \
        assert(false);                                                                                                 \
      }                                                                                                                \
    } while (0)

  #define __TK_ASSERT2(cond, explanation)                                                                              \
    do {                                                                                                               \
      if (!(cond)) {                                                                                                   \
        fprintf(stderr, "Assertion (%s) failed at [%s:%d] (" explanation ")\n", #cond, __FILE__, __LINE__);            \
        assert(false);                                                                                                 \
      }                                                                                                                \
    } while (0)

  /// \brief Assert that the condition is true in debug mode.
  ///
  /// \example ```c
  /// TK_ASSERT(a == 1);
  /// TK_ASSERT(a == 1, "`a` does not equal to 1");
  /// ```
  #define TK_ASSERT(...) __TK_EXPAND(__TK_EXPAND(TK_CONCAT(__TK_ASSERT, TK_NUM_OF(__VA_ARGS__)))(__VA_ARGS__))
#else
  /// \brief Do nothing in release mode.
  ///
  /// \example ```c
  /// TK_ASSERT(a == 1);
  /// TK_ASSERT(a == 1, "`a` does not equal to 1");
  /// ```
  #define TK_ASSERT(...) ((void)0)
#endif // !defined(NDEBUG)

#define __TK_EXPECT1(cond)                                                                                             \
  do {                                                                                                                 \
    if (!(cond)) {                                                                                                     \
      fprintf(stderr, "Expectation (%s) failed at [%s:%d]\n", #cond, __FILE__, __LINE__);                              \
      exit(EXIT_FAILURE);                                                                                              \
    }                                                                                                                  \
  } while (0)

#define __TK_EXPECT2(cond, explanation)                                                                                \
  do {                                                                                                                 \
    if (!(cond)) {                                                                                                     \
      fprintf(stderr, "Expectation (%s) failed at [%s:%d] (" explanation ")\n", #cond, __FILE__, __LINE__);            \
      exit(EXIT_FAILURE);                                                                                              \
    }                                                                                                                  \
  } while (0)

/// \brief Expect that the condition is true.
///
/// \example ```c
/// TK_EXPECT(a == 1);
/// TK_EXPECT(a == 1, "`a` does not equal to 1");
/// ```
#define TK_EXPECT(...) __TK_EXPAND(__TK_EXPAND(TK_CONCAT(__TK_EXPECT, TK_NUM_OF(__VA_ARGS__)))(__VA_ARGS__))
