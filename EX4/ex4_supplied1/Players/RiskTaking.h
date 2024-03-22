#pragma once
#include <string>
#include "Behavior.h"


class RiskTaking : public Behavior {
private:
    const int MAX_HEALTH_TO_BUY_POTION = 50;

public:
    RiskTaking() = default;
    ~RiskTaking() = default;
    std::string getBehaviorName() const;
    void buyPotion(Player& player, int potionPrice, int potionHeal) const;
    BehaviorType getBehaviorType() const;
};



