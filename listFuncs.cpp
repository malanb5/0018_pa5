// Name: Matt Bladek
// USC NetID: bladek
// CSCI 455 PA5
// Spring 2018


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
    key = theKey;
    value = theValue;
    next = n;
}

//*************************************************************************
// put the function definitions for your list functions below


int listSize(ListType & list){

    ListType copyList = list;

    int counter = 0;

    while(copyList != NULL){
        ++counter;
        copyList = copyList-> next;
    }
  return counter;
}

bool listRemove(ListType &list, string target){

}

void listAdd(ListType & list, string target, int aValue){
    ListType aNode;

    if(list == NULL){
        aNode = new Node(target, aValue);
    }
    else{
        aNode = new Node(target, aValue, list);
    }
    list = aNode;

}

void listPrint(ListType & list){

    while(list != NULL){
        cout << list->key << " : " << list->value<<"  --->  ";
        list = list-> next;
    }
    cout<<endl;
}
