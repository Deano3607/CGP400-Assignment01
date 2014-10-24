/*
Dean Leszman
CGP400
Assignment 01
*/
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std;

/*  CLEAR THE SCREEN BUT KEEP TITLE
system("cls");
printf("--------------------------------------------------------------------------------");
printf("\n                                Immortal Kombat                                 \n");
printf("--------------------------------------------------------------------------------");
*/

int main()
{
	int menuresponse = 0;

	system("cls");
	printf("--------------------------------------------------------------------------------\n");
	printf("                                Immortal Kombat                                 \n");
	printf("--------------------------------------------------------------------------------\n\n");
	printf("--- Main Menu ---\n");
	printf("1 - Play Game\n");
	printf("2 - View Instructions\n");
	printf("3 - Quit Game\n\n");

	/*do
	{
		menuresponse = _getch();
	} while ((menuresponse != '49' || menuresponse != '50' || menuresponse != '51'));
	*/
	
	scanf_s("%d", &menuresponse);

	switch (menuresponse)
	{
		case 1:
		{
			int game();
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
			printf("A standard attack has an 80%% chance to deal 10 hitpoints of damage to \nyour opponent.\n\n");

			printf("[2] Heavy Attack\n");
			printf("----------------\n");
			printf("Move 2 will perform a heavy attack.\n");
			printf("A heavy attack has a 50%% chance to deal 20 hitpoints of damage to your \nopponent.\n\n");

			printf("[3] Counter Attack\n");
			printf("------------------\n");
			printf("Move 3 will perform a counter attack.\n");
			printf("A counter attack will allow your opponent to attack first. It has a 65%% \nchance to deal 6 hitpoints of damage to your opponent after they attack you.\n\n");

			printf("[4] Defend\n");
			printf("----------\n");
			printf("Move 4 will perform a defensive action.\n");
			printf("A defensive move will heal your character for 6hp and force the opponents next \nmove to have 30 percent reduced hit chance.\n\n");

			printf("[5] Amulet\n");
			printf("----------\n");
			printf("Move 5 will use a one-time-only amulet.\n");
			printf("The amulet will boost your attack damage by 50%%.\nYou can attack in the same turn after using the amulet.\n\n\n");
			printf("Press any key to return to the main menu.");
			_getch();
			main();
		}
		case 3:
		{
			return 0;
		}
		default:
		{
			main();
		}
	}
}

int game()
{
	system("cls");
	printf("--------------------------------------------------------------------------------\n");
	printf("                                Immortal Kombat                                 \n");
	printf("--------------------------------------------------------------------------------\n\n");
	_getch();
	return 0;
}

void instructions () //Displays instructions to user when called
{
	system("cls");
	printf("--------------------------------------------------------------------------------\n");
	printf("                                Immortal Kombat                                 \n");
	printf("                                 Instructions                                   \n");
	printf("--------------------------------------------------------------------------------\n\n");

	printf("Immortal Kombat is a turn-based fighting game.\n");
	printf("You and your opponent take turns in using one of five moves explained below.\n\n");

	printf("--- Standard Attack\n");
	printf("Move 1 will perform a standard attack.\n");
	printf("A standard attack has an 80 percent chance to deal 10 hitpoints of damage to \nyour opponent.\n\n");

	printf("--- Heavy Attack\n");
	printf("Move 2 will perform a heavy attack.\n");
	printf("A heavy attack has a 50 percent chance to deal 20 hitpoints of damage to your \nopponent.\n\n");

	printf("--- Counter Attack\n");
	printf("Move 3 will perform a counter attack.\n");
	printf("A counter attack will allow your opponent to attack first. It has a 65 percent \nchance to deal 6 hitpoints of damage to your opponent after they attack you.\n\n");

	printf("--- Defend\n");
	printf("Move 4 will perform a defensive action.\n");
	printf("A defensive move will heal your character for 6hp and force the opponents next \nmove to have 30 percent reduced hit chance.\n\n");

	printf("--- Amulet\n");
	printf("Move 5 will use a one-time-only amulet.\n");
	printf("The amulet will boost your attack damage by 50 percent.\nYou can attack in the same turn after using the amulet.\n\n");
	_getch();
}
