//including all the header file required for the project
#include <stdio.h>
#include<time.h>

//implicit function declarations
void printMap();
void exitProgram();
void cheat(int data[]);
void printDirections();
int getRandomPosition();


int main()
{
    srand(time(0));

    int movescount=1;
    int roomnumber=0;
    char command;
    char message[]="You smell a stench.";

    //0       1      2     3     4      5
    //bats1, bats2, pit1, pit2, Wumpus, person
    int coordinates[7]={0};

    //DUBLICATE POSITIONS
    for(int i=0;i<7;i++)
    {
        coordinates[i]=getRandomPosition();
    }
    roomnumber=coordinates[5];
    coordinates[6]=-1;

    while(1)
    {
        printf("You are in room %d. ",roomnumber);
        if(movescount!=1)
        {
            printf("%s\n",message);
        }

        printf("\n\n%d. Enter your move (or 'D' for directions): ",movescount);
        scanf("%c",&command);

        if(command=='D' || command=='d')
        {
            printDirections();
        }
        else if(command=='C' || command=='c')
        {
            cheat(coordinates);
        }
        else if(command=='G' || command=='g')
        {
            //HERE
        }
        else if(command=='P'|| command=='p')
        {
            printMap();
        }
        else if(command=='M'|| command=='m')
        {
            //HERE
            movescount++;
        }
        else if(command=='R'|| command=='r')
        {
            //HERE
        }
        else if(command=='X'|| command=='x')
        {
            exitProgram();
        }

        printf("\n\n");
        getchar();
    }

    return 0;
}

void cheat(int data[])
{
    printf("Cheating! Game elements are in the following rooms: \n");
    printf("Player Wumpus Pit1 Pit2\n");
    printf("  %d     %d     %d     %d",data[5],data[4],data[2],data[3]);
}

int getRandomPosition()
{
    int number=(rand() %(1 - 20 + 1)) + 1;
    return number;
}

void exitProgram()
{
    printf("Exiting Program ...");
    exit(0);
}

void printDirections()
{
    printMap();
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

}

void printMap()
{
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
}
