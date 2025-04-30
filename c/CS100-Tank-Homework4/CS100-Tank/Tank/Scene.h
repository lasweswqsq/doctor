#pragma once

/// \file
/// \brief This file contains the definitions, singletons, and functions of
/// the game-related types, such as `Tank`, `Bullet`, and `Map`.
///
/// The powerful "registries" are intensively used to make our life easier.
/// Please read the comments of `Registry.h` before continue.

//
//
//
//
//
#include "Registry.h"
#include "Terminal.h"

/// \brief Enums of the 2D directions.
typedef enum {
  eDirNN, // Left-down.
  eDirON, // Down.
  eDirPN, // Right-down.

  eDirNO, // Left.
  eDirOO, // Center.
  eDirPO, // Right.

  eDirNP, // Left-up.
  eDirOP, // Up.
  eDirPP, // Right-up.

  eDirInvalid, // Invalid.
} Dir;

/// \brief Enums of the map flags.
typedef enum {
  eFlagNone = ' ',  // Nothing here, passable.
  eFlagSolid = '%', // Solid, impassable and non-destructible.
  eFlagWall = '#',  // Wall, impassable but destructible.

  eFlagTank = 'T', // Tank, impassable but destructible.

  eFlagInvalid = '\0', // Invalid.
} Flag;

/// \example It is easy to create or delete a `Tank` with the help of registries, see `Registry.h`.
/// ```c
/// Tank *tank = RegNew(regTank); //! `malloc` is called here.
/// tank->pos = ...
/// ...
/// RegDelete(tank); //! `free` is called here.
/// ```
typedef struct {
  TK_REG_AUTH;   // Authorize `Tank` to make it compatible with registries, see `Registry.h`.
  Vec pos;       // Position.
  Dir dir;       // Direction.
  Color color;   // Color of the tank and its bullets.
  bool isPlayer; // Whether this tank is player or enemy.
} Tank;

/// \example It is easy to create or delete a `Bullet` with the help of registries, see `Registry.h`.
/// ```c
/// Bullet *bullet = RegNew(regBullet); //! `malloc` is called here.
/// bullet->pos = ...
/// ...
/// RegDelete(bullet); //! `free` is called here.
/// ```
typedef struct {
  TK_REG_AUTH;   // Authorize `Bullet` to make it compatible with registries, see `Registry.h`.
  Vec pos;       // Position.
  Dir dir;       // Direction.
  Color color;   // Color.
  bool isPlayer; // Whether this bullet was shot by player or enemy.
} Bullet;

typedef struct {
  // Width (x) and height (y) of the map.
  Vec size;
  // The flags of every positions of the map.
  //! Note that only static flags such as `eFlagNone` and `eFlagSolid` are included here.
  //! Dynamic flags such as `eFlagTank` are not included and will be set to `eFlagNone`.
  Flag *flags;
} Map;

//
//
//
// Define a registry for `Tank`, see `Registry.h`.
static TK_REG_DEF(Tank, regTank);

// Define a registry for `Bullet`, see `Registry.h`.
static TK_REG_DEF(Bullet, regBullet);

// The map singleton.
static Map map;

//
//
//
/// \brief Convert `pos` to its linearized index of the map.
///
/// \example ```c
/// Vec pos = {x, y};
/// Flag flag = map.flags[Idx(pos)];
/// ```
int Idx(Vec pos) {
  return pos.x + pos.y * map.size.x;
}

/// \brief Move cursor to `pos`.
///
/// \example ```c
/// MoveCursor(pos);
/// printf(TK_TEXT("Hello World!\n", TK_RED));
/// ```
void MoveCursor(Vec pos) {
  int row = map.size.y - 1 - pos.y;
  int col = pos.x * 2;
  TermMoveCursor(row, col);
}

/// \brief Randomly generate a position in map.
Vec RandPos(void) {
  return RandVec(map.size);
}
