#include <iostream>
#include <cstring>
#include "Card.h"
#include "utilities.h"
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
    m_cardsArray = new Card[m_numberOfCards];
    for (int i = 0; i < m_numberOfCards; i++) {
        m_cardsArray[i] = mtmchkin.m_cardsArray[i];
    }
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
        m_cardsArray = new Card[m_numberOfCards];
        
        // Copy cards array
        for (int i = 0; i < m_numberOfCards; i++) {
            m_cardsArray[i] = mtmchkin.m_cardsArray[i];
        }

        m_cardIndex = mtmchkin.m_cardIndex;
        m_status = mtmchkin.m_status;
    }
    return *this;
}

Mtmchkin::~Mtmchkin() {
    if (m_cardsArray != nullptr) {
     delete[] m_cardsArray;
    }
}

void Mtmchkin::playNextCard() {
    if (m_cardIndex == m_numberOfCards) {
        m_cardIndex = 0;
    }
    m_cardsArray[m_cardIndex].printInfo();
    m_cardsArray[m_cardIndex].applyEncounter(m_player);
    m_player.printInfo();
    if (m_player.isKnockedOut()) {
        m_status = GameStatus::Loss;
    }
    if (m_player.isMaxLevel()) {
        m_status = GameStatus::Win;
    }
    m_cardIndex++;

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