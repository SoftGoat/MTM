
#include "Mtmchkin.h"
#include "utilities.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using std::ifstream;
using std::unique_ptr;
Mtmchkin::Mtmchkin(const string& deckPath, const string& playersPath) {
    readCards(deckPath);
    readPlayers(playersPath);
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
    std::shared_ptr<Card> card = m_cards.front();
    printTurnDetails(m_turnIndex,player,*m_cards.front());
    string outcome = (*m_cards.front()).playCard(player);
    printTurnOutcome(outcome);

    //bringing the card to the back of the queue
    m_cards.pop();
    m_cards.push(card);

    m_turnIndex++;
}

void Mtmchkin::playRound() {

    printRoundStart();
    for (Player& player : m_players){ //using reference to change the player and not a copy
        if(!player.isKnockedOut()){
            playTurn(player);
        }
    }
    printRoundEnd();


    printLeaderBoardMessage();
    
    vector<Player> sortedPlayers=m_players;
    std::sort(sortedPlayers.begin(),sortedPlayers.end());
    int i=1;
    for(Player player : sortedPlayers){
        printLeaderBoardEntry(i,player);
        i++;
    }

    printBarrier();
}

bool Mtmchkin::isGameOver() const {
    bool winFlag=false, lostFlag=true;
    static const int MAX_LEVEL=10;//to remove this line
    for (Player player : m_players) {
        if(player.getLevel()==MAX_LEVEL && !player.isKnockedOut()){
            winFlag= true;
        }
        if(player.getHealthPoints()>0){
            lostFlag= false;
        }
    }

    return winFlag||lostFlag;
}

bool Mtmchkin::totalLost() const {
    for (Player player : m_players) {
        if(player.getHealthPoints()>0){
            return false;
        }
    }
    return true;
}


void Mtmchkin::play() {
    printStartMessage();
    int inTrunIndex=0;
    for(Player player:m_players){
        printStartPlayerEntry(m_turnIndex+inTrunIndex,player);
        inTrunIndex++;
    }
    inTrunIndex=0;

    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();

    if(totalLost()){
        printNoWinners();
    }
    else{
        std::sort(m_players.begin(),m_players.end());
        printWinner(m_players.front());
    }
}

void Mtmchkin::readCards(const string &deckPath) {
    ifstream deckFile(deckPath);
    if(!deckFile){
        throw std::runtime_error("Invalid Cards File");
    }
    string cardType;
    while(deckFile>>cardType){
        m_cards.push(CardFactory::createCard(cardType,deckFile));
    }
    if (m_cards.size()<MIN_CARDS){
        throw std::runtime_error("Invalid Cards File");
    }
}


void Mtmchkin:: readPlayers(const string& playersPath){
    int playersCounter=0;
    string name, job, behavior;
    ifstream playersFile(playersPath);
    if(!playersFile){
        throw std::runtime_error("Invalid Players File");
    }
    while(playersFile>>name){
        if(playersFile>>job&&playersFile>>behavior) {
            Player player(name, job, behavior);
            m_players.push_back(player);
            playersCounter++;
        }
        else{
            throw std::runtime_error("Invalid Players File");
        }
    }
    if(playersCounter<MIN_PLAYERS||playersCounter>MAX_PLAYERS){
        throw std::runtime_error("Invalid Players File");
    }
}





