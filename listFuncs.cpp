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

/**
 * determine if the target key is within the linked list or not
 * @param list the linked list to be searched
 * @param target the key to be searched for
 * @return whether or not the key is in the linked list
 */
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


/**
 * calculates the size of the linked list
 * @param list the linked list in question
 * @return the size of the linkedList
 */
int listSize(ListType & list){

    ListType copyOfPointer = list;

    int counter = 0;

    while(copyOfPointer != NULL){
        ++counter;
        copyOfPointer = copyOfPointer-> next;
    }

  return counter;
}

/**
 * deletes the target key and return true, if not there returns false
 * and the list remains unchanged
 * PRE: a non-empty, well-formed linked list
 * @param list a valid linkedList
 * @param target key to be located in the list
 * @return true and the entry removed, false the list remains unchanged
 */
bool listRemove(ListType & list, string target){
    ListType copyOfPointer = list;

    // checks the target is the base case of a list of 1 Node
    if(list -> next == NULL && list -> key == target){
        list = NULL;
        delete list;
        return true;
    }
    else{
        while(copyOfPointer->next != NULL && copyOfPointer -> next-> key != target){
            copyOfPointer = copyOfPointer ->next;
            if(copyOfPointer -> next == NULL) {
                return false;
            }
        }

        copyOfPointer -> next = copyOfPointer ->next ->next;
        delete copyOfPointer ->next;
        return true;

    }
}

/**
 * adds a node to the front of the linked list
 * @param list the linked list in question
 * @param keyToAdd the key to be added
 * @param valueToAdd the value to be added
 */
bool listAdd(ListType & list, string keyToAdd, int valueToAdd){
    ListType aNode;

    if(list == NULL){
        aNode = new Node(keyToAdd, valueToAdd);
    }
    else{
        if(listContains(list, keyToAdd)){
            return false;
        }
        else{
            aNode = new Node(keyToAdd, valueToAdd, list);
        }
    }

    list = aNode;
    return true;

}

/**
 * prints the linked list
 * @param list the linked list to be printed
 */

void listPrint(ListType & list){

    ListType copyOfPointer = list;

    if(copyOfPointer != NULL) {

        while (copyOfPointer != NULL) {
            cout << copyOfPointer->key << " : " << copyOfPointer->value << "  --->  ";
            copyOfPointer = copyOfPointer->next;
        }
        cout<<"NULL"<<endl;
    }
}
