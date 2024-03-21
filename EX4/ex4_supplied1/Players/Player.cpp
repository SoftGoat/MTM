#include <iostream>
#include <cstring>
#include "Player.h"
#include "Sorcerer.h"  
#include "Warrior.h"
#include "Responsible.h"
#include "RiskTaking.h"

const std::string Player::DEFAULT_NAME = "ZoGi"; // Arbitrary
const std::string Player::DEFAULT_JOB = "Warrior"; // Arbitrary
const std::string Player::DEFAULT_BEHAVIOR = "RiskTaking"; // Arbitrary



Player::Player(string name, int level, int force, int hp, int maxHp, int coins, const string job, const string behavior){
    string m_name= name;
    inputValidation(name, level, force, hp, maxHp, coins);
    m_job = createJob(job);
    m_behavior = createBehavior(behavior);
    m_name = name;
    m_level = level;
    m_force = force;
    m_hp =hp;
    m_maxHp = maxHp;
    m_coins = coins;

}

Player::Player(string name, int maxHp, int force, const string job, const string behavior) {
    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    string m_name= name;
    inputValidation(name, level, force, hp, maxHp, coins);
    m_job = createJob(job);
    m_behavior = createBehavior(behavior);
    m_name = name;
    m_level = level;
    m_force = force;
    m_hp = hp;
    m_maxHp = maxHp;
    m_coins = coins;
}

Player::Player(string name, int maxHp, const string job, const string behavior) {

    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    int force = DEFAULT_FORCE;
    string m_name= name;
    inputValidation(name, level, force, hp, maxHp, coins);
    m_job = createJob(job);
    m_behavior = createBehavior(behavior);
    m_name = name;
    m_level = level;
    m_force = force;
    m_hp = hp;
    m_maxHp = maxHp;
    m_coins = coins;
}

Player::Player(string name, const string job, const string behavior) {
    int maxHp = DEFAULT_MAXHP;
    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    int force = DEFAULT_FORCE;
    string m_name= name;
    inputValidation(name, level, force, hp, maxHp, coins);
    m_job = createJob(job);
    m_behavior = createBehavior(behavior);
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
    string m_name= DEFAULT_NAME;
    m_job = createJob(DEFAULT_JOB);
    m_behavior = createBehavior(DEFAULT_BEHAVIOR);

}

Player::Player(const Player& other) {
    m_level = other.m_level;
    m_force = other.m_force;
    m_hp = other.m_hp;
    m_maxHp = other.m_maxHp;
    m_coins = other.m_coins;
    m_name = other.m_name;
    m_job = other.m_job;
    m_behavior = other.m_behavior;
}


Player::~Player()
{
}


Player& Player::operator=(const Player& other) {
    m_level = other.m_level;
    m_force = other.m_force;
    m_hp = other.m_hp;
    m_maxHp = other.m_maxHp;
    m_coins = other.m_coins;
    m_name = other.m_name;
    return *this;
}

bool Player::operator<(const Player& other) const {
    if(m_level < other.m_level){
        return true;
    }
    else if(m_level == other.m_level){
        if(m_coins < other.m_coins){
            return true;
        }
        else if(m_coins == other.m_coins){
            if(m_name < other.m_name){
                return true;
            }
            else{
                return false;
                }
            }
        }
    return false;
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
    return m_job->combatPower(*this);
}


bool Player::inputValidation(string name, int &level, int &force, int &hp, int &maxHp, int &coins)
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
            name = DEFAULT_NAME;
        }
    }

    return unchanged;
}


std::shared_ptr<Job> Player::createJob(const std::string& jobName) {
    if (jobName == "Warrior") {
        return std::make_shared<Warrior>();
    } else if (jobName == "Sorcerer") {
        return std::make_shared<Sorcerer>();
    }
    // Add more else-if blocks for additional jobs, need to be upadted manually

    // Default job if no match found
    std::cout << "Unknown job, defaulting to " << DEFAULT_JOB << std::endl;
    if (DEFAULT_JOB == "Warrior") {
        return std::make_shared<Warrior>();
    } else if (DEFAULT_JOB == "Sorcerer") {
        return std::make_shared<Sorcerer>();
    }

}

std::shared_ptr<Behavior> Player::createBehavior(const std::string& behaviorName) {

    if (behaviorName == "RiskTaking") {
        return std::make_shared<RiskTaking>();
    } else if (behaviorName == "Responsible") {
        return std::make_shared<Responsible>();
    }
    // Add more else-if blocks for additional jobs, need to be upadted manually

    // Default behavior if no match found
    std::cout << "Unknown behavior, defaulting to " << DEFAULT_BEHAVIOR << std::endl;
    if (DEFAULT_BEHAVIOR == "RiskTaking") {
        return std::make_shared<RiskTaking>();
    } else if (DEFAULT_BEHAVIOR == "Responsible") {
        return std::make_shared<Responsible>();
    }

}
