#pragma once
#include "../Players/Job.h"
#include "../Players/Player.h"
#include "../Players/Behavior.h"
class PotionsMerchant : public Card{
    private:
        const int POTIONS_PRICE = 5;
        const int POTIONS_HEAL = 10;
public:
    PotionsMerchant() = default;
    string getDescription() const override;
    string playCard(Player &player) const override;
};
    



