//including all the header file required for the project
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

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

int main()
{
    srand(time(0));

    int movescount=1;
    int roomnumber=0;
    int coordinates[7]={0};
    struct coordinate adjacent[20];
    char message[]="You smell a stench.";

    for(int i=0;i<7;i++)
    {
        coordinates[i]=getRandomPosition();
    }
    coordinates[6]=-1;

    setAdjacent(&adjacent[0]);

    while(1)
    {
        int room=0;
        char command[4]={' ',' ',' ',' '};

        roomnumber=coordinates[5];
        
        printf("You are in room %d. ",roomnumber);
        if(movescount!=1)
        {
            printf("%s\n",message);
        }

        printf("\n%d. Enter your move (or 'D' for directions): ",movescount);
        gets(command);
        
        if(command[3]!=' ')
        {
            room=(int)command[3]-48;
        }
        room+=(((int)command[2]-48)*10);

        if(command[0]=='D' || command[0]=='d')
        {
            printMap();
            printDirections();
        }
        else if(command[0]=='C' || command[0]=='c')
        {
            cheat(coordinates);
        }
        else if(command[0]=='G' || command[0]=='g')
        {
            checkWin(coordinates);
        }
        else if(command[0]=='P'|| command[0]=='p')
        {
            printMap();
        }
        else if(command[0]=='M'|| command[0]=='m')
        {
            if(room>0 && room<21 && (adjacent[roomnumber-1].x==room || adjacent[roomnumber-1].y==room || adjacent[roomnumber-1].z==room))
            {
                coordinates[5]=room;
                movescount++;
            }
            else
            {
                printf("Invalid move. Please retry.\n\n");
            }
        }
        else if(command[0]=='R'|| command[0]=='r')
        {
            resetGame(&coordinates[0]);
        }
        else if(command[0]=='X'|| command[0]=='x')
        {
            exitProgram();
        }
        else
        {
            printf("Invalid move. Please retry.");
        }
    }

    return 0;
}

void resetGame(int *data)
{
    int coordinates[7]={0};
    char temp[20];
    printf("Remember arrowRoom value of -1 means it is with the person.\n");
    printf("Enter the 7 room locations (1..20) for person, pit1, pit2, bats1, bats2, Wumpus, and arrowRoom:\n");
    scanf("%d %d %d %d %d %d %d",&coordinates[0],&coordinates[1],&coordinates[2],&coordinates[3],&coordinates[4],&coordinates[5],&coordinates[6],&coordinates[7]);

    for(int i=0;i<7;i++)
    {
        data[i]=coordinates[i];
    }
}

void checkWin(int data[])
{
    while(1)
    {
        int choice=0;
        printf("Enter room (1..20) you think Wumpus is in: ");
        scanf("%d",&choice);

        if(choice>0 && choice<21)
        {
            if(choice==data[4])
            {
                printf("You won!\n\n");
                exitProgram();
            }
            else
            {
                printf("You lost!\n\n");
                exitProgram();
            }
        }
        else
        {
            printf("Invalid move. Please retry.\n");
        }
    }
}

void cheat(int data[])
{
    printf("Cheating! Game elements are in the following rooms: \n");
    printf("Player   Wumpus   Bats1   Bats2   Pit1   Pit2   Arrow\n");
    printf("  %d       %d       %d       %d      %d     %d     %d",data[5],data[4],data[0],data[1],data[2],data[3],data[6]);
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

void setAdjacent(struct coordinate *data)
{

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
}