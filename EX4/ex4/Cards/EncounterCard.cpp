//
// Created by gilad on 25 מרץ 2024.
//


#include "EncounterCard.h"


    EncounterCard::EncounterCard(const std::string& name) {
        m_name = name;
    }


    std::string EncounterCard::getDescription() const {
        int power=getPower(), loot=getLoot(), damage=getDamage();
        return m_name+" (power "+std::to_string(power)+", loot "+std::to_string(loot)+", damage "+std::to_string((damage))+")";
    }


    std::string EncounterCard::playCard(Player &player) const {
        if(player.getAttackStrength() > getPower()){
            player.addCoins(getLoot());
            player.levelUp();
            return player.getName() + " won the encounter, gained " + std::to_string(getLoot()) + " coins and leveled up!";
        }
        else{
            player.damage(getDamage());
        }
        return player.getName() + " lost the encounter and took " + std::to_string(getDamage()) + " damage!";
    }
