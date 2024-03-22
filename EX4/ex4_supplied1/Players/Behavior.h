#pragma once
#include <string>
#include "Player.h"
using std::string;



class Behavior {
public:
    Behavior(string behavior);
    virtual ~Behavior() = default;
    virtual string getBehaviorName() const = 0;
    virtual void buyPotion(Player& player, int potionHeal, int potionPrice) const = 0;
    virtual BehaviorType getBehaviorType() const = 0;
};

enum class BehaviorType {
    RISK_TAKING,
    RESPONSIBLE
};



