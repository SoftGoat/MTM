#include "PotionsMerchant.h"


string PotionsMerchant::playCard(Player &player)const{
   int potionBougth = (*player.getBehavior()).buyPotion(player,POTIONS_PRICE,POTIONS_HEAL);
    return player.getName() + " bought " + std::to_string(potionBougth) + " potions!";
}
string PotionsMerchant::getDescription()const{
    return "Potions Merchant: heals the player by 10 health points for 5 gold coins.";
}









