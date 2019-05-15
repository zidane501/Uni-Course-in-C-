#include <iostream>
#include "Player.h"
#include "Round.h"
using namespace std;


int main(){
    Player player1("player1");
    Player player2("player2");
    Round round(player1, player2);

    cout << player1.name << endl;


    return 0;
}
