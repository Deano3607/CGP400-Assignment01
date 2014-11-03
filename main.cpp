/*
Dean Leszman
CGP400
Assignment 01
*/

#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

// Variable declarations
int playerhealth = 100;     //Health of player.
int aihealth = 100;         //Health of computer.
int dmg = 0;                //Damage to apply if chance is successful.
int action = 0;             //Action that is used (move 1-5).
int lastaction = 0;         //Holds the last move that happened
int hitchance = 0;          // Holds total chance to hit the enemy.
int bonuschance = 0;        // Bonus chance to hit. Will be negative if enemy uses a counter.
float bonusdmg = 1;         // Multiplier for the damage dealt. 1 by default, 1.5 if using the amulet.
float r = 0;                // Holds the random number generated to use percent chance of doing an action.
bool playeramuletused = 0;  // Holds if the amulet has already been used.
bool aiamuletused = 0;      // ^^
bool gameover = 0;          //Triggered when one of them die.
string turn = "player";     //Holds whose turn it is.

void game();
void move1();
void move2();
void move3();
void move4();
void move5();
void aigame();
void aimove1();
void aimove2();
void aimove3();
void aimove4();
void aimove5();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int menuresponse = 0;

	srand(time(NULL));
	SetConsoleTitle("Immortal Kombat");
	system("cls");
	printf("--------------------------------------------------------------------------------\n");
	printf("                                Immortal Kombat                                 \n");
	printf("--------------------------------------------------------------------------------\n\n");
	printf("--- Main Menu ---\n");
	printf("1 - Play Game\n");
	printf("2 - View Instructions\n");
	printf("3 - Quit Game\n\n");

	scanf_s("%d", &menuresponse);

	switch (menuresponse)
	{
		case 3:
		{
			return 0;
		}
		case 2:
		{
			system("cls");
			printf("--------------------------------------------------------------------------------\n");
			printf("                                Immortal Kombat                                 \n");
			printf("                                 Instructions                                   \n");
			printf("--------------------------------------------------------------------------------\n\n");

			printf("Immortal Kombat is a turn-based fighting game.\n");
			printf("You and your opponent take turns in using one of five moves explained below.\n");
			printf("The last man standing wins the game.\n\n\n");

			printf("[1] Standard Attack\n");
			printf("-------------------\n");
			printf("Move 1 will perform a standard attack.\n");
			printf("A standard attack has an 80%% chance to deal 10 points of damage to \nyour opponent.\n\n");

			printf("[2] Heavy Attack\n");
			printf("----------------\n");
			printf("Move 2 will perform a heavy attack.\n");
			printf("A heavy attack has a 50%% chance to deal 20 points of damage to your \nopponent.\n\n");

			printf("[3] Counter Attack\n");
			printf("------------------\n");
			printf("Move 3 will perform a counter attack.\n");
			printf("A counter attack will allow your opponent to attack first. It has a 65%% \nchance to deal 6 points of damage to your opponent after they attack you.\n\n");

			printf("[4] Defend\n");
			printf("----------\n");
			printf("Move 4 will perform a defensive action.\n");
			printf("A defensive move will heal your character for 6 points and force the opponents next \nmove to have 30%% reduced hit chance.\n\n");

			printf("[5] Amulet\n");
			printf("----------\n");
			printf("Move 5 will use a one-time-only amulet.\n");
			printf("The amulet will boost your attack damage by 50%%.\nYou can attack in the same turn after using the amulet.\n\n\n");
			printf("Press any key to return to the main menu.");
			_getch();
			main();
		}
		case 1:
		{
			game();
		}
		default:
		{
			main();
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void game()
{
	if (playerhealth <= 0 || aihealth <= 0)
	{
		gameover = 0;
	}
	system("cls");
	printf("--------------------------------------------------------------------------------\n");
	printf("                                Immortal Kombat                                 \n");
	printf("--------------------------------------------------------------------------------\n\n");
	printf(" Player  Health: [%d]\n", playerhealth);
	printf("Computer Health: [%d]\n\n", aihealth);
	printf("Enter your chosen move number.\n");
	scanf_s("%d", &action);

	if (turn == "player")
	{
		switch (action)
		{
			case 1:
			{
				move1();
			}
			case 2:
			{
				move2();
			}
			case 3:
			{
				move3();
			}
			case 4:
			{
				move4();
			}
			case 5:
			{
				move5();
			}
		}
	}
	main();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void move1()
{
	printf("You used a normal attack.\n");
	r = rand();
	hitchance = 0.8 + bonuschance;

	if (r <= hitchance)
	{
		dmg = 10 * bonusdmg;
		aihealth -= dmg;
		turn = "ai";
		bonuschance = 0;
		bonusdmg = 1;
		Sleep(2000);
		printf("You dealt %d damage to the enemy.\n", dmg);
	}
	else
	{
		Sleep(2000);
		printf("Your attack missed the enemy!\n");
	}
	printf("Press any key to continue.");
	_getch();
	aigame();
}

void move2()
{
	printf("You used a heavy attack.\n");
	r = rand();
	hitchance = 0.5 + bonuschance;

	if (r <= hitchance)
	{
		dmg = 20 * bonusdmg;
		aihealth -= dmg;
		turn = "ai";
		bonuschance = 0;
		bonusdmg = 1;
		Sleep(2000);
		printf("You dealt %d damage to the enemy.\n", dmg);
	}
	else
	{
		Sleep(2000);
		printf("Your attack missed the enemy!\n");
	}
	printf("Press any key to continue.");
	_getch();
	aigame();
}

void move3()
{
	printf("You used a counter attack.\n");
	r = rand();
	hitchance = 0.65 + bonuschance;

	if (r <= hitchance)
	{
		dmg = 6 * bonusdmg;
		aihealth -= dmg;
		turn = "ai";
		bonuschance = 0;
		bonusdmg = 1;
		Sleep(2000);
		printf("You dealt %d damage to the enemy.\n", dmg);
	}
	else
	{
		Sleep(2000);
		printf("You failed to counter the enemy attack.\n");
	}
	printf("Press any key to continue.");
	_getch();
	aigame();
}

void move4()
{
	if (playerhealth <= 95)
	{
		playerhealth += 5;
		bonuschance = -30;
		printf("You healed for 5 health points.\n");
	}
	else
	{
		printf("You cannot heal with %d health.\n", playerhealth);
	}
	printf("Press any key to continue.");
	_getch();
	aigame();
}

void move5()
{
	if (playeramuletused == 0)
	{
		printf("You have already used your amulet.\n");
	}
	else
	{
		bonusdmg = 1.5;
		playeramuletused = 1;
	}
	printf("Press any key to continue.");
	_getch();
	aigame();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void aigame()
{
	printf("AI INITIALISED");
	_getch();
}
