#pragma once
#include "../Players/Job.h" // Include header for Player class
#include <string>
#include <iostream>
#include <vector>

class Monster : public Card { // Monster class inherits from Card class

private:
    int m_damage; // Damage inflicted by the monster
    int m_combatPower; // Combat power of the monster
    int m_loot; // Loot dropped by the monster
    std::string m_name; // Name of the monster
    std::vector<std::string> members; // Vector to store members of a gang

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
     * Default constructor for a Goblin monster.
     * Initializes the monster with default values for a Goblin.
     */
    Monster();

    /**
     * Constructor for a monster with specific values.
     * @param damage - The damage of the monster.
     * @param combatPower - The combat power of the monster.
     * @param loot - The loot dropped by the monster.
     * @param name - The name of the monster.
     */
    Monster(int damage, int combatPower, int loot, std::string name);

    /**
     * Constructor for creating a monster based on its name.
     * @param name - The name of the monster to create.
     */
    Monster(std::string name);

    /**
     * Destructor for the Monster class.
     */
    ~Monster();

    /**
     * Get a description of the monster.
     * @return - A string describing the monster.
     */
    std::string getDescription() const;

    /**
     * Play the monster card against a player.
     * @param player - The player to play the card against.
     */
    void playCard(Player &player) const;

    /**
     * Add a member to a gang.
     * @param name - The name of the member to add.
     */
    void addMonster(std::string name);

    /**
     * Add a monster to a gang.
     * @param monster - The monster to add to the gang.
     */
    void addMonster(Monster monster);
};
