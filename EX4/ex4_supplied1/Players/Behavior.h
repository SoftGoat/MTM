#pragma once
#include <string>
using std::string;

class Player; // Forward declaration

enum class BehaviorType {
    RISK_TAKING,
    RESPONSIBLE
};


class Behavior {
public:
    virtual ~Behavior() = default;
    virtual string getBehaviorName() const = 0;
    virtual void buyPotion(Player& player, int potionHeal, int potionPrice) const = 0;
    virtual BehaviorType getBehaviorType() const = 0;
};




