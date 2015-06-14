#include <iostream>
#include "2PlayerTTT.h"
//source code for one player to play aginst another player
using namespace std;
using namespace TTT_EX;


tictactoeOvO::tictactoeOvO()
{
	spacetaken = 0;
}

void tictactoeOvO::playTheGame(char spaceNum[])
{
	int desiredSpace;
	int winDraw;

	while ((spacetaken != 9))
	{

		theBoard(spaceNum);	// Player X turn to go
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
			theBoard(spaceNum);	// player O turn to go
			cout << "Player O Please enter a space number to place O in (1-9): ";
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

			// checks to see if the space the user entered is already occupied 
			while ((spaceNum[desiredSpace] == 'X') || (spaceNum[desiredSpace] == 'O'))
			{
				cout << "The space number Player O provided is already occupied" << endl
					<< "Please enter another number that isn't occupied: ";
				cin >> desiredSpace;
				desiredSpace--;
			}

			spaceNum[desiredSpace] = 'O';
			winDraw = winnerXorO(spaceNum);
			
			
			if ((winDraw == 1) || (winDraw == 2))
			{
				if (winDraw == 1)
				{
					theBoard(spaceNum);
					cout << "Player O Wins the game" << endl;
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
void tictactoeOvO::theBoard(char spaceNum[])
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
			cout << "			(" <<spaceNum[i] << ')' << '|';
		}
	}
	cout << endl;
}

// will return a 1 if there is a winner & 0 if there is no winner yet & 2 if it's a draw
int tictactoeOvO::winnerXorO(char spaceNum[])
{
	if ((spaceNum[0] == spaceNum[1]) && (spaceNum[1] == spaceNum[2]))
	{	// there is a winner in the first row
			return 1;
	}
	else if ((spaceNum[3] == spaceNum[4]) && (spaceNum[4] == spaceNum[5]))
	{	// there is a winnder in the second row
	
		return 1;
	}
	else if ((spaceNum[6] == spaceNum[7]) && (spaceNum[7] == spaceNum[8]))
	{	// there is a winner in the third row
		return 1;
	}
	else if ((spaceNum[0] == spaceNum[4]) && (spaceNum[4] == spaceNum[8]))
	{	// there is a winner in the 
		return 1;
	}
	else if ((spaceNum[2] == spaceNum[4]) && (spaceNum[4] == spaceNum[6]))
	{	// there is a winner in the /
		return 1;
	}
	else if ((spaceNum[0] == spaceNum[3]) && (spaceNum[3] == spaceNum[6]))
	{	// there is a winner in the first column
		return 1;
	}
	else if ((spaceNum[1] == spaceNum[4]) && (spaceNum[4] == spaceNum[7]))
	{	// there is a winner in the second column
		return 1;
	}
	else if ((spaceNum[2] == spaceNum[5]) && (spaceNum[5] == spaceNum[8]))
	{	// there is a winner in the third column
		return 1;
	}
	else if (spacetaken == 9)
	{	// all the 9 spaces are taken ;therefore, its a draw
		return 2;
	}
	else
	{	// there is no winner and all the spacese arn't taken yet, so winner yet
		return 0;
	}

}
