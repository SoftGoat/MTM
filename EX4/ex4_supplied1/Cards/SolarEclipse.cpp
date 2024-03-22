#include "SolarEclipse.h"


void SolarEclipse::playCard(Player &player)const{
    if(player.getJob()->getJobType() == JobType::Sorcerer){
        player.buff(SOLAR_BUFF);
    }
    else{
        player.nerf(SOLAR_NERF);
    }
}

string SolarEclipse::getDescription()const{
    return "Solar Eclipse: If the player is a Sorcerer, buff him by "+std::to_string(SOLAR_BUFF)+". Otherwise, nerf him by "+std::to_string(SOLAR_BUFF)+".\n";
}









