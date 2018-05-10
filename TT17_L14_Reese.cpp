// Author:               Lee Reese
// Assignment Number:    Lab 14
// File Name:           TT17_L14_Reese.cpp
// Course/Section:       COSC 1337 Section TT17
// Due Date:             Thursday, 5/10
// Instructor:           Thayer

/*
  For each looping function, provide the code for the equivalent recursive function.
  See Blackboard, Lab 14 for complete instructions.
  
  IMPORTANT: Your recursive functions should NOT use any static local variables
  or global variables! The "state" of the function must be completely self-contained.
  Consider that recursive functions may be called simultaneously by several programs
  at the same time. This occurs when a recursive function is in a library, such
  as qsort(). If calls are not independent, the recursive function is limited
  to a single process.
*/
  
#include <iostream>
#include <iomanip>
using namespace std;

void show_1_to_n_loop(int n) { // looping
  for (int i=1; i<=n; ++i) cout<<i<<" ";
}

void show_1_to_n_recurse(int n) { // recursive
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here...
  if (n > 1)
    show_1_to_n_recurse(n-1);
  cout << n << " ";
}

void show_n_to_1_loop(int n) { // looping
  for (int i=n; i>=1; --i) cout<<i<<" ";
}

void show_n_to_1_recurse(int n) { // recursive
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here...
  cout << n << " ";
  if (n > 1)
    show_n_to_1_recurse(n-1);
}

string reverse_loop(string forward) { // looping
  string backwards;
  int size=forward.size();
  for (int i=0; i<size; ++i) {
    backwards+=forward[size-1-i];
  }
  return backwards;
}

string reverse_recurse(string forward) { // recursive
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here...
  return ""; // replace this with your return value;  is "" until new code added.
}

int add2_fx(int a, int b) { // functional (for illustration only)
  return a+b;
}

int add2_loop(int a, int b) { // looping
  int sum=a;
  if (b>0)
    for (int i=0; i<b; ++i) ++sum;
  else // b<=0
    for (int i=b; i<0; ++i) --sum;
  return sum;
}

int add2_recurse(int a, int b) { // recursive
  // Rule: you may NOT use the *, /, +, =, *=, /=, +=, -= operators.
  // You MAY use: ++ and/or -- (as done in add2_loop)
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here...
  return 0; // replace this with your return value;  is 0 until new code added.
}

int mult2_fx(int a, int b) { // functional (for illustration only)
  return a*b;
}

int mult2_loop(int a, int b) { // looping
  int product=0;
  if (b>0)
    for (int i=0; i<b; ++i) product+=a;
  else // b<=0
    for (int i=b; i<0; ++i) product-=a;
  return product;
}

int mult2_recurse(int a, int b) { // recursive
  // Rule: you may NOT use the *, *=, / or /= operators.
  // You MAY use: +, -, +=, -= operators (as done in mult2_loop)
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here...
  return 0; // replace this with your return value;  is 0 until new code added.
}

int search_loop(int array[], int size, int target) { // looping
  for (int i=0; i<size; ++i)
    if (array[i]==target) {return i;}
  return -1;
}

int search_recurse(int array[], int size, int target) { // recursive
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here...
  return 0; // replace this with your return value;  is 0 until new code added.
}

enum control_t {functional, looping, recursive};
void show_test(int n, string s, control_t control) {
  // utility function to format test output
  // n: test number; s: "description"; control: looping or recursive
  static const string fx="functional", sl="looping", sr="recursive";
  int max_len=max(fx.size(), max(sl.size(), sr.size()));
  string msg;
  switch (control) {
    case functional: msg=fx;     break;
    case looping:    msg=sl;     break;
    case recursive:  msg=sr;     break;
    default:         msg="??";   break;
  }
  char iorr=msg[0];
  msg=" ("+msg+"): ";
  cout<<"\n"<<n<<iorr<<") "<<s<<setw(max_len+5)<<left<<msg;
}

void infinite_recursion() {
  // try at your own risk! Error message can be interesting.
  infinite_recursion();
}

int main () {
  cout<<"start...\n";
  
  show_test(1, "show_1_to_n", looping);    show_1_to_n_loop(7);
  show_test(1, "show_1_to_n", recursive);  show_1_to_n_recurse(7);
  cout<<endl;
  
  show_test(2, "show_n_to_1", looping);    show_n_to_1_loop(10);
  show_test(2, "show_n_to_1", recursive);  show_n_to_1_recurse(10);
  cout<<endl;
  
  show_test(3, "reverse", looping);    cout<<reverse_loop("stressed");
  show_test(3, "reverse", recursive);  cout<<reverse_recurse("stressed");
  cout<<endl;

  show_test(4, "add2", functional);
  cout<<add2_fx( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_fx(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_fx(20, -9); cout<<" ";  // correct:  11
  cout<<add2_fx(-7, -5); cout<<" ";  // correct: -12
  show_test(4, "add2", looping);
  cout<<add2_loop( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_loop(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_loop(20, -9); cout<<" ";  // correct:  11
  cout<<add2_loop(-7, -5); cout<<" ";  // correct: -12
  show_test(4, "add2", recursive);
  cout<<add2_recurse( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_recurse(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_recurse(20, -9); cout<<" ";  // correct:  11
  cout<<add2_recurse(-7, -5); cout<<" ";  // correct: -12
  cout<<endl;

  show_test(5, "mult2", functional);
  cout<<mult2_fx( 2,   5); cout<<" ";  // correct:  10
  cout<<mult2_fx(-4,   5); cout<<" ";  // correct: -20
  cout<<mult2_fx( 3, -10); cout<<" ";  // correct: -30
  cout<<mult2_fx(10,   4); cout<<" ";  // correct:  40
  show_test(5, "mult2", looping);
  cout<<mult2_loop( 2,   5); cout<<" ";  // correct:  10
  cout<<mult2_loop(-4,   5); cout<<" ";  // correct: -20
  cout<<mult2_loop( 3, -10); cout<<" ";  // correct: -30
  cout<<mult2_loop(10,   4); cout<<" ";  // correct:  40
  show_test(5, "mult2", recursive);
  cout<<mult2_recurse( 2,   5); cout<<" ";  // correct:  10
  cout<<mult2_recurse(-4,   5); cout<<" ";  // correct: -20
  cout<<mult2_recurse( 3, -10); cout<<" ";  // correct: -30
  cout<<mult2_recurse(10,   4); cout<<" ";  // correct:  40
  cout<<endl;
  
  int primes[] = {2, 3, 5, 7, 11, 13, 17}; // some prime numbers to search for
  int size_primes=sizeof(primes)/sizeof(int);
  
  show_test(6, "search", looping);
  cout<<search_loop(primes, size_primes, 2)<<", ";
  cout<<search_loop(primes, size_primes, 13)<<", ";
  cout<<search_loop(primes, size_primes, 10);
  show_test(6, "search", recursive);
  cout<<search_recurse(primes, size_primes, 2)<<", ";
  cout<<search_recurse(primes, size_primes, 13)<<", ";
  cout<<search_recurse(primes, size_primes, 10)<<endl;
  
  // uncomment the next line for crash and error message...
  // infinite_recursion();
  
  cout<<"\n...end\n";

  return 0;
} // end of main

// When complete, there will be test output for each of the 6 steps in pairs:
// looping and recursive, as shown below. Your recursive output should match.
/*
start...

1l) show_1_to_n (looping):    1 2 3 4 5 6 7
1r) show_1_to_n (recursive):

2l) show_n_to_1 (looping):    10 9 8 7 6 5 4 3 2 1
2r) show_n_to_1 (recursive):

3l) reverse (looping):    desserts
3r) reverse (recursive):

4f) add2 (functional): 9 10 11 -12
4l) add2 (looping):    9 10 11 -12
4r) add2 (recursive):  0 0 0 0

5f) mult2 (functional): 10 -20 -30 40
5l) mult2 (looping):    10 -20 -30 40
5r) mult2 (recursive):  0 0 0 0

6l) search (looping):    0, 5, -1
6r) search (recursive):  0, 0, 0

...end
*/
