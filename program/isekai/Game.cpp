#include "Game.hpp"

#ifdef __linux__

  char getch() {
    struct termios oldT;
    tcgetattr(STDIN_FILENO, &oldT);

    struct termios newT;
    newT = oldT;
    newT.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newT);

    char ch;
    read(STDIN_FILENO, &ch, 1);


    tcsetattr(STDIN_FILENO, TCSANOW, &oldT);
    return ch;
  }

#endif

Game::Game() {
  init_();
}

void Game::init_() {
  status_ = "Hari yang menyenangkan";
  map_.generateMap();
  map_.spawnPlayer(player_);
  for (int _ = 0; _ < maxMonsters; _++) {
    map_.spawnMonster(monsters_);
  }
  for (int _ = 0; _ < maxTraps; _++) {
    map_.spawnTraps(traps_);
  }
  for (int _ = 0; _ < maxTreasures; _++) {
    map_.spawnTreasures();
  }
  map_.spawnEnd();
}

void Game::playerInfo_() {
  printf("===Dungeon Explorer===]\n");
  printf("Nyawa: %d | HP: %.f | Skor: %d\n", player_.getLife(), player_.getHealth(), player_.getPoints());
}

void Game::printFightInfo_() {
  printf("|Hero: %s (HP: %.1f, ATK: %.1f, DEF: %.1f)|\n", player_.getName().c_str(), player_.getHealth(), player_.getAttack(), player_.getDefense());
  printf("|Monster: %s (HP: %.1f, ATK: %.f, DEF: %.1f)|\n\n", player_.getCurrentEnemy().getName().c_str(), player_.getCurrentEnemy().getHealth(), player_.getCurrentEnemy().getAttack(), player_.getCurrentEnemy().getDefense());
}

void Game::clear_() {
  #ifdef _WIN32 
    system("cls");
  #else 
    system("clear");
  #endif
}

void Game::render_() {
  playerInfo_();
  map_.renderMap();
  std::cout << status_ << std::endl;
  std::cout << "Move (WASD)" << std::endl;
}

void Game::check_() {
  auto& currentLayer = map_.getMap()[player_.getPosition().getY()][player_.getPosition().getX()];
  if (currentLayer.size() > 1) {
    if (currentLayer[1].getValue() == "M") {
      player_.setBattle(true);
      Character* enemy;
      for (auto& monster: monsters_) {
        if ((monster.getPosition().getX() == currentLayer[1].getPosition().getX()) && (monster.getPosition().getY() == currentLayer[1].getPosition().getY())) {
          enemy = &monster;
        }
      }
      player_.setCurrentEnemy(*enemy);
    } else if (currentLayer[1].getValue() == "X") {
      player_.minLife(1);
      status_ = "Ah shit here we go again";
    } else if (currentLayer[1].getValue() == "T") {
      player_.addPoints(10);
      currentLayer.erase(currentLayer.begin() + 1);
      status_ = "My goddess fortuna, its a treasure !!!";
    } else if (currentLayer[1].getValue() == "E") {
      status_ = "Kamu keluar dari dungeon.";
      exit(0);
    } else {
      status_ = "Hari yang menyenangkan";
    }
  }
}

void Game::input_() {
  char key_pressed = getch();
  switch(key_pressed) {
    case 'w':
      map_.movePlayer(player_, {0, -1});
      break;
    case 'a':
      map_.movePlayer(player_, {-1, 0});
      break;
    case 's':
      map_.movePlayer(player_, {0, 1});
      break;
    case 'd':
      map_.movePlayer(player_, {1, 0});
      break;
    case 'q':
      exit(0);
      break;
    case 'r':
      init_();
      break;
  }
}

void Game::checkWinner_() {
  if (player_.getHealth() <= 0) {
    std::cout << player_.getCurrentEnemy().getName() << " Menang!" << std::endl;
    isRunning_ = false;
    exit(0);
  } else if(player_.getCurrentEnemy().getHealth() <= 0) {
    std::cout << player_.getName() << " Menang!" << std::endl;
    player_.setBattle(false);
    player_.clearEnemy();
    totalTurn = 0;
  }
}



void Game::fight_() {
  std::cout << "=== Battle of Legends!! ===" << std::endl;
  printFightInfo_();

  printf(">> TURN %d\n", totalTurn);

  if (totalTurn % 2 != 0) {
    player_.takeTurn(player_.getCurrentEnemy());
  } else {
    player_.getCurrentEnemy().takeTurn(player_);
  }
  checkWinner_();
}

void Game::update_() {
  check_();
}

void Game::start() {
  while (isRunning_) {
    if (!player_.isBattle()) {
      clear_();
      update_();
      render_();
      input_();
    } else {
      clear_();
      checkWinner_();
      fight_();
      totalTurn++;
    }
  }
}
