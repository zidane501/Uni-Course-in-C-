#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <vector>
#include "cardclass.h"
class Cards
{
    public:
        Cards();

        CardClass cardDeck[52];
        std::vector <int> pickedCards;

        void generateNewDeck(bool pickRandCard=false, int pickRandColorIndex = -1, int pickRandValueIndex = -1);

        bool checkIfCardHasBeenPicked(int randInt);

        CardClass pickCard();
    protected:

    private:
};

#endif // CARDS_H
