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



public:
    Card(CardType type, const CardStats& stats);
    bool inputValidation(char*& name, int& level, int& force, int& hp, int& maxHp, int& coins);
    void printPlayerInfo(const char* name, int level, int force, int hp, int coins);
    void applyEncounter(Player& player) const;
    void printInfo() const;
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;
private:


};



Card::Card(CardType type, const CardStats& stats){  
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

Card::Card(const Card& other){
    this->m_effect = other.m_effect;
    this->m_stats= other.m_stats;
}

Card& Card::operator=(const Card& other){
    if (this != &other) { // Check for self-assignment
        this->m_effect = other.m_effect;
        this->m_stats = other.m_stats;
    }
    return *this;
}

Card:: ~Card() {
        // No explicit cleanup needed for member variables
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


