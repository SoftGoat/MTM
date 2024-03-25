//
// Created by gilad on 25 מרץ 2024.
//

#ifndef EX4_ENCOUNTERCARD_H
#define EX4_ENCOUNTERCARD_H

#include "Card.h"
#include "../Players/Player.h"

class EncounterCard :public Card{
protected:
    std::string m_name; // Name of the monster
public:
    /**
     * c'tor of Encounter card, initial the name of the encounter card
     * @param name - the name of the monster/gang
     */
    EncounterCard(const std::string& name) {
        m_name = name;
    }

    ~EncounterCard()=default;

    /**
     * Gets the description of the card
     *
     * @return - the description of the card
    */
    std::string getDescription() const override{
        int power=getPower(), loot=getLoot(), damage=getDamage();
        return m_name+"(power "+std::to_string(power)+", loot "+std::to_string(loot)+", damage "+std::to_string((damage))+")";
    }

    /**
    * Plays the card
    *
    * @param player - the player that plays the card
    * @return - a message that describes the result of the card - win or lose and the affect
    */
    std::string playCard(Player &player) const override   {
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

    /**
     * return the attack power of the monster/gang
     * @return the attack power of the monster/gang
     */
    virtual const int getPower() const =0;

    /**
     * return the damage of the monster/gang
     * @return the damage of the monster/gang
     */
    virtual const int getDamage() const =0;

    /**
     * return the loot of the monster/gang
     * @return the loot of the monster/gang
     */
    virtual const int getLoot() const =0;
};




#endif //EX4_ENCOUNTERCARD_H
