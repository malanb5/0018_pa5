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
int * listContains(const ListType & list, const string target){
    ListType copyOfPointer = list;

    while(copyOfPointer != NULL){
        if(copyOfPointer -> key == target){
            return & copyOfPointer -> value;
        }
        copyOfPointer = copyOfPointer -> next;
    }

    return NULL;
}

int listSize(const ListType & list){

    ListType copyOfPointer = list;

    int counter = 0;

    while(copyOfPointer != NULL){
        ++counter;
        copyOfPointer = copyOfPointer-> next;
    }

  return counter;
}

bool listRemove(ListType & list, const string target){
    ListType copyOfPointer = list;

    if(list == NULL){
        return false;
    }
    // if the head of the list is the target delete the head and reassign the
    // pointer to point the next pointer in the list
    else if(list -> key == target){
        delete copyOfPointer;
        list = list -> next;
        return true;
    }
    // if there there are two Nodes in the linked list, loop through to find the target
    // if not there then return false
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

bool listAdd(ListType & list, const string keyToAdd, const int valueToAdd){
    ListType aNode;

    // if the list is empty, create a new node
    if(list == NULL){
        aNode = new Node(keyToAdd, valueToAdd);
    }
    else{
        // if the name is already present, return false
        if(listContains(list, keyToAdd) != NULL){
            return false;
        }
        // if the list is not empty, create a new node with the next pointer pointing to the head of the current list
        else{
            aNode = new Node(keyToAdd, valueToAdd, list);
        }
    }
    // the list pointer, now points to the new Node added
    list = aNode;
    return true;

}

void listPrint(const ListType & list){

    ListType copyOfPointer = list;

    // prints out a non-empty list
    if(copyOfPointer != NULL) {

        while (copyOfPointer != NULL) {
            cout << copyOfPointer->key << " " << copyOfPointer->value<<endl;
            copyOfPointer = copyOfPointer->next;
        }
    }
}