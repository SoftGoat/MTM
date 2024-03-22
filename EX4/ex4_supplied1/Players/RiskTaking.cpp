#include "RiskTaking.h"

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
