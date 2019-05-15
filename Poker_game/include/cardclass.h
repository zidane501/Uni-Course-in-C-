#ifndef CARDCLASS_H
#define CARDCLASS_H

#include <iostream>
#include <string>

class CardClass
{
    public:
        CardClass(int cardRank = 0,  std::string cardColor = "Spadeartlubsiamond", std::string cardValue = "President");

        int rank;
        std::string color;
        std::string value;

    protected:

    private:
};

#endif // CARDCLASS_H
