#pragma once

/// \file
/// \brief This file contains the terminal-related functions, which
/// help us implement and run console games in the terminal.

//
//
//
//
//
#include "Base.h"

#ifdef _WIN32
  #include <conio.h>
  #include <windows.h>
#else
  #include <fcntl.h>
  #include <termios.h>

/// \brief Test whether the keyboard has been stroke.
/// Returns 1 if there is a keyboard stroke, or 0 if there is none.
int kbhit(void) {
  struct termios oldt;
  tcgetattr(STDIN_FILENO, &oldt);
  struct termios newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  int ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}

/// \brief Get a character from input without showing it.
int getch(void) {
  struct termios oldt;
  tcgetattr(STDIN_FILENO, &oldt);
  struct termios newt = oldt;
  newt.c_lflag &= ~ICANON;
  newt.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  int ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}
#endif // _WIN32

/// \brief Test whether the keyboard has been stroke.
/// Returns 1 if there is a keyboard stroke, or 0 if there is none.
///
/// \warning This function should always be used instead of `kbhit` to
/// make the codes more portable.
int kbhit_t(void) {
#if TK_MSVC
  return _kbhit();
#else
  return kbhit();
#endif
}

/// \brief Get a character from input without showing it.
///
/// \warning This function should always be used instead of `getch` to
/// make the codes more portable.
int getch_t(void) {
#if TK_MSVC
  return _getch();
#else
  return getch();
#endif
}

//
//
//
void TermClearScreen(void) {
  printf("\033[2J\033[1;1f");
}

void TermHideCursor(void) {
  printf("\033[?25l");
}

void TermShowCursor(void) {
  printf("\033[?25h");
}

/// \brief Move cursor to the given `row` and `col`.
void TermMoveCursor(int row, int col) {
  printf("%c[%d;%df", 0x1B, row + 1, col + 1);
}

//
//
//
void TermDisableInputEcho(void) {
#ifdef _WIN32
  HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
  DWORD mode = 0;
  GetConsoleMode(hStdin, &mode);
  SetConsoleMode(hStdin, mode & ~ENABLE_ECHO_INPUT);
#else
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);
#endif // _WIN32
}

void TermEnableInputEcho(void) {
#ifdef _WIN32
  HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
  DWORD mode = 0;
  GetConsoleMode(hStdin, &mode);
  SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT);
#else
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag |= ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);
#endif // _WIN32
}

bool TermIsStdoutTerm(void) {
#ifdef _WIN32
  return GetFileType(GetStdHandle(STD_OUTPUT_HANDLE)) == FILE_TYPE_CHAR;
#else
  return isatty(STDOUT_FILENO);
#endif // _WIN32
}

/// \brief Setup the terminal as a game environment.
///
/// \note This function should be called before rendering.
void TermSetupGameEnvironment(void) {
  TK_EXPECT(TermIsStdoutTerm(), "Console games must be run in a terminal");

#ifdef _WIN32
  HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
  TK_EXPECT(hStd != INVALID_HANDLE_VALUE);

  DWORD dwMode = 0;
  TK_EXPECT(GetConsoleMode(hStd, &dwMode));

  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  TK_EXPECT(SetConsoleMode(hStd, dwMode), "Failed to enable virtual terminal processing");
#endif // _WIN32

  TermHideCursor();
  atexit(TermShowCursor);

  TermDisableInputEcho();
  setbuf(stdout, NULL);
}
