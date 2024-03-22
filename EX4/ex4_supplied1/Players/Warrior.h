#pragma once
#include "Job.h"

class Warrior : public Job
{
private:
    const int WARRIOR_BUFF = 2;
public:
    Warrior() = default;
    ~Warrior() = default;
    int Warrior::combatPower(Player &Player)const;
    string getJobName() const;
    JobType getJobType() const;
    

};
