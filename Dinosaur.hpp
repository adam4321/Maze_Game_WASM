/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    Header file for the Dinosaur class derived from space
***********************************************************************/

#ifndef DINOSAUR_HPP
#define DINOSAUR_HPP  

#include "Space.hpp"


class Dinosaur : public Space
{
public:
    Dinosaur() {};
    void printImg() override;
    void action(Character &player) override;
};
#endif
