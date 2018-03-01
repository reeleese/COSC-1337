/*
  Name:
  COSC 1337 Spring 2018 TT17
  Exam 1, Programming portion
  When complete: Change course designator in filename from DDHH to TT10;
                 Change "Lastname" to your lastname.
  Upload file: TT17_X1_Lastname.cpp to BlackBoard Assignment link.
*/

#include <iostream>
#include <iomanip>
using namespace std;

/* INSTRUCTIONS:
  There are 6 regular steps and 1 extra credit.
  Some algorithms and IPOs (Input, Processing, Output) are provided. Usually, "input"
  is not keyboard input from the user; it is almost always a function parameter.
  
  Step 1. (5 points)
  A common programming task is to get numerical input from the user.
  Write a single function that will:
    1) Display a prompt
    2) Get user's input (from keyboard)
    3) Verify that the input is valid (within a range, inclusive)
    4) If the input is invalid, display an error message and try again
    5) If the input is valid, accept it and return

    Create a new function that performs the steps above. Use the following:
      1) Function name: get_input
      2) Parameter: prompt         (pass by constant reference)
      3) Parameter: error_msg      (pass by constant reference)
      4) Parameter: min_value      (pass by value)
      5) Parameter: max_value;     (pass by value)
      6) Parameter: range_check (true or false)     (pass by value)
      7) return: value

  Function get_input() should provide error checking that detects non-numeric input.
  If parameter range_check is true, display the valid range after the prompt so the
  user knows what range of values is acceptable and provide range checking; otherwise,
  don't provide range checking. Usually range checking is desired; provide a default.
  Hints: 1) if (cin>>value) { } else { }; 2) cin.clear(); 3) cin.ignore();


  Step 2. (5 points)
    Test the function get_input() by asking the user for their birthday. Call it
    3 times to get: month, day, year. Provide a valid range for each. Assume a
    valid day is 1 to 31, month is 1 to 12, year is from 1900 to 2017. For now,
    don't worry about the number of days each month has; that comes later.


  Step 3. (10 points)
    Despite input validation, it is possible the user entered the wrong information.
    Give the user an opportunity to verify and correct invalid input. Create a loop
    that displays the person's birthday as entered in MM/DD/YYYY format. Example: 7/4/1776
    On ONE line, display the entered date, followed by a menu of options:
      birthday is 7/4/1776  Options: CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse?
    The options should do this:
      m)onth   : reenter the month;
      d)ay     : reenter the day;
      y)ear    : reenter the year;
      a)ccept  : user claims data is correct, accept date as entered and exit loop
      r)efuse  : user does NOT want to enter a birthday. Set date to 0/0/0000, exit loop
      
    In main, get the user's birthday. Loop as described above to accept changes.
    Accept upper and lower case. Use a switch statement for the options.


  Step 4. (10 points)
    With get_input, each part of a date may be in range, but the complete birthday
    may be invalid. Perhaps it has an invalid number of days for the month.

    Enhance your birthday validation process to verify that the number of days is valid
    for the number of the month. Do NOT modify the get_input function, keep that generic.
    Create a new function, isvalid_day_month().  Here is the IPO:
      Inputs:      number of day, number of month
      Processing:  compute whether the day, month combination is valid. Use a switch statement.
      Output:      boolean: return true if valid, false if invalid
      For now, use these limits: (copy/paste the line below to save time):
        const int Jan=31, Feb=28, Mar=31, Apr=30, May=31, Jun=30, Jul=31, Aug=31, Sep=30, Oct=31, Nov=30, Dec=31;

    Call isvalid_day_month() in Step 3 code as appropriate. If user a)ccepts, but date is invalid,
    don't accept; display error and retry. If user refuses to enter date, don't validate, exit loop.


  Step 5. (5 points)
    Currently, the function isvalid_day_month() does not handle leap years. It will not accept
    valid birthdays like: 2/29/2017. Enhance isvalid_day_month(). Add a 3rd parameter, year.
    RENAME it to: isvalid_day_month_year() and enhance to handle leap years.
    To determine whether a year is a leap year, follow these steps:
      1) If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
      2) If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
      3) If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
      4) The year is a leap year (2/29 is valid).
      5) The year is not a leap year (2/29 is not valid).
    Use if () {} else {} structures to implement these steps.
    
  
  Step 6. (5 points)
    To provide an incentive for your user to enter a valid date, give the user a chance
    to win a prize. After a valid date is entered, see if the user won a prize. If user
    refused, no prize is offered.

    Create a new function, won_prize() Here is the IPO:
      Input:     1 in n odds of winning the prize. Example: won_prize(100); // 1 in 100 chance of winning
      Processing: Calculate whether the person won the prize
      Output:     true if they won the prize, false if not
    
    In main, after the user entered a valid date, call won_prize() with a 1 in 100
    chance of winning. Notify the user whether they won or not.
    Hint: use time(), srand(), rand(), %. Important: ONLY call srand() ONCE!


  Step 7. (3 points) EXTRA CREDIT, OPTIONAL
    Your boss is worried that the program may award too many prizes. To verify the prize
    award process, test it. Simulate running the prize award function 10,000 times. In
    10,000 times, how many times was a prize won? Print the output to convince your boss
    that it works. The output should be: "Of 10000 people, 125 people won: 1.25 percent."
*/


// step 1 (5 points) function get_input() goes here ---
get_input() {}; // modify as appropriate


// step 4 (10 points) function isvalid_day_month() goes here ---
isvalid_day_month() {}; // edit as appropriate
// step 5 (5 points) function isvalid_day_month_year() goes here ---
isvalid_day_month_year(){}; // edit as appropriate
// After step5, ONLY isvalid_day_month_year() is expected. It includes code from steps 4 and 5


int main() {
  cout << "COSC 1337 Exam 1 Lab Portion" << endl;

// step 2 (5 points) 3 calls to get_input() goes here ---
  get_input();  get_input();  get_input();  // edit as appropriate
  
// step 3 (10 points) loop to reenter birthday
// step 4's call to isvalid_day_month (enhancement to step 3)
// step 5's call to isvalid_day_month_year (enhancement to step 4)
// step 6's call to won_prize() (enhancement to step 5)

// step 7 (3 points, optional extra credit) test if won_prize().

  cout<<endl<<"Goodbye!"<<endl; // this should appear as the last line of your output
  return EXIT_SUCCESS; // Use return 0 if EXIT_SUCCESS is undefined
}

/*
  Paste your test output here

*/
