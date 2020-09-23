/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    File that implements the Start derived class 
***********************************************************************/

#include "Start.hpp"

/*********************************************************************
** Description:   Constructor function for the Start class
*********************************************************************/
Start::Start() 
{
    stick = true;
}

/*********************************************************************
** Description:   Function that prints the image for the Finish class
**                ascii art from http://ascii.co.uk/art/rooms
*********************************************************************/
void Start::printImg()
{
    cout << R"(
+------------------------------------+ 
|#####|WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW| 
|#####|<(       HOME ROOM          )>| 
|#####|WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW| 
|#####|WWWWWWWWWW.----.WWWWWWWWWWWWWW| 
|#####|WWWWWWWW,'  ||  `.WWWWWWWWWWWW| 
|#####|WWWWWWWI    ||    IWWWWWWWWWWW| 
|#####|WWWWWWWI    ||    IWWWWWWWWWWW| 
|#####|WWWWWWWI    ||    IWWWWWWWWWWW| 
|#####|WWWWWWWI   _||_   IWWWWWWWWWWW| 
|#####|WWWWWWWI  ' || `  IWWWWWWWWWWW| 
|#####|WWWWWWWI    ||    IWWWWWWWWWWW| 
|#####|WWWWWWWI    ||    IWWWWWWWWWWW| 
|#####|WWWWWWWI    ||    IWWWWWWWWWWW| 
|#####|WWWWWWWI____||____IWWWWWWWWWWW| 
|#####/                              | 
|####/                               | 
|###/                                | 
|##/                                 | 
|#/                                  | 
|/                                   | 
+------------------------------------+ 

~.:.~.:.~.:.~.:.~.:.~.:.~.:.~.:.~.:.~.:.~.:.<>.:.~.:.~.:.~.:.



)";
}

/*********************************************************************
** Description:   Method that runs the room's action
*********************************************************************/
void Start::action(Character &player)
{
    cout << "You have found a stick" << endl;
    cout << "It could be helpful later...";
    cout << endl << endl;
    cout << "Press enter to add the stick to your inventory";
    cout << endl << endl;

    player.addItem("stick");
    player.setStickCount(player.getStickCount() + 1);

    visits++;
}
