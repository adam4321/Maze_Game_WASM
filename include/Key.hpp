/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    Header file for the Key class derived from space
***********************************************************************/

#ifndef KEY_HPP
#define KEY_HPP  

#include "Space.hpp"


class Key : public Space
{
public:
    Key();
    ~Key() {}
    void printImg() override;
    void action(Character &player) override;
};
#endif
