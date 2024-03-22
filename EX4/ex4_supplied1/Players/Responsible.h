#pragma once
#include <string>
#include "Behavior.h"


class Responsible : public Behavior {
private:
  

public:
    Responsible() = default;
    ~Responsible() = default;
    std::string getBehaviorName() const;
    void buyPotion(Player& player, int potionPrice, int potionHeal) const;
    BehaviorType getBehaviorType() const;
};



