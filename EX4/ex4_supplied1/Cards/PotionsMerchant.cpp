#include "PotionsMerchant.h"


void PotionsMerchant::playCard(Player &player)const{
    (*player.getBehavior()).buyPotion(player,POTIONS_PRICE,POTIONS_HEAL);
}









