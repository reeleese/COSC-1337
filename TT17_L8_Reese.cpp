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
    char _board[3][3] =
      {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
      };
    int _remainingMoves = 9;
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
      //Do nothing
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
      if (getCoordinate(row, col, position))
	_board[row][col] = player;
    }

    //Convert Board to a string
    string toString() {
      stringstream ss;
      int i = 0;
      while(i < pow(_boardDimension, 2)) {
	ss << "  " << i++
	   << "| " << i++ << " |"
	   << i++ << "  "
	   << endl;
	if (i != pow(_boardDimension, 2)) 
	  ss << "------------" << endl;
      }
      return ss.str();
    }
};

int main() {
  Board gameBoard = Board();
  cout << gameBoard.toString();
  return 0;
}
