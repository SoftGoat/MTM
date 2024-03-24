#pragma once
#include "../Players/Player.h"

class SolarEclipse : public Card{
private:
    const int SOLAR_BUFF = 1;
    const int SOLAR_NERF = 1;
    
public:
    /**
     * Default constructor
    */
    SolarEclipse() = default;
    /**
     * Default Destructor
    */
    ~SolarEclipse() = default;
    /**
     *@return - the description of the card
    */
    string getDescription() const override;
    /**
     * Plays the card
     * 
     * @param player - the player that plays the card
     * @return - a message that describes the result of the card
     */
    string playCard(Player &player) const override;
};
    



