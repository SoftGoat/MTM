#pragma once
#include "Job.h"
#include <memory>
#include "Player.h" 

class Sorcerer : public Job {
private:
    Sorcerer() = default; // Make constructor private to ensure singleton
    static std::shared_ptr<Sorcerer> shared_instance;

public:
    /**
     * Destructor
    */
    ~Sorcerer() = default;
    /**
     * @param player the player to calculate the combat power
     * @return shared pointer to the instance of the class
    */
    int combatPower(Player& player) const override; 
    /**
     * @return the name of the job
    */
    string getJobName() const override; 
    /**
     * @return the type of the job
    */
    JobType getJobType() const override; 
    /**
     * @return shared pointer to the instance of the class
    */
    static std::shared_ptr<Sorcerer> getInstance();
};

