#include "RiskTaking.h"
std::shared_ptr<RiskTaking> RiskTaking::instance = nullptr;

void RiskTaking::buyPotion(Player& player, int potionPrice, int potionHeal) const {
    if (player.getHealthPoints() < MAX_HEALTH_TO_BUY_POTION && player.pay(potionPrice)) {
        player.heal(potionHeal);
    }
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