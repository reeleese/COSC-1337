
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
-output b-day in MM/DD/YYYY

*/

#include <iostream>
#include <iomanip>
using namespace std;

int get_input(const string& prompt, const string& error_msg, 
	       int min_value, int max_value, bool range_check = true);
char get_choice();
void fix_cin();
bool isvalid_day_moth(int day, int month);

//MAIN
int main() {
  //Welcome message
  cout << "This program does nothing." << endl;

  //Get initial birthday values
  int year = get_input("What is your birth year", "error", 1900, 2017);
  int month = get_input("What is your birth month", "error", 1, 12);
  int day = get_input("Which is your birth day", "error", 1, 31);

  char choice{};

  //Menu
  do {
    cout << "Your birthday is: " << month << "/" << day << "/" << year << " "
	 << "CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse?" << endl
	 << "Choice: ";
    choice = get_choice();

    if (choice != 'a' && choice != 'r') {
      switch (choice) {
      case 'y' : //year
	  year = get_input("What is your birth year", "error", 1900, 2017);
	  break;

      case 'm' : //month
	  month = get_input("What is your birth month", "error", 1, 12);
	  break;

      case 'd' : //day
	  day = get_input("Which is your birth day", "error", 1, 31);
	  break;

      default  : //Bad choice
	cout << "Not a valid choice." << endl;
	break;
      }
    }
  } while(choice != 'a' && choice != 'r');
}

/*
  Function: fix_cin
  Purpose: clear errors on cin and clear the buffer up to the point the enter
  key was pressed
*/
void fix_cin() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    fix_cin();
    return get_input(prompt, error_msg, min_value, max_value, range_check);
  }

  //Ensure input is in range
  if (value < min_value || value > max_value) {
    cout << error_msg << " Value not in range."<< endl;
    return get_input(prompt, error_msg, min_value, max_value, range_check);
  } 
  return value;

}

/*
  Function get_choice
  Purpose: Get users choice for a menu
*/
char get_choice() {
  char choice{};
  while(!(cin >> choice)) {
    fix_cin();
    return get_choice();
  }
  choice = tolower(choice);
  return choice;
}

/*
  Function: isvalid_day_month
  Purpose: Determine whether a month-day pair represents a valid date
*/
bool isvalid_day_month(int day, int month) {
  const int Jan=31, Feb=28, Mar=31, Apr=30, May=31, Jun=30, Jul=31, 
            Aug=31, Sep=30, Oct=31, Nov=30, Dec=31;

  switch (month) {
    case 1 : 
      return (month <= Jan? true : false);
    case 2 : 
      return (month <= Feb? true : false);
    case 3 : 
      return (month <= Mar? true : false);
    case 4 : 
      return (month <= Apr? true : false);
    case 5 : 
      return (month <= May? true : false);
    case 6 : 
      return (month <= Jun? true : false);
    case 7 : 
      return (month <= Jul? true : false);
    case 8 : 
      return (month <= Aug? true : false);
    case 9 : 
      return (month <= Sep? true : false);
    case 10 : 
      return (month <= Oct? true : false);
    case 11 : 
      return (month <= Nov? true : false);
    case 12 : 
      return (month <= Dec? true : false);
      
  }
  //For really weird pairs
  return false;
}
