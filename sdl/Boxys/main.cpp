
#include <iostream>

#include "Game.h"

int main(int argc, char** argv)
{
    std::cout << "Initializing.." << std::endl;

    Game theGame;

    theGame.CreateWorld();

    return theGame.OnExecute();

}
