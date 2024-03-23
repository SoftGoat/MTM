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
    ~Responsible() = default;
    static std::shared_ptr<Responsible> getInstance();
    std::string getBehaviorName() const;
    void buyPotion(Player& player, int potionPrice, int potionHeal) const;
    BehaviorType getBehaviorType() const;
};



