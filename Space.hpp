/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    Header file for the Space base class 
***********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>

#include "Character.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Space
{
protected:
    Space *up;
    Space *right;
    Space *down;
    Space *left;
    bool finished = false;
    bool key = false;
    bool stick = false;
    string map;
public:
    Space() {};
    virtual void setDirections(Space *U, Space *L, Space *R, Space *D);
    virtual Space *getUp();
    virtual Space *getRight();
    virtual Space *getDown();
    virtual Space *getLeft();
    virtual bool getFinish();
    virtual void setMap(string input);
    virtual void printMap();
    virtual void printImg() = 0;
    virtual void action(Character &player) = 0;
};
#endif