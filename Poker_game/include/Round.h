#ifndef ROUND_H
#define ROUND_H

#include <iostream>
#include "cards.h""
#include "Player.h"

class Round:public Cards{
    public:
        Round(Player player1, Player player2);

        std::string newLine = ("\n");

        int pot                       = 0; // Calculates the pot during a round
        int bigBlind                  = 2;
        int smallBlind                = 1;
        std::string flopCards         = ""; // Used for printing out cards
        std::string turnCard          = ""; //Used for printing out cards
        std::string riverCard         = ""; // Used for printing out cards

        void gameAction(Player player1, Player player2);
        void accountingPrint(Player player);
        void dealCards(Player player1, Player player2);
        void dealingBlinds(Player playerButton, Player playerNotButton);
        std::string question(Player player, std::string choiceAction);

        void raiseAction(int raiseAmount, Player playerActive, Player playerNotActive);
        void callAction(Player playerActive, Player playerNotActive);
        void checkAction(Player playerActive, Player playerNotActive);
        void foldAction(Player playerActive, Player playerNotActive);

        void choiceOfAction(std::string choice, Player playerActive, Player playerNotActive);
        void resetValues(Player player1, Player player2);

        void preFlop(Player playerButton, Player playerNotButton);
        void flop(Player playerButton, Player playerNotButton);
        void turn(Player playerButton, Player playerNotButton);
        void river(Player playerButton, Player playerNotButton);
    protected:

    private:
};

#endif // ROUND_H
