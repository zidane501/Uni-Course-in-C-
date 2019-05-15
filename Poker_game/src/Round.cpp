#include "Round.h"
#include <iostream>
#include <string>

Round::Round(Player player1, Player player2){
            //super().__init__()
    std::cout << "Entering: Round Constructor\n";

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
    std::cout << "Leaving: Round Constructor\n";

}

void Round::gameAction(Player playerButton, Player playerNotButton){

    std::cout << "Entering: gameAction()\n";

    this->dealingBlinds(playerButton, playerNotButton);
    this->dealCards(playerButton, playerNotButton);
    this->preFlop(playerButton, playerNotButton);
    this->flop(playerButton, playerNotButton);
    this->turn(playerButton, playerNotButton);
    this->river(playerButton, playerNotButton);

    std::cout << "Leaving: Round gameAction()\n";

}

void Round::accountingPrint(Player player){
    // Function that is used to see the players money developments at each part
    std::cout << "Entering: accountingPrint()\n";
    std::cout << player.name + ".cash: " << player.cash << "\n";
    std::cout << player.name + ".playerPot: " << player.playerPot << "\n";
    std::cout << "Leaving: accountingPrint()\n";
}

void Round::dealCards(Player player1, Player player2){
            // Assigns cards to each player
    std::cout << "Entering dealCards()\n";
    player1.card1 = this->pickCard();
    player1.card2 = this->pickCard();
    player2.card1 = this->pickCard();
    player2.card2 = this->pickCard();
    std::cout << "Player1: " << player1.card1.value << " and " << player1.card2.value << "\n";
    std::cout << "Player2: " << player2.card1.value << " and " << player2.card2.value << "\n";
    std::cout << "Leaving: dealCards()\n";
}

void Round::dealingBlinds(Player playerButton, Player playerNotButton){
    std::cout << "Entering dealingBlinds()\n";

    playerButton.cash           = playerButton.cash - this->bigBlind;
    playerNotButton.cash        = playerNotButton.cash - this->smallBlind;

    playerButton.playerPot      = this->bigBlind;
    playerNotButton.playerPot   = this->smallBlind;

    this->accountingPrint(playerButton);
    this->accountingPrint(playerNotButton);

    this->pot                    = this->bigBlind + this->smallBlind;

    std::cout << "Pot:" << this->pot << "\n";

    std::cout << "Leaving: dealingBlinds()\n";
};

std::string Round::question(Player player, std::string choiceAction){
    std::cout << "Entering: question()\n";
    std::cout << "\n" << "************************************************************" << "\n";
    std::cout << player.name + ":" <<  player.card1.value << " of " << player.card1.color << " and " << player.card2.value << " of " << player.card2.color << "\n";

    int callAmount = this->pot - player.playerPot*2;

    std::string choice;

    if(choiceAction == "ch"){
        //choice = input(player.name +  "|Plrpot: "  + str(player.playerPot) + " |Pot: " +  str(this->pot) + " | Raise, check or fold (r, ch, f)\n")
        std::cout << "\n" << player.name +  " | Plrpot: "  + std::to_string(player.playerPot) + " | Pot: " +  std::to_string(this->pot) + " | Raise, check or fold (r, ch, f)\n" << "\n";
        std::cin >> choice;
    }
    if(choiceAction == "ca" || choiceAction == "r"){

        std::cout << "\n" << player.name +  " | Plrpot: "  + std::to_string(player.playerPot) + " | Pot: " +  std::to_string(this->pot) + " | Raise, call or fold (r, ca, f)\n" << "\n";
        std::cin >> choice;
    }


    std::cout << this->newLine + "************************************************************" << this->newLine;

    std::cout << "Leaving: question()\n";

    return choice;
};

void Round::raiseAction(int raiseAmount, Player playerActive, Player playerNotActive){

    std::cout << "Entering: raiseAction()\n";

    this->accountingPrint(playerActive);
    this->accountingPrint(playerNotActive);

    int callAmount = playerNotActive.playerPot - playerActive.playerPot;

    std::cout << "raiAct callAmount: " << callAmount << "\n";

    if (callAmount < 0){callAmount = 0;};

    int amountTotal = callAmount + raiseAmount;
    std::cout << "callAmount + raiseAmount: " << amountTotal << "\n";

    playerActive.cash           = playerActive.cash - amountTotal;

    playerActive.playerPot      = playerActive.playerPot + amountTotal;

    this->pot                    = playerActive.playerPot + playerNotActive.playerPot;
    std::cout << "this->pot: " << this->pot << "\n";

    this->accountingPrint(playerActive);
    this->accountingPrint(playerNotActive);

    std::string choice = this->question(playerNotActive, "ca");

    this->choiceOfAction(choice, playerNotActive, playerActive);

    std::cout << " Leaving: raiseAction" << "\n";
};

void Round::callAction(Player playerActive, Player playerNotActive){
    std::cout << "Entering: callAction()\n";

    int callAmount               = playerNotActive.playerPot - playerActive.playerPot;

    std::cout << "callAct callAmount: " << callAmount << "\n";

    playerActive.cash            = playerActive.cash - callAmount;

    playerActive.playerPot       = playerActive.playerPot + callAmount;

    this->pot                    = playerActive.playerPot + playerNotActive.playerPot;

    std::cout << "this->pot: " << this->pot << "\n";

    this->accountingPrint(playerActive);
    this->accountingPrint(playerNotActive);

    std::cout << " Leaving: callAction" << "\n";
};
void Round::checkAction(Player playerActive, Player playerNotActive){
    std::cout << "Entering: checkAction()\n";

    playerActive.checked = true;

    if(!playerNotActive.checked){

        if(playerActive.playerPot - playerNotActive.playerPot == 0){
            std::string choice = this->question(playerNotActive, "ch");
            this->choiceOfAction(choice, playerNotActive, playerActive);
        }
        else{
            std::string choice = this->question(playerNotActive, "ca");
            this->choiceOfAction(choice, playerNotActive, playerActive);
        }
    std::cout << "Leaving: checkAction()\n";
    }
};
void Round::foldAction(Player playerActive, Player playerNotActive){

    std::cout << "Entering: foldkAction()\n";

    playerActive.playerPot      = 0;
    playerNotActive.playerPot   = 0;

    playerActive.hasButton      = !playerActive.hasButton;
    playerNotActive.hasButton   = !playerNotActive.hasButton;

    playerNotActive.cash        = playerNotActive.cash + this->pot;
    this->pot                   = 0;

    std::cout << "Leaving: foldAction()\n";

};

void Round::choiceOfAction(std::string choice, Player playerActive, Player playerNotActive){
    std::cout << "Entering: choiceOfAction()\n";

    std::cout << "choice: " << choice << "\n";

    if (choice == "r" ){this->raiseAction(this->bigBlind, playerActive, playerNotActive);};
    if (choice == "ch"){this->checkAction(playerActive, playerNotActive);};
    if (choice == "ca"){this->callAction( playerActive, playerNotActive);};
    if (choice == "f" ){this->foldAction( playerActive, playerNotActive);};

    std::cout << "Leaving: choiceOfAction()\n";
};

void Round::resetValues(Player player1, Player player2){
    player1.checked, player2.checked                = false, false;
};

void Round::preFlop(Player playerButton, Player playerNotButton){
    std::cout << "Entering: preFlop()\n";

    this->resetValues(playerButton, playerNotButton);

    std::cout << "\n" << "************************** Preflop **********************************\n";

    std::string choice = this->question(playerNotButton, "ch");

    this->choiceOfAction(choice, playerButton, playerNotButton);

    std::cout << "Leaving: preFlop()\n";


};

void Round::flop(Player playerButton, Player playerNotButton){
    std::cout << "Entering: flop()\n";

    this->resetValues(playerButton, playerNotButton);

    std::cout << "\n" << "************************** Flop **********************************\n";

    CardClass flopCard1 = this->pickCard(); CardClass flopCard2 = this->pickCard(); CardClass flopCard3 = this->pickCard();

    this->flopCards = flopCard1.value + " of " + flopCard1.color + " | " + flopCard2.value + " of " + flopCard2.color  + " | " + flopCard3.value + " of " + flopCard3.color + this->newLine;

    std::cout << "\n" + this->flopCards + this->newLine;

    std::string choice = this->question(playerNotButton, "ch");

    this->choiceOfAction(choice, playerButton, playerNotButton);

    std::cout << "Leaving: flop()\n";

};

void Round::turn(Player playerButton, Player playerNotButton){
    std::cout << "Entering: turn()\n";

    this->resetValues(playerButton, playerNotButton);

    std::cout << "\n" << "************************** Turn **********************************\n";

    CardClass turnCardObj = this->pickCard();

    this->turnCard = turnCardObj.value + " of " + turnCardObj.color;

    std::cout << "\n" + this->flopCards << " " << turnCard <<  "\n";

    std::string choice = this->question(playerNotButton, "ch");

    this->choiceOfAction(choice, playerButton, playerNotButton);

    std::cout << "Leaving: turn()\n";

};
void Round::river(Player playerButton, Player playerNotButton){
    std::cout << "Entering: river()\n";

    this->resetValues(playerButton, playerNotButton);

    std::cout << "\n" << "************************** River **********************************\n";

    CardClass riverCardObj = this->pickCard();

    this->riverCard = riverCardObj.value + " of " + riverCardObj.color;

    std::cout << "\n" << this->flopCards << " || " << turnCard << " || " << riverCard << "\n";

    std::string choice = this->question(playerNotButton, "ch");

    this->choiceOfAction(choice, playerButton, playerNotButton);

    std::cout << "Leaving: river()\n";
};
