/************************************************
 * @File	logic.c				*
 * @Version	1.0.0				*
 * @Brief	Logic of the tictactoe game	*
 * @Author	Omar Sameh			*
 ************************************************/

/* Linking section */
/*-----------------*/
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

/* Definition section */
/*--------------------*/
#define ROW 3
#define COLUMN 3

/* Global variable section */
/*-------------------------*/
char inputCounter = -1;
unsigned char XO = 'X';
static unsigned char board[ROW][COLUMN];

/* Subprogram section */
/*--------------------*/

static void 
printBoard(void)
{
	unsigned char iterator = 0;
	unsigned char counter = 0;
	unsigned char asciiOfNum1 = 49;
	if(-1 == inputCounter)
	{
	puts("Starting the game...\n");
	}
	while(inputCounter == -1)
	{
		for(iterator = 0; iterator < ROW; iterator++)
		{
			for(counter = 0; counter < COLUMN; counter++)
			{
				board[iterator][counter] = asciiOfNum1++;
			}
		}
		inputCounter++;
	}
	for(iterator = 0; iterator < ROW; iterator++)
	{
		for(counter = 0; counter < COLUMN; counter++)
		{
			printf("  %c  ",(*(*(board+iterator)+counter)));
			if(counter < 2)
			{
				printf("|");
			}
		}
		if(iterator < 2)
		{
			printf("\n-----|-----|-----\n");
		}
	}
	puts("\n");
}

static unsigned char
switchPlayer(void)
{
	if('X' == XO)
	{
		XO = 'O';
	}
	else
	{
		XO = 'X';
	}
	return (XO);
}

static void takeInput(unsigned char playerMove)
{
    unsigned char row = 0;
    unsigned char column = 0;
    unsigned int choice = 1;
    do
    {
        if (choice > 9 || choice < 1)
        {
            puts("Invalid choice!!");
        }
        
        printf("Player %c, it is your turn:\n", playerMove);
        printf("Enter a number (1-9): ");
        scanf("%d", &choice);
        printf("\n");

        row = (choice - 1) / 3;
        column = (choice - 1) % 3;
    } 
    while (choice > 9 || choice < 1 || board[row][column] == 'X' || board[row][column] == 'O');

    board[row][column] = playerMove;
    inputCounter++;
}

static void
quitOption()
{
	puts("Exiting the game...");
	exit(0);
}

static void
startOption(void)
{
	unsigned char playerMove = 0;
	unsigned char quit = 'p';
	unsigned char win = 0;
	inputCounter = -1;
	while(inputCounter <= 9)
	{
	do
	{
		printBoard();
		playerMove = switchPlayer();
		takeInput(playerMove);

		if(inputCounter >= 5)
		{
			win = checkWin();
			switch(win)
			{
				case 'X':
					printBoard();
					puts("Player X Won!!, horaaay");
					break;
				case 'O':
					printBoard();
					puts("Player O Won!!, horaaay");
					break;
				case 'T':
					printBoard();
					puts("It is a tie");
					break;
			}
			if('O' == win || 'X' == win || 'T' == win)
			{
				printf("Do you want to play again or quit the game(p-q):");
				do
				{	
					if(quit != 'p' && quit != 'q')
					{
						printf("Invaild input!! Enter p to play again or q to quit the game:");
					}
					scanf(" %c",&quit);
					
					if('q' == quit)
					{
						quitOption();
					}
					else if('p' == quit)
					{
						startOption();
					}
					else
					{
					}

				}
				while(quit != 'p' && quit != 'q');
			}
		}
	}
	while(quit != 'q');
	
	}
}
static void
helpOption()
{
	puts("=== Help section ===");
	puts("1. The game is played on a 3x3 grid.");
	puts("2. Player 1 is O, Player 2 is X.");
	puts("3. The first player to align 3 symbols wins.");
	puts("4. Players take turns to place their symbols.");
	puts("Press Enter to return to the main menu.");
	getchar();
	getchar();
}

static void
creditsOption()
{
	puts("=== Credits section ===");
	puts("Developed by: Omar Sameh");
	puts("Thank you for playing!");
	puts("Press Enter to return to the main menu.");
	getchar();
	getchar();
}

static void
startDisplayOptions(void)
{
	puts("1. Start");
	puts("2. Help");
	puts("3. Credits");
	puts("4. Quit");
}

void
selectOption(void)
{
	while(1)
	{
		inputCounter = -1;
		startDisplayOptions();
		unsigned char option = 1;
		do
		{
			if(option > 4 || option < 1)
			{
				puts("Invalid input, try again!!");
			}
			else
			{
			}
			printf("Select number from the options:");
			scanf("%d",&option);
		}
		while(option > 4 || option < 1);
	
		switch(option)
		{
			case 1:
				startOption();
				break;
			case 2:
				helpOption();
				break;
			case 3:
				creditsOption();
				break;
			case 4:
				quitOption();
				break;
			default:
				puts("It should be impossiple to get here");
		}
	}	
}


unsigned char
checkWin(void)
{
	unsigned char win = 0;
	unsigned char row = 0;
	unsigned char column = 0;
	// Horizontal lines check
	if(board[row][column] == board[row][column+1] && board[row][column] == board[row][column+2])
	{
		win = board[row][column];
	}
	else if(board[row+1][column] == board[row+1][column+1] && board[row+1][column] == board[row+1][column+2])
	{
		win = board[row+1][column];
	}
	else if(board[row+2][column] == board[row+2][column+1] && board[row+2][column] == board[row+2][column+2])
	{
		win = board[row+2][column];
	}
	// Vertical lines check
	else if(board[row][column] == board[row+1][column] && board[row][column] == board[row+2][column])
	{
		win = board[row][column];
	}
	else if(board[row][column+1] == board[row+1][column+1] && board[row][column+1] == board[row+2][column+1])
	{
		win = board[row][column+1];
	}
	else if(board[row][column+2] == board[row+1][column+2] && board[row][column+2] == board[row+2][column+2])
	{
		win = board[row][column+2];
	}
	// Diagonal lines check
	else if(board[row][column] == board[row+1][column+1] && board[row][column] == board[row+2][column+2])
	{
		win = board[row][column];
	}
	else if(board[row+2][column] == board[row+1][column+1] && board[row+2][column] == board[row][column+2])
	{
		win = board[row+2][column];
	}
	else if(9 == inputCounter)
	{
		win = 'T';
	}

	return (win);
}
