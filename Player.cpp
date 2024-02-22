#include <iostream>
#include <cstring>
#include "Player.h"
#include "utilities.h"

Player::Player(const char *name_, int level, int force, int hp, int maxHp, int coins)
{
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    m_name = name;
    m_level = level;
    m_force = force;
    m_hp =hp;
    m_maxHp = maxHp;
    m_coins = coins;
}

Player::Player(const char *name_, int maxHp, int force) {

    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    m_name = name;
    m_level = level;
    m_force = force;
    m_hp = hp;
    m_maxHp = maxHp;
    m_coins = coins;
}

Player::Player(const char *name_, int maxHp) {

    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    int force = DEFAULT_FORCE;
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    m_name = name;
    m_level = level;
    m_force = force;
    m_hp = hp;
    m_maxHp = maxHp;
    m_coins = coins;
}

Player::Player(const char *name_) {
    int maxHp = DEFAULT_MAXHP;
    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    int force = DEFAULT_FORCE;
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    m_name = name;
    m_level = level;
    m_force = force;
    m_hp = hp;
    m_maxHp = maxHp;
    m_coins = coins;
}

Player::Player(){
    int maxHp = DEFAULT_MAXHP;
    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    int force = DEFAULT_FORCE;
    char* name = new char[strlen(DEFAULT_NAME) + 1];
    strcpy(name, DEFAULT_NAME);
    inputValidation(name, level, force, hp, maxHp, coins);
    m_name = name;
    m_level = level;
    m_force = force;
    m_hp = hp;
    m_maxHp = maxHp;
    m_coins = coins;
}

Player::Player(const Player& other) {
    m_level = other.m_level;
    m_force = other.m_force;
    m_hp = other.m_hp;
    m_maxHp = other.m_maxHp;
    m_coins = other.m_coins;
    
    // Initialize name to NULL before assigning
    m_name = nullptr;

    // If other.name is not null, then perform the copy
    if (other.m_name != nullptr) {
        m_name = new char[strlen(other.m_name) + 1];
        strcpy(m_name, other.m_name);
    }
}


Player::~Player()
{
    delete[] m_name;
}


Player& Player::operator=(const Player& other) {
    if(this!=&other){
        char* temp = new char[strlen(other.m_name) + 1];
        if(temp == NULL){
            std::cout<<"operator '=' faild"<<std::endl;
            return *this;
        }
        if(m_name != NULL){
            delete[] m_name;
        }
        m_level = other.m_level;
        m_force = other.m_force;
        m_hp = other.m_hp;
        m_maxHp = other.m_maxHp;
        m_coins = other.m_coins;
        m_name = temp;
        strcpy(m_name, other.m_name);

    }
    return *this;
}


void Player::printInfo() {
    printPlayerInfo(m_name, m_level, m_force, m_hp, m_coins);

}

void Player::levelUp() {
    if (m_level < MAXIMUM_LEVEL) {
        m_level++;
    } else {
        std::cout << "Player already reached max level: " << std::endl;
    }
}

int Player::getLevel() {
    return m_level;
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

bool Player::isMaxLevel() const {
    if (m_level >= MAXIMUM_LEVEL) {  // shoudnt be sincero that level > MAXIMUM_LEVEL
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

bool Player::inputValidation(char *name, int &level, int &force, int &hp, int &maxHp, int &coins)
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
    char* temp = name;
    bool nameIsValid =true;
    while (*temp != '\0' && nameIsValid) {
        if (*temp < 'A' || (*temp > 'Z' && *temp < 'a') || *temp > 'z') {
            unchanged = false;
          //  std::cout << "The value of 'name' is invalid, value changed to default setting:  " << DEFAULT_NAME << std::endl;
            nameIsValid =false;
        }
        temp++;
    }
    return unchanged;
}
