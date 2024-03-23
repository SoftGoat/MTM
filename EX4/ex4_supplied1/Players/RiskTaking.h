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
    static std::shared_ptr<RiskTaking> getInstance();
    ~RiskTaking() = default;
    std::string getBehaviorName() const;
    void buyPotion(Player& player, int potionPrice, int potionHeal) const;
    BehaviorType getBehaviorType() const;
};



