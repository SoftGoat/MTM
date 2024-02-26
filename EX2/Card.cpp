#include <iostream>
#include <cstring>
#include "Card.h"
#include "utilities.h"
#include "Player.h"
const int MINIMUM_LOOT =0;
const int MINIMUM_BUFF =0;
const int MINIMUM_COST =0;
const int MINIMUM_FORCE =0;
const int MINIMUM_HEAL =0;
const int MINIMUM_HPLOSSONDEFEAT =0;

Card::Card(CardType type, const CardStats &stats) {
    m_effect = type;
    if (type == CardType::Battle) {
        m_stats.loot = stats.loot; //< MINIMUM_LOOT ? MINIMUM_LOOT: stats.loot;
        m_stats.force = stats.force; //< MINIMUM_FORCE ? MINIMUM_FORCE: stats.force;
        m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;// < MINIMUM_HPLOSSONDEFEAT ? MINIMUM_HPLOSSONDEFEAT: stats.hpLossOnDefeat;
    } 
    else if (type == CardType::Buff) {
        m_stats.buff = stats.buff;// < MINIMUM_BUFF ? MINIMUM_BUFF: stats.buff;
        m_stats.cost = stats.cost;// < MINIMUM_COST ? MINIMUM_COST: stats.cost;
    } 
    else if (type == CardType::Heal) {
        m_stats.cost = stats.cost;// < MINIMUM_COST ? MINIMUM_COST: stats.cost;
        m_stats.heal = stats.heal;
    }
    else if (type == CardType::Treasure) {
        m_stats.loot = stats.loot;// < MINIMUM_LOOT ? MINIMUM_LOOT: stats.loot;
    } 
    else {
        std::cout << "Invalid argument" << std::endl;
    }
}


void Card::applyEncounter(Player& player) const{

    if (m_effect == CardType::Battle) {
        if(player.getAttackStrength()>=m_stats.force){ //Player won
            player.addCoins(m_stats.loot);
            player.levelUp();
            printBattleResult(true);
        }
        else{ //Player lost
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }

    } 
    else if (m_effect == CardType::Buff&&player.pay(m_stats.cost)) { // payment was successful and its a buff card
            player.buff(m_stats.buff);
    } 
    else if (m_effect == CardType::Heal&&player.pay(m_stats.cost)) { // payment was successful and its a heal card
        player.heal(m_stats.heal);
    } else if (m_effect == CardType::Treasure) {
        player.addCoins(m_stats.loot);
       
    } 

}

void Card::printInfo() const {
    if (m_effect == CardType::Battle) {
        printBattleCardInfo(m_stats);
    } 
    else if (m_effect == CardType::Buff) { 
        printBuffCardInfo(m_stats);
    } 
    else if (m_effect == CardType::Heal) { 
        printHealCardInfo(m_stats);
    }
    else if (m_effect == CardType::Treasure) {
        printTreasureCardInfo(m_stats);
    }
    else{
    std::cout << "Card type is undefined:\n" << std::endl;
    }
}
