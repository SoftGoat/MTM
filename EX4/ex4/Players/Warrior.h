#pragma once
#include "Job.h"
#include <memory> // Include the necessary header file
#include "Player.h" // Ensure this is included if `Player` is used

class Warrior : public Job {
private:
    static const int WARRIOR_BUFF = 2;
    static const int SOLAR_EFFECT_WARRIOR=-1;
    Warrior() = default; // Make constructor private to ensure singleton
    static std::shared_ptr<Warrior> shared_instance;
public:
    /**
     * Destructor
    */
    ~Warrior() = default;
    /**
     * @param player the player to calculate the combat power
     * @return shared pointer to the instance of the class
    */
    int combatPower(Player& player) const override;
    /**
     * @param player - the player that that affected by the solar eclipse
     * Returns the change of force the player had
    */
    int solarEclipse(Player &player) const override;
    /**
     * @return the name of the job
    */
    string getJobName() const override;

    /**
     * @return shared pointer to the instance of the class
    */
    static std::shared_ptr<Warrior> getInstance();
};

