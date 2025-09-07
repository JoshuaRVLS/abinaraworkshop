#include "Map.hpp"
#include "Utils.hpp"

void Map::generateMap() {
  std::cout << "Generating map..." << std::endl;
  tiles_.resize(10);
  for (int i = 0; i < tiles_.size(); i++) {
    tiles_[i].resize(10);
    for (int j = 0; j < tiles_[i].size(); j++) {
      tiles_[i][j].resize(10);
    }
  }

  for (int row = 0; row < tiles_.size(); row++) {
    for (int col = 0; col < tiles_[row].size(); col++) {
        // Generate terrain and wall;
        if ((row != 0 && row != 10 - 1) && (col > 0 && col < 10 - 1)) {
          std::cout << "Addin Terrain" << std::endl;
          tiles_[row][col].insert(tiles_[row][col].begin(), Sprite(".", Position({row, col})));
        } else {
          std::cout << "Addin Wall" << std::endl;
          tiles_[row][col].insert(tiles_[row][col].begin(), Sprite("#", Position({row, col})));
        }
    }
  }

  // Adding Random Inside Wall (5-10 wall)
  std::mt19937 gen(rd());
  std::uniform_int_distribution generateNumber(5, 10);
  std::uniform_int_distribution randomPosition(1, 9);

  for (int k = 0; k < generateNumber(gen); k++) {
    int randomPositionX = randomPosition(gen);
    int randomPositionY = randomPosition(gen);
    tiles_[randomPositionY][randomPositionX].insert(tiles_[randomPositionY][randomPositionX].begin(), Sprite("#", Position({randomPositionX, randomPositionY})));
  }
  
}

void Map::renderMap() {
  for (auto& row: tiles_) {
    for (auto& col: row) {
      std::cout << col[0].getValue();
    }
    std::cout << std::endl;
  }
}

void Map::spawnPlayer(Player& player) {
  int randomPositionX = utils::generateNumber(1, 8);
  int randomPositionY = utils::generateNumber(1, 8);
  Position playerPosition(randomPositionX, randomPositionY);
  player = Player("P", playerPosition, "Budi", 100, 30, 20);
  tiles_[randomPositionY][randomPositionX].insert(tiles_[randomPositionY][randomPositionX].begin(), player);
}

void Map::spawnMonster(std::vector<Monster>& monsters) {
  int randomPositionX = utils::generateNumber(1, 8);
  int randomPositionY = utils::generateNumber(1, 8);
  Position monsterPosition(randomPositionX, randomPositionY);
  Monster monster = Monster("M", monsterPosition, "Monster", utils::generateNumber(50, 100), utils::generateNumber(10, 20), utils::generateNumber(10, 20));
  monsters.push_back(monster);
  tiles_[randomPositionY][randomPositionX].insert(tiles_[randomPositionY][randomPositionX].begin(), monster);
}

void Map::spawnTraps(std::vector<Trap> &traps) {
  int randomPositionX = utils::generateNumber(1, 8);
  int randomPositionY = utils::generateNumber(1, 8);
  Position trapPosition(randomPositionX, randomPositionY);
  Trap trap = Trap("X", trapPosition, 1);
  tiles_[randomPositionY][randomPositionX].insert(tiles_[randomPositionY][randomPositionX].begin(), trap);
}

void Map::spawnEnd() {
  int randomPositionX = utils::generateNumber(1, 8);
  int randomPositionY = utils::generateNumber(1, 8);
  Position endPosition(randomPositionX, randomPositionY);
  Sprite end = Trap("E", endPosition, 1);
  tiles_[randomPositionY][randomPositionX].insert(tiles_[randomPositionY][randomPositionX].begin(), end);
}

void Map::spawnTreasures() {
  int randomPositionX = utils::generateNumber(1, 8);
  int randomPositionY = utils::generateNumber(1, 8);
  Position treasurePosition(randomPositionX, randomPositionY);
  Sprite treasure = Trap("T", treasurePosition, 1);
  tiles_[randomPositionY][randomPositionX].insert(tiles_[randomPositionY][randomPositionX].begin(), treasure);
}

Tiles &Map::getMap() {
  return tiles_;
}

void Map::movePlayer(Player& player, std::vector<int> coordinates) {
    int currentPositionX = player.getPosition().getX();
    int currentPositionY = player.getPosition().getY();
    int newPositionX = currentPositionX + coordinates[0];
    int newPositionY = currentPositionY + coordinates[1];
    
    if (newPositionX < 0 || newPositionX >= 20 || newPositionY < 0 || newPositionY >= 20) {
        return; 
    }
    
    if (tiles_[newPositionY][newPositionX][0].getValue() == "#") {
        return; 
    }
    
    if (!tiles_[currentPositionY][currentPositionX].empty()) {
        for (auto it = tiles_[currentPositionY][currentPositionX].begin(); 
             it != tiles_[currentPositionY][currentPositionX].end(); ++it) {
            if (it->getValue() == "P") {
                tiles_[currentPositionY][currentPositionX].erase(it);
                break;
            }
        }
    }
  
    tiles_[newPositionY][newPositionX].insert(
        tiles_[newPositionY][newPositionX].begin(), 
        Sprite("P", {newPositionX, newPositionY})
    );
    
    player.setPosition({newPositionX, newPositionY});
};