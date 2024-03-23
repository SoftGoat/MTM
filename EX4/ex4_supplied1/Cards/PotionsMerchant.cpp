#include "PotionsMerchant.h"


void PotionsMerchant::playCard(Player &player)const{
    (*player.getBehavior()).buyPotion(player,POTIONS_PRICE,POTIONS_HEAL);
}
string PotionsMerchant::getDescription()const{
    return "Potions Merchant: heals the player by 10 health points for 5 gold coins.";
}









