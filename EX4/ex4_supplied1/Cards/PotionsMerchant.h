#pragma once
#include "../Players/Job.h"

class PotionsMerchant : public Card{
    private:
        const int POTIONS_PRICE = 5;
        const int POTIONS_HEAL = 10;
public:
    PotionsMerchant();
    string getDescription() const;
    void playCard(Player &player) const;
};
    



