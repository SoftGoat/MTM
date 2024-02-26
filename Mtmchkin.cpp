#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Mtmchkin.h"



Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) {
    m_player = Player(playerName);
    m_numberOfCards = numOfCards;
    m_cardsArray = new Card[numOfCards];
    for (int i = 0; i < numOfCards; i++) {
        m_cardsArray[i] = cardsArray[i];
    }
    m_cardIndex = 0;
    m_status = GameStatus::MidGame;
}

Mtmchkin::Mtmchkin(const Mtmchkin &mtmchkin) {
    m_player = mtmchkin.m_player;
    m_numberOfCards = mtmchkin.m_numberOfCards;
    m_cardsArray = copyCardsArray(mtmchkin.m_cardsArray,mtmchkin.m_numberOfCards);
    m_cardIndex = mtmchkin.m_cardIndex;
    m_status = mtmchkin.m_status;
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& mtmchkin) {
    if (this != &mtmchkin) {
        // Delete existing resources
        delete[] m_cardsArray;
        // Copy member variables
        m_player = mtmchkin.m_player;
        m_numberOfCards = mtmchkin.m_numberOfCards;
        m_cardsArray = copyCardsArray(mtmchkin.m_cardsArray,mtmchkin.m_numberOfCards);
        m_cardIndex = mtmchkin.m_cardIndex;
        m_status = mtmchkin.m_status;
    }
    return *this;
}

Mtmchkin::~Mtmchkin() {
    delete[] m_cardsArray;
}

void Mtmchkin::playNextCard() {
    if(!isOver()) {
        if (m_cardIndex == m_numberOfCards) {
            m_cardIndex = 0;
        }
        m_cardsArray[m_cardIndex].printInfo();
        m_cardsArray[m_cardIndex].applyEncounter(m_player);
        m_player.printInfo();
        if (m_player.isKnockedOut()) {
            m_status = GameStatus::Loss;
        }
        if (m_player.getLevel() == GAME_MAX_LEVEL) {
            m_status = GameStatus::Win;
        }
        m_cardIndex++;
    }
}

bool Mtmchkin::isOver() const {
    if (m_status == GameStatus::MidGame) {
        return false;
    }
    return true;
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}

/**
 * make and return a copy of a giver cards array.
 * @param cardsArray - the cards array to copy
 * @param numOfCards - the size of the array
 * @return the copied cards array
 */
Card* Mtmchkin::copyCardsArray(const Card* cardsArray, int numOfCards){
    Card* newCardsArray=new Card [numOfCards];
    for (int i = 0; i < numOfCards; i++) {
        newCardsArray[i]=cardsArray[i];
    }
    return newCardsArray;
}