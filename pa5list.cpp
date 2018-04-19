/**
 Name: Matt Bladek
 USC NetID: bladek
 CS 455 PA5

 pa5list.cpp
 a program to test the linked list code necessary for a hash table chain

 You are not required to submit this program for pa5.

 We gave you this starter file for it so you don't have to figure
 out the #include stuff.  The code that's being tested will be in
 listFuncs.cpp, which uses the header file listFuncs.h

 The pa5 Makefile includes a rule that compiles these two modules
 into one executable.
 */

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

ListType testListAdd();

void testListRemove();

void size(ListType & list);

void testContains();


int main() {

//    testListAdd();

//    testListRemove();

    testContains();

    return 0;
}

void size(ListType & list){
    cout << listSize(list)<<endl;
}

ListType testListAdd(){
    ListType newList;
    listAdd(newList, "hello", 1);
    listAdd(newList, "goodbye", 2);
    listAdd(newList, "wed", 3);
    listAdd(newList, "wed", 4);
    listAdd(newList, "wed", 5);
    listAdd(newList, "wed", 6);

    size(newList);
    listPrint(newList);
    return newList;
}

void testListRemove(){
    ListType newList = testListAdd();
    listPrint(newList);

    listRemove(newList, "hello");
    listPrint(newList);
    size(newList);

    listRemove(newList, "goodbye");
    listPrint(newList);
    size(newList);

    listRemove(newList, "wed");
    listPrint(newList);
    size(newList);
}

void testContains(){
    ListType newList = testListAdd();

    cout<<listContains(newList, "hello");
    cout<<listContains(newList, "wed");
    cout<<listContains(newList, "goodbye");
    cout<<listContains(newList, "wilco");

}