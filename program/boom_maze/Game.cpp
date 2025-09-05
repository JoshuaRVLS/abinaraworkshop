#include "Game.hpp"

#ifdef __linux__
  char getch() {
    struct termios oldTerminal;

    tcgetattr(STDIN_FILENO, &oldTerminal);

    struct termios newTerminal;
    newTerminal = oldTerminal;
    
    newTerminal.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTerminal);
    
    char ch;
    read(STDIN_FILENO, &ch, 1);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminal);
    return ch;
  }
#endif 


Game::Game() {
  this->init_();
}

void Game::init_() {
  this->maze.generateMaze();
}

void Game::clear_() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void Game::render_() {
  this->maze.printMap();
}

void Game::check_() {
  auto& currentLayer = this->maze.getMap()[this->maze.getPlayerPosition()[1]][this->maze.getPlayerPosition()[0]];
  if (currentLayer.size() > 1) {
    currentLayer[1].setHidden(false);
    if (currentLayer[1].getValue() == "*") {
      std::cout << "Kamu Kalah!" << std::endl;
      this->isRunning_ = false;
      exit(0);
    } else if (currentLayer[1].getValue() == "E") {
      std::cout << "Kamu Menang!" << std::endl;
      this->isRunning_ = false;
      exit(0);
    }
  }
}

void Game::input_() {
  std::cout << "[w = move up]\n[a = move left]\n[s = move down]\n[d = move right]\n[q = quit]\n[r = restart]" << std::endl;
  char key_pressed = getch();
  switch(key_pressed) {
    case 'w':
      this->maze.movePlayer({0, -1});
      break;
    case 'a':
      this->maze.movePlayer({-1, 0});
      break;
    case 's':
      this->maze.movePlayer({0, 1});
      break;
    case 'd':
      this->maze.movePlayer({1, 0});
      break;
    case 'q':
      exit(0);
      break;
    case 'r':
      this->maze.generateMaze();
      break;
  }
}

void Game::start() {
  while (this->isRunning_) {
    this->clear_();
    this->render_();
    this->check_();
    this->input_();
  }
}