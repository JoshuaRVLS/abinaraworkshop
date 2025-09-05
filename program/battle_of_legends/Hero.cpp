#include "Hero.hpp"
#include "Utils.hpp"
#ifdef _WIN32
  #include <conio.h>
#else 
  #include <termios.h>
  #include <unistd.h>
#endif
#include "Game.hpp"

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

Hero::Hero(const std::string &name, double health, double attack, double defense) : Character(name, health, attack, defense) {
  this->init_();
};

void Hero::init_() {
  this->skills_.emplace_back("Power Strike", 1.5);
}

void Hero::uniqueSkill(Character &target, Skill &skill) {
  double damage = utils::generateNumber(1, this->getAttack() * skill.getBonusDamage()) - (target.getDefense());

  if (damage < 0) damage = 0;

  printf("%s Menyerang %s dengan serangan skill %s! (Damage %.f%)\n", this->getName().c_str(), target.getName().c_str(),  skill.getName().c_str(), damage);
  target.takeDamage(damage);
  printf("%s HP tersisa: %.1f\n", target.getName().c_str(), target.getHealth());
}

void Hero::normalAttack(Character &target) {
  double damage = utils::generateNumber(1, this->attack_) - target.getDefense();

  if (damage < 0) damage = 0;

  printf("%s Menyerang %s dengan serangan biasa! (Damage %.f)\n", this->getName().c_str(), target.getName().c_str(), damage);
  target.takeDamage(damage);

  
  printf("%s HP tersisa: %.1f\n", target.getName().c_str(), target.getHealth());
}

void Hero::defense() {
  this->onDefense = true;
}

void Hero::defenseOff() {
  this->onDefense = false;
}

void Hero::takeTurn(Character& target) {
  bool stillFight = true;

  while(stillFight) {
    std::cout << "\n[Aksi hero]" << std::endl;
    std::cout << "[1] Serang" << std::endl;
    std::cout << "[2] Skills" << std::endl;
    std::cout << "[3] Bertahan" << std::endl;
    std::cout << "\n[Choose option by pressing keyboard]" << std::endl;

    char key = getch();
      
    switch(key) {
      case '1':
        this->normalAttack(target);
        stillFight = false;
        break;
      case '2':
        std::cout << "Choose Skills: " << std::endl; 
        for (int i = 0; i < this->getSkills().size(); i++) {
          printf("%d. %s (Damage +%.f%)\n", i, this->getSkills()[i].getName().c_str(), this->getSkills()[i].getBonusDamage()*100);
        }
        int skill_choosed;
        std::cout << "Choose Skill: ";
        std::cin >> skill_choosed;
          
        this->uniqueSkill(target, this->getSkills()[skill_choosed]);

        stillFight = false;
        break;
      case '3':
        this->defense();
        stillFight = false;
        break;
    }      
  }

  
};
