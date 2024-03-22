#pragma once
#include "Job.h"

class Sorcerer : public Job
{
private:
    /* data */
public:
    Sorcerer() = default;
    ~Sorcerer() = default;
    int Sorcerer::combatPower(Player &Player)const;
    string getJobName() const;
    JobType getJobType() const;
    

};
