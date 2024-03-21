#include <iostream>
#include <cstring>
#include "Player.h"

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

void Player::buff(int attack) {
    if(attack>0){
    m_force += attack;
    }
    
}

void Player::heal(int potion) {
    if(potion > 0){
        int temp = m_hp + potion;
        m_hp = temp > m_maxHp ? m_maxHp : temp;
    }
}

void Player::damage(int attack){
    if(attack > 0){
        int temp = m_hp-attack;
        m_hp = temp < MINIMUM_HP ? MINIMUM_HP : temp;
    }
}

bool Player::isKnockedOut() const {
    if(m_hp <= MINIMUM_HP){  // shoudnt be sincero that hp < MINIMUM_HP
        return true;
    }
    return false;
}

void Player::addCoins(int money){
    if(money >0){
        m_coins+=money;
    }
}

bool Player::pay(int transaction){
    if(transaction < 0){
        return false;
    }
    int temp = m_coins-transaction;
    if (temp < MINIMUM_COINS)
    {
        return false;
    }
    m_coins = temp;
    return true;
}


int Player::getAttackStrength(){
    return m_force+m_level;
}

bool Player::inputValidation(string name, int &level, int &force, int &hp, int &maxHp, int &coins, const string job, const string behavior)
{
    bool unchanged = true;
    if (level < MINIMUM_LEVEL || level > MAXIMUM_LEVEL)
    {
        level = DEFAULT_LEVEL;
        unchanged = false;
        std::cout << "The value of 'level' is invalid value changed to default setting:  " << DEFAULT_LEVEL << std::endl;
    }

    if (force < MINIMUM_FORCE)
    {
        force = DEFAULT_FORCE;
        unchanged = false;
        std::cout << "The value of 'force' is invalid, value changed to default setting:  " << DEFAULT_FORCE << std::endl;

    }

    if (maxHp < MINIMUM_HP)
    {
        maxHp = DEFAULT_MAXHP;
        unchanged = false;
        std::cout << "The value of 'maxHp' is invalid, value changed to default setting:  " << DEFAULT_MAXHP << std::endl;
    }

    if (hp < MINIMUM_HP || hp > maxHp)
    {
        hp = maxHp;
        unchanged = false;
        std::cout << "The value of 'hp' is invalid, value changed to maxHp value :  " << maxHp << std::endl;
    }
    if (coins < MINIMUM_COINS)
    {
        coins = DEFAULT_COINS;
        unchanged = false;
        std::cout << "The value of 'coins' is invalid, value changed to default setting:  " << DEFAULT_COINS << std::endl;
    }
    for (char ch : name){
        if (!isalpha(ch)) {
            unchanged = false;
            std::cout << "The value of 'name' is invalid, value changed to default setting:  " << DEFAULT_NAME << std::endl;
        }
    }
    return unchanged;
}
