/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    Header file for the Cheese class derived from space
***********************************************************************/

#ifndef CHEESE_HPP
#define CHEESE_HPP  

#include "Space.hpp"


class Cheese : public Space
{
public:
    Cheese() {}
    ~Cheese() {}
    void printImg() override;
    void action(Character &player) override;
};
#endif
