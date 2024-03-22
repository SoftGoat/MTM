#pragma once
#include "../Players/Player.h"

class Card {
private:

public:
    /**
     * Gets the description of the card
     * 
     * @return - the description of the card
    */
    virtual string getDescription() const = 0;

    virtual void playCard(Player &player) const =0;
};
