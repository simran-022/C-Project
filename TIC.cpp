#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class tictactoe 
{
  public: 
	tictactoe();
	     //default CTOR, initializes our board and moves counter.
	void displayBoard()const;
       	 //displays our board through each iteration.
	void getMove(char player);
	     //asks the user for his move, once received, checks if move is valid
         //and if so stores move in board for next iteration.
	void playGame();
         //creates a loop in order to play the game.
  private: 
	static const int BSIZE = 3; 
	     //board size
	static const int maxMoves = 9; 
	     //max moves possible in a game of ttt
	static const int minMovesToWin = 5; 
	     //min moves before checking for win
	char board[BSIZE][BSIZE]; 
	     //our board
	int totalMoves;
	     //moves counter
	bool checkForWins(char player)const;	
	     //takes in the player sign  
		 //checks board (rows, colums and diagonals) to see if we have found a winner
	bool checkForDraw()const;
	     //checks to see if max number of moves has been reached.
      	 // if so it's a tie
	void fill_board();
       	 //fills our 3*3 array of blank spaces
	char togglePlayer(char player);
	     //changes the player sign at the end of the turn
	
};

  tictactoe::tictactoe()
    {
	totalMoves = 0;
	fill_board();
	}

  void tictactoe::fill_board()
    {
	for (int row = 0; row < BSIZE; row++) 
	   {
		for (int col = 0; col < BSIZE;col++){
		board[row][col] = ' ' ;
		 }
	   }
    }
  void tictactoe::displayBoard()const 
    {
	cout << " -------------------\n";
	for (int row = 0; row < BSIZE; row++) 
	    {
		cout << " | ";
		for (int col = 0; col < BSIZE; col++) 
		  {
			cout <<  board[row][col] << "   | ";
		  }
		cout << "\n -------------------\n";
       	} 
    } 
  void tictactoe::getMove(char player)
    {
	     //variables
	string input; 
	     //stores our input
	char char_entered; 
	     //takes the character entered for evaluation
	int num_entered, row, col, index; 
	     //help set our play on the board.
	
	while (true) 
	   {
		cout << player << " \n\n Where do you want to play ? Select a number from 1-9 : " << endl;
		getline(cin, input);

		if (input != "  ")
		    {
			     //Since we are checking for a correct move
			     //we convert string into a cstring for easier comparison.
			char_entered = input.c_str()[0];
			if (char_entered >= '1' && char_entered <= '9') 
			     {
			    	 //If the input is between the desired range, convert it into an int.
				   num_entered = char_entered - '0';
				     //Use this number to find index and store the move into our board.
				   index = num_entered - 1; 
				     //this way if user enters 1 it means index 0 of board.

				     //we can use division and the remainder, in order to find the correct row and column. 
			       row = index / 3; 
				   col = index % 3; 
				     //check if the position on the board is empty (correct move), else it's wrong move.
			       char b_pos = board[row][col];
				    if (b_pos != 'X' && b_pos != 'O') 
					    {
					      //if correct move, place mark on board and we can move onto the next turn
				         board[row][col] = player;
				    	 totalMoves++;
					     break; 
				        }
				  else
				  cout << "\n ******Wrong move. Position is already taken. Try again******" << endl;
		         }
		     	 else
				 cout << "\n You must enter a number between 1-9 to make your move." << "Try again.";
		       }
		         else 
		   	     cout << "You must enter something!!" << endl;
	    }
	             cout << "\n Total moves: " << this->totalMoves << endl;
    } 

     char tictactoe::togglePlayer(char player) 
	    {
	     player = player == 'X' ? 'O' : 'X';
	     return (player);
	    }

    bool tictactoe::checkForWins(char player)const
	{
	   //only check for a winner once the min moves to win has been reached.
   	   if (totalMoves >= minMovesToWin)
	   {
	    //check rows for winner
	    if (board[0][0] == player && board[0][1] == player && board[0][2] == player)
		{
		  return true;
		}
		if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
		{
			return true;
		}
		if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
		{
			return true;
		}
		   //columns 
		if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
		{
			return true;
		}
		if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
		{
			return true;
		}
		if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
		{
			return true;
		}
		  //Across
		if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		{
			return true;
		}
		if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		{
			return true;
		}
	   }
	return false;
	}

bool tictactoe::checkForDraw()const
{
	return totalMoves == maxMoves;
}

void tictactoe::playGame()
{
	char player = 'X'; //initialize the player.
	bool gameOver = false;
	//single game iteration
	do 
	{
		displayBoard();
		getMove(player);
		if (checkForWins(player)) 
		{
			cout << "\n \n *********** WE HAVE A WINNER!! *********** \n " << endl
			 << player<< "__WINS!! \n\n";
			gameOver = true;
		}
		else if (checkForDraw()) 
		{
			cout << "\n ********** IT'S A DRAW! Play again! **********" << endl;
			gameOver = true;
		}
		player = togglePlayer(player);
	} 
	while (!gameOver);

	displayBoard();
}

int main() 
{
 tictactoe game;
 game.playGame();
 return 0;
}
