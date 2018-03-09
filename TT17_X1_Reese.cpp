
/*
  Name: Lee Reese
  COSC 1337 Spring 2018 TT17
  Exam 1, Programming portion
  When complete: Change course designator in filename from DDHH to TT10;
                 Change "Lastname" to your lastname.
  Upload file: TT17_X1_Lastname.cpp to BlackBoard Assignment link.
*/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <math.h>
#include<limits>
using namespace std;

//Function prototypes
int get_input(const string&, const string&, int, int, bool = true);
char get_choice();
void fix_cin();
bool isvalid_day_month_year(int, int, int);
bool won_prize(int);
void test_for_boss(int, int, int&, double&);

//MAIN
int main() {
  //Welcome message
  cout << "This program records your birthday and "
       << "gives you the chance to win a prize." << endl;

  //Get initial birthday values
  int year = get_input("What is your birth year", "error", 1900, 2017);
  int month = get_input("What is your birth month", "error", 1, 12);
  int day = get_input("Which is your birth day", "error", 1, 31);

  char choice{};

  //Menu
  do {
    cout << endl; //formatting

    //Let the user know if they have given an invalid date
    bool bad_birthday = !isvalid_day_month_year(day, month, year);
    if (bad_birthday)
      cout << "NOTICE: Your given birthday is not a valid date "
	   << "and cannot be accepted." << endl;

    //Menu
    cout << "Your birthday is: " 
	 << setfill('0') << setw(2) << month << "/" 
	 << setfill('0') << setw(2) << day << "/" 
	 << year << " "
	 << "CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse?" << endl
	 << "Choice: ";
    choice = get_choice();
    
    //Edit day, month, year
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
    
    //Accept
    else if (choice == 'a') {
      //Accept but invalid b-day
      if (bad_birthday) {
	cout << "You have provided an invalid birthday and may not accept. "
	     << endl;
	choice = '_';
      }
      cout << "Your birthday has been accepted.";
    }

    //Refuse
    else if (choice == 'r') {
      year = 0;
      month = 0;
      day = 0;
    }
  } while(choice != 'a' && choice != 'r');
  
  cout << endl; //formatting
  
  //Give user opportunity to win a priz
  cout << (won_prize(100)? "You won a prize!" : "You did not win a prize.")
       << endl;

  //Test for the boss
  int wins = 0;
  double win_percent = -1;
  test_for_boss(10000, 100, wins, win_percent);
  cout << "\nFor boss' eyes only:\n"
       << "Of 10000 people, "
       << wins << " people won: " 
       << setprecision(2) << fixed << win_percent << " percent."
       << endl;

  //Goodbye
  cout << "Goodbye!" << endl;
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
  Function: isvalid_day_month_year
  Purpose: Determine whether a month-day pair represents a valid date
*/
bool isvalid_day_month_year(int day, int month, int year) {
  const int Jan=31, Feb=28, Mar=31, Apr=30, May=31, Jun=30, Jul=31, 
            Aug=31, Sep=30, Oct=31, Nov=30, Dec=31;

  //Leap Years
  if (day == 29 && month == 2) {
    if (year % 4 != 0)
      return false;
    else if (year % 100 != 0)
      return true;
    else if (year % 400 != 0)
      return false;
    else
      return true;
  }

  //Common Years
  switch (month) {
    case 1 : 
      return (day <= Jan? true : false);
    case 2 : 
      return (day <= Feb? true : false);
    case 3 : 
      return (day <= Mar? true : false);
    case 4 : 
      return (day <= Apr? true : false);
    case 5 : 
      return (day <= May? true : false);
    case 6 : 
      return (day <= Jun? true : false);
    case 7 : 
      return (day <= Jul? true : false);
    case 8 : 
      return (day <= Aug? true : false);
    case 9 : 
      return (day <= Sep? true : false);
    case 10 : 
      return (day <= Oct? true : false);
    case 11 : 
      return (day <= Nov? true : false);
    case 12 : 
      return (day <= Dec? true : false);
      
  }
  //For really weird pairs
  return false;
}

/*
  Function: won_prize()
  Purpose: Let the user know if they won a prize
*/
bool won_prize(int chance) {
  
  //Generate winning value and users attempt
  int random_win = rand() % chance;
  int random_attempt = rand() % chance;

  return random_win == random_attempt;
}

/*
  Function: test_for_boss
  Purpose: Validate experimental probability of winning a prize from
  won_prize()
*/
void test_for_boss(int count, int chance, int& wins, double& win_percent) {
  for (int i = 0; i < count; i++) {
    if (won_prize(chance)) wins++;
  }
  win_percent =  double(wins) / double(count) * 100;
}
