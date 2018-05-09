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

using namespace std;

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
    Day(int month=0, int date = 1) {
      // For nonexistant month, use 0 (january) instead
      if (month < 0 || month > 11)
        month = 0;
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
      for (int i = month; i > 0; i--)
        day -= daysInMonth[i];
      return day;
    }

    // Overloaded Operators
    Day operator++();
    Day operator++(int);
    Day operator--();
    Day operator--(int);
};

Day Day::operator++() {
  int temp = _day;
  temp++;
  _day = temp % 365;
  return *this;
}

Day Day::operator++(int) {
  Day temp = *this;
  _day++;
  _day %= 365;
  return temp;
}

string Day::monthsOfYear[12] = {"jan", "feb", "mar", "apr",
                                "may", "jun", "jul", "aug",
                                "sep", "oct", "nov", "dec"};
int Day::daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};
int main() {/*
  Day jan1  = Day(0, 1);
  Day feb1  = Day(1, 1);
  Day mar1  = Day(2, 1); 
  Day dec31 = Day(11, 31); dec31;
  cout << "jan1:  " << jan1.getMonth() << endl;
  cout << "feb1:  " << feb1.getMonth() << endl;
  cout << "mar1:  " << mar1.getMonth() << '/' << mar1.getDate() << endl;
  cout << "dec31: " << dec31.getMonth() << '/' << dec31.getDate() << endl;*/

  Day jan1 = Day(0, 1); jan1++;
  cout << jan1.getDay() << endl; ++jan1;
  cout << jan1.getDay() << endl;
  return 0;
}
