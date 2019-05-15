#include "Player.h"
#include <iostream>

Player::Player(std::string plrName = "GenericPlayer"){
    std::cout << "Entering: Player Constructor\n";
    this->name = plrName;
};
