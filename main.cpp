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
int playerHealth = 100;     //Health of player.
int aiHealth = 100;         //Health of computer.
int dmg = 0;                //Damage to apply if chance is successful.
int action = 0;             //Action that is used (move 1-5).
int lastAction = 0;         //Holds the last move that happened
int hitChance = 0;          // Holds total chance to hit the enemy.
int bonusChance = 0;        // Bonus chance to hit. Will be negative if enemy uses a counter.
float bonusDmg = 1;         // Multiplier for the damage dealt. 1 by default, 1.5 if using the amulet.
float r = 0;                // Holds the random number generated to use percent chance of doing an action.
bool playerAmuletUsed = 0;  // Holds if the amulet has already been used.
bool aiAmuletUsed = 0;      // ^^
bool gameOver = 0;          //Triggered when one of them die.
string turn = "player";     //Holds whose turn it is.

void game();
void standardMove();
void heavyMove();
void counterMove();
void defendMove();
void amuletMove();
void aiGame();
void aiStandardMove();
void aiHeavyMove();
void aiCounterMove();
void aiDefendMove();
void aiAmuletMove();

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

	do
	{
		scanf_s("%d", &menuresponse);
	} while (menuresponse != 1 || menureponse != 2 || menuresponse != 3);

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
			return 0;
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void game()
{
	do
	{
		if (playerHealth <= 0 || aiHealth <= 0)
		{
			gameOver = 1;
		}
		system("cls");
		printf("--------------------------------------------------------------------------------\n");
		printf("                                Immortal Kombat                                 \n");
		printf("--------------------------------------------------------------------------------\n\n");
		printf(" Player  Health: [%d]\n", playerHealth);
		printf("Computer Health: [%d]\n\n", aiHealth);
		printf("Enter your chosen move number.\n");
		scanf_s("%d", &action);
	
		if (turn == "player")
		{
			switch (action)
			{
				case 1:
				{
					standardMove();
				}
				case 2:
				{
					heavyMove();
				}
				case 3:
				{
					counterMove();
				}
				case 4:
				{
					defendMove();
				}
				case 5:
				{
					amuletMove();
				}
			}
		}
	} while (gameOver != 1);
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void standardMove()
{
	printf("You used a standard attack.\n");
	r = rand();
	hitChance = 0.8 + bonusChance;

	if (r <= hitChance)
	{
		dmg = 10 * bonusDmg;
		aiHealth -= dmg;
		turn = "ai";
		bonusChance = 0;
		bonusDmg = 1;
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
	aiGame();
	return;
}

void heavyMove()
{
	printf("You used a heavy attack.\n");
	r = rand();
	hitChance = 0.5 + bonusChance;

	if (r <= hitChance)
	{
		dmg = 20 * bonusDmg;
		aiHealth -= dmg;
		turn = "ai";
		bonusChance = 0;
		bonusDmg = 1;
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
	aiGame();
	return;
}

void counterMove()
{
	printf("You used a counter attack.\n");
	r = rand();
	hitChance = 0.65 + bonusChance;

	if (r <= hitChance)
	{
		dmg = 6 * bonusDmg;
		aiHealth -= dmg;
		turn = "ai";
		bonusChance = 0;
		bonusDmg = 1;
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
	aiGame();
	return;
}

void defendMove()
{
	if (playerHealth <= 95)
	{
		playerHealth += 5;
		bonusChance = -30;
		printf("You healed for 5 health points.\n");
	}
	else
	{
		printf("You cannot heal with %d health.\n", playerHealth);
	}
	printf("Press any key to continue.");
	_getch();
	aiGame();
	return;
}

void amuletMove()
{
	if (playerAmuletUsed == 0)
	{
		printf("You have already used your amulet.\n");
	}
	else
	{
		bonusDmg = 1.5;
		playerAmuletUsed = 1;
	}
	printf("Press any key to continue.");
	_getch();
	aiGame();
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void aiGame()
{
	printf("AI INITIALISED");
	
	switch (action)
		{
			case 1:
			{
				aiStandardMove();
			}
			case 2:
			{
				aiHeavyMove();
			}
			case 3:
			{
				aiCounterMove();
			}
			case 4:
			{
				aiDefendMove();
			}
			case 5:
			{
				aiAmuletMove();
			}
		}
	_getch();
	return;
}

void aiStandardMove()
{
	printf("The AI used a standard attack.\n");
	r = rand();
	hitChance = 0.8 + bonusChance;

	if (r <= hitChance)
	{
		dmg = 10 * bonusDmg;
		playerHealth -= dmg;
		turn = "ai";
		bonusChance = 0;
		bonusDmg = 1;
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
	aiGame();
	return;
}
