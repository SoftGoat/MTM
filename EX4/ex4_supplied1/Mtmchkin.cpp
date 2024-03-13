
#include "Mtmchkin.h"
#include "utilities.h"
#include <fstream>

using std::ifstream;

Mtmchkin::Mtmchkin(const string& deckPath, const string& playersPath) {

    /*===== TODO: Open and read cards file =====*/
    readCards(deckPath);
    /*==========================================*/


    /*===== TODO: Open and Read players file =====*/
    try{
        readPlayers(playersPath);
    }catch (...){

    }
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

bool Mtmchkin::readCards(string deckPath) {
    int cardsCounter=0;

    return false;
}


void Mtmchkin:: readPlayers(const string& playersPath){
    int playersCounter=0;
    string name, job, behavior;
    ifstream playersFile(playersPath);
    if(!playersFile){
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
    if(playersCounter<2||playersCounter>6){
        throw std::exception();
    }
}

