#include "Monster.h"

Monster::Monster(const string &name) : EncounterCard(name) {
    if(name=="Goblin"){
        m_damage = GOBLIN_DAMAGE;
        m_combatPower = GOBLIN_COMBAT_POWER;
        m_loot = GOBLIN_LOOT;
    } else
    {
        if(name=="Dragon"){
            m_damage = DRAGON_DAMAGE;
            m_combatPower = DRAGON_COMBAT_POWER;
            m_loot = DRAGON_LOOT;
        }

        else {
            if(name=="Giant"){
                m_damage = GIANT_DAMAGE;
                m_combatPower = GIANT_COMBAT_POWER;
                m_loot = GIANT_LOOT;
            }
            else {
                throw std::runtime_error("Invalid Cards File");
            }
        }
    }
}

const int Monster::getPower() const {
    return m_combatPower;
}

const int Monster::getLoot() const {
    return m_loot;
}

const int Monster::getDamage() const {
    return m_damage;
}











