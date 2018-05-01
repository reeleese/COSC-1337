/*
  Author:          Lee Reese
  Assignment:      Lab 11
  Topic:           memory diagram with stack, heap structures
  File Name:       TT17_L11_Reese.cpp
  Course/Section:  COSC 1337
  Due Date:        Tuesday 5/8
  Instructor:      Thayer
*/

using namespace std;

class Day{
  private:
    int _day;
    enum _month {jan=31, feb=28, mar=31, apr=30, may=31, jun=30,
                 jul=31, aug=31, sep=30, oct=31, nov=30, dec=31}
  
  public:
    // Constructor
    Day(int day = 0) {
      if (day >= 0) _day = day;
    }

    // Return day
    int getDay() const {
      return _day;
    }

};

int main() {
  return 0;
}
