#include "cards.h"
#include "cardclass.h"
#include <iostream>

Cards::Cards()
{
    std::cout << "Entering: Cards constructor\n";
    this->generateNewDeck();
}

CardClass cardDeck[52];

void Cards::generateNewDeck(bool pickRandCard, int pickRandColorIndex, int pickRandValueIndex)
{
    std::cout << "Entering: generateNewDeck()\n";
    const std::string values[13] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    const std::string colors[4] = {"Hearts","Diamonds","Clubs","Spades"};

    for(size_t color_i = 0; color_i<4; color_i++){
        for(size_t val = 0; val < 13; val++)
        {
            if (val==pickRandValueIndex && color_i==pickRandColorIndex) {
                /* code */
            }

            this->cardDeck[color_i*13 + val] = CardClass(color_i+1, colors[color_i], values[val]);
            //cout<< cardDeck[i].value <<endl;
        }
    }

};

bool Cards::checkIfCardHasBeenPicked(int randInt)
{
    std::cout << "Entering: checkIfCardHasBeenPicked\n";
    for(size_t i = 0; i < pickedCards.size() ; i++)
    {
        if (pickedCards[i] == randInt){
            return false;
        }


    }

    pickedCards.push_back(randInt);

    return true;
};

CardClass Cards::pickCard()
    {
    std::cout << "Entering: pickCard()\n";
    int randIndex = rand() % 52;

    std::cout << randIndex;

    if(checkIfCardHasBeenPicked(randIndex)){
        CardClass pickedCard = cardDeck[randIndex];
        cardDeck[randIndex] = CardClass(0,"0","0");
        return pickedCard;
    }
    else
    {
        pickCard();
        std::cout << randIndex;
    }


};
