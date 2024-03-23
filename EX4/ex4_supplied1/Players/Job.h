#pragma once
#include <string>
#include "../Cards/Card.h"
using std::string;

class Player; // Forward declaration

enum class JobType {
    Warrior,
    Sorcerer,
    // Add other job types as needed
};

class Job {
public:
    virtual int combatPower(Player &Player) const = 0;
    virtual string getJobName() const = 0; // Now pure virtual
    virtual JobType getJobType() const = 0; // Now pure virtual
    virtual ~Job() = default;
};
