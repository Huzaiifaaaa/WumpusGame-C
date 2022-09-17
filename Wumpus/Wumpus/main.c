
/* ---------------------------------------------
Program 1: Wumbus Game Part 1

Course: CS 211, Fall 2022. Thurs 10 am
System: Windows using Visual Studio Code and Replit autograder
Author: Jamani Alford
---------------------------------------------
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<malloc.h>

// custom datastructure to store adjacent rooms for each room
struct coordinate
{
       int x;
       int y;
       int z;
};

// implicit function declarations
void printMap();
void exitProgram();
void printDirections();
int getRandomPosition();
void setAdjacent(struct coordinate *data);

// main function
// driver function
// execution starts from here
// no parameters
// return type is int
// returns 0 on successful execution
int main()
{
       srand(1); // seeding the random number generator
       
       // declaring variables
       int movescount = 1;
       int roomnumber = 0;
       char message[50] = "";

       //dynamic array to store program element coordinates
       int *coordinates;
       coordinates=(int*) malloc(7 * sizeof(int));
       //dynamic array to store adjacent rooms
       struct coordinate *adjacent;
       adjacent = (struct coordinate*) malloc(20 * sizeof(struct coordinate));
       
       //0      1     2   3     4      5     6
       //bat1, bat2,pit1,pit2,wumpus,person,arrow
       for(int i=0;i<7;i++)
       {
              coordinates[i]=getRandomPosition();
       }
       coordinates[6]=-1;//setting arrow position

       setAdjacent(adjacent); // calling function to set adjacent vertices

       while (1) // looping infinte times
       {
              // declaring variables
              int room = 0;
              char command=' ';

              roomnumber = coordinates[5]; // setting user room number

              printf("You are in room %d. ", roomnumber); // printing message
              if (message != NULL)                        // printing hint message
              {
                     printf("%s", message); // printing
                     strcpy(message, "");
              }

              printf("\n\n%d. Enter your move (or 'D' for directions): ",movescount); // asking for user input
              scanf("%c %d",&command,&room);      // getting user input


              if (command == 'D' || command == 'd') // if directions command
              {
                     printMap();        // printing map
                     printDirections(); // printing directions
              }
              else if (command == 'C' || command == 'c') // if cheat command
              {
              }
              else if (command == 'G' || command == 'g') // if guess command
              {

              }
              else if (command == 'P' || command == 'p') // if print command
              {
                     printMap(); // print the map
              }
              else if (command == 'M' || command == 'm') // if move command
              {
                     if(room==adjacent[roomnumber-1].x || room==adjacent[roomnumber-1].y || room==adjacent[roomnumber-1].z)
                     {
                            printf("HELLOWWW. \n");
                     }
                     else
                     {
                            printf("Invalid move.  Please retry. \n");
                     }
              }
              else if (command == 'R' || command == 'r') // if reset command
              {

              }
              else if (command == 'X' || command == 'x') // if exit comamand
              {
                     exitProgram(); // call exitProgram function
              }
              else // else if invalid command
              {
                     printf("Invalid move. Please retry.\n"); // print invalid move message
              }
       }

       return 0; // returning 0 on successful execution
} // end if main

// function getRandomPosition()
// returns random number generated between 1 and 20
// return type is int
int getRandomPosition()
{
       int number = (rand() % 20) + 1; // generates random number between 1 and 20
       return number;                  // returning number generated
} // end of function

// function exitProgram()
// takes no parameter
// exits the program
// return type is void
void exitProgram()
{
       printf("\nExiting Program ..."); // printing message
       exit(0);                         // exiting the program
} // end of function

// function printDirections()
// takes no parameter
// prints the directions/rules to the user
// return type is void
void printDirections()
{
       // printing rules & directions;
       printf("Hunt the Wumpus:\n");
       printf("The Wumpus lives in a completely dark cave of 20 rooms. Each\n");
       printf("room has 3 tunnels leading to other rooms.\n\n");

       printf("Hazards:\n");
       printf("1. Two rooms have bottomless pits in them.  If you go there you fall "
              "and die.\n");

       printf("2. The Wumpus is not bothered by the pits, as he has sucker feet. "
              "Usually he is\n");
       printf("   asleep. He will wake up if you enter his room. When you move into "
              "the Wumpus'\n");
       printf("   room, then he wakes and moves if he is in an odd-numbered room, "
              "but stays\n");
       printf("   still otherwise.  After that, if he is in your room, he snaps "
              "your neck and \n");
       printf("   you die!\n\n");

       printf("Moves:\n");
       printf("On each move you can do the following, where input can be upper or "
              "lower-case:\n");
       printf("1. Move into an adjacent room.  To move enter 'M' followed by a "
              "space and\n");
       printf("   then a room number.\n");

       printf("2. Enter 'R' to reset the person and hazard locations, useful for "
              "testing.\n");
       printf("3. Enter 'C' to cheat and display current board positions.\n");
       printf("4. Enter 'D' to display this set of instructions.\n");
       printf("5. Enter 'P' to print the maze room layout.\n");
       printf("6. Enter 'G' to guess which room Wumpus is in, to win or lose the "
              "game!\n");
       printf("7. Enter 'X' to exit the game.\n\n");

       printf("Good luck!\n\n\n");

} // end of function

// function printMap()
// takes no parameter
// prints the map of the cave
// return type is void
void printMap()
{
       // printing map
       printf("\n       ______18______\n");
       printf("      /      |       \\\n");
       printf("     /      _9__      \\\n");
       printf("    /      /    \\      \\\n");
       printf("   /      /      \\      \\\n");
       printf("  17     8        10     19\n");
       printf("  | \\   / \\      /  \\   / |\n");
       printf("  |  \\ /   \\    /    \\ /  |\n");
       printf("  |   7     1---2     11  |\n");
       printf("  |   |    /     \\    |   |\n");
       printf("  |   6----5     3---12   |\n");
       printf("  |   |     \\   /     |   |\n");
       printf("  |   \\       4      /    |\n");
       printf("  |    \\      |     /     |\n");
       printf("  \\     15---14---13     /\n");
       printf("   \\   /            \\   /\n");
       printf("    \\ /              \\ /\n");
       printf("    16---------------20\n\n");
} // end of function

// function setAdjacent(struct coordinate *data)
// takes struct coordinate as parameter
// sets the adjacent rooms of the struct coordinate
// return type is void
void setAdjacent(struct coordinate *data)
{
       // setting adjacent rooms

       // 1st room
       data[0].x = 2;
       data[0].y = 5;
       data[0].z = 8;

       // 2nd room
       data[1].x = 1;
       data[1].y = 3;
       data[1].z = 10;

       // 3rd room
       data[2].x = 2;
       data[2].y = 4;
       data[2].z = 12;

       // 4th room
       data[3].x = 3;
       data[3].y = 5;
       data[3].z = 14;

       // 5th room
       data[4].x = 1;
       data[4].y = 4;
       data[4].z = 6;

       // 6th room
       data[5].x = 5;
       data[5].y = 7;
       data[5].z = 15;

       // 7th room
       data[6].x = 6;
       data[6].y = 8;
       data[6].z = 17;

       // 8th room
       data[7].x = 1;
       data[7].y = 7;
       data[7].z = 9;

       // 9th room
       data[8].x = 8;
       data[8].y = 10;
       data[8].z = 19;

       // 10th room
       data[9].x = 2;
       data[9].y = 9;
       data[9].z = 11;

       // 11th room
       data[10].x = 10;
       data[10].y = 12;
       data[10].z = 19;

       // 12th room
       data[11].x = 3;
       data[11].y = 11;
       data[11].z = 13;

       // 13th room
       data[12].x = 12;
       data[12].y = 14;
       data[12].z = 20;

       // 14th room
       data[13].x = 4;
       data[13].y = 13;
       data[13].z = 15;

       // 15th room
       data[14].x = 6;
       data[14].y = 14;
       data[14].z = 16;

       // 16th room
       data[15].x = 15;
       data[15].y = 17;
       data[15].z = 20;

       // 17th room
       data[16].x = 7;
       data[16].y = 16;
       data[16].z = 18;

       // 18th room
       data[17].x = 9;
       data[17].y = 17;
       data[17].z = 19;

       // 19th room
       data[18].x = 11;
       data[18].y = 18;
       data[18].z = 20;

       // 20th room
       data[19].x = 13;
       data[19].y = 16;
       data[19].z = 19;
} // end of function
