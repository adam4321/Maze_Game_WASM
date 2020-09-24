/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    Header file for the Door class derived from space
***********************************************************************/

#ifndef DOOR_HPP
#define DOOR_HPP  

#include "Space.hpp"


class Door : public Space
{
public:
    Door() {}
    ~Door() {}
    void printImg() override;
    void action(Character &player) override;
};
#endif
