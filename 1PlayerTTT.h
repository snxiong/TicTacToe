#ifndef TTTOVC_H	// TTTOVC == Tic Tac Toe One VS Computer
#define TTTOVC_H

namespace TTT_EX2
{
	class tictactoeOvC
	{
		public:
			tictactoeOvC();
			void playTheGameComputer(char space[]);	// function that will initiate the game
			void theBoard(char space[]); // function that will display the current game board to the user
			int winnerXorO(char space[]); // will check if there is a winner or a draw or if the game needs to continue
			int smartComputer(char space[]); //function that will be used by the computer player to counter the user
		private:
			int spacetaken; // checks to see how many space has been used up on the game board
	};
}

#endif
