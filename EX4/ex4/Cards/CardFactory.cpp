// CardFactory.cpp
#include "CardFactory.h"



std::shared_ptr<Card> CardFactory::createCard(const std::string& cardName) {
    if (cardName == "Goblin" || cardName == "Gang" || cardName == "Dragon" || cardName == "Giant") {
        return std::make_shared<Monster>(cardName);
    } else if (cardName == "Potions Merchant") {
        return std::make_shared<PotionsMerchant>();
    } else if (cardName == "Solar Eclipse") {
        return std::make_shared<SolarEclipse>();
    }
    throw std::runtime_error("Invalid Cards File");
    return nullptr;
}


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

std::shared_ptr<Monster> CardFactory::buildGangCard(std::ifstream &deckFile) {
    int gangSize;
    if (!(deckFile >> gangSize)) {
        throw std::runtime_error("Invalid Cards File");
    }

    std::shared_ptr<Monster> gangCard = std::make_shared<Monster>("Gang");
    for(int i = 0; i < gangSize; i++) {
        std::string monster;
        deckFile >> monster;
        if (monster == "Goblin" || monster == "Giant" || monster == "Dragon") {
            gangCard->addMonster(monster);
        } else if (monster == "Gang") {
            std::shared_ptr<Monster> gangCard2 = buildGangCard(deckFile);
            gangCard->addMonster(*gangCard2);
        }
        else{
            throw std::runtime_error("Invalid Cards File");
        }
    }
    return gangCard;
}
