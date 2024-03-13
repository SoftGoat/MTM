#include <memory>

#include "player.h"

Player::Player(const string name,const string job,const string behavior) {
    if(checkNameValidation(name)) {
        m_name = name;
    }
    else{
        throw std:: exception();
    }
    //todo enum job, building the right sub class. check if wrong, throw
    m_job = std::make_shared<Job> (job);
    //todo enum behavior, building the right sub class. check if wrong, throw
    m_behavior = std::make_shared<Behavior>(behavior);

}



string Player::getDescription() const {
    return "getdis";
}

string Player:: getName() const{
    return "getname";
}


int Player:: getLevel() const{
    return 1;
}


int Player:: getForce() const{
    return 2;
}


int Player:: getHealthPoints() const{
    return 3;
}


int Player:: getCoins() const{
    return 4;
}

bool Player::checkNameValidation(const string name) {
    if(name.length()>MAX_NAME_LENGTH){
        return false;
    }
    for(char i : name){
        if(i<'A'||(i>'Z'&&i<'a')||i>'z'){
            return false;
        }
    }
    return true;
}






