
#include "Responsible.h"
void Responsible::buyPotion(Player& player, int potionPrice, int potionHeal) const {
    while(player.getHealthPoints() < player.getMaxHealthPoints() && player.pay(potionPrice)){
        player.heal(potionHeal);
    }

    
}
string Responsible::getBehaviorName() const {
    return "Responsible";
}
BehaviorType Responsible::getBehaviorType() const {
    return BehaviorType::RESPONSIBLE;
}
