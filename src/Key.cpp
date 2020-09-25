/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    File that implements the Key derived class 
***********************************************************************/

#include "Key.hpp"

/*********************************************************************
** Description:   Constructor function for the Key class
*********************************************************************/
Key::Key()
{
    key = true;
}

/*********************************************************************
** Description:   Function that prints the image for the Key Room.
**                ascii art from http://ascii.co.uk/art/key
*********************************************************************/
void Key::printImg()
{
    cout << R"(




     8 8 8 8                     ,ooo.
     8a8 8a8                    oP   ?b
    d888a888zzzzzzzzzzzzzzzzzzzz8     8b
     `""^""'                    ?o___oP'



)";
}

/*********************************************************************
** Description:   Method that runs the room's action
*********************************************************************/
void Key::action(Character &player)
{
    cout << "You have found a key";
    cout << endl << endl;
    cout << "Press enter to add the key to your inventory";
    cout << endl << endl;

    player.addItem("key");
    player.setKey(true);
}
