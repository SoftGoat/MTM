#include "SolarEclipse.h"

//cant use getPotionsPurchaseMessage since it will cause circular dependency
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
    return "SolarEclipse";
}









