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
  init_();
}

void Game::init_() {
  maze.generateMaze();
}

void Game::clear_() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void Game::render_() {
  maze.printMap();
}

void Game::check_() {
  auto& currentLayer = maze.getMap()[maze.getPlayerPosition()[1]][maze.getPlayerPosition()[0]];
  if (currentLayer.size() > 1) {
    currentLayer[1].setHidden(false);
    if (currentLayer[1].getValue() == "*") {
      std::cout << "Kamu Kalah!" << std::endl;
      isRunning_ = false;
      exit(0);
    } else if (currentLayer[1].getValue() == "E") {
      std::cout << "Kamu Menang!" << std::endl;
      isRunning_ = false;
      exit(0);
    }
  }
}

void Game::input_() {
  std::cout << "[w = move up]\n[a = move left]\n[s = move down]\n[d = move right]\n[q = quit]\n[r = restart]" << std::endl;
  char key_pressed = getch();
  switch(key_pressed) {
    case 'w':
      maze.movePlayer({0, -1});
      break;
    case 'a':
      maze.movePlayer({-1, 0});
      break;
    case 's':
      maze.movePlayer({0, 1});
      break;
    case 'd':
      maze.movePlayer({1, 0});
      break;
    case 'q':
      exit(0);
      break;
    case 'r':
      maze.generateMaze();
      break;
  }
}

void Game::start() {
  while (isRunning_) {
    clear_();
    render_();
    check_();
    input_();
  }
}