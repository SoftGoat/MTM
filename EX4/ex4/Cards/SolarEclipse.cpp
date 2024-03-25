#include "SolarEclipse.h"

//cant use getPotionsPurchaseMessage since it will cause circular dependency
string SolarEclipse::playCard(Player &player)const{
    int forceChange = player.getJob()->solarEclipse(player);
    return player.getName() + " was affected by a solar eclipse! their force has changed by " + std::to_string(forceChange) + "!";

}

string SolarEclipse::getDescription()const{
    return "SolarEclipse";
}









