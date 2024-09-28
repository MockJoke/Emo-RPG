#pragma once

#include <iostream>
#include <cstdlib>
#include <chrono>
#include "player.h"
#include "enemy.h"

void sleep(const std::chrono::duration<int>&); 
void getEnemyStats(Enemy*);
void checkAlive(Enemy*);
void moveForward();
void gameStart(); 
