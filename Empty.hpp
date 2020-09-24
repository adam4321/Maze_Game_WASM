/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    Header file for the Empty class derived from space
***********************************************************************/

#ifndef EMPTY_HPP
#define EMPTY_HPP  

#include "Space.hpp"


class Empty : public Space
{
public:
    Empty() {}
    ~Empty() {}
    void printImg() override;
    void action(Character &player) override;
};
#endif
