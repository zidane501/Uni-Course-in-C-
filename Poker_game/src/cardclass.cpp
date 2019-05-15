#include "cardclass.h"
#include <iostream>
CardClass::CardClass(int cardRank,  std::string cardColor, std::string cardValue){

            std::cout << "Entering: CardClass constructor\n";
            std::cout << " cardColor: " << cardColor << " | cardValue: " << cardValue << " ";

            this->rank = cardRank;
            this->color = cardColor;
            this->value = cardValue;

            std::cout << "Leaving: CardClass constructor\n";
}

