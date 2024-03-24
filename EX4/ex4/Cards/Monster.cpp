#include "Monster.h"


Monster::Monster(){
    m_damage = GOBLIN_DAMAGE;
    m_combatPower = GOBLIN_COMBAT_POWER;
    m_loot = GOBLIN_LOOT;
    m_name = GOBLIN_NAME;
    members.push_back(GOBLIN_NAME);
    m_monsterType = MonsterType::GOBLIN;
}

Monster::Monster(int damage, int combatPower, int loot, string name){
    m_damage = damage;
    m_combatPower = combatPower;
    m_loot = loot;
    m_name = name;
    members.push_back(name);
    m_monsterType = getType(name);
}


Monster::Monster(string name){
    m_damage = 0;
    m_combatPower = 0;
    m_loot = 0;
    m_name = "";
    addMonster(name);
}

Monster::~Monster(){
    members.clear();
}

// cant use getEncounterWonMessage and getEncounterLostMessage since its will be a circular dependency
string Monster::playCard(Player &player)const{
    if(player.getAttackStrength() > m_combatPower){
        player.addCoins(m_loot);
        player.levelUp();
        return player.getName() + " won the encounter, gained " + std::to_string(m_loot) + " coins and leveled up!"; 
    }
    else{
        player.damage(m_damage);
    }
    return player.getName() + " lost the encounter and took " + std::to_string(m_damage) + " damage!"; 
}


void Monster::addMonster(string name){

    MonsterType type = getType(name);
    m_monsterType = type; // setting the type of the monster atrribute
    if(type == MonsterType::OTHER){
        //std::cout << "Invalid monster name, changed to goblin" << std::endl; possible option
        std::runtime_error("Invalid Cards File");
        m_damage = GOBLIN_DAMAGE;
        m_combatPower = GOBLIN_COMBAT_POWER;
        m_loot = GOBLIN_LOOT;
        members.push_back(GOBLIN_NAME);
    }
    else
    if(type == MonsterType::GOBLIN){
        m_damage += GOBLIN_DAMAGE;
        m_combatPower += GOBLIN_COMBAT_POWER;
        m_loot += GOBLIN_LOOT;
        members.push_back(name);
    }
    else if(type == MonsterType::DRAGON){
        m_damage += DRAGON_DAMAGE;
        m_combatPower += DRAGON_COMBAT_POWER;
        m_loot += DRAGON_LOOT;
        members.push_back(name);
    }

    else if(type == MonsterType::GIANT){
        m_damage += GIANT_DAMAGE;
        m_combatPower += GIANT_COMBAT_POWER;
        m_loot += GIANT_LOOT;
        members.push_back(name);
    }
    else if(type == MonsterType::GANG){
        m_damage += 0;
        m_combatPower += 0;
        m_loot += 0;
    }

    else{
        //std::cout << "Invalid monster name, changed to goblin" << std::endl; possible option
        throw std::runtime_error("Invalid Cards File");
        m_damage = GOBLIN_DAMAGE;
        m_combatPower = GOBLIN_COMBAT_POWER;
        m_loot = GOBLIN_LOOT;
        members.push_back(GOBLIN_NAME);
    }
    m_name = m_name == "" ? name : m_name;
    
}

void Monster::addMonster(Monster monster){
    m_damage += monster.m_damage;
    m_combatPower += monster.m_combatPower;
    m_loot += monster.m_loot;
    m_name = m_name == "" ? monster.m_name : m_name;
    members.push_back(monster.m_name);
}

MonsterType Monster::getType(std::string name)const{
    if(name == GOBLIN_NAME){
        return MonsterType::GOBLIN;
    }
    else if(name == DRAGON_NAME){
        return MonsterType::DRAGON;
    }
    else if(name == GIANT_NAME){
        return MonsterType::GIANT;
    }
    else if(name == GANG_NAME){
        return MonsterType::GANG;
    }
    else{
        return MonsterType::OTHER;
    }
}




string Monster::getDescription()const{
    if(this->getType(this->m_name) == MonsterType::GANG){
        return  "Gang of " + std::to_string(members.size()) + " members (power " + std::to_string(m_combatPower) + ", loot " + std::to_string(m_loot) + ", damage " + std::to_string(m_damage)+")"; 
    }
    return  m_name + " (power " + std::to_string(m_combatPower) + ", loot " + std::to_string(m_loot) + ", damage " + std::to_string(m_damage)+")";
}











