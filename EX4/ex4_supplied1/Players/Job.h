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
    virtual int combatPower(Player &Player) const = 0;
    /**
     * Returns the name of the job
    */
    virtual string getJobName() const = 0; // Now pure virtual
    /**
     * Returns the type of the job
    */
    virtual JobType getJobType() const = 0; // Now pure virtual
    virtual ~Job() = default;
};
