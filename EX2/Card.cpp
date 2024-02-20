#include <iostream>
#include <cstring>
#include "Card.h"
#include "utilities.h"
#include "Player.h"

Card::Card(CardType type, const CardStats &stats) {
    m_effect = type;

    if (type == CardType::Battle) {
        m_stats.loot = stats.loot;
        m_stats.force = stats.force;
        m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;
    } 
    else if (type == CardType::Buff) {
        m_stats.buff = stats.buff;
    } 
    else if (type == CardType::Heal) {
        m_stats.cost = stats.cost;
        m_stats.heal = stats.heal;
    }
     else if (type == CardType::Treasure) {
        m_stats.loot = stats.loot;
        m_stats.force = stats.force;
        m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;
    } 
    else {
        std::cout << "Invalid argument" << std::endl;
    }
}

void Card::applyEncounter(Player& player) const{

    if (m_effect == CardType::Battle) {
        if(player.getAttackStrength()>=m_stats.force){ //Player won
            printBattleResult(true);
            player.addCoins(m_stats.loot);
            player.levelUp();
        }
        else{ //Player lost
            printBattleResult(false);
            player.damage(m_stats.hpLossOnDefeat);
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
