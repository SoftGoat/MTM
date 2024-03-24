#include "PotionsMerchant.h"

//cant use  since it will cause circular dependency

string PotionsMerchant::playCard(Player &player)const{
   int potionBougth = (*player.getBehavior()).buyPotion(player,POTIONS_PRICE,POTIONS_HEAL);
    return player.getName() + " bought " + std::to_string(potionBougth) + " potions!";
}
string PotionsMerchant::getDescription()const{
    return "PotionsMerchant";
}









