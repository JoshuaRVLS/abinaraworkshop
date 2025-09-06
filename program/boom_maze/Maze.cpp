#include "Maze.hpp"

std::string& Maze::generateSymbol() {
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> randomNumber(0, (int)symbols.size()-1); 
  return symbols[randomNumber(gen)];
}

std::vector<int> &Maze::getPlayerPosition() {
  return playerPosition;
}

int Maze::generateRandomPosition() {
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> randomNumber(0, 19);
  return randomNumber(gen);
} 

void Maze::generateMaze() {
  map.clear();
  map.resize(20);
  for (int i = 0; i < map.size(); i++) {
    map[i].resize(20);
    map[i][i].resize(10);
  }

  int playerPositionX = generateRandomPosition();
  int playerPositionY = generateRandomPosition();
  playerPosition = {playerPositionX, playerPositionY};
  map[playerPositionY][playerPositionX].insert(map[playerPositionY][playerPositionX].begin(), Sprite("P", {playerPositionX, playerPositionY}));
  
  int endPositionX = generateRandomPosition();
  int endPositionY = generateRandomPosition();
  endPosition = {endPositionX, endPositionY};
  map[endPositionY][endPositionX].insert(map[endPositionY][endPositionX].begin(), Sprite("E", {endPositionX, endPositionY}));

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      std::string symbol = generateSymbol();
      if (map[i][j].size() > 0) {
        if (!(map[i][j][0].getValue() == "E")) {
          map[i][j].push_back(Sprite(symbol, {j, i}));
        }
      }
      map[i][j].push_back(Sprite(symbol, {j, i}));
    }
  }
}

void Maze::printMap() {
  
  for (auto& row: map) { 
    for (auto& col: row) {
      if (col[0].isHidden() && col[0].getValue() != "#" && col[0].getValue() != "P" && col[0].getValue() != "E") {
        std::cout << "?";
      } else {
        std::cout << col[0].getValue();
      }
    }
    std::cout << std::endl;
  }
}

void Maze::movePlayer(std::vector<int> coordinates) {
    int currentPositionX = playerPosition[0];
    int currentPositionY = playerPosition[1];
    int newPositionX = currentPositionX + coordinates[0];
    int newPositionY = currentPositionY + coordinates[1];
    
    if (newPositionX < 0 || newPositionX >= 20 || newPositionY < 0 || newPositionY >= 20) {
        return; 
    }
    
    if (map[newPositionY][newPositionX][0].getValue() == "#") {
        return; 
    }
    
    if (!map[currentPositionY][currentPositionX].empty()) {
        for (auto it = map[currentPositionY][currentPositionX].begin(); 
             it != map[currentPositionY][currentPositionX].end(); ++it) {
            if (it->getValue() == "P") {
                map[currentPositionY][currentPositionX].erase(it);
                break;
            }
        }
    }
  
    map[newPositionY][newPositionX].insert(
        map[newPositionY][newPositionX].begin(), 
        Sprite("P", {newPositionX, newPositionY})
    );
    
    playerPosition = {newPositionX, newPositionY};
}

Map &Maze::getMap() {
  return map;
}
