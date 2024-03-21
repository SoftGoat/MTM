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
    Job();
    virtual ~Job() = default;
    virtual int combatPower(Player &Player) const;
    virtual void event(Card& card);
};


#endif //EX4_JOB_H
