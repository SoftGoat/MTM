#include "Player.h"


const std::string Player::DEFAULT_NAME = "ZoGi"; // Arbitrary
const std::shared_ptr<Job> Player::DEFAULT_JOB = Warrior::getInstance(); // Arbitrary
const std::shared_ptr<Behavior> Player::DEFAULT_BEHAVIOR = Responsible::getInstance(); // Arbitrary



Player::Player(string name, int level, int force, int hp, int maxHp, int coins, const string job, const string behavior){
    this->m_name= name;
    inputValidation(name, level, force, hp, maxHp, coins);
    this->m_job = createJob(job);
    this->m_behavior = createBehavior(behavior);

}

Player::Player(string name, int maxHp, int force, const string job, const string behavior) {
    this->m_hp = maxHp;
    this->m_coins = DEFAULT_COINS;
    this->m_level = DEFAULT_LEVEL;
    this->m_name= name;
    this->m_maxHp = maxHp;
    inputValidation(m_name, m_level, m_force, m_hp, m_maxHp, m_coins);
    this->m_job = createJob(job);
    this->m_behavior = createBehavior(behavior);
}

Player::Player(string name, int maxHp, const string job, const string behavior) {
    this->m_hp = maxHp;
    this->m_maxHp = maxHp;
    this->m_coins = DEFAULT_COINS;
    this->m_level = DEFAULT_LEVEL;
    this->m_force = DEFAULT_FORCE;
    string m_name= name;
    inputValidation(m_name, m_level, m_force, m_hp, m_maxHp, m_coins);
    this->m_job = createJob(job);
    this->m_behavior = createBehavior(behavior);
}

Player::Player(string name, const string job, const string behavior) {
    this->m_maxHp = DEFAULT_MAXHP;
    this->m_hp = m_maxHp;
    this->m_coins = DEFAULT_COINS;
    this->m_level = DEFAULT_LEVEL;
    this->m_force = DEFAULT_FORCE;
    this->m_name= name;
    inputValidation(m_name, m_level, m_force, m_hp, m_maxHp, m_coins);
    this->m_job = createJob(job);
    this->m_behavior = createBehavior(behavior);
}

Player::Player(){
    this->m_maxHp = DEFAULT_MAXHP;
    this->m_hp = m_maxHp;
    this->m_coins = DEFAULT_COINS;
    this->m_level = DEFAULT_LEVEL;
    this->m_force = DEFAULT_FORCE;
    this->m_name= DEFAULT_NAME;
    this->m_job = DEFAULT_JOB;
    this->m_behavior = DEFAULT_BEHAVIOR;
}

Player::Player(const Player& other) {
    this->m_level = other.m_level;
    this->m_force = other.m_force;
    this->m_hp = other.m_hp;
    this->m_maxHp = other.m_maxHp;
    this->m_coins = other.m_coins;
    this->m_name = other.m_name;
    this->m_job = other.m_job;
    this->m_behavior = other.m_behavior;
}


Player::~Player()
{
}

string Player::getJobName() const {
    return m_job->getJobName();
}

string Player::getBehaviorName() const {
    return m_behavior->getBehaviorName();
}

Player& Player::operator=(const Player& other) {
    this->m_level = other.m_level;
    this->m_force = other.m_force;
    this->m_hp = other.m_hp;
    this->m_maxHp = other.m_maxHp;
    this->m_coins = other.m_coins;
    this->m_name = other.m_name;
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


void Player::heal(int potion) {
    if(potion > 0){
        int temp = m_hp + potion;
        m_hp = temp > m_maxHp ? m_maxHp : temp;
    }
}

void Player::levelUp(){
    if (m_level < MAXIMUM_LEVEL) {
        m_level++;
    } else {
        std::cout << "Player already reached max level: " << std::endl;
    }
}

int Player::getLevel() const{
    return m_level;
}



void Player::buff(int attack) {
    if(attack>0){
    m_force += attack;
    }
    
}

void Player::nerf(int attack) {
    if(attack>0){
    m_force -= attack;
    }
    
}

int Player::getForce()const {
    return m_force;
}

int Player::getHealthPoints() const {
    return m_hp;
}

int Player::getMaxHealthPoints() const {
    return m_maxHp;
}

int Player::getCoins() const {
    return m_coins;
}

string Player::getName() const {
    return m_name;
}

std::shared_ptr<Behavior> Player::getBehavior() const {
    return m_behavior;
}

shared_ptr<Job> Player::getJob() const {
    return m_job;
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
        return Warrior::getInstance();
    } else if (jobName == "Sorcerer") {
        return Sorcerer::getInstance();
    }
    // Add more else-if blocks for additional jobs, need to be upadted manually

    // Default job if no match found
    std::cout << "Unknown job, creating default job.\n";
    return DEFAULT_JOB; 
}

std::shared_ptr<Behavior> Player::createBehavior(const std::string& behaviorName) {

    if (behaviorName == "RiskTaking") {
        return RiskTaking::getInstance();
    } else if (behaviorName == "Responsible") {
        return Responsible::getInstance();
    }
    // Add more else-if blocks for additional jobs, need to be upadted manually

    // Default behavior if no match found
    std::cout << "Unknown behavior, creating default behavior.\n";
    return DEFAULT_BEHAVIOR; 
}

string Player::getDescription() const {
    return m_name + ", "+this->getJobName()+" with "+ this->getBehaviorName() + " behavior " + "(Level: " + std::to_string(m_level) + ", force: " + std::to_string(m_force) + ")";
}




