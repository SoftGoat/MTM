#pragma once
#include "Job.h"
#include <memory> // Include the necessary header file
#include "Player.h" // Ensure this is included if `Player` is used

class Warrior : public Job {
private:
    const int WARRIOR_BUFF = 2;
    Warrior() = default; // Make constructor private to ensure singleton
    static std::shared_ptr<Warrior> shared_instance;
public:
    int combatPower(Player& player) const override;
    string getJobName() const override;
    JobType getJobType() const override;
    ~Warrior() = default;
    static std::shared_ptr<Warrior> getInstance();
};

