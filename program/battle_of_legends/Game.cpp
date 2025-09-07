#include "Game.hpp"
#include "Utils.hpp"


void clear() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}



void Game::wait_() {
  std::cout << "Press (q = quit, enter = continue)...";
  #ifdef __linux__
    int key = utils::getch();
  #else 
    int key = getch();
  #endif
  if (key == 'q') {
   exit(0);
  }
}

void Game::printInfo_() {
  printf("|Hero: %s (HP: %.1f, ATK: %.1f, DEF: %.1f)|\n", hero->getName().c_str(), hero->getHealth(), hero->getAttack(), hero->getDefense());
  printf("|Monster: %s (HP: %.1f, ATK: %.f, DEF: %.1f)|\n\n", monster->getName().c_str(), monster->getHealth(), monster->getAttack(), monster->getDefense());
}


void Game::checkWinner_() {
  if (hero->getHealth() <= 0) {
    std::cout << monster->getName() << " Menang!" << std::endl;
    isRunning_ = false;
    exit(0);
  } else if(monster->getHealth() <= 0) {
    std::cout << hero->getName() << " Menang!" << std::endl;
    isRunning_ = false;
    exit(0);
  }
}

void Game::update_() {
  checkWinner_();
}

void Game::fight_() {
  std::cout << "=== Battle of Legends!! ===" << std::endl;
  printInfo_();

  printf(">> TURN %d\n", totalTurn);

  if (totalTurn % 2 != 0) {
    hero->takeTurn(*monster);
  } else {
    monster->takeTurn(*hero);
  }
  checkWinner_();
}

Game::Game()
{
  hero = new Hero("Hero", 100, 30, 5);
  monster = new Monster("Demon", 100, 30, 10);
};

Game::~Game() {
  delete hero;
  delete monster;
};

void Game::start() {
  while (isRunning_) {
    clear();
    update_();
    fight_();
    wait_();
    totalTurn++;
  }
}
