#include "Trap.hpp"

Trap::Trap(const std::string &value, Position &position, int damage): Sprite(value, position), damage_(damage) {}

void Trap::setPosition(Position position) {
  position_ = position;
}
void Trap::giveDamage(Player &player) {
  player.setHealth(player.getHealth() - damage_);
};