#include "Player.hpp"
#include "Map.hpp"
#include "Utils.hpp"
#include "Game.hpp"



Player::Player(const std::string& value, Position& position, const std::string &name, double health, double attack, double defense) : Character(name, health, attack, defense), Sprite(value, position) {
  init_();
}

void Player::setPosition(Position position) {
  position_ = position;
}

void Player::addPoints(int points) {
  points_ += points;
}

void Player::minLife(int by) {
  life_ -= by;
};

int& Player::getLife() {
  return life_;
}

int& Player::getPoints() {
  return points_;
}

void Player::init_() {
  skills_.emplace_back("Power Strike", 1.5);
}

void Player::uniqueSkill(Character &target, Skill &skill) {
  double damage = utils::generateNumber(1, getAttack() * skill.getBonusDamage()) - (target.getDefense());

  if (damage < 0) damage = 0;

  printf("%s Menyerang %s dengan serangan skill %s! (Damage %.f%)\n", getName().c_str(), target.getName().c_str(),  skill.getName().c_str(), damage);
  target.takeDamage(damage);
  printf("%s HP tersisa: %.1f\n", target.getName().c_str(), target.getHealth());
}

void Player::normalAttack(Character &target) {
  double damage = utils::generateNumber(1, attack_) - target.getDefense();

  if (damage < 0) damage = 0;

  printf("%s Menyerang %s dengan serangan biasa! (Damage %.f)\n", getName().c_str(), target.getName().c_str(), damage);
  target.takeDamage(damage);

  
  printf("%s HP tersisa: %.1f\n", target.getName().c_str(), target.getHealth());
}

void Player::defense() {
  onDefense = true;
}

void Player::defenseOff() {
  onDefense = false;
}

void Player::takeTurn(Character& target) {
  bool stillFight = true;

  while(stillFight) {
    std::cout << "\n[Aksi hero]" << std::endl;
    std::cout << "[1] Serang" << std::endl;
    std::cout << "[2] Skills" << std::endl;
    std::cout << "[3] Bertahan" << std::endl;
    std::cout << "\n[Choose option by pressing keyboard]" << std::endl;

    #ifdef __linux__
      char key = utils::getch();
    #else 
      char key = getch();
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

  
}