#ifndef TTTOVO_H	//TTTOVO == Tic Tac Toe One VS One
#define TTTOVO_H

namespace TTT_EX
{

	class tictactoeOvO
	{
		public:
			tictactoeOvO();
			void playTheGame(char space[]);
			void theBoard(char space[]);
			int winnerXorO(char space[]);
		private:
			int spacetaken;
	};

}


#endif
