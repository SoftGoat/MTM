#include "RiskTaking.h"
std::shared_ptr<RiskTaking> RiskTaking::instance = nullptr;

int RiskTaking::buyPotion(Player& player, int potionPrice, int potionHeal) const {
    int potionsBought = 0;
    if (player.getHealthPoints() < MAX_HEALTH_TO_BUY_POTION && player.pay(potionPrice)) {
        player.heal(potionHeal);
        potionsBought++;
    }
    return potionsBought;
}
string RiskTaking::getBehaviorName() const {
    return "RiskTaking";
}
BehaviorType RiskTaking::getBehaviorType() const {
    return BehaviorType::RISK_TAKING;
}

std::shared_ptr<RiskTaking> RiskTaking::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<RiskTaking>(new RiskTaking()); // Directly use 'new' here
    }
    return instance;
}