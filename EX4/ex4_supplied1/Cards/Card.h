#pragma once
#include <string>
class Player;  // Forward declaration
class Card {
private:

public:

    Card() = default;
    ~Card() = default;
    /**
     * Gets the description of the card
     * 
     * @return - the description of the card
    */
    virtual std::string getDescription() const = 0;
    /**
    * Plays the card
    * 
    * @param player - the player that plays the card
    * @return - a message that describes the result of the card
    */
    virtual std::string playCard(Player &player) const =0;
};
