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

ListType makeList();

void testListAdd();

void testListRemove();

void testContains();

void printExp(string &, string &);

void testInd(ListType &, string &, string &);

int main() {

    testListAdd();

    testListRemove();

    testContains();

    return 0;
}

/**
 * helper function to make a linked list
 * @return a newly formed linked list
 */
ListType makeList(){
    ListType newList = NULL;
    listAdd(newList, "hello", 1);
    listAdd(newList, "goodbye", 2);
    listAdd(newList, "wed", 3);
    return newList;
}

/**
 * tests the add function of listFuncs.cpp
 */
void testListAdd(){
    cout <<"TESTING ADD FUNCTIONALITY"<<endl;

    ListType newList = NULL;
    string exp = "NULL";
    string expSize = "0";
    testInd(newList, exp, expSize);

    listAdd(newList, "hello", 1);
    exp = "hello : 1";
    expSize = "1";
    testInd(newList, exp, expSize);

    listAdd(newList, "goodbye", 2);
    exp = "goodbye : 2\nhello : 1";
    expSize = "2";
    testInd(newList, exp, expSize);

    listAdd(newList, "wed", 3);
    exp = "wed : 3\ngoodbye : 2\nhello : 1";
    expSize = "3";
    testInd(newList, exp, expSize);

    listAdd(newList, "wed", 4);
    exp = "wed:3\ngoodbye : 2\nhello : 1";
    expSize = "3";
    testInd(newList, exp, expSize);
}

/**
 * tests the remove function of listFuncs.cpp
 */
void testListRemove(){

    cout << "TESTING REMOVE FUNCTIONALITY"<<endl;
    ListType newList = makeList();
    string exp = "wed:3\ngoodbye : 2\nhello : 1";
    string expSize = "3";
    testInd(newList, exp, expSize);

    cout << "Trying to remove hello from the list"<<endl;
    listRemove(newList, "hello");
    exp = "wed:3\ngoodbye : 2";
    expSize = "2";
    testInd(newList, exp, expSize);

    cout << "Trying to remove unexpected from the list"<<endl;
    listRemove(newList, "unexpected");
    exp = "wed:3\ngoodbye : 2";
    expSize = "2";
    testInd(newList, exp, expSize);

    cout << "Trying to remove wed from the list"<<endl;
    listRemove(newList, "wed");
    exp = "goodbye : 2";
    expSize = "1";
    testInd(newList, exp, expSize);

    cout << "Trying to remove goodbye from the list"<<endl;
    listRemove(newList, "goodbye");
    exp = "";
    expSize = "0";
    testInd(newList, exp, expSize);

    cout << "Trying to remove hello from the list"<<endl;
    listRemove(newList, "hello");
    exp = "";
    expSize = "0";
    testInd(newList, exp, expSize);

    cout << "Repopulating the list" << endl;
    newList = makeList();
    exp = "wed:3\ngoodbye : 2\nhello : 1";
    expSize = "3";
    testInd(newList, exp, expSize);

    cout << "Trying to remove goodbye from the list"<<endl;
    listRemove(newList, "goodbye");
    exp = "wed:3\nhello : 1";
    expSize = "2";
    testInd(newList, exp, expSize);

    cout << "Repopulating the list" << endl;
    newList = makeList();
    exp = "wed:3\ngoodbye : 2\nhello : 1";
    expSize = "3";
    testInd(newList, exp, expSize);

    cout << "Trying to remove wed from the list"<<endl;
    listRemove(newList, "wed");
    exp = "goodbye : 2\nhello : 1";
    expSize = "2";
    testInd(newList, exp, expSize);

    cout << "Trying to remove goodbye and hello from the list"<<endl;
    listRemove(newList, "goodbye");
    listRemove(newList, "hello");
    exp = "";
    expSize = "0";
    testInd(newList, exp, expSize);

}

/**
 * tests the contains function of listFuncs.cpp
 */
void testContains(){
    ListType newList = makeList();
    newList = makeList();
    string exp = "wed:3\ngoodbye : 2\nhello : 1";
    string expSize = "3";
    testInd(newList, exp, expSize);

    cout << "Finding hello in the list"<<endl;
    cout << "The expected result is: 1" <<endl;
    cout << "The result is: " << * listContains(newList, "hello")<<endl;

    cout << "Finding wed in the list"<<endl;
    cout << "The expected result is: 3" <<endl;
    cout << "The result is: " << * listContains(newList, "wed")<<endl;


    cout << "Finding goodbye in the list"<<endl;
    cout << "The expected result is: 2" <<endl;
    cout << "The result is: " << * listContains(newList, "goodbye")<<endl;

    if(listContains(newList, "wilco") == NULL){
        cout << "NULL"<<"\n";
    }

}

/**
 * helper function to print the individual test of add
 * @param list the list ot be tested
 * @param result the expected result
 */
void testInd(ListType & list, string & result, string & size){
    printExp(result, size);
    cout << "The list printed out is: "<<endl;
    listPrint(list);
    cout << "The list size is: " << listSize(list) << "\n" <<endl;
}

/**
 * prints out the expected result
 * @param result expected result
 */
void printExp(string & result, string & size){
    cout << "The expected result is: " << endl;
    cout << result << "\nThe expected size is: " << size << endl;
}