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
  map_.generateMap();
}

void Game::clear_() {
  #ifdef _WIN32 
    system("cls");
  #else 
    system("clear");
  #endif
}

void Game::render_() {

}

void Game::input_() {
  char ch = getch();
  std::cout << ch;
}

void Game::start() {
  while (isRunning_) {
    clear_();
    render_();
    input_();
  }
}
