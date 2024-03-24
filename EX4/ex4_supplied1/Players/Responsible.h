#pragma once
#include <string>
#include "Behavior.h"
#include <memory>
#include "Player.h"

class Responsible : public Behavior {
private:

    static std::shared_ptr<Responsible> instance;
    Responsible() = default; // Make constructor private to ensure singleton

public:
    /**
     * Destructor
    */
    ~Responsible() = default;
    /**
     * @return shared pointer to the instance of the class
    */
    static std::shared_ptr<Responsible> getInstance();
    /**
     * @return the type of the behavior
    */
    std::string getBehaviorName() const;
    /**
     * @param player the player to heal
     * @param potionPrice the price of the potion
     * @param potionHeal the amount of health the potion heals
     * @return int the amount of potions bought
    */
    int buyPotion(Player& player, int potionPrice, int potionHeal) const;
    /**
     * @return the type of the behavior
    */
    BehaviorType getBehaviorType() const;
};



