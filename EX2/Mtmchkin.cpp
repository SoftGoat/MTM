#include <iostream>
#include <cstring>
#include "Card.h"
#include "utilities.h"
#include "Player.h"
#include "Mtmchkin.h"

class Mtmchkin
{
private:
    GameStatus gameStatus;
    Player player;
    Card* cards;
    


public:
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);
    void playNextCard();
    bool isOver() const;
    GameStatus getGameStatus() const;
    ~Mtmchkin();



private:



};
