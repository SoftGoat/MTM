#pragma once
#include "Job.h"
#include <memory>
#include "Player.h" 

class Sorcerer : public Job {
private:
    Sorcerer() = default; // Make constructor private to ensure singleton
    static std::shared_ptr<Sorcerer> shared_instance;

public:
    int combatPower(Player& player) const override; 
    string getJobName() const override; 
    JobType getJobType() const override; 
    ~Sorcerer() = default;
    static std::shared_ptr<Sorcerer> getInstance();
};

