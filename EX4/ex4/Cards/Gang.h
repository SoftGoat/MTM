

#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "EncounterCard.h"
#include <vector>

class Gang : public EncounterCard{
    std::vector<shared_ptr<EncounterCard>> m_members;
    int m_damage;
    int m_loot;
    int m_power;
public:

    /**
     * c'tor of gang, create a new gang, in size of gangSize
     * @param gangSize the size of the gang
     */
    Gang(int gangSize);

    ~Gang(){
        m_members.clear();
    }
    /**
     * Add a member to a gang.
     * @param name - The name of the member to add.
     * @return void
     */
    void addMonster(const shared_ptr<EncounterCard> &encounterCard);

    /**
     * return the attack power of the monster/gang
     * @return the attack power of the monster/gang
     */
    const int getPower() const override;

    /**
     * return the loot of the monster/gang
     * @return the loot of the monster/gang
     */
    const int getLoot() const override;

    /**
     * return the damage of the monster/gang
     * @return the damage of the monster/gang
     */
    const int getDamage() const override;

};


#endif //EX4_GANG_H
