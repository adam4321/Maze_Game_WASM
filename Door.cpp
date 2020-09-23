/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    File that implements the Door derived class 
***********************************************************************/

#include "Door.hpp"

/*********************************************************************
** Description:   Function that prints the image for the Dinosaur class
**          ascii art from https://www.asciiart.eu/art-and-design/mazes
*********************************************************************/
void Door::printImg()
{
   cout << R"(
   88888888888888888888888888888888888888888888888888888888888888888888888
   88.._|      | `-.  | `.  -_-_ _-_  _-  _- -_ -  .'|   |.'|     |  _..88
   88   `-.._  |    |`!  |`.  -_ -__ -_ _- _-_-  .'  |.;'   |   _.!-'|  88
   88      | `-!._  |  `;!  ;. _______________ ,'| .-' |   _!.i'     |  88
   88..__  |     |`-!._ | `.| |_______________||."'|  _!.;'   |     _|..88
   88   |``"..__ |    |`";.| i|_|MMMMMMMMMMM|_|'| _!-|   |   _|..-|'    88
   88   |      |``--..|_ | `;!|l|MMoMMMMoMMM|1|.'j   |_..!-'|     |     88
   88   |      |    |   |`-,!_|_|MMMMP'YMMMM|_||.!-;'  |    |     |     88
   88___|______|____!.,.!,.!,!|d|MMMo * loMM|p|,!,.!.,.!..__|_____|_____88
   88      |     |    |  |  | |_|MMMMb,dMMMM|_|| |   |   |    |      |  88
   88      |     |    |..!-;'i|r|MPYMoMMMMoM|r| |`-..|   |    |      |  88
   88      |    _!.-j'  | _!,"|_|M<>MMMMoMMM|_||!._|  `i-!.._ |      |  88
   88     _!.-'|    | _."|  !;|1|MbdMMoMMMMM|l|`.| `-._|    |``-.._  |  88
   88..-i'     |  _.''|  !-| !|_|MMMoMMMMoMM|_|.|`-. | ``._ |     |``"..88
   88   |      |.|    |.|  !| |u|MoMMMMoMMMM|n||`. |`!   | `".    |     88
   88   |  _.-'  |  .'  |.' |/|_|MMMMoMMMMoM|_|! |`!  `,.|    |-._|     88
   88  _!"'|     !.'|  .'| .'|[@]MMMMMMMMMMM[@] \|  `. | `._  |   `-._  88
   88-'    |   .'   |.|  |/| /                 \|`.  |`!    |.|      |`-88
   88      |_.'|   .' | .' |/                   \  \ |  `.  | `._    |  88
   88     .'   | .'   |/|  /                     \ |`!   |`.|    `.  |  88
   88  _.'     !'|   .' | /                       \|  `  |  `.    |`.|  88
   88888888888888888888888888888888888888888888888888888888888888888888888


)";
}

/*********************************************************************
** Description:   Method that runs the room's action
*********************************************************************/
void Door::action(Character &player)
{
    cout << "You have reached the final door...";
    cout << endl << endl;

    if (player.hasKey() == true)
    {
        cout << "You have a key!  Press enter to unlock the door...";
        cout << endl << endl;
        cout << "Then move into the room to escape";
    }
    else
    {
        cout << "Press enter and go find a key before you can escape!";
    }
    
    cout << endl << endl << endl;
}
