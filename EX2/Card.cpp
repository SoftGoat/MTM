#include <iostream>
#include <cstring>
#include "Card.h"
#include "utilities.h"
#include "Player.h"

class Card
{
private:
    CardType m_effect;
    CardStats m_stats;
    void printBattleCardInfo(const CardStats& card)const;
    void printBuffCardInfo(const CardStats& card)const;
    void printHealCardInfo(const CardStats& card)const;
    void printTreasureCardInfo(const CardStats& card)const;


public:
    Card(CardType type, const CardStats& stats);
    bool inputValidation(char*& name, int& level, int& force, int& hp, int& maxHp, int& coins);
    void printPlayerInfo(const char* name, int level, int force, int hp, int coins);
    void applyEncounter(Player& player) const;
    void printInfo() const;

private:



};



Card::Card(CardType type, const CardStats& stats){   // Battle, Buff, Heal, Treasure. 
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
            player.addCoins(m_stats.loot);
            player.levelUp();
        }
        else{ //Player lost
            player.damage(m_stats.hpLossOnDefeat);
        }

    } 
    else if (m_effect == CardType::Buff&&player.pay(m_stats.cost)) { // payment was successful and its a buff card
            player.buff(m_stats.buff);
    } 
    else if (m_effect == CardType::Heal&&player.pay(m_stats.cost)) { // payment was successful and its a heal card
        player.heal(m_stats.heal);
    }
     else if (m_effect == CardType::Treasure) {
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




void Card::printBattleCardInfo(const CardStats& card)const {
    std::cout << "Card drawn:\n" << std::endl;
    std::cout << "Type: Battle\n"<< std::endl;
    std::cout << "Force: " << card.force<<"\n"<<std::endl;
    std::cout << "Profit (on win): " << card.loot<<"\n"<< std::endl;
    std::cout << "Damage taken (on loss): " << card.hpLossOnDefeat<<"\n"<< std::endl;
    std::cout << "------------------------\n" << std::endl;
}
void Card::printBuffCardInfo(const CardStats& card)const {
    std::cout << "Card drawn:\n" << std::endl;
    std::cout << "Type: Buff\n"<< std::endl;
    std::cout << "Buff: " << card.buff<<"\n"<<std::endl;
    std::cout << "Cost: " << card.cost<<"\n"<< std::endl;
    std::cout << "------------------------\n" << std::endl;

}
void Card::printHealCardInfo(const CardStats& card)const {
    std::cout << "Card drawn:\n" << std::endl;
    std::cout << "Type: Heal\n"<< std::endl;
    std::cout << "Heal: " << card.heal<<"\n"<<std::endl;
    std::cout << "Cost: " << card.cost<<"\n"<< std::endl;
    std::cout << "------------------------\n" << std::endl;

}
void Card::printTreasureCardInfo(const CardStats& card)const {
    std::cout << "Card drawn:\n" << std::endl;
    std::cout << "Type: Treasure\n"<< std::endl;
    std::cout << "Loot: " << card.loot<<"\n"<<std::endl;
    std::cout << "------------------------\n" << std::endl;
}



       
    

                                         

