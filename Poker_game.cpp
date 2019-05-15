#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class CardClass{
    private:


    public:

        CardClass(int rank = 0,  string color = "Spadeartlubsiamond", string value = "President"){
            this->rank = rank;
            this->color = color;
            this->value = value;
        }

        ~CardClass(){}

        int rank;
        string color;
        string value;

};

class Cards{
    private:


    public:
        Cards(){
            generateNewDeck();
        }
        ~Cards(){}

        CardClass cardDeck[52];


        void generateNewDeck(bool pickCard = false, int pickColorIndex = -1, int pickValueIndex = -1)
        {

            const string values[13] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
            const string colors[4] = {"Hearts","Diamonds","Clubs","Spades"};

            for(size_t color_i = 0; color_i<4; color_i++){
                for(size_t val = 0; val < 13; val++)
                {
                    if (val==pickValueIndex && color_i==pickColorIndex) {
                        /* code */
                    }

                    cardDeck[color_i*13 + val] = CardClass(color_i+1, colors[color_i], values[val]);
                    //cout<< cardDeck[i].value <<endl;
                }
            }

        };

        vector <int> pickedCards;
        bool checkIfCardHasBeenPicked(int randInt)
        {
            for(size_t i = 0; i < pickedCards.size() ; i++)
            {
                if (pickedCards[i] == randInt){
                    return false;
                }


            }

            pickedCards.push_back(randInt);

            return true;
        }

        CardClass pickCard()
        {
            int randIndex = rand() % 52;

            cout << randIndex << endl;

            if(checkIfCardHasBeenPicked(randIndex)){
                CardClass pickedCard = cardDeck[randIndex];
                cardDeck[randIndex] = CardClass(0,"0","0");
                return pickedCard;
            }
            else
            {
                pickCard();
                cout << randIndex << endl;
            }


        };
};

/*class Player(object):
    def __init__(self, name):
        print("Entering player __init__")
        self.card1                  = None #Cards on hand
        self.card2                  = None #Cards on hand
        self.active                 = False # Not really used, should be deleted
        self.cash                   = 200 # The overall cash of the player (set to 100 BB)
        self.playerPot              = 0   # The money the player has in the pot
        self.checked                = False # To tell the program that the other player has checked
        self.hasButton              = False
        self.name                   = name
        print("Leaving player __init__")*/

class Player{
    public:
        Player(string name = "GenericPlayer"){
            this->name = name;
        };
        CardClass card1;
        CardClass card2;
        int cash;
        int playerPot;                  // The money the player has in the pot
        bool checked                = false; // To tell the program that the other player has checked
        bool hasButton              = false;
        string name;

};

class Round{
    public:
        Round(Player player1, Player player2){
            //super().__init__()
            cout << "Entering: Round __init__" << endl;

            if( !player1.hasButton  && !player2.hasButton){
                player1.hasButton = true;
                // If is needed at the very first round to determine who has button
            };

            if (player1.hasButton){ // If use to set button before each round
                this->gameAction(player1,player2);
            }
            else{
                this->gameAction(player2,player1);
            };
            cout << "Leaving: Round __init__" << endl;
        }


        int pot                       = 0; // Calculates the pot during a round
        int bigBlind                  = 2;
        int smallBlind                = 1;
        string flopCards              = ""; // Used for printing out cards
        string turnCard               = ""; //Used for printing out cards
        string riverCard              = ""; // Used for printing out cards

        void gameAction(Player player1, Player player2){

        }

        void accountingPrint(Player player){
            // Function that is used to see the players money developments at each part
            cout << player.name + ".cash:" << player.cash << endl;
            cout << player.name + ".playerPot:" << player.playerPot << endl;
        }

        void dealCards(Player player1, Player player2){
            // Assigns cards to each player
            cout << "Entering dealCards()" << endl;
            player1.card1 = this->pickCard();
            player1.card2 = this->pickCard();
            player2.card1 = this->pickCard();
            player2.card2 = this->pickCard();
            cout << "player1:" << player1.card1.value << "and" << player1.card2.value << endl;
            cout << "player2:" << player2.card1.value << "and" << player2.card2.value << endl;
        }

};



int main(){
    Player player1("player1");
    Player player2("player2");
    Round round(player1, player2);

    cout << player1.name << endl;


    return 0;
}
