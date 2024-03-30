
#include "Gang.h"

Gang::Gang(int gangSize) : EncounterCard("Gang of " + std::to_string(gangSize) + " members") {
    m_damage = 0;
    m_loot = 0;
    m_power = 0;
}

void Gang::addMonster(const shared_ptr<EncounterCard> &encounterCard) {
    m_members.push_back(encounterCard);
    m_power += encounterCard->getPower();
    m_loot += encounterCard->getLoot();
    m_damage += encounterCard->getDamage();
}

const int Gang::getPower() const {
    return m_power;
}

const int Gang::getLoot() const {
    return m_loot;
}

const int Gang::getDamage() const  {
    return m_damage;
}