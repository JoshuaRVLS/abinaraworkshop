#include "Hero.hpp"
#include "Utils.hpp"
#include "Game.hpp"



Hero::Hero(const std::string &name, double health, double attack, double defense) : Character(name, health, attack, defense) {
  init_();
};

void Hero::init_() {
  skills_.emplace_back("Power Strike", 1.5);
}

void Hero::uniqueSkill(Character &target, Skill &skill) {
  double damage = utils::generateNumber(1, getAttack() * skill.getBonusDamage()) - (target.getDefense());

  if (damage < 0) damage = 0;

  printf("%s Menyerang %s dengan serangan skill %s! (Damage %.f%)\n", getName().c_str(), target.getName().c_str(),  skill.getName().c_str(), damage);
  target.takeDamage(damage);
  printf("%s HP tersisa: %.1f\n", target.getName().c_str(), target.getHealth());
}

void Hero::normalAttack(Character &target) {
  double damage = utils::generateNumber(1, attack_) - target.getDefense();

  if (damage < 0) damage = 0;

  printf("%s Menyerang %s dengan serangan biasa! (Damage %.f)\n", getName().c_str(), target.getName().c_str(), damage);
  target.takeDamage(damage);

  
  printf("%s HP tersisa: %.1f\n", target.getName().c_str(), target.getHealth());
}

void Hero::defense() {
  onDefense = true;
}

void Hero::defenseOff() {
  onDefense = false;
}

void Hero::takeTurn(Character& target) {
  bool stillFight = true;

  while(stillFight) {
    std::cout << "\n[Aksi hero]" << std::endl;
    std::cout << "[1] Serang" << std::endl;
    std::cout << "[2] Skills" << std::endl;
    std::cout << "[3] Bertahan" << std::endl;
    std::cout << "\n[Choose option by pressing keyboard]" << std::endl;

    #ifdef __linux__
      int key = utils::getch();
    #else 
      int key = getch();
    #endif
      
    switch(key) {
      case '1':
        normalAttack(target);
        stillFight = false;
        break;
      case '2':
        std::cout << "Choose Skills: " << std::endl; 
        for (int i = 0; i < getSkills().size(); i++) {
          printf("%d. %s (Damage +%.f%)\n", i, getSkills()[i].getName().c_str(), getSkills()[i].getBonusDamage()*100);
        }
        int skill_choosed;
        std::cout << "Choose Skill: ";
        std::cin >> skill_choosed;
          
        uniqueSkill(target, getSkills()[skill_choosed]);

        stillFight = false;
        break;
      case '3':
        defense();
        stillFight = false;
        break;
    }      
  }

  
};
