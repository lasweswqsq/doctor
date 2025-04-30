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
#include <windows.h>

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

  //初始化地图，给每个格子分配一个空白的flag
  map.flags = (Flag *)malloc(sizeof(Flag) * map.size.x * map.size.y);
  for (int y = 0; y < map.size.y; ++y)
    for (int x = 0; x < map.size.x; ++x) {
      Vec pos = {x, y};

      Flag flag = eFlagNone;
      if (x == 0 || y == 0 || x == map.size.x - 1 || y == map.size.y - 1)
        flag = eFlagSolid;

      map.flags[Idx(pos)] = flag;
    }

  //在地图内构建不可摧毁墙壁
  for (int i = 0; i<nSolids; ++i) {
    //取2到maxSize-2之间的随机数
    int ranX = 2 + rand() % (map.size.x -2 -2 + 1 );
    int ranY = 2 + rand() % (map.size.y -2 -2 + 1);
    int temp = 0;
    // 构建障碍时如果已经有占了格子了，就重新选择区域构建
    for (int y = -1; y <= 1; ++y) {
      for (int x = -1; x <= 1; ++x) {
        Vec pos = {ranX+x,ranY+y};
        if(map.flags[Idx(pos)]!= eFlagNone){
          i--;
          temp = 1;
          break;
        }
      }
      if (temp == 1)
        break;
    }  
    if (temp == 1)
      continue;
    for (int y = -1; y <= 1; ++y)
      for (int x = -1; x <= 1; ++x) {
        Vec pos = {ranX+x,ranY+y};
        map.flags[Idx(pos)] = eFlagSolid;
      }

  }
  //在地图内构建可摧毁墙壁
  for (int i = 0; i<nWalls; ++i) {
    int ranX = 2 + rand() % (map.size.x -2 -2 + 1);
    int ranY = 2 + rand() % (map.size.y -2 -2 + 1);
    int temp = 0;
    // 构建障碍时如果已经有占了格子了，就重新选择区域构建
    for (int y = -1; y <= 1; ++y) {
      for (int x = -1; x <= 1; ++x) {
        Vec pos = {ranX+x,ranY+y};
        if(map.flags[Idx(pos)]!= eFlagNone){
          i--;
          temp = 1;
          break;
        }
      }
      if (temp == 1)
        break;
    }  
    if (temp == 1)
      continue;
    for (int y = -1; y <= 1; ++y)
      for (int x = -1; x <= 1; ++x) {
        Vec pos = {ranX+x,ranY+y};
        map.flags[Idx(pos)] = eFlagWall;
      }

  }
  
  //构建自己的坦克
  {
    while(true) {
      int ranX = 2 + rand() % (map.size.x -2 -2 + 1);
      int ranY = 2 + rand() % (map.size.y -2 -2 + 1);
      int temp = 0;
    // 构建坦克时如果已经有占了格子了，就重新选择区域构建
      for (int y = -1; y <= 1; ++y) {
        for (int x = -1; x <= 1; ++x) {
          Vec pos = {ranX+x,ranY+y};
          if(map.flags[Idx(pos)]!= eFlagNone){
            temp = 1;
            break;
          } 
        }
        if (temp == 1)
          break; 
      }
      if(temp == 1)
        continue;
      Tank *tank = RegNew(regTank);
      tank->pos = (Vec){ranX, ranY};
      tank->dir = eDirNO;
      tank->color = TK_GREEN;
      tank->isPlayer = true;
      tank->health = 100;
      
      for (int y = -1; y <= 1; ++y) 
        for (int x = -1; x <= 1; ++x) {
          Vec pos = {ranX+x,ranY+y};
          map.flags[Idx(pos)] = eFlagTank ;
        }
      
      
      break;
    }
  }
  //构建敌人的坦克
  for (int i = 0; i < nEnemies; ++i) {
    while(true) {
      int ranX = 2 + rand() % (map.size.x -2 -2 + 1);
      int ranY = 2 + rand() % (map.size.y -2 -2 + 1);
      int temp = 0;
    // 构建坦克时如果已经有占了格子了，就重新选择区域构建
      for (int y = -1; y <= 1; ++y) {
        for (int x = -1; x <= 1; ++x) {
          Vec pos = {ranX+x,ranY+y};
          if(map.flags[Idx(pos)]!= eFlagNone){
            temp = 1;
            break;
          } 
        }
        if (temp == 1)
          break; 
      }
      if(temp == 1)
        continue;
      Tank *tank = RegNew(regTank);
      tank->pos = (Vec){ranX, ranY};
      tank->dir = eDirOP;
      tank->color = TK_RED;
      tank->isPlayer = false;
      tank->health = 100;
      //把坦克区域置为占用
      for (int y = -1; y <= 1; ++y) 
        for (int x = -1; x <= 1; ++x) {
          Vec pos = {ranX+x,ranY+y};
          map.flags[Idx(pos)] = eFlagTank ;
        }
    
      break;
    }

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

  //TODO: You may need to delete or add codes here.
  for (RegIterator it = RegBegin(regTank); it != RegEnd(regTank); it = RegNext(it)) {
    Tank *tank = RegEntry(regTank, it);
    //if (tank->pos.y < map.size.y - 3)
      //++tank->pos.y;
    if (tank-> isPlayer == true) {
      if (game.keyHit == 'w' ){
        if(tank->dir == eDirOP && map.flags[Idx((Vec){tank->pos.x,tank->pos.y+2})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x-1,tank->pos.y+2})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x+1,tank->pos.y+2})] == eFlagNone) {
          ++tank->pos.y;
          for(int i = -1 ; i<=1 ; ++i){
            map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y-2})] = eFlagNone;
            RdrPutChar((Vec){tank->pos.x+i,tank->pos.y-2}, map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y-2})], TK_AUTO_COLOR);
            map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y+1})] = eFlagTank;
            //RdrPutChar((Vec){tank->pos.x+i,tank->pos.y+1}, map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y+1})], TK_AUTO_COLOR);
                      
          }
          
          continue;
          
        }
        else {
          tank->dir = eDirOP;
          continue;
        }
      } 
      if (game.keyHit == 's'  ) {
        if(tank->dir == eDirON && map.flags[Idx((Vec){tank->pos.x,tank->pos.y-2})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x-1,tank->pos.y-2})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x+1,tank->pos.y-2})] == eFlagNone) {
          --tank->pos.y;
          for(int i = -1 ; i<=1 ; ++i){
            map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y+2})] = eFlagNone;
            RdrPutChar((Vec){tank->pos.x+i,tank->pos.y+2}, map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y+2})], TK_AUTO_COLOR);
            map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y-1})] = eFlagTank;
            
          }
        }
        else {
          tank->dir = eDirON;
        }
      }
      if (game.keyHit == 'a' ){
        if(tank->dir == eDirNO && map.flags[Idx((Vec){tank->pos.x-2,tank->pos.y})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x-2,tank->pos.y-1})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x-2,tank->pos.y+1})] == eFlagNone)  {
          --tank->pos.x;
          for(int i = -1 ; i<=1 ; ++i){
            map.flags[Idx((Vec){tank->pos.x+2,tank->pos.y+i})] = eFlagNone;
            RdrPutChar((Vec){tank->pos.x+2,tank->pos.y+i}, map.flags[Idx((Vec){tank->pos.x+2,tank->pos.y+i})], TK_AUTO_COLOR);
            map.flags[Idx((Vec){tank->pos.x-1,tank->pos.y+i})] = eFlagTank;
            
          }
        }
        else {
          tank->dir = eDirNO;
        }
      }
      if (game.keyHit == 'd' ) {
        if(tank->dir == eDirPO && map.flags[Idx((Vec){tank->pos.x+2,tank->pos.y})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x+2,tank->pos.y-1})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x+2,tank->pos.y+1})] == eFlagNone) {
          ++tank->pos.x;
          for(int i = -1 ; i<=1 ; ++i){
            map.flags[Idx((Vec){tank->pos.x-2,tank->pos.y+i})] = eFlagNone;
            RdrPutChar((Vec){tank->pos.x-2,tank->pos.y+i}, map.flags[Idx((Vec){tank->pos.x-2,tank->pos.y+i})], TK_AUTO_COLOR);
            map.flags[Idx((Vec){tank->pos.x+1,tank->pos.y+i})] = eFlagTank;
          }
        }
        else {
          tank->dir = eDirPO;
        }
      }
      if (game.keyHit == 'k') {
        Bullet *bullet = RegNew(regBullet);
        bullet->color = TK_GREEN;
        bullet->isPlayer = true;
        bullet->dir = tank->dir;
        if(tank->dir == eDirON){
          bullet->pos.x = tank->pos.x;
          bullet->pos.y = tank->pos.y-1;
        }
        if(tank->dir == eDirOP){
          bullet->pos.x = tank->pos.x;
          bullet->pos.y = tank->pos.y+1;
        }
        if(tank->dir == eDirNO){
          bullet->pos.x = tank->pos.x-1;
          bullet->pos.y = tank->pos.y;
        }
        if(tank->dir == eDirPO){
          bullet->pos.x = tank->pos.x+1;
          bullet->pos.y = tank->pos.y;
        }
        
      }
    }
    
  }
  
  for (RegIterator it = RegBegin(regBullet); it != RegEnd(regBullet); it = RegNext(it)) {
      Bullet *bullet = RegEntry(regBullet, it);
      switch(bullet->dir) {
        case eDirOP:
          ++bullet->pos.y;
          break;
        case eDirNO:
          --bullet->pos.x;
          break;
        case eDirPO:
          ++bullet->pos.x;
          break;
        case eDirON:
          --bullet->pos.y;
          break;
        default:
          break;
          
      }
      Vec pos = {bullet->pos.x,bullet->pos.y};
      //导弹撞墙了给移除掉
      if(map.flags[Idx(pos)] == eFlagSolid) {
        RegRemove(bullet);
        continue;
      }
      //导弹撞可击倒的墙了，把墙移除掉
      if(map.flags[Idx(pos)] == eFlagWall) {
        RegRemove(bullet);
        map.flags[Idx(pos)] = eFlagNone;
        RdrPutChar(pos, map.flags[Idx((pos))], TK_AUTO_COLOR);
        continue;
      }
      
      //导弹撞坦克坦克受伤，受伤到一定程度移除坦克
      if(map.flags[Idx(pos)] == eFlagTank) {
        RegRemove(bullet);
        for (RegIterator it = RegBegin(regTank); it != RegEnd(regTank); it = RegNext(it)){
          Tank *tank = RegEntry(regTank, it);
          int temp = 0;
          for(int y = -1 ; y <= 1 ; y++) {
            for(int x = -1 ; x <= 1 ; x++) {
              if(bullet->pos.x + x == tank->pos.x && bullet->pos.y + y == tank->pos.y) {
                //随机扣血
                tank->health = tank->health - ((rand() % 100) + 1);
                if (tank->health <= 0) {
                  Vec tempPos = {tank->pos.x,tank->pos.y};
                  temp =1 ;
                  RegRemove(tank);
                  for(int y = -1 ; y <= 1 ; y++)
                    for(int x = -1 ; x <= 1 ; x++) {
                      map.flags[Idx((Vec){tempPos.x+x,tempPos.y+y})] = eFlagNone;
                      RdrPutChar((Vec){tempPos.x+x,tempPos.y+y}, map.flags[Idx((Vec){tempPos.x+x,tempPos.y+y})], TK_AUTO_COLOR);
                  }
                  RegDelete(tank);
                  break;
                 
                  
                }
              } 
            }
            if(temp == 1) 
              break;
          }
          if(temp == 1) 
              break;
        }
        
      }
      
  }
  

  RdrRender();
  RdrFlush();
}

// 独立判断AI的操作
void GameUpdateAI(void) {

    double frameTime = (double)1000 / (double)10;
    clock_t frameBegin = clock();
    for (RegIterator it = RegBegin(regTank); it != RegEnd(regTank); it = RegNext(it)) {
      Tank *tank = RegEntry(regTank, it);
      if (tank-> isPlayer == false) {
        
        int ran = 1 + rand() % (6-1+1);
        if (ran == 1 ){
          if(tank->dir == eDirOP && map.flags[Idx((Vec){tank->pos.x,tank->pos.y+2})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x-1,tank->pos.y+2})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x+1,tank->pos.y+2})] == eFlagNone) {
            ++tank->pos.y;
          for(int i = -1 ; i<=1 ; ++i){
            map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y-2})] = eFlagNone;
            RdrPutChar((Vec){tank->pos.x+i,tank->pos.y-2}, map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y-2})], TK_AUTO_COLOR);
            map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y+1})] = eFlagTank;
          //RdrPutChar((Vec){tank->pos.x+i,tank->pos.y+1}, map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y+1})], TK_AUTO_COLOR);
                    
        }
      }
        else {
          tank->dir = eDirOP;
      }
    } 
      if (ran == 2  ) {
        if(tank->dir == eDirON && map.flags[Idx((Vec){tank->pos.x,tank->pos.y-2})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x-1,tank->pos.y-2})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x+1,tank->pos.y-2})] == eFlagNone) {
          --tank->pos.y;
          for(int i = -1 ; i<=1 ; ++i){
            map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y+2})] = eFlagNone;
            RdrPutChar((Vec){tank->pos.x+i,tank->pos.y+2}, map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y+2})], TK_AUTO_COLOR);
            map.flags[Idx((Vec){tank->pos.x+i,tank->pos.y-1})] = eFlagTank;
          
        }
      }
        else {
          tank->dir = eDirON;
        }
    }
      if (ran == 3 ){
        if(tank->dir == eDirNO && map.flags[Idx((Vec){tank->pos.x-2,tank->pos.y})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x-2,tank->pos.y-1})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x-2,tank->pos.y+1})] == eFlagNone) {
          --tank->pos.x;
          for(int i = -1 ; i<=1 ; ++i){
            map.flags[Idx((Vec){tank->pos.x+2,tank->pos.y+i})] = eFlagNone;
            RdrPutChar((Vec){tank->pos.x+2,tank->pos.y+i}, map.flags[Idx((Vec){tank->pos.x+2,tank->pos.y+i})], TK_AUTO_COLOR);
            map.flags[Idx((Vec){tank->pos.x-1,tank->pos.y+i})] = eFlagTank;
          
        }
      }
        else {
          tank->dir = eDirNO;
        }
    }
      if (ran == 4 ) {
        if(tank->dir == eDirPO && map.flags[Idx((Vec){tank->pos.x+2,tank->pos.y})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x+2,tank->pos.y-1})] == eFlagNone && map.flags[Idx((Vec){tank->pos.x+2,tank->pos.y+1})] == eFlagNone) {
          ++tank->pos.x;
          for(int i = -1 ; i<=1 ; ++i){
            map.flags[Idx((Vec){tank->pos.x-2,tank->pos.y+i})] = eFlagNone;
            RdrPutChar((Vec){tank->pos.x-2,tank->pos.y+i}, map.flags[Idx((Vec){tank->pos.x-2,tank->pos.y+i})], TK_AUTO_COLOR);
            map.flags[Idx((Vec){tank->pos.x+1,tank->pos.y+i})] = eFlagTank;
        }
      }
        else {
          tank->dir = eDirPO;
        }
      }
      if (ran == 5) {
        Bullet *bullet = RegNew(regBullet);
        bullet->color = TK_RED;
        bullet->isPlayer = true;
        bullet->dir = tank->dir;
        if(tank->dir == eDirON){
          bullet->pos.x = tank->pos.x;
          bullet->pos.y = tank->pos.y-1;
        }
        if(tank->dir == eDirOP){
          bullet->pos.x = tank->pos.x;
          bullet->pos.y = tank->pos.y+1;
        }
        if(tank->dir == eDirNO){
          bullet->pos.x = tank->pos.x-1;
          bullet->pos.y = tank->pos.y;
        }
        if(tank->dir == eDirPO){
          bullet->pos.x = tank->pos.x+1;
          bullet->pos.y = tank->pos.y;
        }
      
    }
    while (((double)(clock() - frameBegin) / CLOCKS_PER_SEC) * 1000.0 < frameTime - 0.5)
      Daze();
    frameBegin = clock();
    

      }
    }
    
  
  
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
    GameUpdateAI();

    while (((double)(clock() - frameBegin) / CLOCKS_PER_SEC) * 1000.0 < frameTime - 0.5)
      Daze();
    frameBegin = clock();
  }

  GameTerminate();
}
