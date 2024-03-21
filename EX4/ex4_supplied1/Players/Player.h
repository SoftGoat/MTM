#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include "Job.h"
#include "Behavior.h"
using std::shared_ptr;

class Player {
private:
    char* m_name; /**< The name of the player */
    int m_level; /**< The level of the player */
    int m_force; /**< The force of the player */
    int m_hp; /**< The current hit points of the player */

    int m_maxHp; /**< The maximum hit points of the player */
    int m_coins; /**< The number of coins the player has */
    string m_name;
    shared_ptr<Job> m_job;
    shared_ptr<Behavior> m_behavior;
    static const int MAX_NAME_LENGTH=15;
    static bool checkNameValidation(const string name);

    constexpr static const char *DEFAULT_NAME = "ZoGi"; /**< The default name for a player */
    static const int DEFAULT_LEVEL = 1; /**< The default level for a player */
    static const int DEFAULT_FORCE = 5; /**< The default force for a player */
    static const int DEFAULT_MAXHP = 100; /**< The default maximum hit points for a player */
    static const int DEFAULT_COINS = 10; /**< The default number of coins for a player */
    static const int MAXIMUM_LEVEL = 10; /**< The maximum level a player can reach */
    static const int MINIMUM_LEVEL = 1; /**< The minimum level a player can have */
    static const int MINIMUM_FORCE = 0; /**< The minimum force a player can have */
    static const int MINIMUM_HP = 0; /**< The minimum hit points a player can have */
    static const int MINIMUM_COINS = 0; /**< The minimum number of coins a player can have */
    static const int MAXIMUM_HP = 100; /**< The maximum hit points a player can have */

    /**
     * @brief Validates the input values for the player attributes.
     * @param name The name of the player.
     * @param level The level of the player.
     * @param force The force of the player.
     * @param hp The hit points of the player.
     * @param maxHp The maximum hit points of the player.
     * @param coins The number of coins the player has.
     * @return True if the input values are valid, false otherwise.
     */
    bool inputValidation(const string name, int &level, int &force, int &hp, int &maxHp, int &coins, const string job, const string behavior);

    /**
     * @brief Prints the player's information.
     * @param name The name of the player.
     * @param level The level of the player.
     * @param force The force of the player.
     * @param hp The hit points of the player.
     * @param coins The number of coins the player has.
     */

        /**
     * @brief Constructor with parameters.
     * @param name_ The name of the player.
     * @param level The level of the player.
     * @param force The force of the player.
     * @param hp The hit points of the player.
     * @param maxHp The maximum hit points of the player.
     * @param coins The number of coins the player has.
     * @param job The job of the player.
     * @param behavior The behavior of the player.
     */
    Player(const string name_, int level, int force, int hp, int maxHp, int coins, const string job, const string behavior);

public:
    /**
     * @brief Default constructor. Initializes player with default values.
     */
    Player();


    /**
     * @brief Constructor with parameters.
     * @param name_ The name of the player.
     * @param force The force of the player.
     * @param maxHp The maximum hit points of the player.
     * @param job The job of the player.
     * @param behavior The behavior of the player.
     */
    Player(const string name_,int maxHp, int force, const string job, const string behavior);

    /**
     * @brief Constructor with parameters.
     * @param name_ The name of the player.
     * @param maxHp The maximum hit points of the player.
     * @param job The job of the player.
     * @param behavior The behavior of the player.
     */
    Player(const string name_, int maxHp, const string job, const string behavior);

    /**
     * @brief Constructor with parameters.
     * @param name_ The name of the player.
     * @param job The job of the player.
     * @param behavior The behavior of the player.
     */
    explicit Player(const string name_, const string job, const string behavior);

    /**
     * @brief Copy constructor.
     * @param other The other player to copy from.
     */
    Player(const Player& other);

    /**
     * @brief Destructor.
     */
    ~Player();

    /**
     * @brief Assignment operator.
     * @param other The other player to assign from.
     * @return Reference to the assigned player.
     */
    Player& operator=(const Player& other);

    /**
     * @brief Comparison operator.
     * @param other The other player to compare to.
     * @return True if the player is greater than the other player, false otherwise.
     */
    bool operator<(const Player& other) const;

    /**
     * @brief Prints the player's information.
     */
    void printInfo();

    /**
     * @brief Increases the player's level by 1, if possible.
     */
    void levelUp();

    /**
     * @brief Gets the level of the player.
     * @return The level of the player.
     */
    int getLevel();

    /**
     * @brief Increases the player's force.
     * @param attack The amount of force to increase.
     */
    void buff(int attack);

    /**
     * @brief Increases the player's hit points by a given amount, up to the maximum hit points.
     * @param potion The amount of hit points to increase.
     */
    void heal(int potion);

    /**
     * @brief Reduces the player's hit points by a given amount.
     * @param dmg The amount of hit points to reduce.
     */
    void damage(int dmg);

    /**
     * @brief Checks if the player is knocked out (has 0 hit points).
     */
    bool isKnockedOut() const;


    /**
     * @brief Adds coins to the player's inventory.
     * @param money The amount of coins to add.
     */
    void addCoins(int money);

    /**
     * @brief Pays a transaction using coins from the player's inventory.
     * @param transaction The amount of coins to pay.
     * @return True if the transaction was successful, false if the player does not have enough coins.
     */
    bool pay(int transaction);

    /**
     * @brief Calculates the player's attack strength.
     * @return The player's attack strength.
     */
    int getAttackStrength();
    /**
    * @brief Gets the description of the player
    * 
    */

    std::string getDescription() const;

    /**
    * Gets the name of the player
    * 
    * @return - name of the player
    */
    std::string getName() const;

    /**
     * Gets the current level of the player
        * 
        * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     * 
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     * 
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     * 
     * @return - coins of the player
    */
    int getCoins() const;
};

#endif // PLAYER_H
