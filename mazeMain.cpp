/***********************************************************************
** Program name:   WASM Maze Game
** Author:         Adam Wright
** Date:           9/19/2020
** Description:    Single player console game where the player is a rat
**                 in a maze. The player needs to escape the maze before
**                 they die from running out of health (cheese). The 
**                 program can be run by typing maze into the command 
**                 line and following the prompts.
**
**                 This version is a rewrite which uses emscripten to
**                 compile the program into a WASM module so that the
**                 game can be run in a web browser using a faux CLI
**                 which is emulated in HTML and CSS.
**
**                 To build the program, install LLVM enscripten and
**                 then run the makefile by typing  --  make maze
**                 at the command line. Then the generated HTML file
**                 can be run in a web browser and will act as the
**                 initial entry point.
***********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <emscripten.h>

#include "Character.hpp"
#include "Space.hpp"
#include "Start.hpp"
#include "Empty.hpp"
#include "Dinosaur.hpp"
#include "Key.hpp"
#include "Cheese.hpp"
#include "Door.hpp"
#include "Finish.hpp"


// DECLARE NAMESPACES ---------------------------------------------------------

using std::cout;
using std::endl;


// GLOBAL VARIABLES -----------------------------------------------------------

bool onlyNumbers = false;
int gameMenu = 0;
Space *current;
Character player;
bool finished = false;
bool key = false;
bool wall = true;
bool hitWall = false;
bool dinoDeath = false;
int roomNum = 1;

// Create room instances
Space *one = new Start();
Space *two = new Dinosaur();
Space *three = new Cheese();
Space *four = new Empty();
Space *five = new Dinosaur();
Space *six = new Cheese();
Space *seven = new Empty();
Space *eight = new Dinosaur();
Space *nine = new Cheese();
Space *ten = new Key();
Space *eleven = new Key();
Space *twelve = new Empty();
Space *thirteen = new Door();
Space *fourteen = new Finish();


// FUNCTION DECLARATIONS ------------------------------------------------------

void start_prompt(void);        // Start game or exit
void start_room(void);          // Press enter for start room
void check_for_end(void);       // Test for finsh or death
void ack_action(void);          // Press enter after room action seen
void check_for_wall(void);      // 
void room_loop(void);           // Test for cardinal direction movement
void game_end(void);            // Test for win or death
void cleanup_restart(void);     // Clean-up then reload the page


// MAIN -----------------------------------------------------------------------

int main(void)
{
    // Set the paths between rooms
    one->setDirections(three, two, NULL, NULL);
    two->setDirections(four, ten, NULL, one);
    three->setDirections(five, four, one, NULL);
    four->setDirections(six, NULL, two, three);
    five->setDirections(seven, six, three, NULL);
    six->setDirections(eight, NULL, four, five);
    seven->setDirections(eleven, eight, five, NULL);
    eight->setDirections(twelve, nine, six, seven);
    nine->setDirections(thirteen, NULL, NULL, eight);
    ten->setDirections(NULL, NULL, NULL, two);
    eleven->setDirections(NULL, twelve, seven, NULL);
    twelve->setDirections(NULL, thirteen, eight, eleven);
    thirteen->setDirections(NULL, NULL, nine, twelve);
    fourteen->setDirections(NULL, NULL, NULL, NULL);


    // Set the map for each room

    /*********************************************************************
    ** Description:   Set the Map using this layout
    **                      
    **                 _____________
    **                 |11|12|13|14|   <= Finish
    **                 |7_|8_|9_|
    **                 |5_|6_|
    **                 |3_|4_|__
    **       Start =>  |1_|2_|10|
    **                 
    *********************************************************************/

    one->setMap(R"(_________
|_|_|_|F|
|_|_|_|
|_|_|
|_|_|_
|X|_|_|)");

    two->setMap(R"(_________
|_|_|_|F|
|_|_|_|
|_|_|
|_|_|_
|S|X|_|)");

    three->setMap(R"(_________
|_|_|_|F|
|_|_|_|
|_|_|
|X|_|_
|S|_|_|)");

    four->setMap(R"(_________
|_|_|_|F|
|_|_|_|
|_|_|
|_|X|_
|S|_|_|)");

    five->setMap(R"(_________
|_|_|_|F|
|_|_|_|
|X|_|
|_|_|_
|S|_|_|)");

    six->setMap(R"(_________
|_|_|_|F|
|_|_|_|
|_|X|
|_|_|_
|S|_|_|)");

    seven->setMap(R"(_________
|_|_|_|F|
|X|_|_|
|_|_|
|_|_|_
|S|_|_|)");

    eight->setMap(R"(_________
|_|_|_|F|
|_|X|_|
|_|_|
|_|_|_
|S|_|_|)");

    nine->setMap(R"(_________
|_|_|_|F|
|_|_|X|
|_|_|
|_|_|_
|S|_|_|)");

    ten->setMap(R"(_________
|_|_|_|F|
|_|_|_|
|_|_|
|_|_|_
|S|_|X|)");

    eleven->setMap(R"(_________
|X|_|_|F|
|_|_|_|
|_|_|
|_|_|_
|S|_|_|)");

    twelve->setMap(R"(_________
|_|X|_|F|
|_|_|_|
|_|_|
|_|_|_
|S|_|_|)");

    thirteen->setMap(R"(_________
|_|_|X|F|
|_|_|_|
|_|_|
|_|_|_
|S|_|_|)");


    /*********************************************************************
    ** Description:   Rat ascii art from 
    **        https://asciiart.website/index.php?art=animals/rodents/other
    *********************************************************************/

    cout << R"(

    ######################################################################
    #         __             _,-"~^"-.                                   #
    #       _// )      _,-"~`         `.                                 #
    #     ." ( /`"-,-"`                 ;                                #
    #    / 6                             ;                               #
    #   /           ,             ,-"     ;                              #
    #  (,__.--.      \           /        ;                              #
    #   //'   /`-.\   |          |        `._________                    #
    #     _.-'_/`  )  )--...,,,___\     \-----------,)                   #
    #   ((("~` _.-'.-'           __`-.   )         //                    #
    #         ((("`             (((---~"`         //                     #
    #                                            ((________________      #
    #                                            `----""""~~~~^^^```     #
    ######################################################################
    )";


    cout << R"(
                          
                          **  The Rat's Maze  **
                          **********************
                               ***********
                                   ***
                                    *
    )";

    // Prompt the user to start the game
    cout << endl << endl;
    cout << "Press 1 to Enter the Maze" << endl;
    cout << "Press 2 to Exit";
    cout << endl << endl;


    /* ------------------------------------------------------------------------
    * Once control is passed to emscripten infinite loop, main can't be reached
    * ---------------------------------------------------------------------- */
    emscripten_set_main_loop(start_prompt, 10, 1);
}


// ASK USER TO ENTER OR EXIT --------------------------------------------------
    
void start_prompt(void) {

    int start_bool = 0;

    // Inline JS - Get the value entered into the faux CLI
    start_bool = EM_ASM_INT({
        return input;
    }, start_bool);

    // Select 2 to Exit
    if (start_bool == 2)
    {
        cout << "Maze Game Quitting  --  Goodbye!";
        cout << endl << endl;

        // // Free the heap memory
        // delete one;
        // delete two;
        // delete three;
        // delete four;
        // delete five;
        // delete six;
        // delete seven;
        // delete eight;
        // delete nine;
        // delete ten;
        // delete eleven;
        // delete twelve;
        // delete thirteen;
        // delete fourteen;

        emscripten_cancel_main_loop();

        // Inline JS - Exit out to previous window
        EM_ASM({
            setTimeout(() => {
                window.history.back();
            }, 800);
        });
    }

    // Select 1 to start
    if (start_bool == 1) {
        cout << ".........................................................................." << endl;
        cout << "**************************************************************************";
        cout << endl << endl;
        cout << "I'm afraid that you are a rat!!!" << endl;
        cout << "You have been dropped into a room in a maze!";
        cout << endl << endl << endl;
        cout << "Your goal is to move from room to room and escape" << endl;
        cout << "before your Cheese-O-Meter runs out and you die...";
        cout << endl << endl;
        cout << "You loose a piece of cheese for each move" << endl;
        cout << "and you need to find a key to escape...";
        cout << endl << endl << endl;


        cout << "Press enter to Begin";
        cout << endl << endl;

        emscripten_cancel_main_loop();
        emscripten_set_main_loop(start_room, 10, 1);
    }
}


// PRESS ENTER TO START -------------------------------------------------------

void start_room(void)
{
    int start_bool = 0;

    // Inline JS - Get the value entered into the faux CLI
    start_bool = EM_ASM_INT({
        if (input == "") {
            return 5;
        }
    }, start_bool);

    // Enter is pressed, then start the game loop
    if (start_bool == 5) {
        cout << endl << endl;

        // Set the current room to one to start the game
        current = one;

        emscripten_cancel_main_loop();
        emscripten_set_main_loop(check_for_end, 10, 1);
    }
}


// TEST FOR GAME END ---------------------------------------------------------- 

void check_for_end(void)
{
    // Game loop that runs until the player wins or dies
    if (finished == false && player.getHealth() > 0)
    {
        if (wall == false)
        {
            current->printImg();

        }
        wall = true;

        emscripten_cancel_main_loop();
        emscripten_set_main_loop(check_for_wall, 10, 1);
    }

    // The player has reached the end or died
    else
    {
        emscripten_cancel_main_loop();
        emscripten_set_main_loop(game_end, 10, 1);
    }
}


// TEST FOR HITTING WALL ------------------------------------------------------

void check_for_wall(void)
{
    // Inline JS - Set input to a garbage value
    EM_ASM({
        input = 42;
    });

    if (wall == true && player.getHealth() > 0)
    {
        if (hitWall == false)
        {
            current->action(player);

            // Inline JS - Set input to a garbage value
            EM_ASM({
                input = 42;
            });

            // Move to player input loop                
            emscripten_cancel_main_loop();
            emscripten_set_main_loop(ack_action, 10, 1);
        }
        else
        {
            cout << endl << endl;

            if (player.getHealth() < 1)
            {
                dinoDeath = true;

                emscripten_cancel_main_loop();
                emscripten_set_main_loop(game_end, 10, 1);
            }

            if (dinoDeath == false)
            {
                player.printHealth();
                player.printItems();
                current->printMap();

                // Print the user menu
                cout << "Press 1 to move UP" << endl;
                cout << "Press 2 to move RIGHT" << endl;
                cout << "Press 3 to move DOWN" << endl;
                cout << "Press 4 to move LEFT" << endl;
                cout << endl << endl;
            }

            emscripten_cancel_main_loop();
            emscripten_set_main_loop(room_loop, 10, 1);
        }
        
    }
    else
    {
        emscripten_cancel_main_loop();
        emscripten_set_main_loop(check_for_end, 10, 1);
    }
}


// PRESS ENTER TO CONTINUE ----------------------------------------------------

void ack_action(void)
{
    int start_bool = 0;

    // Inline JS - Get the value entered into the faux CLI
    start_bool = EM_ASM_INT({
        if (input == "") {
            return 5;
        }
    }, start_bool);

    // Enter is pressed, then start the game loop
    if (start_bool == 5) {
        cout << endl << endl;

        if (player.getHealth() < 1)
        {
            dinoDeath = true;

            emscripten_cancel_main_loop();
            emscripten_set_main_loop(game_end, 10, 1);
        }

        if (dinoDeath == false)
        {
            player.printHealth();
            player.printItems();
            current->printMap();

            // Print the user menu
            cout << "Press 1 to move UP" << endl;
            cout << "Press 2 to move RIGHT" << endl;
            cout << "Press 3 to move DOWN" << endl;
            cout << "Press 4 to move LEFT" << endl;
            cout << endl << endl;
        }

        emscripten_cancel_main_loop();
        emscripten_set_main_loop(room_loop, 10, 1);
    }
}


// TEST THE USER INPUT AND CHOOSE NEXT ROOM -----------------------------------

void room_loop(void)
{
    gameMenu = 0;

    // Inline JS - Get the value entered into the faux CLI
    gameMenu = EM_ASM_INT({
        return input;
    }, gameMenu);


    // Input validation and then actions based on the selection
    if (gameMenu == 1 || gameMenu == 2 || gameMenu == 3 ||  gameMenu == 4)
    {
        // Check if the move is a wall or else move the player
        if (gameMenu == 1)
        {
            if (current->getUp() == NULL)
            {
                cout << endl << endl;
                cout << "Sorry that is a wall..." << endl;
                cout << "Try again.";
                cout << endl << endl << endl;
                hitWall = true;
            }
            else
            {
                wall = false;
                hitWall = false;
                current = current->getUp();
            }

            finished = current->getFinish();
            player.setHealth(player.getHealth() - 1);
        }

        else if (gameMenu == 2)
        {
            if (current->getRight() == NULL)
            {
                cout << endl << endl;
                cout << "Sorry that is a wall..." << endl;
                cout << "Try again.";
                cout << endl << endl << endl;
                hitWall = true;
            }
            else
            {
                wall = false;
                hitWall = false;
                current = current->getRight();
            }

            finished = current->getFinish();
            player.setHealth(player.getHealth() - 1);
        }

        else if (gameMenu == 3)
        {
            if (current->getDown() == NULL)
            {
                cout << endl << endl;
                cout << "Sorry that is a wall..." << endl;
                cout << "Try again.";
                cout << endl << endl << endl;
                hitWall = true;
            }
            else
            {
                wall = false;
                hitWall = false;
                current = current->getDown();
            }

            finished = current->getFinish();
            player.setHealth(player.getHealth() - 1);
        }

        else if (gameMenu == 4)
        {
            if (current->getLeft() == NULL)
            {
                cout << endl << endl;
                cout << "Sorry that is a wall..." << endl;
                cout << "Try again.";
                cout << endl << endl << endl;
                hitWall = true;
            }
            else
            {
                wall = false;
                hitWall = false;
                current = current->getLeft();
            }

            finished = current->getFinish();
            player.setHealth(player.getHealth() - 1);
        }

        if (player.hasKey() == true)
        {
            thirteen->setDirections(NULL, fourteen, nine, twelve);
        }

        // Check for hitting a wall
        if (wall == true)
        {
            emscripten_cancel_main_loop();
            emscripten_set_main_loop(check_for_end, 10, 1);
        }

        // Return to check for end with player in the new room
        emscripten_cancel_main_loop();
        emscripten_set_main_loop(check_for_end, 10, 1);
    }
}


// 

void game_end(void)
{
    // Check the state at the end and print a win or a death
    if (finished == true)
    {
        current->printImg();

        cout << "Congratulations You have escaped the maze..." << endl;
        cout << "You are a lucky rat!";
        cout << endl << endl;
        cout << "Press enter to finish";
        cout << endl << endl;

        // Call the cleanup function
        emscripten_cancel_main_loop();
        emscripten_set_main_loop(cleanup_restart, 10, 1);
    }
    
    else
    {
        if (dinoDeath == false)
        {

            /*********************************************************************
            ** Description:   Death ascii art from http://ascii.co.uk/art/death    
            *********************************************************************/

                cout << R"(

                        ...
                        ;::::;
                    ;::::; :;
                    ;:::::'   :;
                ;:::::;     ;.
                ,:::::'       ;           OOO\
                ::::::;       ;          OOOOO\
                ;:::::;       ;         OOOOOOOO
                ,;::::::;     ;'         / OOOOOOO
            ;:::::::::`. ,,,;.        /  / DOOOOOO
            .';:::::::::::::::::;,     /  /     DOOOO
            ,::::::;::::::;;;;::::;,   /  /        DOOO
        ;`::::::`'::::::;;;::::: ,#/  /          DOOO
        :`:::::::`;::::::;;::: ;::#  /            DOOO
        ::`:::::::`;:::::::: ;::::# /              DOO
        `:`:::::::`;:::::: ;::::::#/               DOO
            :::`:::::::`;; ;:::::::::##                OO
            ::::`:::::::`;::::::::;:::#                OO
            `:::::`::::::::::::;'`:;::#                O
            `:::::`::::::::;' /  / `:#
            ::::::`:::::;'  /  /   `#


            I'm sorry but you've died
                    --- 
            Press enter to Try again
)";

        }

        // Call the cleanup function
        emscripten_cancel_main_loop();
        emscripten_set_main_loop(cleanup_restart, 10, 1);
    }
}


// PRESS ENTER AND REFRESH THE PAGE -------------------------------------------

void cleanup_restart(void)
{
    int end_bool = 0;

    // Inline JS - Get the value entered into the faux CLI
    end_bool = EM_ASM_INT({
        if (input == "") {
            return 5;
        }
    }, end_bool);

    if (end_bool == 5)
    {
        emscripten_cancel_main_loop();

        // // Free the heap memory
        // delete one;
        // delete two;
        // delete three;
        // delete four;
        // delete five;
        // delete six;
        // delete seven;
        // delete eight;
        // delete nine;
        // delete ten;
        // delete eleven;
        // delete twelve;
        // delete thirteen;
        // delete fourteen;

        // Inline JS - Reload the page using JS
        EM_ASM({
            location.reload();
        });
    }
}
