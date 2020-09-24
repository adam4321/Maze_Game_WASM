/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    File that implements the Space base class 
***********************************************************************/

#include "Space.hpp"

/*********************************************************************
** Description:   Method that prints the map associated with the room
*********************************************************************/
void Space::printMap()
{
    cout << " MAP" << endl;
    cout << map;
    cout << endl << endl << endl;
}

/*********************************************************************
** Description:   Getter and setter functions for Space 
*********************************************************************/
void Space::setDirections(Space *U, Space *R, Space *D, Space *L)
{
    up = U;
    right = R;
    down = D;
    left = L;
}

Space *Space::getUp()
{
    return up;
}

Space *Space::getRight()
{
    return right;
}

Space *Space::getDown()
{
    return down;
}

Space *Space::getLeft()
{
    return left;
}

bool Space::getFinish()
{
    return finished;
}

void Space::setMap(string input)
{
    map = input;
}