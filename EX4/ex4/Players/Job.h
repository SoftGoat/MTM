#pragma once
#include <string>
#include "../Cards/Card.h"
using std::string;

class Player; // Forward declaration, prevents circular dependency

enum class JobType {
    Warrior,
    Sorcerer,
    // Add other job types as needed
};

class Job {
public:
    /**
     * @param player - the player that the combat power is calculated for
     * Returns the combat power of the player
    */
    virtual int combatPower(Player &player) const = 0;
    /**
     * @param player - the player that affected by the solar eclipse
     * Returns the change in force the player had
    */
    virtual int solarEclipse(Player &player) const = 0;
    /**
     * Returns the name of the job
    */
    virtual string getJobName() const = 0; // Now pure virtual

    virtual ~Job() = default;
};
