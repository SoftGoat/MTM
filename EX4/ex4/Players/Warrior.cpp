#include "Warrior.h"
std::shared_ptr<Warrior> Warrior::shared_instance = nullptr;

std::shared_ptr<Warrior> Warrior::getInstance() {
    if (!shared_instance) {
        shared_instance = std::shared_ptr<Warrior>(new Warrior());
    }
    return shared_instance;
}

int Warrior::combatPower(Player& player) const {
    return player.getLevel() + WARRIOR_BUFF * player.getForce();
}

string Warrior::getJobName() const {
    return "Warrior";
}

JobType Warrior::getJobType() const {
    return JobType::Warrior;
}
