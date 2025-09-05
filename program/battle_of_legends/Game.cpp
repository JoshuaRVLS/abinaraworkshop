#include "Game.hpp"
#ifdef _WIN32
  #include <conio.h>
#else 
  #include <termios.h>
  #include <unistd.h>
#endif

void clear() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

#ifdef __linux__
  char getch() {
      struct termios oldt;
      tcgetattr(STDIN_FILENO, &oldt);
      
      struct termios newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      
      char ch;
      read(STDIN_FILENO, &ch, 1);
      
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      
      return ch;
  }
#endif

void Game::wait_() {
  std::cout << "Press (q = quit, enter = continue)...";
  int key = getch();
  if (key == 'q') {
   exit(0);
  }
}

void Game::printInfo_() {
  printf("|Hero: %s (HP: %.1f, ATK: %.1f, DEF: %.1f)|\n", this->hero->getName().c_str(), this->hero->getHealth(), this->hero->getAttack(), this->hero->getDefense());
  printf("|Monster: %s (HP: %.1f, ATK: %.f, DEF: %.1f)|\n\n", this->monster->getName().c_str(), this->monster->getHealth(), this->monster->getAttack(), this->monster->getDefense());
}


void Game::checkWinner_() {
  if (this->hero->getHealth() <= 0) {
    std::cout << this->monster->getName() << " Menang!" << std::endl;
    this->isRunning_ = false;
    exit(0);
  } else if(this->monster->getHealth() <= 0) {
    std::cout << this->hero->getName() << " Menang!" << std::endl;
    this->isRunning_ = false;
    exit(0);
  }
}

void Game::update_() {
  checkWinner_();
}

void Game::fight_() {
  std::cout << "=== Battle of Legends!! ===" << std::endl;
  this->printInfo_();

  printf(">> TURN %d\n", totalTurn);

  if (this->totalTurn % 2 != 0) {
    this->hero->takeTurn(*monster);
  } else {
    this->monster->takeTurn(*hero);
  }
  checkWinner_();
}

Game::Game()
{
  this->hero = new Hero("Hero", 100, 30, 5);
  this->monster = new Monster("Demon", 100, 30, 10);
};

Game::~Game() {
  delete this->hero;
  delete this->monster;
};

void Game::start() {
  while (this->isRunning_) {
    clear();
    this->update_();
    this->fight_();
    this->wait_();
    this->totalTurn++;
  }
}
