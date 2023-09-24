#include "Menu.h"

int main()
{
 //initialize random seed
    srand(static_cast<unsigned>(time(0)));
   
// initialize object
   
    Menu menu;
    
    while (menu.getWindowIsOpen())
    {
        menu.Update();
        menu.Render();
    }

    
// game loop
    


    return 0;
}