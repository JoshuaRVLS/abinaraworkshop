#pragma once 
#include <vector>
#include "Sprite.hpp"
#include <iostream>
#include <random>
#include <Monster.hpp>
#include <Player.hpp>
#include <Trap.hpp>

typedef std::vector<std::vector<std::vector<Sprite>>> Tiles;

class Map {
  Tiles tiles_;
  std::random_device rd;



public:
  Map() {};

  void generateMap();
  void renderMap();
  void spawnPlayer(Player& player);
  void spawnMonster(std::vector<Monster>& monsters);
  void spawnTraps(std::vector<Trap>& traps);
  void spawnEnd();
  void spawnTreasures();
  Tiles& getMap();
  void movePlayer(Player& player, std::vector<int> coordinates);

};