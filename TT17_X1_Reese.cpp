
/*
  Name: Lee Reese
  COSC 1337 Spring 2018 TT17
  Exam 1, Programming portion
  When complete: Change course designator in filename from DDHH to TT10;
                 Change "Lastname" to your lastname.
  Upload file: TT17_X1_Lastname.cpp to BlackBoard Assignment link.
*/

/*
TODO:
-Make get_input handle unusual numbers


*/

#include <iostream>
#include <iomanip>
using namespace std;

int get_input(const string& prompt, const string& error_msg, 
	       int min_value, int max_value, bool range_check = true);

int main() {
  cout << "This program does nothing." << endl;
  int year = get_input("What is your birth year", "error", 1900, 2017);
  int month = get_input("What is your birth month", "error", 1, 12);
  int day = get_input("Which is your birth day", "error", 1, 31);
}

/*
Function: get_input
Purpose: Get an int in range[min_value, max_value] from the user.
*/
int get_input(const string& prompt, const string& error_msg, 
	       int min_value, int max_value, bool range_check) {
  //Prompt
  cout << prompt << " ";
  if (range_check)
    cout << "[" << min_value << ", " << max_value << "]";
  cout << ": ";
  
  int value{};
  
  //Ensure input is an int
  while (!(cin >> value)) {
    cout << error_msg << " Value must be an integer."<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return get_input(prompt, error_msg, min_value, max_value, range_check);
  }

  //Ensure input is in range
  if (value < min_value || value > max_value) {
    cout << error_msg << " Value not in range."<< endl;
    return get_input(prompt, error_msg, min_value, max_value, range_check);
  } 
  return value;

}
