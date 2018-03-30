// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 8  Purpose: Tic-Tac-Toe Game

/*
TODO:




*/

#include<iostream>
#include<string>
#include<cmath>

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
    int _remainingMoves;
    int _boardDimension;

    //Private Functions
  
    bool getCoordinate(int &row, int &col, int position) {
      //Return false if  position is invalid
      if (pow(_boardDimension, 2) <= position || 0 > position)
	return false;

      row = position / _boardDimension;
      col = position % _boardDimension;
      return true;
    }
  
  public:

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
  
};

int main() {
  
  return 0;
}
