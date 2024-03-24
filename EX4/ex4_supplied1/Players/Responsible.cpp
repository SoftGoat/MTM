
#include "Responsible.h"
std::shared_ptr<Responsible> Responsible::instance = nullptr;

int Responsible::buyPotion(Player& player, int potionPrice, int potionHeal) const {
    int potionsBought = 0;
    while(player.getHealthPoints() < player.getMaxHealthPoints() && player.pay(potionPrice)){
        player.heal(potionHeal);
        potionsBought++;
    }
    return potionsBought;
}
string Responsible::getBehaviorName() const {
    return "Responsible";
}
BehaviorType Responsible::getBehaviorType() const {
    return BehaviorType::RESPONSIBLE;
}

std::shared_ptr<Responsible> Responsible::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<Responsible>(new Responsible()); // Directly use 'new' here
    }
    return instance;
}