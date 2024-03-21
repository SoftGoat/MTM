
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
    string getDescription() const;

    void playCard(Player &player) const;
};
