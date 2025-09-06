#include "Map.hpp"
#include "Player.hpp"

void Map::generateMap() {
  tiles_.resize(10);
  for (int i = 0; i < tiles_.size(); i++) {
    tiles_[i].resize(10);
    tiles_[i].resize(3);
  }

  for (int row = 0; row < tiles_.size(); row++) {
    for (int col = 0; col < tiles_[row].size(); col++) {
      for (int tile = 0; tile < tiles_[row][col].size(); tile++) {
        // Generate terrain and wall;
        if (col == 0 || col == tiles_[row].size()) {
          tiles_[row][col].insert(tiles_[row][col].begin(), Player());
        } else {
          
        }
      }
    }
    std::cout << std::endl;
  }
}
