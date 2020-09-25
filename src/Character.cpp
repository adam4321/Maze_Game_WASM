/***********************************************************************
** Program name:   Maze Game
** Author:         Adam Wright
** Date:           5/30/2019
** Description:    File that implements the Character class 
***********************************************************************/

#include "Character.hpp"

/*********************************************************************
** Description:   Constructor function for the Character class
*********************************************************************/
Character::Character()
{
    health = 10;
    itemCount = 1;
    key = false;
    stickCount = 0;
}

/*********************************************************************
** Description:   Method that prints the Character's health bar
*********************************************************************/
void Character::printHealth()
{
    cout << "    Cheese-o-Meter" << endl;
    cout << "-----------------------" << endl;
    cout << "| ";
    
    for (auto i = 0; i < 10; i++)
    {
        if (i < health)
        {
            cout << "* ";
        }

        else
        {
            cout << "  ";
        }
    }
    
    cout << "|" << endl;
    cout << "-----------------------" << endl << endl;
}

/*********************************************************************
** Description:   Method that adds an item if the inventory is at 3
**                items or below. It takes a string for the item type
**                as it's argument.
*********************************************************************/
void Character::addItem(string input)
{
    if(itemCount < 4)
    {
        items.push_back(input);
        itemCount++;
    }

    else
    {
        cout << "Sorry your intentory is full";
        cout << endl << endl;
    }  
}

/*********************************************************************
** Description:   Method that removes items in inventory
*********************************************************************/
void Character::removeItem(string input)
{
    auto itr = find(items.begin(), items.end(), input);
    if (itr != items.end()) items.erase(itr);
    itemCount--;
}

/*********************************************************************
** Description:   Method that prints the current items in inventory
*********************************************************************/
void Character::printItems()
{
    cout << "Inventory: ";

    for (vector<string>::const_iterator i = items.begin(); i != items.end(); ++i)
    {
        cout << *i << ' ';
    }

    cout << endl << endl;
}

/*********************************************************************
** Description:   Getters and setters for the Character class
*********************************************************************/
int Character::getHealth()
{
    return health;
}

void Character::setHealth(int input)
{
    health = input;
}

int Character::getItemCount()
{
    return itemCount;
}

void Character::setItemCount(int input)
{
    itemCount = input;
}

void Character::setKey(bool input)
{
    key = input;
}

bool Character::hasKey()
{
    return key;
}

void Character::setStickCount(int input)
{
    stickCount = input;
}

int Character::getStickCount()
{
    return stickCount;
}