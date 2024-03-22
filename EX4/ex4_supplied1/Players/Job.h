#pragma once
#include <string>
#include "../Cards/Card.h"
#include "Player.h" 

using std::string;

class Job {

public:
    virtual ~Job() = default;
    virtual int combatPower(Player &Player) const = 0;
    virtual string getJobName() const = 0;
    virtual JobType getJobType() const = 0;
};


enum class JobType {
    Warrior,
    Sorcerer,
    // Add other job types as needed
};



