#include <iostream>
#include <cstring>
#include "Player.h"
#include "utilities.h"

Player::Player(const char *name_, int level, int force, int hp, int maxHp, int coins)
{
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    this->name = name;
    this->level = level;
    this->force = force;
    this->hp =hp;
    this->maxHp = maxHp;
    this->coins = coins;
}

Player::Player(const char *name_, int force, int maxHp) {

    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    this->name = name;
    this->level = level;
    this->force = force;
    this->hp = hp;
    this->maxHp = maxHp;
    this->coins = coins;


}

Player::Player(const char *name_, int maxHp) {

    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    int force = DEFAULT_FORCE;
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    this->name = name;
    this->level = level;
    this->force = force;
    this->hp = hp;
    this->maxHp = maxHp;
    this->coins = coins;


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
    this->name = name;
    this->level = level;
    this->force = force;
    this->hp = hp;
    this->maxHp = maxHp;
    this->coins = coins;
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
    this->name = name;
    this->level = level;
    this->force = force;
    this->hp = hp;
    this->maxHp = maxHp;
    this->coins = coins;

}

Player::Player(const Player& other) {
    this->level = other.level;
    this->force = other.force;
    this->hp = other.hp;
    this->maxHp = other.maxHp;
    this->coins = other.coins;
    
    // Initialize name to NULL before assigning
    this->name = nullptr;

    // If other.name is not null, then perform the copy
    if (other.name != nullptr) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
}


Player::~Player()
{
    delete[] name;
}


Player& Player::operator=(const Player& other) {
    if(this!=&other){
        char* temp = new char[strlen(other.name) + 1];
        if(temp == NULL){
            std::cout<<"operator '=' faild"<<std::endl;
            return *this;
        }
        if(name != NULL){
            delete[] name; 
        }
        level = other.level;
        force = other.force;
        hp = other.hp;
        maxHp = other.maxHp;
        coins = other.coins;
        name = temp;
        strcpy(name, other.name);

    }
    return *this;
}


void Player::printInfo() {
    printPlayerInfo(this->name, this->level, this->force, this->hp, this->coins);

}

void Player::levelUp() {
    if (this->level < MAXIMUM_LEVEL) {
        this->level++;
    } else {
        std::cout << "Player already reached max level: " << std::endl;
    }
}

int Player::getLevel() {
    return this->level;
}

void Player::buff(int attack) {
    if(attack>0){
    this->force += attack;
    }
    
}

void Player::heal(int potion) {
    if(potion > 0){
        int temp = this->hp + potion;
        this->hp = temp > this->maxHp ? this->maxHp : temp;
    }
}

void Player::damage(int attack){
    if(attack > 0){
        int temp = this->hp-attack;
        this->hp = temp < MINIMUM_HP ? MINIMUM_HP : temp;
    }
}

bool Player::isKnockedOut() const {
    if(this->hp == MINIMUM_HP){  // shoudnt be sincero that hp < MINIMUM_HP
        return true;
    }
    return false;
}

bool Player::isMaxLevel() const {
    if (level == MAXIMUM_LEVEL) {  // shoudnt be sincero that level > MAXIMUM_LEVEL
        return true;
    }
    return false;
}

void Player::addCoins(int money){
    if(money >0){
        this->coins+=money;
    }
}

bool Player::pay(int transaction){
    if(transaction < 0){
        return false;
    }
    int temp = this->coins-transaction;
    if (temp < MINIMUM_COINS)
    {
        return false;
    }
    this->coins = temp;
    return true;
}


int Player::getAttackStrength(){
    return this->force+this->level;
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
