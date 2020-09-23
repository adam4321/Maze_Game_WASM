/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    Header file for the Finish class derived from space
***********************************************************************/

#ifndef FINISH_HPP
#define FINISH_HPP  

#include "Space.hpp"


class Finish : public Space
{
public:
    Finish();
    void printImg() override;
    void action(Character &player) override {};
};
#endif
