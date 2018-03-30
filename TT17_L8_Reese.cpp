// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 8  Purpose: Tic-Tac-Toe Game

/*
TODO:
-Diag victory



*/

#include<iostream>
#include<string>
#include<cmath>
#include<sstream>

using namespace std;
class Board {

  private:
    //Attributes
  char _board[3][3];
      
    int _remainingMoves;
    const int _boardDimension = 3;

    //setters
    void subtractMove() {
      _remainingMoves--;
    }
  
    //Determines if a desired position consistutes a valid position on the board
    bool getCoordinate(int &row, int &col, int position) {

      //Return false if  position is invalid
      if (pow(_boardDimension, 2) <= position || 0 > position)
	return false;

      //Decode position int ocoordinates
      row = position / _boardDimension;
      col = position % _boardDimension;
      return true;
    }

    //Builds a square board with side length boardDimension
    void constructBoard(int boardDimension) {
      
    }
  
  public:
    //Constructor
    Board() {
      for (int col = 0; col < _boardDimension; col++)
	for (int row = 0; row < _boardDimension; row++)
	  _board[row][col] = ' ';
      _remainingMoves = pow(_boardDimension, 2);
    }

    //Getters
    const int getRemainingMoves() {
      return _remainingMoves;
    }
  
    char isWinner(char player) {
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
      return false;
    }

    void makeMove(char player, int position) {
      //Only make a move if possible
      if (_remainingMoves <= 0)
	return;

      //Place char player at the desired possition
      int row; int col;
      if (getCoordinate(row, col, position)) {
	cout << "success" << endl;
	_board[row][col] = player;
	subtractMove();
      }
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
	//Horizontal Line (if appropriate)
	if (row != _boardDimension-1)
	  ss << "-----------" << endl;
      }
      return ss.str();
    }
};

void printBoardMap() {
  cout << " 0 | 1 | 2 \n"
       << "-----------\n"
       << " 3 | 4 | 5 \n"
       << "-----------\n"
       << " 6 | 7 | 8 \n";
}

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
  Board gameBoard = Board();

  while (gameBoard.getRemainingMoves() > 0) {
    cout << "Remaining Moves: " << gameBoard.getRemainingMoves() << endl;
    
    char player = (gameBoard.getRemainingMoves()%2 == 0? 'O' : 'X' );
    
    //Prompt
    printBoardMap();
    stringstream prompt;
    prompt << "Make your move player "
	   << player << ": ";
    int choice = static_cast<int>(getInput(prompt.str()));
    cout << "Choice : " << choice << endl;
    gameBoard.makeMove(choice, player);
    gameBoard.toString();  
  }

  
  gameBoard.makeMove('X', 0);
  gameBoard.makeMove('X', 3);
  gameBoard.makeMove('X', 6);
  cout << gameBoard.toString();
  if(gameBoard.isWinner('X')) cout << "X wins\n";
  return 0;
}
