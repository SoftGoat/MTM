#include "Sorcerer.h"

std::shared_ptr<Sorcerer> Sorcerer::shared_instance = nullptr;

std::shared_ptr<Sorcerer> Sorcerer::getInstance() {
    if (!shared_instance) {
        shared_instance = std::shared_ptr<Sorcerer>(new Sorcerer()); 
    }
    return shared_instance;
}

int Sorcerer::combatPower(Player& player) const {
    return player.getLevel() + player.getForce(); // calculate the combat power
}

string Sorcerer::getJobName() const {
    return "Sorcerer";
}

int Sorcerer::solarEclipse(Player& player) const {
    player.buff(SOLAR_EFFECT_SORCERER);
    return SOLAR_EFFECT_SORCERER;
}
