// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 8  Purpose: Tic-Tac-Toe Game

/*
TODO:




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
  
    //Determine the current winner
    char winner() {
      
    }

    //Place an 'X' or an 'O'
    void makeMove(char player, int position) {
      //Only make a move if possible
      if (_remainingMoves <= 0)
	return;

      //Place appropriate char at the desired possition
      int row; int col;
      if (getCoordinate(row, col, position)) {
	_board[row][col] = player;
	subtractMove();
      }
    }

    //Convert Board to a string
    string toString() {
      stringstream ss;
      for (int row = 0; row < _boardDimension; row++){
	for (int col = 0; col < _boardDimension; col++){
	  switch (col) {
	    case 0: case 2 :
	      ss << " " << _board[row][col] << " ";
	      break;
	    case 1 :
	      ss << "| " << _board[row][col] << " |";
	      break;
	    
	  }
	}
	ss << endl;
	if (row != _boardDimension-1)
	  ss << "-----------" << endl;
      }
	
      return ss.str();
    }
};

int main() {
  Board gameBoard = Board();
  gameBoard.makeMove('X', 2);
  gameBoard.makeMove('O', 4);
  cout << gameBoard.toString();
  return 0;
}
