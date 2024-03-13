#pragma once

#include "Behavior.h"
#include "Job.h"
#include <memory>
using std::shared_ptr;

class Player {
private:
    string m_name;

    shared_ptr<Job> m_job;
    shared_ptr<Behavior> m_behavior;
    static const int MAX_NAME_LENGTH=16;
    static bool checkNameValidation(const string name);
public:
    Player(const string name, const string job, const string behavior);

    /**
     * Gets the description of the player
     * 
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     * 
     * @return - name of the player
    */
    string getName() const;

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
