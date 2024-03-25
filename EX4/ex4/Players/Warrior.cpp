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



int Warrior::solarEclipse(Player &player) const {
    if (player.getForce()>0){
        player.buff(SOLAR_EFFECT_WARRIOR);
        return SOLAR_EFFECT_WARRIOR;
    }
    return 0;
}
