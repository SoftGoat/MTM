
#include "Mtmchkin.h"
#include "utilities.h"
#include "EncounterCard.h"
#include "EventCard.h"
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

bool biggerPlayer(const Player &player1, const Player &player2){
    if(player1.getLevel()>player2.getLevel()){
        return true;
    }
    if(player1.getLevel()<player2.getLevel()){
        return false;
    }
    if(player1.getCoins()>player2.getCoins()){
        return true;
    }
    if(player1.getCoins()<player2.getCoins()){
        return false;
    }
    return player1.getName().compare(player2.getName())<0;
}


void Mtmchkin::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Draw a card from the deck
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the card
     * 4. Print the turn outcome with "printTurnOutcome"
    */
    Card card=*m_cards.front();
    printTurnDetails(m_turnIndex,player,card);
    //todo play card
    /**
     * string outCome=card.play(player);
     * printTurnOutCome(outCome);
     */


    //bringing the card to the back of the queue
    m_cards.pop();
    m_cards.push(&card);

    m_turnIndex++;
}

void Mtmchkin::playRound() {

    printRoundStart();
    for (Player player : m_players){
        playTurn(player);
    }
    printRoundEnd();


    printLeaderBoardMessage();
    
    vector<Player> sortedPlayers=m_players;
    std::sort(sortedPlayers.begin(),sortedPlayers.end(),biggerPlayer);
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
        if(player.getLevel()==MAX_LEVEL){
            winFlag= true;
        }
        if(player.getHealthPoints()>0){
            lostFlag= false;
        }
    }
    if(m_turnIndex>10)//remove this either
            return true;
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
    for(Player player:m_players){
        printStartPlayerEntry(m_turnIndex,player);
    }

    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/
    if(totalLost()){
        printNoWinners();
    }
    else{
        std::sort(m_players.begin(),m_players.end(),biggerPlayer);
        printWinner(m_players.front());
    }
}

void Mtmchkin::readCards(const string &deckPath) {
    ifstream deckFile(deckPath);
    if(!deckFile){
        throw std::exception();
    }
    string cardType;
    while(deckFile>>cardType){
        if(cardType=="Goblin"||cardType=="Giant"||cardType=="Dragon"){
            EncounterCard *encounterCard= new EncounterCard(cardType);
            m_cards.push(encounterCard);
        } else {
            if (cardType=="Gang") {
                GangCard gangCard= buildGangCard(deckFile);
                m_cards.push(&gangCard);
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


GangCard Mtmchkin::buildGangCard(std::ifstream &deckFile) {
    int gangSize;
    deckFile>>gangSize;
    if(!gangSize){
        throw std::exception();
    }
    GangCard gangCard(gangSize);
    for(int i=0; i<gangSize; i++) {
        string monster;
        deckFile>> monster;
        if(monster=="Goblin"||monster=="Giant"||monster=="Dragon") {
            EncounterCard encounterCard(monster);
            gangCard.addMonster(&encounterCard);
        } else {
            if(monster=="Gang"){
                GangCard gangCard2=buildGangCard(deckFile);
                gangCard.addMonster(&gangCard2);
            }
        }
    }
    return gangCard;
}

