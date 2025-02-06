using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  // cout << dat.back() << endl; // should return a runtime error and say "Empty list"
  // cout << dat.front() << endl; // should return a runtime error and say "Empty list"
  dat.pop_front();
  dat.pop_back();
  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("9");
  dat.push_front("bigaloo");
  dat.pop_back();

  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;  // prints: bigaloo 8 7

  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored

  dat.pop_back();
  dat.pop_back();
  dat.pop_back();
  dat.pop_back();

  cout << dat.size() << endl;  // prints 0 since list is empty
  // cout << dat.get(0) << endl; //prints invalid_argument, "Bad location"

  dat.pop_front();
  dat.push_front("bigsby");
  dat.push_back("bricken");
  cout << dat.front() << endl; //prints bigsby
  cout << dat.back() << endl; //prints bricken
  dat.pop_front();
  cout << dat.get(0) << endl; //prints bricken
  cout << dat.front() << endl; //prints bricken
  cout << dat.back() << endl; //prints bricken

  dat.pop_back();
  dat.push_front("billabong");
  dat.push_back("bocolate");
  cout << dat.front() << endl; //prints billabong
  cout << dat.back() << endl; //prints bocolate
  dat.pop_back();
  cout << dat.get(0) << endl; //prints billabong
  cout << dat.front() << endl; //prints billabong
  cout << dat.back() << endl; //prints billabong


}
