#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "cardclass.h"

class Player
{
    public:

        Player(std::string plrName);

        CardClass card1;
        CardClass card2;
        std::string name;
        int cash         = 200;
        int playerPot    = 0;                  // The money the player has in the pot
        bool checked     = false; // To tell the program that the other player has checked
        bool hasButton   = false;


    protected:

    private:
};

#endif // PLAYER_H
