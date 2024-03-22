
#include "Sorcerer.h"


int Sorcerer::combatPower(Player& player)const{
    return player.getLevel() + player.getForce();
}

string Sorcerer::getJobName() const{
    return "Sorcerer";
}

JobType Sorcerer::getJobType() const{
    return JobType::Sorcerer;
}

