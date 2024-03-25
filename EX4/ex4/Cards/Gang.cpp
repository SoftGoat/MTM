
#include "Gang.h"

Gang::Gang(int gangSize) : EncounterCard("Gang of "+ std::to_string(gangSize)+" members"){}

void Gang::addMonster(const shared_ptr<EncounterCard> &encounterCard) {
    m_members.push_back(encounterCard);
}

const int Gang::getPower() const {
    int powerSum=0;
    for(shared_ptr<EncounterCard> member:m_members){
        powerSum+=member->getPower();
    }
    return powerSum;
}

const int Gang::getLoot() const {
    int lootSum=0;
    for(shared_ptr<EncounterCard> member:m_members){
        lootSum+=member->getLoot();
    }
    return lootSum;
}

const int Gang::getDamage() const  {
    int damageSum=0;
    for(shared_ptr<EncounterCard> member:m_members){
        damageSum+=member->getDamage();
    }
    return damageSum;
}