/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
using namespace std;
#include "split.h"
#include <iostream>


int main(int argc, char* argv[])
{
  Node* in = nullptr;
  for (int i = 6; i>= 1; i--){
    in = new Node(i, in);
  }
  Node* odds = nullptr;
  Node* evens = nullptr;
  split(in, odds, evens);

  Node* printOdds = odds;
  cout << "odds:";
  while(printOdds){
    cout << printOdds->value << " ";
    printOdds = printOdds->next;
  }
  cout << endl;

  Node* printEvens = evens;
  cout << "evens:";
  while(printEvens){
    cout << printEvens->value << " ";
    printEvens = printEvens->next;
  }
  cout << endl;

}
