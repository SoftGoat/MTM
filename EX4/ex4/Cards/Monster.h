#pragma once
#include "../Players/Job.h" // Include header for Player class
#include <string>
#include <iostream>
#include <vector>
#include "EncounterCard.h"
#include "../Players/Player.h" // Include header for Player class


class Monster : public EncounterCard { // Monster class inherits from Card class

private:
    int m_damage; // Damage inflicted by the monster
    int m_combatPower; // Combat power of the monster
    int m_loot; // Loot dropped by the monster

    // Constants defining default values for various types of monsters
    const int GOBLIN_DAMAGE = 10;
    const int GOBLIN_COMBAT_POWER = 5;
    const int GOBLIN_LOOT = 2;
    const std::string GOBLIN_NAME = "Goblin";
    const int DRAGON_DAMAGE = 9001;
    const int DRAGON_COMBAT_POWER = 17;
    const int DRAGON_LOOT = 100;
    const std::string DRAGON_NAME = "Dragon";
    const int GIANT_DAMAGE = 25;
    const int GIANT_COMBAT_POWER = 12;
    const int GIANT_LOOT = 5;
    const std::string GIANT_NAME = "Giant";
    const std::string GANG_NAME = "Gang";



public:

    /**
     * Constructor for creating a monster based on its name.
     * @param name - The name of the monster to create.
     */
    Monster(const string &name);

    /**
     * Destructor for the Monster class.
     */
    ~Monster()=default;


    /**
     * return the attack power of the monster/gang
     * @return the attack power of the monster/gang
     */
    const int getPower() const override;

    /**
     * return the loot of the monster/gang
     * @return the loot of the monster/gang
     */
    const int getLoot() const override;

    /**
     * return the damage of the monster/gang
     * @return the damage of the monster/gang
     */
    const int getDamage() const override;

};

