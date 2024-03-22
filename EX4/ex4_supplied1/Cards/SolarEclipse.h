#pragma once
#include "../Players/Job.h"

class SolarEclipse : public Card{
private:
    const int SOLAR_BUFF = 1;
    const int SOLAR_NERF = 1;
    
public:
    SolarEclipse() = default;
    string getDescription() const;
    void playCard(Player &player) const;
};
    



