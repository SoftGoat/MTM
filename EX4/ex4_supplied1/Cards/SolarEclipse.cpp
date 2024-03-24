#include "SolarEclipse.h"


string SolarEclipse::playCard(Player &player)const{
    if(player.getJob()->getJobType() == JobType::Sorcerer){
        player.buff(SOLAR_BUFF);
    return player.getName() + " was affected by a solar eclipse! their force has changed by " + std::to_string(SOLAR_BUFF) + "!";
    }
    else{
        player.nerf(SOLAR_NERF);
    }
    return player.getName() + " was affected by a solar eclipse! their force has changed by " + std::to_string(-SOLAR_NERF) + "!"; // change by negative SOLAR_NERF value

}

string SolarEclipse::getDescription()const{
    return "Solar Eclipse: If the player is a Sorcerer, buff him by "+std::to_string(SOLAR_BUFF)+". Otherwise, nerf him by "+std::to_string(SOLAR_BUFF)+".\n";
}









