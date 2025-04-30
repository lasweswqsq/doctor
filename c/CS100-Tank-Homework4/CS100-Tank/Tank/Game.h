#pragma once

/// \file
/// \brief This file contains the game lifecycle and logics.
/// There are 5 important functions:
/// `GameInit`, `GameInput`, `GameUpdate`, `GameTerminate`, and
/// the most important: `GameLifecycle`.
/// Please read the corresponding comments to understand their relationships.

//
//
//
//
//
#include "Config.h"
#include "Renderer.h"

#include <time.h>

typedef struct {
  char keyHit; // The keyboard key hit by the player at this frame.
} Game;

// The game singleton.
static Game game;

// The keyboard key "ESC".
static const char keyESC = '\033';

//
//
//
/// \brief Configure the scene (See `Scene.h`) with `config` (See `Config.h`), and
/// perform initializations including:
/// 1. Terminal setup.
/// 2. Memory allocations.
/// 3. Map and object generations.
/// 4. Rendering of the initialized scene.
///
/// \note This function should be called at the very beginning of `GameLifecycle`.
void GameInit(void) {
  // Setup terminal.
  TermSetupGameEnvironment();
  TermClearScreen();

  // Configure scene.
  map.size = config.mapSize;
  int nEnemies = config.nEnemies;
  int nSolids = config.nSolids;
  int nWalls = config.nWalls;

  // Initialize scene.
  RegInit(regTank);
  RegInit(regBullet);

  map.flags = (Flag *)malloc(sizeof(Flag) * map.size.x * map.size.y);
  for (int y = 0; y < map.size.y; ++y)
    for (int x = 0; x < map.size.x; ++x) {
      Vec pos = {x, y};

      Flag flag = eFlagNone;
      if (x == 0 || y == 0 || x == map.size.x - 1 || y == map.size.y - 1)
        flag = eFlagSolid;

      map.flags[Idx(pos)] = flag;
    }

  {
    Tank *tank = RegNew(regTank);
    tank->pos = (Vec){2, 2};
    tank->dir = eDirOP;
    tank->color = TK_GREEN;
    tank->isPlayer = true;
  }

  // Initialize renderer.
  renderer.csPrev = (char *)malloc(sizeof(char) * map.size.x * map.size.y);
  renderer.colorsPrev = (Color *)malloc(sizeof(Color) * map.size.x * map.size.y);
  renderer.cs = (char *)malloc(sizeof(char) * map.size.x * map.size.y);
  renderer.colors = (Color *)malloc(sizeof(Color) * map.size.x * map.size.y);

  for (int i = 0; i < map.size.x * map.size.y; ++i) {
    renderer.csPrev[i] = renderer.cs[i] = ' ';
    renderer.colorsPrev[i] = renderer.colors[i] = TK_NORMAL;
  }

  // Render scene.
  for (int y = 0; y < map.size.y; ++y)
    for (int x = 0; x < map.size.x; ++x) {
      Vec pos = {x, y};
      RdrPutChar(pos, map.flags[Idx(pos)], TK_AUTO_COLOR);
    }
  RdrRender();
  RdrFlush();
}

//
//
//
/// \brief Read input from the player.
///
/// \note This function should be called in the loop of `GameLifecycle` before `GameUpdate`.
void GameInput(void) {
  game.keyHit = kbhit_t() ? (char)getch_t() : '\0';
}

//
//
//
/// \brief Perform all tasks required for a frame update, including:
/// 1. Game logics of `Tank`s, `Bullet`s, etc.
/// 2. Rerendering all objects in the scene.
///
/// \note This function should be called in the loop of `GameLifecycle` after `GameInput`.
void GameUpdate(void) {
  RdrClear();

  // TODO: You may need to delete or add codes here.
  for (RegIterator it = RegBegin(regTank); it != RegEnd(regTank); it = RegNext(it)) {
    Tank *tank = RegEntry(regTank, it);
    if (tank->isPlayer == true) {
      if (game.keyHit == 'w') {
        tank->dir = eDirUP;
      }
  }



  RdrRender();
  RdrFlush();
}

//
//
//
/// \brief Terminate the game and free all the resources.
///
/// \note This function should be called at the very end of `GameLifecycle`.
void GameTerminate(void) {
  while (RegSize(regTank) > 0)
    RegDelete(RegEntry(regTank, RegBegin(regTank)));

  while (RegSize(regBullet) > 0)
    RegDelete(RegEntry(regBullet, RegBegin(regBullet)));

  free(map.flags);

  free(renderer.csPrev);
  free(renderer.colorsPrev);
  free(renderer.cs);
  free(renderer.colors);

  TermClearScreen();
}

//
//
//
/// \brief Lifecycle of the game, defined by calling the 4 important functions:
/// `GameInit`, `GameInput`, `GameUpdate`, and `GameTerminate`.
///
/// \note This function should be called by `main`.
void GameLifecycle(void) {
  GameInit();

  double frameTime = (double)1000 / (double)config.fps;
  clock_t frameBegin = clock();

  while (true) {
    GameInput();
    if (game.keyHit == keyESC)
      break;

    GameUpdate();

    while (((double)(clock() - frameBegin) / CLOCKS_PER_SEC) * 1000.0 < frameTime - 0.5)
      Daze();
    frameBegin = clock();
  }

  GameTerminate();
}
