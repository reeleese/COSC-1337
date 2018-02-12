// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 1  Purpose:  Provide menu-driven option loop that calculates: restaurant bill; BMI; or quits the loop.

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
  bool done_looping = false;
  while (!done_looping) {
    //Menu
    cout << "Options: c)alculate restaurant bill; B)MI; q)uit: ";
    char option = ' ';
    cin >> option;
    option = tolower(option);
    
    //Calculate restaurant bill.
    if (option == 'c') {
      //Get food cost
      double food_cost = 0;
      cout << "Enter the food cost: $";
      cin >> food_cost;

      //Get tip percentage
      double tip_percentage = 0;
      cout << "Enter desired tip percentage (%): ";
      cin >> tip_percentage;
      tip_percentage = tip_percentage / 100;
    
      //Calculate total bill. Tip is based on food cost w/o tax.
      const double tax_rate = 0.0825;
      double tax_owed = food_cost * tax_rate;
      double tip_owed = tip_percentage * food_cost;
      double total_bill = food_cost + tax_owed + tip_owed;

      //Print bill totals.
      cout << "\nBill\n";
      cout << "Subtotal: $";
      printf("%.2f\n", food_cost);
            
      cout << "Tax: $";
      printf("%.2f\n", tax_owed);
      
      cout << "Tip: $";
      printf("%.2f\n", tip_owed);

      cout << "Total Bill: $";
      printf("%.2f", total_bill);
      cout << "\n\n";
    }

    //Calculate BMI.
    else if (option == 'b') {
    
      //Get weight.
      int weight = 0;
      cout << "Enter your weight (in pounds): ";
      cin >> weight;
    
      //Get height.
      cout << "Enter your height in feet and inches,\n";
      
      int height_feet = 0;
      cout << "Feet: ";
      cin >> height_feet;
      
      int height_inches = 0;
      cout << "Inches: "; 
      cin >> height_inches;

      height_inches = height_feet * 12 + height_inches;

      //Calculate BMI
      double BMI = weight/ pow(height_inches, 2) * 703;
      cout << "Your BMI is: " << BMI;
      cout << "\n\n";
    }
    
    //Quit loop.
    else if (option == 'q') {
      done_looping = true;
    }

    //Invalid option.
    else {
      cout << "Invalid option, \"" << option << "\" chosen.";
      cout << "\n\n";
    }
  }

  //End of loop.
  cout << "Goodbye.\n";
  return 0;
}
/*
Program Output:
Options: c)alculate restaurant bill; B)MI; q)uit: c
Enter the food cost: $10
Enter desired tip percentage (%): 10

Bill
Subtotal: $10.00
Tax: $0.83
Tip: $1.00
Total Bill: $11.82

Options: c)alculate restaurant bill; B)MI; q)uit: b
Enter your weight (in pounds): 150
Enter your height in feet and inches,
Feet: 6
Inches: 0
Your BMI is: 20.3414

Options: c)alculate restaurant bill; B)MI; q)uit: w
Invalid option, "w" chosen.

Options: c)alculate restaurant bill; B)MI; q)uit: q
Goodbye.
*/
