
#include "Warrior.h"

int Warrior::combatPower(Player& player)const{
    return player.getLevel() + WARRIOR_BUFF*player.getForce();
}

string Warrior::getJobName() const{
    return "Warrior";
}

JobType Warrior::getJobType() const{
    return JobType::Warrior;
}
