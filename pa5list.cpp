// Name: Matt Bladek
// USC NetID: bladek
// CS 455 PA5

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
    ListType newList;
    listAdd(newList, "hello", 1);
    listAdd(newList, "goodbye", 1);
    listAdd(newList, "wed", 1);
    listAdd(newList, "wed", 1);
    listAdd(newList, "wed", 1);
    listAdd(newList, "wed", 1);

    cout << listSize(newList)<<endl;

    listPrint(newList);

  return 0;
}
