/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    File that implements the Cheese derived class 
***********************************************************************/

#include "Cheese.hpp"

/*********************************************************************
** Description:   Function that prints the image for the Dinosaur class
**                ascii art from http://ascii.co.uk/art/cheese
*********************************************************************/
void Cheese::printImg()
{
    cout << R"(


         _--"-.
      .-"      "-.
     |""--..      '-.
     |      ""--..   '-.
     |.-. .-".    ""--..".
     |'./  -_'  .-.      |
     |      .-. '.-'   .-'
     '--..  '.'    .-  -.
          ""--..   '_'   :
                ""--..   |
                      ""-' 


                      
)";
}

/*********************************************************************
** Description:   Method that runs the room's action
*********************************************************************/
void Cheese::action(Character &player)
{
    cout << "You have found a piece of cheese";
    cout << endl << endl;
    cout << "Press enter to add it to your Cheese-o-Meter";
    cout << endl << endl;

    player.setHealth(player.getHealth() + 1);
}
