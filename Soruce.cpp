#include <iostream>
#include "2PlayerTTT.h"
#include "1PlayerTTT.h"
using namespace std;
using namespace TTT_EX;
using namespace TTT_EX2;



int main()
{
	tictactoeOvO oneVsOne;
	tictactoeOvC oneVsComp;
	char space[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	char mode = 'Y';
	int numMode;


	
		cout
			<< "A) 2 Players [One VS One]" << endl
			<< "B) 1 Player  [One VS Computer(Super Duper Hard Mode)" << endl
			<< "Please choose an option from above: ";
		cin >> mode;

		switch (mode)
		{
		case 'A': oneVsOne.playTheGame(space);
			break;
		case 'a': oneVsOne.playTheGame(space);
			break;
		case'B': oneVsComp.playTheGameComputer(space);
			break;
		case'b': oneVsComp.playTheGameComputer(space);
			break;
		default:
			cout << "The option you inputed is invalid" << endl << endl
				<< "A) 2 Players [One VS One]" << endl
				<< "B) 1 Player  [One VS Computer(Super Duper Hard Mode)" << endl
				<< "Please choose an option from above: ";
			cin >> mode;
		}


	system("pause");
	return 0;
}
