

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream materials{"lab4_info.txt"};
  vector<string> stuff;
  if (materials) {
    cout << "success.\n";
    string speed = "yo";
    while (materials >> speed) {
      stuff.push_back(speed);
    }
  }
  else
    cout << "fail.";
  for (int i = 0; i < stuff.size(); ++i) {
    cout << stuff[i] << endl;
  }
  return 0;
}
