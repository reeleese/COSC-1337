// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 6  Purpose: Calculate the distance between two things

/*
TODO:
-Purpose
-Program output

*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

//Variables
float distance{0};
int first;
int second;

//Error Messages
const string error_char = "Sorry, character must be alphabetic. Try again.";
const string error_number = "Sorry, out-of-range. Try again.";
const string error_point = "This error should never happen.";

//Prompts
const string prompt_char = "Gimme a character: ";
const string prompt_number = "Gimme a number";
const string prompt_point = "";

//Input Functions
char input(bool first, string error_message) {
  //Prompt
  cout << (first ? "Enter first letter ":"Enter second letter ")
       << "(a to z): ";
  
  //Input
  char user_input{};
  cin >> user_input;
  
  //If char is not a-z or A-Z, try again.
  if (!isalpha(user_input)) {
    cout << error_message << endl;
    return input(first, error_message);
  }
  return user_input;
}

float input(float min, float max, string prompt, string error_message);
void input(double &x, double &y, string prompt);

//Distance functions

//Display functions


int main() {
  //Sentinel
  char option{};
  
  //Menu
  do {
    cout << "Options: l)etter; n)umber; p)oint; q)uit: ";
    cin >> option;
    
    switch (option) {
      case 'l':
	first = int (input(true, error_char));
	second = int (input(false, error_char));
	break;
      case 'n':
	break;
      case 'p':
	break;
      case 'q':
	cout << "Good-bye!" << endl;
	break;
    }
  } while (option != 'q');
  return 0;
}

/*
Program Output:

*/
