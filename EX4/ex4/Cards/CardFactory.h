// CardFactory.h
#pragma once
#include "Card.h"
#include "Monster.h"
#include "Gang.h"
#include "PotionsMerchant.h"
#include "SolarEclipse.h"
#include <memory>
#include <string>
#include <fstream>

class CardFactory {
public:
    /**
     * Creates a card by the given name
     * 
     * @param cardName - the name of the card
     * @param deckFile - the deck file
     * @return - a shared pointer to the card
     * @throw invalid_argument - if the card name is unknown
     */
    static std::shared_ptr<Card> createCard(const std::string& cardName, std::ifstream &deckFile);
    /**
     * Builds a gang card from the given deck file
     * 
     * @param deckFile - the deck file
     * @return - a shared pointer to the gang card
    */
    static std::shared_ptr<Gang> buildGangCard(std::ifstream &deckFile);

    private:
        static const int MINIMUM_NUMBER_OF_GANG_MEMBERS = 2;

};