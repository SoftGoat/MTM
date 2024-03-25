#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include "Sorcerer.h"  
#include "Warrior.h"
#include "Responsible.h"
#include "RiskTaking.h"
using std::shared_ptr;
using std::string;
// Forward declarations
class Warrior;
class Sorcerer;
class Responsible;
class RiskTaking;
class Job; 
class Behavior; 



class Player {
private:
    string m_name; /**< The name of the player */
    int m_level; /**< The level of the player */
    int m_force; /**< The force of the player */
    int m_hp; /**< The current hit points of the player */

    int m_maxHp; /**< The maximum hit points of the player */
    int m_coins; /**< The number of coins the player has */
    shared_ptr<Job> m_job; /**< The job of the player */
    shared_ptr<Behavior> m_behavior; /**< The behavior of the player */
    static const int MAX_NAME_LENGTH=15;
    static const int MIN_NAME_LENGTH=3;

    static const string DEFAULT_NAME; /**< The default name for a player */
    static const int DEFAULT_LEVEL = 1; /**< The default level for a player */
    static const int DEFAULT_FORCE = 5; /**< The default force for a player */
    static const int DEFAULT_MAXHP = 100; /**< The default maximum hit points for a player */
    static const int DEFAULT_COINS = 10; /**< The default number of coins for a player */
    static const shared_ptr<Job> DEFAULT_JOB; /**< The default job for a player */
    static const shared_ptr<Behavior> DEFAULT_BEHAVIOR; /**< The default behavior for a player */
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
    static bool inputValidation(const string name, int &level, int &force, int &hp, int &maxHp, int &coins);

    /**
     * @brief Creates a job for the player.
     * @param jobName The name of the job.
     * @return A shared pointer to the created job.
     */

    std::shared_ptr<Job> createJob(const std::string& jobName);

    /**
     * @brief Creates a behavior for the player.
     * @param behaviorName The name of the behavior.
     * @return A shared pointer to the created behavior.
     */

    std::shared_ptr<Behavior> createBehavior(const std::string& behaviorName);


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
    explicit Player(const string name, const string job, const string behavior);

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
     * @brief Increases the player's level by 1, if possible.
     */
    void levelUp();

    /**
     * @brief Gets the level of the player.
     * @return The level of the player.
     */
    int getLevel() const;

    /**
     * @brief Get the behavior of the player.
     * @return The behavior name of the player.
     */

    string getBehaviorName() const;

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
     * Gets the maximum amount of health points the player can have
     * 
     * @return - maximum health points of the player
    */

    int getMaxHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     * 
     * @return - coins of the player
    */
    int getCoins() const;
    /**
    * Gets the job of the player
    * @return - job of the player
    */
    shared_ptr<Job> getJob() const;
    /**
    * Gets the behavior of the player
    * @return - behavior of the player
    */
    shared_ptr<Behavior> getBehavior() const;
};

