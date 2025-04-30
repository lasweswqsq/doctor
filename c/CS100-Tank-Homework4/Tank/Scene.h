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
#include "Renderer.h"
#include "Terminal.h"

/// \brief Enums of the 2D directions.
typedef enum {
	eDirLD = 1, // Left-down.
	eDirD = 2, // Down.
	eDirRD = 3, // Right-down.

	eDirL = 4, // Left.
	eDirC = 5, // Center.
	eDirR = 6, // Right.

	eDirLU = 7, // Left-up.
	eDirU = 8, // Up.
	eDirRU = 9, // Right-up.

	eDirInvalid = 0, // Invalid.
} Dir, Direction;

/// \brief Enums of the map flags.
typedef enum {
	eFlagNone = ' ', // Nothing here, passable.
	eFlagSolid = '%', // Solid, impassable and non-destructible.
	eFlagWall = '#', // Wall, impassable but destructible.

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
	TK_REG_AUTH; // Authorize `Tank` to make it compatible with registries, see `Registry.h`.
	Vec pos; // Position.
	Dir dir; // Direction.
	Color color; // Color of the tank and its bullets.
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
	TK_REG_AUTH; // Authorize `Bullet` to make it compatible with registries, see `Registry.h`.
	Vec pos; // Position.
	Dir dir; // Direction.
	Color color; // Color.
	bool isPlayer; // Whether this bullet was shot by player or enemy.
} Bullet;

typedef struct {
	// Width (x) and height (y) of the map.
	Vec size;
	// The flags of every positions of the map.
	//! Note that only static flags such as `eFlagNone` and `eFlagSolid` are included here.
	//! Dynamic flags such as `eFlagTank` are not included and will be set to `eFlagNone`.
	Flag* flags;
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
int Idx(Vec pos) { return pos.x + pos.y * map.size.x; }

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
Vec RandPos(void) { return RandVec(map.size); }

/**
* @brief get the clockwise rotated result by the (int) (Dir) index
* @attention eDirC and eDirR will not be rotated or changed
*/
const Direction directionClockwise[] = {
	eDirInvalid,
	eDirL,
	eDirLD,
	eDirD,
	eDirLU,
	eDirC,
	eDirRD,
	eDirU,
	eDirRU,
	eDirR
};

/**
* @brief get the ANTIclockwise rotated result by the (int) (Dir) index
* @attention eDirC and eDirR will not be rotated or changed
*/
const Direction directionAntiClockwise[] = {
	eDirInvalid,
	eDirD,
	eDirRD,
	eDirR,
	eDirLD,
	eDirC,
	eDirRU,
	eDirL,
	eDirLU,
	eDirU
};

/**
* @brief get the opposite side of the (int) (Dir) index
* @attention eDirC and eDirR will not be changed
*/
const Direction directionOpposite[] = {
	eDirInvalid,
	eDirRU,
	eDirU,
	eDirLU,
	eDirR,
	eDirC,
	eDirL,
	eDirRD,
	eDirD,
	eDirLD
};

Vector2D LVec$_$init$_II_LVec$(const int x, const int y) {
	Vector2D ret;
	ret.x = x;
	ret.y = y;
	return ret;
}

static Vector2D vectorFromDirection[10];

bool LMap$_checkEmptyBlock_LVec$_Z(const Vector2D position) { return map.flags[Idx(position)] == ' '; }

Vector2D LVec$_add_LVec$LDir$_LVec$(const Vector2D vector, const Direction direction) {
	const Vector2D rel = vectorFromDirection[direction];
	return LVec$_$init$_II_LVec$(vector.x + rel.x, vector.y + rel.y);
}

Vector2D LVec$_add_LVec$LVec$_LVec$(const Vector2D vector1, const Vector2D vector2) { return LVec$_$init$_II_LVec$(vector1.x + vector2.x, vector1.y + vector2.y); }

/**
* @brief check if the tank can move towards a certain direction.
* @param position the position of the tank
* @param direction the target direction
* @returns bool true - can move; false - cannot move
* @note if direction == eDirInvalid, always returns false: _, eDirInvalid -> false
*/
bool checkCanMove(Vector2D position, const Direction direction) {
	if (!direction) return false;
	Vector2D destination = LVec$_add_LVec$LDir$_LVec$(position, direction);
	if (position.x == 0 || position.y == 0) return false;
	if (position.x > map.size.x - 2 || position.y > map.size.y - 2) return false;
	return LMap$_checkEmptyBlock_LVec$_Z(LVec$_add_LVec$LDir$_LVec$(destination, direction)) && LMap$_checkEmptyBlock_LVec$_Z(LVec$_add_LVec$LDir$_LVec$(destination, directionClockwise[direction])) && LMap$_checkEmptyBlock_LVec$_Z(LVec$_add_LVec$LDir$_LVec$(destination, directionAntiClockwise[direction]));
}

bool LMap$_checkOutsideMap_LVec$_Z(const Vector2D position) { return position.x < 1 || position.x >= map.size.x - 1 || position.y < 1 || position.y >= map.size.y - 1; }

/**
* @brief check if there is enough space to place a 3 * 3 block or tank or anything
* @param position center of the 3 * 3
* @returns bool true - can place, false - place not enough, or maybe out of the map
*/
bool LMap$_checkCanPlace_LVec$_Z(const Vector2D position) {
	if (position.x <= 1 || position.x >= map.size.x - 2 || position.y <= 1 || position.y >= map.size.y - 2) return false;
	if (!LMap$_checkEmptyBlock_LVec$_Z(position)) return false;
	Direction dir = eDirLD;
	do {
		if (!LMap$_checkEmptyBlock_LVec$_Z(LVec$_add_LVec$LDir$_LVec$(position, dir))) return false;
		dir = directionAntiClockwise[dir];
	} while (dir != eDirLD);
	return true;
}

void RdrPutChar(Vec pos, char c, Color color);

/**
* @brief set a 3 * 3 block to (char) c
* @param position the center of the 3 * 3 block
* @param c the (Flag) char to fill the block
*/
void LMap$_setBlock_LVec$C_V(const Vector2D position, char c) {
	Direction dir = eDirLD;
	map.flags[Idx(position)] = (Flag)c;
	RdrPutChar(position, c, 0);
	do {
		map.flags[Idx(LVec$_add_LVec$LDir$_LVec$(position, dir))] = (Flag)c;
		RdrPutChar(position, c, 0);
		dir = directionAntiClockwise[dir];
	} while (dir != eDirLD);
}

void LMap$_setLocation_LVec$C_V(const Vector2D position, char c) {
	map.flags[Idx(position)] = (Flag)c;
	RdrPutChar(position, c, 0);
}

/**
* @brief generates a random 3 * 3 block filled with (char) c, ensuring no collision or overlap
* @param c the (Flag) char to fill the block
*/
void LMap$_generateRandom_C_V(char c) {
	Vector2D vec = {rand(), rand()};
	while (!LMap$_checkCanPlace_LVec$_Z(vec)) { vec = (Vector2D){rand(), rand()}; }
	if (c == 'T') {
		Tank* tank = RegNew(regTank);
		tank->pos = vec;
		tank->isPlayer = false;
		tank->dir = eDirU;
		tank->color = TK_RED;
		LMap$_setBlock_LVec$C_V(vec, 'T');
		return;
	}
	LMap$_setBlock_LVec$C_V(vec, c);
}

/**
* @brief to destroy an entire block (no matter what it is) where the bullet hits. Automatically detects the enemy and the player by the param (bool) isPlayer.
* @param position the (Vec) (Vector2D) position to destroy
* @param isPlayer whether this bullet belongs to the player
* @returns bool true - you should RegDelete the bullet; false - the bullet hits empty, do not RegDelete the bullet
*/
bool LMap$_destroyBlock_LVec$Z_Z(const Vector2D position, bool isPlayer) {
	if (map.flags[Idx(position)] == ' ') return false;
	if (map.flags[Idx(position)] == '#') {
		map.flags[Idx(position)] = ' ';
		return true;
	}
	if (map.flags[Idx(position)] == 'T') {
		for (RegIterator it = RegBegin(regTank); it != RegEnd(regTank); it = RegNext(it)) {
			Tank* tank = RegEntry(regTank, it);
			Vec pos = tank->pos;
			if (position.x - 1 <= pos.x && position.x + 1 >= pos.x && position.y - 1 <= pos.y && position.y + 1 >= pos.y) {
				if (tank->isPlayer == isPlayer) return true;
				LMap$_setBlock_LVec$C_V(tank->pos, ' ');
				RegDelete(tank);
				return true;
			}
		}
	}
	return true;
}
