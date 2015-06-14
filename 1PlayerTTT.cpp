#include <iostream>
#include <cstdlib>
#include <ctime>
#include "1PlayerTTT.h"
// source code for one player to play aginst a computer
using namespace std;
using namespace TTT_EX2;

//initialize the private variable spacetaken
tictactoeOvC::tictactoeOvC()
{
	spacetaken = 0;
}

//the function that will initiate the game with one player vs a computer
void tictactoeOvC::playTheGameComputer(char spaceNum[])
{
	int desiredSpace;	// will hold the space number that the player whats to place his  mark
	int winDraw;	// will hold the number that will indicate if there is a win or a draw
	int smartStart = 0;
	srand(time(0));

	cout << "You will be Player X" << endl << "Computer will be Player O" << endl;

	while (spacetaken != 9)
	{
		desiredSpace = 0;
		theBoard(spaceNum);	// Player turn to go
		cout << "Player X Please enter a space number to place X in (1-9): ";
		cin >> desiredSpace;
		while (desiredSpace <= 0 || desiredSpace > 9)
		{
			cout << "The space number Player X provided is not an option" << endl
				<< "Please enter a space number to place X in (1-9): ";
			cin >> desiredSpace;

		}

		desiredSpace--;
		cout << endl;
		spacetaken++;

		

		//checks to see if the space the user entered is already occupied
		while ((spaceNum[desiredSpace] == 'X') || (spaceNum[desiredSpace] == 'O'))
		{
			cout << "The space number Player X provided is already occupied" << endl
				<< "Please enter another number that isn't occupied: ";
			cin >> desiredSpace;
			desiredSpace--;
		}

		spaceNum[desiredSpace] = 'X';
		
		winDraw = winnerXorO(spaceNum);

		if ((winDraw == 1) || (winDraw == 2))
		{
			if (winDraw == 1)
			{
				theBoard(spaceNum);
				cout << "Player X Wins the game" << endl;
			}
			else
			{
				theBoard(spaceNum);
				cout << "The game is a draw" << endl;
			}
			spacetaken = 9;
		}
		else
		{

			if (spacetaken > 2)
			{
				desiredSpace = smartComputer(spaceNum);	// checks to see if the player could possibly win, and blocks them if they are
				smartStart = 1;
			}

			if (desiredSpace == 9 || smartStart == 0) // if smartComputer() returns a 9, then player isn't going to win, and we can use a random digit
			{ 
				desiredSpace = rand() % (9 - 1) + 1;	// computer comes up with a random number
				while ((spaceNum[desiredSpace] == 'X') || (spaceNum[desiredSpace] == 'O'))
				{	// if that random number is already occupied, then a new random will be provided until a non-occupied space appears
					desiredSpace = rand() % rand() % (9 - 1) + 1;
				}
			}

			smartStart = 0;
			
			spaceNum[desiredSpace] = 'O';
			spacetaken++;
			winDraw = winnerXorO(spaceNum);

			if ((winDraw == 1) || (winDraw == 2))
			{
				if (winDraw == 1)
				{
					theBoard(spaceNum);
					cout << "Computer Wins the game" << endl;
				}
				else
				{
					theBoard(spaceNum);
					cout << "The game is a draw" << endl;
				}
				spacetaken = 9;
			}

		}
	}

}


// will display the current board to the players
void tictactoeOvC::theBoard(char spaceNum[])
{
	for (int i = 0; i <= 8; i++)
	{

		if (i == 2 || i == 5 || i == 8)
		{
			cout << "(" << spaceNum[i] << ')' << endl;
			if (i == 8)
			{

			}
			else
				cout << "			-----------" << endl;
		}
		else
		{
			if (i == 1 || i == 4 || i == 7)
			{
				cout << '(' << spaceNum[i] << ')' << '|';
			}
			else
				cout << "			(" << spaceNum[i] << ')' << '|';
		}
	}
	cout << endl;
}

int tictactoeOvC::smartComputer(char spaceNum[])
{
	//possibility #1
	if ((spaceNum[0] == 'X') || (spaceNum[1] == 'X') || (spaceNum[2] == 'X'))
	{	// if 'X' is in any of the three places then the program will check to see if there is a possible win for the player
		if (spaceNum[0] == spaceNum[1])
		{	// checks the first 2 spots to see if they are the same
			if (spaceNum[2] == 'O' || spaceNum[2] == 'X')
			{ }	// checks to see if the program already blocked this possible win previously
			else
				return 2;	// else return a 2, so that the computer may block the player possible win
		}
		else if (spaceNum[1] == spaceNum[2])
		{	// checks the middle and the last spot to see if there is a possible win
			if (spaceNum[0] == 'O' || spaceNum[0] == 'X')
			{ }	// checks to see if the program already blocked this possible win previously
			else
				return 0;	// else return a 0, so that the computer may block the player possible win
		}
		else if (spaceNum[0] == spaceNum[2])
		{	// checks the first and last spot to see if there is a possible win
			if (spaceNum[1] == 'O' || spaceNum[1] == 'X')
			{ }	// checks to see if the program already blocked this possible win previously
			else
				return 1;	// else return a 1, so that the computer may block the player possible win
		}
	}

	//possibility #2
	if ((spaceNum[3] == 'X') || (spaceNum[4] == 'X') || (spaceNum[5] == 'X'))
	{
		if (spaceNum[3] == spaceNum[4])
		{
			if (spaceNum[5] == 'O' || spaceNum[5] == 'X')
			{}
			else
				return 5;
		}
		else if (spaceNum[4] == spaceNum[5])
		{
			if (spaceNum[3] == 'O' || spaceNum[3] == 'X')
			{}
			else
			return 3;
		}
		else if (spaceNum[3] == spaceNum[5])
		{
			if (spaceNum[4] == 'O' || spaceNum[4] == 'X')
			{}
			else
			return 4;
		}
	}

	//possibility #3
	if ((spaceNum[6] == 'X') || (spaceNum[7] == 'X') || (spaceNum[8] == 'X'))
	{
		if (spaceNum[6] == spaceNum[7])
		{
			if (spaceNum[8] == 'O' || spaceNum[8] == 'X')
			{}
			else
				return 8;
		}
		else if (spaceNum[7] == spaceNum[8])
		{
			if (spaceNum[6] == 'O' || spaceNum[6] == 'X')
			{}
			else
				return 6;
		}
		else if (spaceNum[6] == spaceNum[8])
		{
			if (spaceNum[7] == 'O' || spaceNum[7] == 'X')
			{
			}
			else
				return 7;
		}
	}

	//possibility #4
	if ((spaceNum[0] == 'X') || (spaceNum[4] == 'X') || (spaceNum[8] == 'X'))
	{
		if (spaceNum[0] == spaceNum[4])
		{
			if (spaceNum[8] == 'O' || spaceNum[8] == 'X')
			{}
			else
				return 8;
		}
		else if (spaceNum[4] == spaceNum[8])
		{
			if (spaceNum[0] == 'O' || spaceNum[0] == 'X')
			{}
			else
				return 0;
		}
		else if (spaceNum[0] == spaceNum[8])
		{
			if (spaceNum[4] == 'O' || spaceNum[4] == 'X')
			{}
			else
				return 4;
		}
	}

	//possibility #5
	if ((spaceNum[2] == 'X') || (spaceNum[4] == 'X') || (spaceNum[6] == 'X'))
	{
		if (spaceNum[2] == spaceNum[4])
		{
			if (spaceNum[6] == 'O' || spaceNum[6] == 'X')
			{}
			else
				return 6;
		}
		else if (spaceNum[4] == spaceNum[6])
		{
			if (spaceNum[2] == 'O' || spaceNum[2] == 'X')
			{}
			else
				return 2;
		}
		else if (spaceNum[2] == spaceNum[6])
		{
			if (spaceNum[4] == 'O' || spaceNum[4] == 'X')
			{}
			else
				return 4;
		}
	}

	//possibility #6
	if ((spaceNum[0] == 'X') || (spaceNum[3] == 'X') || (spaceNum[6] == 'X'))
	{
		if (spaceNum[0] == spaceNum[3])
		{
			if (spaceNum[6] == 'O' || spaceNum[6] == 'X')
			{}
			else
				return 6;
		}
		else if (spaceNum[3] == spaceNum[6])
		{
			if (spaceNum[0] == 'O' || spaceNum[0] == 'X')
			{}
			else
				return 0;
		}
		else if (spaceNum[0] == spaceNum[6])
		{
			if (spaceNum[3] == 'O' || spaceNum[3] == 'X')
			{}
			else
				return 3;
		}
	}

	//possibility #7
	if ((spaceNum[1] == 'X') || (spaceNum[4] == 'X') || (spaceNum[7] == 'X'))
	{
		if (spaceNum[1] == spaceNum[4])
		{
			if (spaceNum[7] == 'O' || spaceNum[7] == 'X')
			{}
			else
				return 7;
		}
		else if (spaceNum[4] == spaceNum[7])
		{
			if (spaceNum[1] == 'O' || spaceNum[1] == 'X')
			{}
			else
				return 1;
		}
		else if (spaceNum[1] == spaceNum[7])
		{
			if (spaceNum[4] == 'O' || spaceNum[4] == 'X')
			{}
			else
				return 4;
		}
	}

	//possibility #8
	if ((spaceNum[2] == 'X') || (spaceNum[5] == 'X') || (spaceNum[8] == 'X'))
	{
		if (spaceNum[2] == spaceNum[5])
		{
			if (spaceNum[8] == 'O' || spaceNum[8] == 'X')
			{}
			else
				return 8;
		}
		else if (spaceNum[5] == spaceNum[8])
		{
			if (spaceNum[2] == 'O' || spaceNum[2] == 'X')
			{}
			else
				return 2;
		}
		else if (spaceNum[2] == spaceNum[8])
		{
			if (spaceNum[5] == 'O' || spaceNum[5] == 'X')
			{}
			else
				return 5;
		}
	}
	return 9;// if all the statement above didn't return anything then a 9 will be return
}

int tictactoeOvC::winnerXorO(char spaceNum[])
{// there are only 8 possible ways to win tic tac toe
	if ((spaceNum[0] == spaceNum[1]) && (spaceNum[1] == spaceNum[2])) //possibility #1
	{	// there is a winner in the first row
		return 1;
	}
	else if ((spaceNum[3] == spaceNum[4]) && (spaceNum[4] == spaceNum[5]))//possibility #2
	{	// there is a winnder in the second row

		return 1;
	}
	else if ((spaceNum[6] == spaceNum[7]) && (spaceNum[7] == spaceNum[8]))//possibility #3
	{	// there is a winner in the third row
		return 1;
	}
	else if ((spaceNum[0] == spaceNum[4]) && (spaceNum[4] == spaceNum[8]))//possibility #4
	{	// there is a winner in the 
		return 1;
	}
	else if ((spaceNum[2] == spaceNum[4]) && (spaceNum[4] == spaceNum[6]))//possibility #5
	{	// there is a winner in the /
		return 1;
	}
	else if ((spaceNum[0] == spaceNum[3]) && (spaceNum[3] == spaceNum[6]))//possibility #6
	{	// there is a winner in the first column
		return 1;
	}
	else if ((spaceNum[1] == spaceNum[4]) && (spaceNum[4] == spaceNum[7]))//possibility #7
	{	// there is a winner in the second column
		return 1;
	}
	else if ((spaceNum[2] == spaceNum[5]) && (spaceNum[5] == spaceNum[8]))//possibility #8
	{	// there is a winner in the third column
		return 1;
	}
	else if (spacetaken == 9)
	{	// all the 9 spaces are taken ;therefore, its a draw
		return 2;
	}
	else
	{	// there is no winner and all the space arn't taken yet, so winner yet
		return 0;
	}
}
