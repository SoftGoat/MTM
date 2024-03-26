#pragma once
#include <string>
#include <memory>
#include <vector>
#include <queue>

#include "Players/Player.h"
#include "Cards/Card.h"
#include "Cards/Monster.h"
#include "./Cards/CardFactory.h"


using std::string;
using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::queue;

class Mtmchkin{
private:
    int m_turnIndex;
    vector<Player> m_players;
    std::queue<std::shared_ptr<Card>> m_cards;
    static const int MAX_PLAYERS=6;
    static const int MIN_PLAYERS=2;
    static const int MIN_CARDS=2;
    /**
     * Playes a single turn for a player
     * 
     * @param player - the player to play the turn for
     * 
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     * 
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     * 
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

    void readCards(const string& deckPath);

    void readPlayers(const string& playersPath);

    Monster buildGangCard(std::ifstream &deckFile);

    bool totalLost() const;

public:
    /**
     * Constructor of Mtmchkin class
     * 
     * @param deckPath - path to the deck file
     * @param playersPath - path to the players file
     * 
     * @return - Mtmchkin object with the given deck and players
     *
    */
    Mtmchkin(const string& deckPath, const string& playersPath);

    /**
     * Plays the entire game
     * 
     * @return - void
    */
    void play();

};
