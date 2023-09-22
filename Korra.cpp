#include "Game.h"

int main()
{
 //initialize random seed
    srand(static_cast<unsigned>(time(0)));
   
// initialize object
   
    Game game;
    
    
// game loop
    game.run();


    return 0;
}