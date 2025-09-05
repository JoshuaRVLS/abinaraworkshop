#include "Maze.hpp"

std::string& Maze::generateSymbol() {
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> randomNumber(0, (int)symbols.size()-1); 
  return symbols[randomNumber(gen)];
}

std::vector<int> &Maze::getPlayerPosition() {
  return this->playerPosition;
}

int Maze::generateRandomPosition() {
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> randomNumber(0, 19);
  return randomNumber(gen);
} 

void Maze::generateMaze() {
  this->map.clear();
  this->map.resize(20);
  for (int i = 0; i < this->map.size(); i++) {
    this->map[i].resize(20);
    this->map[i][i].resize(10);
  }

  int playerPositionX = this->generateRandomPosition();
  int playerPositionY = this->generateRandomPosition();
  this->playerPosition = {playerPositionX, playerPositionY};
  this->map[playerPositionY][playerPositionX].insert(this->map[playerPositionY][playerPositionX].begin(), Sprite("P", {playerPositionX, playerPositionY}));
  
  int endPositionX = this->generateRandomPosition();
  int endPositionY = this->generateRandomPosition();
  this->endPosition = {endPositionX, endPositionY};
  this->map[endPositionY][endPositionX].insert(this->map[endPositionY][endPositionX].begin(), Sprite("E", {endPositionX, endPositionY}));

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      std::string symbol = generateSymbol();
      if (this->map[i][j].size() > 0) {
        if (!(this->map[i][j][0].getValue() == "E")) {
          this->map[i][j].push_back(Sprite(symbol, {j, i}));
        }
      }
      this->map[i][j].push_back(Sprite(symbol, {j, i}));
    }
  }
}

void Maze::printMap() {
  
  for (auto& row: this->map) { 
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
    int currentPositionX = this->playerPosition[0];
    int currentPositionY = this->playerPosition[1];
    int newPositionX = currentPositionX + coordinates[0];
    int newPositionY = currentPositionY + coordinates[1];
    
    if (newPositionX < 0 || newPositionX >= 20 || newPositionY < 0 || newPositionY >= 20) {
        return; 
    }
    
    if (this->map[newPositionY][newPositionX][0].getValue() == "#") {
        return; 
    }
    
    if (!this->map[currentPositionY][currentPositionX].empty()) {
        for (auto it = this->map[currentPositionY][currentPositionX].begin(); 
             it != this->map[currentPositionY][currentPositionX].end(); ++it) {
            if (it->getValue() == "P") {
                this->map[currentPositionY][currentPositionX].erase(it);
                break;
            }
        }
    }
  
    this->map[newPositionY][newPositionX].insert(
        this->map[newPositionY][newPositionX].begin(), 
        Sprite("P", {newPositionX, newPositionY})
    );
    
    this->playerPosition = {newPositionX, newPositionY};
}

Map &Maze::getMap() {
  return map;
}
