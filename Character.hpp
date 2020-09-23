/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    Header file for the Character class 
***********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP  

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find;


class Character
{
private:
    int health;
    int itemCount;
    bool key;
    int stickCount;
    vector<string> items;
public:
    Character();
    void setHealth(int input);
    int getHealth();
    void printHealth();
    int getItemCount();
    void setItemCount(int input);
    void addItem(string input);
    void removeItem(string input);
    void printItems();
    void setKey(bool input);
    bool hasKey();
    int getStickCount();
    void setStickCount(int input);
};
#endif
