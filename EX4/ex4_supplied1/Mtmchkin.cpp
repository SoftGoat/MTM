
#include "Mtmchkin.h"
#include "utilities.h"
#include "EncounterCard.h"
#include "EventCard.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::unique_ptr;

Mtmchkin::Mtmchkin(const string& deckPath, const string& playersPath) {

    /*===== TODO: Open and read cards file =====*/
    readCards(deckPath);
    /*==========================================*/


    /*===== TODO: Open and Read players file =====*/
    readPlayers(playersPath);

    /*============================================*/


    this->m_turnIndex = 1;
}

void Mtmchkin::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Draw a card from the deck
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the card
     * 4. Print the turn outcome with "printTurnOutcome"
    */

    m_turnIndex++;
}

void Mtmchkin::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/
    for (Player player : m_players){
        playTurn(player);
    }

    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();
    
    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool Mtmchkin::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    if(m_turnIndex>10)
        return true;
    return false; // Replace this line
    /*===================================================*/
}

void Mtmchkin::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/
    
    /*========================================================================*/
}

void Mtmchkin::readCards(string deckPath) {
    ifstream deckFile(deckPath);
    if(!deckFile){
        throw std::exception();
    }
    string cardType;
    while(deckFile>>cardType){
        if(cardType=="Goblin"||cardType=="Giant"||cardType=="Dragon"){
            EncounterCard *encounterCard= new EncounterCard(cardType);
            encounterCard->addMonster(cardType);
            m_cards.push(encounterCard);
            std::cout<<m_cards.front()->getDescription()<<"  ";
        } else {
            if (cardType=="Gang") {
                addGangCard(&deckFile);
            } else {
                if (cardType == "SolarEclipse") {
                    SolarEclipseCard *solarEclipseCard=new SolarEclipseCard();
                    m_cards.push(solarEclipseCard);
                } else {
                    if (cardType == "PotionsMerchant") {
                        PotionsMerchantCard *potionsMerchantCard=new PotionsMerchantCard();
                        m_cards.push(potionsMerchantCard);
                    } else {
                        throw std::exception();
                    }
                }

            }
        }
    }
    if (m_cards.size()<MIN_CARDS){
        throw std::exception();
    }
}


void Mtmchkin:: readPlayers(const string& playersPath){
    int playersCounter=0;
    string name, job, behavior;
    ifstream playersFile(playersPath);
    if(!playersFile){
        throw std::exception();
    }
    while(playersFile>>name){
        if(playersFile>>job&&playersFile>>behavior) {
            Player player(name, job, behavior);
            m_players.push_back(player);
            playersCounter++;
        }
        else{
            throw std::exception();
        }
    }
    if(playersCounter<MIN_PLAYERS||playersCounter>MAX_PLAYERS){
        throw std::exception();
    }
}

void Mtmchkin::addGangCard(std::ifstream *deckFile) {
    int gangSize;
    *deckFile>>gangSize;
    if(!gangSize){
        throw std::exception();
    }
    string gangName= "Gang of "+std::to_string(gangSize)+" members";
    EncounterCard *encounterCard= new EncounterCard(gangName);
    for(int i=0; i<gangSize; i++) {
        string monster;
        *deckFile>> monster;
        encounterCard->addMonster(monster);
    }
    m_cards.push(encounterCard);

}


