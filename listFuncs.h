// Name: Matt Bladek
// USC NetID: bladek
// CSCI 455 PA5
// Spring 2018


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);

};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

/**
 * determine if the target key is within the linked list or not
 * @param list the linked list to be searched
 * @param target the key to be searched for
 * @return whether or not the key is in the linked list
 */
int * listContains(ListType & list, string target);

/**
 * deletes the target key and return true, if not there returns false
 * and the list remains unchanged
 * @param list a valid linkedList
 * @param target key to be located in the list
 * @return true and the entry removed, false the list remains unchanged
 */
bool listRemove(ListType & list, string target);

/**
 * adds a node to the front of the linked list
 * @param list the linked list in question
 * @param keyToAdd the key to be added
 * @param valueToAdd the value to be added
 */
bool listAdd(ListType & list, string target, int aValue);

/**
 * calculates the size of the linked list
 * @param list the linked list in question
 * @return the size of the linkedList
 */
int listSize(ListType & list);

/**
 * prints the linked list
 * @param list the linked list to be printed
 */
void listPrint(ListType & list);

// keep the following line at the end of the file
#endif
