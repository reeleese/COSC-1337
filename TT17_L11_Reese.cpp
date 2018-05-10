/*
  Author:          Lee Reese
  Assignment:      Lab 11
  Topic:           memory diagram with stack, heap structures
  File Name:       TT17_L11_Reese.cpp
  Course/Section:  COSC 1337
  Due Date:        Tuesday 5/8
  Instructor:      Thayer
*/

#include<iostream>
#include <algorithm>
#include <sstream>

using namespace std;

enum Month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

class Day{
  private:
    // Variables
    int _day;

    public:
    // Constants
    const static int daysInYear = 365;
    const static int year = 2018;
    static string monthsOfYear[12];
    static int daysInMonth[12];
  
    // Constructor
    Day(Month month=jan, int date = 1) {
      // For nonexistant day, use 0 instead
      if (date < 1 || date > daysInMonth[month])
        date = 1;
      // Resolve month and date into day
      int day = date;
      for (int i = month-1; i >= 0; i--)
        day += daysInMonth[i];
      _day = day;
    }

    // Return day
    int getDay() const {
      return _day;
    }
  
    // Return month
    int getMonth() const {
      int day = getDay();
      
      // drop down thru the months until day is negative
      int month = 0;
      for (;month < 12; month++) {
        day -= daysInMonth[month];
        if (day <= 0)
          break;
      }
      return month;
    }

    // Return Date
    int getDate() const {
      int day = getDay();
      int month = getMonth();

      // Trim all previous months off of day to get date
      for (int i = month-1; i >= 0; i--)
        day -= daysInMonth[i];
      return day;
    }

    // Overloaded Operators
    Day operator++();
    Day operator++(int);
    Day operator--();
    Day operator--(int);

  // print
  void print() {
    string month = monthsOfYear[getMonth()];
    int date = getDate();
    cout << month << ' ' << date;
  }
};

// Overloaded ++Day 
Day Day::operator++() {
  _day++;
  if (_day != 365)  // don't let dec31 evaluate to jan0
    _day %= 365;
  return *this;
}

// Overloaded Day++
Day Day::operator++(int) {
  Day temp = *this;
  _day++;
  if (_day != 365)  // don't let dec31 evaluate to jan0
    _day %= 365;
  return temp;
}

// Overloaded --Day
Day Day::operator--() {
  _day--;
  _day %= 365;
  if (_day == 0)  // jan1 goes to dec31 instead of jan0
    _day = 365;
  return *this;
}

// Overloaded Day--
Day Day::operator--(int) {
  Day temp = *this;
  _day--;
  _day %= 365;
  if (_day == 0) // jan1 goes to dec31 instead of jan0
    _day = 365;
  return temp;
}

string Day::monthsOfYear[12] = {"jan", "feb", "mar", "apr",
                                "may", "jun", "jul", "aug",
                                "sep", "oct", "nov", "dec"};
int Day::daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

Month stringToMonth(string str) {
  if (str == "feb") return Month::feb;
  if (str == "mar") return Month::mar;
  if (str == "apr") return Month::apr;
  if (str == "may") return Month::may;
  if (str == "jun") return Month::jun;
  if (str == "jul") return Month::jul;
  if (str == "aug") return Month::aug;
  if (str == "sep") return Month::sep;
  if (str == "oct") return Month::oct;
  if (str == "nov") return Month::nov;
  if (str == "dec") return Month::dec;
  return jan;
}

void test_operators() {
  Day bday(jul, 4);
  cout<<"start at: "; bday.print(); cout<<endl;
  for (int i=0; i<5; ++i) {cout<<" "; (--bday).print();} cout<<endl;
  for (int i=0; i<5; ++i) {cout<<" "; (++bday).print();} cout<<endl;
  for (int i=0; i<5; ++i) {cout<<" "; (bday++).print();} cout<<endl;
  for (int i=0; i<5; ++i) {cout<<" "; (bday--).print();} cout<<endl;
  cout<<"end at: "; bday.print(); cout<<endl;
}

int main() {
  test_operators();
  cout << endl;
  
  bool done = false;
  while(!done) {
    // Prompt
    cout << "Give me a day and a month. " << endl
	 << "Note: invalid information defaults to jan." << endl
	 << "      invlaid date defaults to 1." << endl;
    
    // Get Month
    string user_month{};
    cout << "Give month: ";
    cin >> user_month;
    Month month = stringToMonth(user_month);

    // Get Date
    int date{};
    cout << "Give date: ";
    cin >> date;

    // Output
    Day userDay = Day(month, date);
    cout << "You entered: ";
    userDay.print();
    cout << endl;

    // Repeat if desired
    char choice{};
    cout << "Would you like to go again? (y/n)";
    cin >> choice;
    if(choice == 'n')
      done = true;
    cout << endl;
  }
  return 0;
}

/*
Assumptions: 
- I assumed that the user would only enter dates with three characters lowercase
- I assumed the user was perfect and would not give me nasty input.

Program Output:
start at: jul 4
 jul 3 jul 2 jul 1 jun 30 jun 29
 jun 30 jul 1 jul 2 jul 3 jul 4
 jul 4 jul 5 jul 6 jul 7 jul 8
 jul 9 jul 8 jul 7 jul 6 jul 5
end at: jul 4

Give me a day and a month. 
Note: invalid information defaults to jan.
      invlaid date defaults to 1.
Give month: jan   
Give date: 31
You entered: jan 31
Would you like to go again? (y/n)y

Give me a day and a month. 
Note: invalid information defaults to jan.
      invlaid date defaults to 1.
Give month: may
Give date: 5
You entered: may 5
Would you like to go again? (y/n)y

Give me a day and a month. 
Note: invalid information defaults to jan.
      invlaid date defaults to 1.
Give month: dec 31
Give date: You entered: dec 31
Would you like to go again? (y/n)y

Give me a day and a month. 
Note: invalid information defaults to jan.
      invlaid date defaults to 1.
Give month: dec 32
Give date: You entered: dec 1
Would you like to go again? (y/n)n

*/
