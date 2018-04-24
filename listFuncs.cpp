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

int * listContains(ListType & list, string target){
    ListType copyOfPointer = list;

    while(copyOfPointer != NULL){
        if(copyOfPointer -> key == target){
            return & copyOfPointer -> value;
        }
        copyOfPointer = copyOfPointer -> next;
    }

    return NULL;
}

int listSize(ListType & list){

    ListType copyOfPointer = list;

    int counter = 0;

    while(copyOfPointer != NULL){
        ++counter;
        copyOfPointer = copyOfPointer-> next;
    }

  return counter;
}

bool listRemove(ListType & list, string target){
    ListType copyOfPointer = list;

    if(list == NULL){
        return false;
    }
    else if(list -> key == target){
        delete copyOfPointer;
        list = list -> next;
        return true;
    }
    else{
        while(copyOfPointer ->next != NULL){
            if(copyOfPointer ->next -> key == target){
                delete copyOfPointer -> next;
                copyOfPointer -> next = copyOfPointer -> next -> next;
                return true;
            }
            copyOfPointer = copyOfPointer -> next;
        }
        return false;
    }
}

bool listAdd(ListType & list, string keyToAdd, int valueToAdd){
    ListType aNode;

    if(list == NULL){
        aNode = new Node(keyToAdd, valueToAdd);
    }
    else{
        if(listContains(list, keyToAdd) != NULL){
            return false;
        }
        else{
            aNode = new Node(keyToAdd, valueToAdd, list);
        }
    }

    list = aNode;
    return true;

}

void listPrint(ListType & list){

    ListType copyOfPointer = list;

    if(copyOfPointer != NULL) {

        while (copyOfPointer != NULL) {
            cout << copyOfPointer->key << " " << copyOfPointer->value<<endl;
            copyOfPointer = copyOfPointer->next;
        }
    }
}