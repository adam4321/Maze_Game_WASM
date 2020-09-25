/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    File that implements the Empty derived class 
***********************************************************************/

#include "Empty.hpp"

/*********************************************************************
** Description:   Function that prints the image for the Dinosaur class
**          ascii art from https://www.asciiart.eu/art-and-design/mazes
*********************************************************************/
void Empty::printImg()
{
   cout << R"(
        ______________
        |\ ___________ /|
        | |  /|,| |   | |
        | | |,x,| |   | |
        | | |,x,' |   | |
        | | |,x   ,   | |
        | | |/    |   | |
        | |    /] ,   | |
        | |   [/ ()   | |
        | |       |   | |
        | |       |   | |
        | |       |   | |
        | |      ,'   | |
        | |   ,'      | |
        |_|,'_________|_|




)";
}

/*********************************************************************
** Description:   Method that runs the room's action
*********************************************************************/
void Empty::action(Character &player)
{
    cout << "This room is empty...Nothing to see here...";
    cout << endl << endl;
    cout << "Press enter to move along";
    cout << endl << endl << endl;
}
