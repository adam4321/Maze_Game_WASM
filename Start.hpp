/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    Header file for the Start class derived from space
***********************************************************************/

#ifndef START_HPP
#define START_HPP  

#include "Space.hpp"


class Start : public Space
{
private:
    int visits = 0;
public:
    Start();
    ~Start() {}
    void printImg() override;
    void action(Character &player) override;
};
#endif
