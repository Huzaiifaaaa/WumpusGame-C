//including all the header file required for the project
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//custom datastructure to store adjacent rooms for each room
struct coordinate{
    int x;
    int y;
    int z;
};

//implicit function declarations
void printMap();
void exitProgram();
void cheat(int data[]);
void printDirections();
int getRandomPosition();
void checkWin(int data[]);
void resetGame(int *data);
void setAdjacent(struct coordinate *data);

//main function
//driver function
//execution starts from here
//no parameters
//return type is int
//returns 0 on successful execution
int main()
{
    srand(time(0));//seeding the random number generator

    //declaring variables
    int movescount=1;
    int roomnumber=0;
    int coordinates[7]={0};
    struct coordinate adjacent[20];
    char message[]="You smell a stench.";

    for(int i=0;i<7;i++)//looping
    {
        coordinates[i]=getRandomPosition();//getting random positions for game elements
    }
    coordinates[6]=-1;//setting arrow position

    setAdjacent(&adjacent[0]);//calling function to set adjacent vertices

    while(1)//looping infinte times
    {
        //declaring variables
        int room=0;
        char command[4]={' ',' ',' ',' '};

        roomnumber=coordinates[5];//setting user room number
        
        printf("You are in room %d. ",roomnumber);//printing message
        if(movescount!=1)//printing hint message
        {
            printf("%s\n",message);//printing
        }

        printf("\n%d. Enter your move (or 'D' for directions): ",movescount);//asking for user input
        gets(command);//getting user input
        
        //parsing user command
        if(command[3]!=' ')
        {
            room=(int)command[3]-48;//char to int conversion
        }
        room+=(((int)command[2]-48)*10);//char to int conversion

        if(command[0]=='D' || command[0]=='d')//if directions command
        {
            printMap();//printing map
            printDirections();//printing directions
        }
        else if(command[0]=='C' || command[0]=='c')//if cheat command
        {
            cheat(coordinates);//calling cheat function
        }
        else if(command[0]=='G' || command[0]=='g')//if guess command
        {
            checkWin(coordinates);//calling checkWin function
        }
        else if(command[0]=='P'|| command[0]=='p')//if print command
        {
            printMap();//print the map
        }
        else if(command[0]=='M'|| command[0]=='m')//if move command
        {
            if(room>0 && room<21 && (adjacent[roomnumber-1].x==room || adjacent[roomnumber-1].y==room || adjacent[roomnumber-1].z==room))
            {
                coordinates[5]=room;

                //HERE
                //CHECK FOR WIMPUS
                //CHECK FOR PIT
                //CHECK FOR BATS

                movescount++;
            }
            else
            {
                printf("Invalid move. Please retry.\n\n");
            }
        }
        else if(command[0]=='R'|| command[0]=='r')//if reset command 
        {
            resetGame(&coordinates[0]);//call resetGame function
        }
        else if(command[0]=='X'|| command[0]=='x')//if exit comamand
        {
            exitProgram();//call exitProgram function
        }
        else//else if invalid command
        {
            printf("Invalid move. Please retry.");//print invalid move message
        }
    }//end of while loop

    return 0;//returning 0 on successful execution
}//end if main

//function resetGame(int *data)
//takes address to coordinates array as parameter
//sets the values as per user choice
//return type is void
void resetGame(int *data)
{
    int coordinates[7]={0};//declaring an array to store the coordinates
    int temp[20];//declaring an array to store the user input
    printf("Remember arrowRoom value of -1 means it is with the person.\n");//printing the message
    printf("Enter the 7 room locations (1..20) for person, pit1, pit2, bats1, bats2, Wumpus, and arrowRoom:\n");//printing the message
    scanf("%d %d %d %d %d %d %d",&coordinates[0],&coordinates[1],&coordinates[2],&coordinates[3],&coordinates[4],&coordinates[5],&coordinates[6],&coordinates[7]);//taking input from user

    for(int i=0;i<7;i++)//copying data 
    {
        data[i]=coordinates[i];
    }
}//end of function

//function checkWin(int data)
//takes array of coordinates as parameter
//takes user guess, compares with wumpus position, & decides win or lose
//return type is void
void checkWin(int data[])
{
    while(1)//infinite loop
    {
        int choice=0;//declaring choice as integer
        printf("Enter room (1..20) you think Wumpus is in: ");//printing message
        scanf("%d",&choice);//user input

        if(choice>0 && choice<21)//if choice is valid
        {
            if(choice==data[4])//comparing input with wumpus position
            {
                printf("You won!\n\n");//printing message
                exitProgram();//exit program
            }
            else
            {
                printf("You lost!\n\n");//printing message
                exitProgram();//exit program
            }
        }
        else//if choice is invalid
        {
            printf("Invalid move. Please retry.\n");//printing message
        }
    }
}//end of function

//function cheat(int data[])
//takes array of coordinates as parameter
//prints the values of the coordinates
//return type is void
void cheat(int data[])
{
    printf("Player   Wumpus   Bats1   Bats2   Pit1   Pit2   Arrow\n");//printing the header
    printf("  %d       %d       %d       %d      %d     %d     %d",data[5],data[4],data[0],data[1],data[2],data[3],data[6]);//printing the values
}//end of function

//function getRandomPosition()
//takes no parameter
//returns random number generated between 1 and 20
//return type is int
int getRandomPosition()
{
    int number=(rand() %(1 - 20 + 1)) + 1;//generates random number between 1 and 20
    return number;//returning number generated
}//end of function

//function exitProgram()
//takes no parameter
//exits the program
//return type is void
void exitProgram()
{
    printf("Exiting Program ...");//printing message
    exit(0);//exiting the program
}//end of function

//function printDirections()
//takes no parameter
//prints the directions/rules to the user
//return type is void
void printDirections()
{
    //printing rules & directions;
    printf("\n");

    printf("Hunt the Wumpus:\n");
    printf("The Wumpus lives in a completely dark cave of 20 rooms. Each\n");
    printf("room has 3 tunnels leading to other rooms.\n\n");

    printf("Hazards:\n");
    printf("1. Two rooms have bottomless pits in them.  If you go there you fall and die.\n");
    printf("2. Two other rooms have super-bats.  If you go there, the bats grab you and\n");
    printf("   fly you to some random room, which could be troublesome.  Then those bats go\n");
    printf("   to a new room different from where they came from and from the other bats.\n");
    printf("3. The Wumpus is not bothered by the pits or bats, as he has sucker feet and\n");
    printf("   is too heavy for bats to lift.  Usually he is asleep.  Two things wake\n");
    printf("   him up: Anytime you shoot an arrow, or you entering his room.  The Wumpus\n");
    printf("   will move into the lowest-numbered adjacent room anytime you shoot an arrow.\n");
    printf("   When you move into the Wumpus' room, then he wakes and moves if he is in an\n");
    printf("   odd-numbered room, but stays still otherwise.  After that, if he is in your\n");
    printf("   room, he snaps your neck and you die!\n\n");
    printf("Moves:\n");
    printf("On each move you can do the following, where input can be upper or lower-case:\n");
    printf("1. Move into an adjacent room.  To move enter 'M' followed by a space and\n");
    printf("   then a room number.\n");
    printf("2. Shoot your guided arrow through a list of up to three adjacent rooms, which\n");
    printf("   you specify.  Your arrow ends up in the final room.\n");
    printf("   To shoot enter 'S' followed by the number of rooms (1..3), and then the\n");
    printf("   list of the desired number (up to 3) of adjacent room numbers, separated\n");
    printf("   by spaces. If an arrow can't go a direction because there is no connecting\n");
    printf("   tunnel, it ricochets and moves to the lowest-numbered adjacent room and\n");
    printf("   continues doing this until it has traveled the designated number of rooms.\n");
    printf("   If the arrow hits the Wumpus, you win! If the arrow hits you, you lose. You\n");
    printf("   automatically pick up the arrow if you go through a room with the arrow in\n");
    printf("   it.\n");
    printf("3. Enter 'R' to reset the person and hazard locations, useful for testing.\n");
    printf("4. Enter 'C' to cheat and display current board positions.\n");
    printf("5. Enter 'D' to display this set of instructions.\n");
    printf("6. Enter 'P' to print the maze room layout.\n");
    printf("7. Enter 'X' to exit the game.\n\n");

    printf("Good luck!\n");

}//end of function

//function printMap()
//takes no parameter
//prints the map of the cave
//return type is void
void printMap()
{
    //printing map
    printf("           ______18______\n");
    printf("          /      |       \\\n");
    printf("         /      _9__      \\\n");
    printf("        /      /    \\      \\\n");
    printf("       /      /      \\      \\\n");
    printf("      17     8        10     19\n");
    printf("      | \\   / \\      /  \\   / |\n");
    printf("      |  \\ /   \\    /    \\ /  |\n");
    printf("      |   7     1---2     11  |\n");
    printf("      |   |    /     \\    |   |\n");
    printf("      |   6----5     3---12   |\n");
    printf("      |   |     \\   /     |   |\n");
    printf("      |   \\       4      /    |\n");
    printf("      |    \\      |     /     |\n");
    printf("      \\     15---14---13     /\n");
    printf("       \\   /            \\   /\n");
    printf("        \\ /              \\ /\n");
    printf("        16---------------20\n");
}//end of function

//function setAdjacent(struct coordinate *data)
//takes struct coordinate as parameter
//sets the adjacent rooms of the struct coordinate
//return type is void
void setAdjacent(struct coordinate *data)
{
    //setting adjacent rooms

    //1st room
    data[0].x=2;
    data[0].y=5;
    data[0].z=8;

    //2nd room
    data[1].x=1;
    data[1].y=3;
    data[1].z=10;

    //3rd room
    data[2].x=2;
    data[2].y=4;
    data[2].z=12;

    //4th room
    data[3].x=3;
    data[3].y=5;
    data[3].z=14;

    //5th room
    data[4].x=1;
    data[4].y=4;
    data[4].z=6;

    //6th room
    data[5].x=5;
    data[5].y=7;
    data[5].z=15;

    //7th room
    data[6].x=6;
    data[6].y=8;
    data[6].z=17;

    //8th room
    data[7].x=1;
    data[7].y=7;
    data[7].z=9;

    //9th room
    data[8].x=8;
    data[8].y=10;
    data[8].z=19;

    //10th room
    data[9].x=2;
    data[9].y=9;
    data[9].z=11;

    //11th room
    data[10].x=10;
    data[10].y=12;
    data[10].z=19;

    //12th room
    data[11].x=3;
    data[11].y=11;
    data[11].z=13;

    //13th room
    data[12].x=12;
    data[12].y=14;
    data[12].z=20;

    //14th room
    data[13].x=4;
    data[13].y=13;
    data[13].z=15;

    //15th room
    data[14].x=6;
    data[14].y=14;
    data[14].z=16;

    //16th room
    data[15].x=15;
    data[15].y=17;
    data[15].z=20;

    //17th room
    data[16].x=7;
    data[16].y=16;
    data[16].z=18;

    //18th room
    data[17].x=9;
    data[17].y=17;
    data[17].z=19;

    //19th room
    data[18].x=11;
    data[18].y=18;
    data[18].z=20;

    //20th room
    data[19].x=13;
    data[19].y=16;
    data[19].z=19;
}//end of function