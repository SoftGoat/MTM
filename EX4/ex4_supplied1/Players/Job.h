//
// Created by gilad on 17 מרץ 2024.
//

#ifndef EX4_JOB_H
#define EX4_JOB_H

#include <string>
#include "../Cards/Card.h"
#include "Player.h" 

using std::string;

class Job {

public:
    virtual ~Job() = default;
    virtual int combatPower(Player &Player) const = 0;
    virtual void event(Card& card) const = 0;
};


#endif //EX4_JOB_H
