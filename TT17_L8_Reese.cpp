// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 8  Purpose: Tic-Tac-Toe Game


#include<iostream>
#include<string>
#include<cmath>
#include<sstream>
#include<stdio.h>

using namespace std;
class Board {

  private:
    //Attributes
    char _board[3][3];
      
    int _remainingMoves;
    int _boardDimension;

    //setters
    void subtractMove() {
      _remainingMoves--;
    }
  
    //Determines if a desired position consistutes a valid position on the board
    bool getCoordinate(int &row, int &col, int position) {

      //Return false if  position is invalid
      if (pow(_boardDimension, 2) <= position || 0 > position)
	return false;

      //Decode position into coordinates
      row = position / _boardDimension;
      col = position % _boardDimension;
      return true;
    }
  
  public:
    //Constructor
    Board() {
      _boardDimension = 3;
      for (int row = 0; row < _boardDimension; row++)
	for (int col = 0; col < _boardDimension; col++)
	  _board[row][col] = ' ';
      _remainingMoves = pow(_boardDimension, 2);
    }

    //Getters
    const int getRemainingMoves() {
      return _remainingMoves;
    }

    //Determines if there is a diagonal winner (helper for isWinner())
    bool isWinnerDiag(char& player, int col_init, bool down) {
      int row = 0; int col = col_init;
      while (row < 3) {
	if (_board[row][col] != player)
	  break;
	if (row == _boardDimension-1)
	  return true;
	
	//Move forward
	row++;
	
	//Move down (++) or up (--)
	if (down)
	  col++;
	else
	  col--;
      }
      return false;
    }

    //Determines if there is a winner
    bool isWinner(char player) {
      //Vertical Victory
      for (int col = 0; col < _boardDimension; col++)
	for (int row = 0; row < _boardDimension; row++) {
	  if (_board[row][col] != player)
	    break;
	  if (row == _boardDimension-1)
	    return true;
	}

      //Horizontal Victory
      for (int row = 0; row < _boardDimension; row++)
	for (int col = 0; col < _boardDimension; col++) {
	  if (_board[row][col] != player)
	    break;
	  if (col == _boardDimension-1)
	    return true;
	}

      //Diagonal Victory
      if (isWinnerDiag(player, 0, true))
	return true;
      if (isWinnerDiag(player, 2, false))
	return true;

      //No Victory
      return false;
    }

    bool gameOver(char& winner) {
      if (isWinner('X')) {
	winner = 'X';
	return true;
      }
      if (isWinner('O')) {
	winner = 'O';
	return true;
      }
      if (_remainingMoves <= 0)
	return true;
      return false;
      
    }

    bool makeMove(char player, int position) {
      //Only make a move if possible
      if (_remainingMoves <= 0)
	return false;

      //Place char player at the desired possition
      int row; int col;
      if (getCoordinate(row, col, position)) {
	//Ensure space is empty
	if (_board[row][col] != ' ')
	  return false;
	_board[row][col] = player;
	subtractMove();
      }
      return true;
    }
      
    string toString() {
      stringstream ss;
      for (int row = 0; row < _boardDimension; row++){
	for (int col = 0; col < _boardDimension; col++){
	  
	  //Draw tiles with vertical lines
	  switch (col) {
	    case 0 :
	    case 2 : ss << " " << _board[row][col] << " ";
	             break;
            case 1 : ss << "| " << _board[row][col] << " |";
	             break;
  	  default :  break;
	  }
	}
	ss << endl;
	//Horizontal Line (or not)
	if (row != _boardDimension-1)
	  ss << "-----------" << endl;
      }
      return ss.str();
    }
};

double getInput(string prompt) {  
  double number{};
  cout << prompt;
  
  //Ensure input is a number
  while (!(cin >> number)) {
    cout << "Value must be an integer." << endl;
    cin.clear();
    cin.ignore(255, '\n');
    cout << prompt; 
  }
  return number;
}

int main() {
  bool playAgain = true;
  double winsX = 0;
  double winsY = 0;
  double winsCat = 0;
  
  while (playAgain) {
    Board gameBoard = Board();
    bool gameOver = false;

    while (gameOver == false) {
      cout << endl
	   << "Remaining Moves: " << gameBoard.getRemainingMoves() << endl;
    
      char player = (gameBoard.getRemainingMoves()%2 == 0? 'O' : 'X' );
    
      //Prompt
      cout << gameBoard.toString();
      stringstream prompt;
      prompt << "Make your move player "
	     << player << ": ";
      int choice = static_cast<int>(getInput(prompt.str()));
      
      //Make Move
      if (!gameBoard.makeMove(player, choice)) {
	cout << "Bad move. Please choose a number between 0 and 8." << endl
	     << "Additionally, you may not occupy an already occupied space."
	     << endl;
      }

      //Check for a game over
      char winner = ' ';
      if (gameBoard.gameOver(winner)) {
	gameOver = true;
	cout << "\nGame Over!" << endl;

	//Cat's Game
	if (winner == ' ') {
	  //Statistics
	  winsCat++;
	  //Message
	  cout << "It's a cat's game. You both lose!" << endl;
	}
	
	//Somebody is a winner
	else
	  //Statitistics
	  if (winner == 'X')
	    winsX++;
	  else if (winner == 'Y')
	    winsY++;
	
	  //Congratulatory message
	  cout << "Player " << winner << " has won!"
	       << " Congratulations!" << endl;
      }
    }
    //Would user like to play again
    cout << "Would you like to play again? (y/n): ";
    char choice;
    cin >> choice;
    if (choice != 'y')
      playAgain = false;
}
  

  winsX = 10;
  winsY = 10;
  winsCat = 10;
  //Statistics Calculations
  double totalGames = winsX + winsY + winsCat;
  cout << "totl games" << totalGames << endl;
  double percentX = winsX * 100 / totalGames;
  double percentY = winsX * 100 / totalGames;
  double percentCat = winsX * 100 / totalGames;
  
  //Statistics Output
  printf("Percentage of games won by X: %0.2f%%\n" , percentX);
  printf("Percentage of games won by Y: %0.2f%%\n" , percentY);
  printf("Percentage cat's games: %0.2f%%\n" , percentCat);
  
  return 0;
}
