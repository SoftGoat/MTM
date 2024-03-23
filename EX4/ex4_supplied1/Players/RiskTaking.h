#pragma once
#include <string>
#include "Behavior.h"
#include <memory>
#include "Player.h"

class Player; // Forward declaration

class RiskTaking : public Behavior {
private:
    const int MAX_HEALTH_TO_BUY_POTION = 50;
    static std::shared_ptr<RiskTaking> instance;
    RiskTaking() = default; // Make constructor private to ensure singleton

public:
    /**
     * Destructor
    */
   ~RiskTaking() = default;
    /**
     * @return shared pointer to the instance of the class
    */
    static std::shared_ptr<RiskTaking> getInstance();
    /**
     * @return the type of the behavior
    */
    std::string getBehaviorName() const;
    /**
     * @param player the player to heal
     * @param potionPrice the price of the potion
     * @param potionHeal the amount of health the potion heals
     * @return void
    */
    void buyPotion(Player& player, int potionPrice, int potionHeal) const;
    /**
     * @return the type of the behavior
    */
    BehaviorType getBehaviorType() const;
};



