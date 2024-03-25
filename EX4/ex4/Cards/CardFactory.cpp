// CardFactory.cpp
#include "CardFactory.h"



std::shared_ptr<Card> CardFactory::createCard(const std::string& cardName, std::ifstream &deckFile) {
    if (cardName == "Goblin" || cardName == "Dragon" || cardName == "Giant") {
        return std::make_shared<Monster>(cardName);
    } else if (cardName == "Gang") {
        return buildGangCard(deckFile);
    } else if (cardName == "PotionsMerchant") {
        return std::make_shared<PotionsMerchant>();
    } else if (cardName == "SolarEclipse") {
        return std::make_shared<SolarEclipse>();
    }
    throw std::runtime_error("Invalid Cards File");
    return nullptr;
}

std::shared_ptr<Gang> CardFactory::buildGangCard(std::ifstream &deckFile) {
    int gangSize;
    if (!(deckFile >> gangSize) || gangSize< MINIMUM_NUMBER_OF_GANG_MEMBERS) {
        throw std::runtime_error("Invalid Cards File");
    }

    std::shared_ptr<Gang> gangCard = std::make_shared<Gang>(gangSize);
    for(int i = 0; i < gangSize; i++) {
        std::string monster;
        deckFile >> monster;
        if (monster == "Goblin" || monster == "Giant" || monster == "Dragon") {
            shared_ptr<Monster> monsterCard =std::make_shared<Monster>(monster);
            gangCard->addMonster(monsterCard);
        } else if (monster == "Gang") {
            std::shared_ptr<Gang> gangCard2 = buildGangCard(deckFile);
            gangCard->addMonster(gangCard2);
        }
        else{
            throw std::runtime_error("Invalid Cards File");
        }
    }
    return gangCard;
}
