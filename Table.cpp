// Name: Matt Bladek
// USC NetID: bladek
// CSCI 455 PA5
// Spring 2018

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"

//*************************************************************************


Table::Table() {
    hashSize = HASH_SIZE;
    data = new ListType[hashSize];
    numberOfEntries = 0;

}

Table::Table(unsigned int hSize) {
    hashSize = hSize;
    data = new ListType[hashSize]();
    numberOfEntries = 0;
}

/**
 * checks if the key is present in the table
 * @param key the target to be looked up in the table
 * @return whether or not the key is present
 * NULL if not present, the value if present
 */
int * Table::lookup(const string &key) {
    int hash = hashCode(key);
    int hashAddress = hash % hashSize;

    ListType location = data[hashAddress];

    return listContains(location, key);
}



bool Table::remove(const string &key) {
    return false;  // dummy return value for stub
}

/**
 * inserts a Node into the hashTable if possible
 * @param key the key to be inserted into the hashTable
 * @param value the value assocaited with the key
 * @return
 */
bool Table::insert(const string &key, int value) {
    int hash = hashCode(key);
    int hashAddress = hash % hashSize;

    if(listAdd(data[hashAddress], key, value)){
        ++numberOfEntries;
        return true;
    }
    else{
        return false;
    }
}

int Table::numEntries() const {
    return numberOfEntries;
}

/**
 * prints out the contents of the hashtable
 */
void Table::printAll() const {

    for(int address = 0; address < hashSize; ++address){
        listPrint(data[address]);
    }

}


// add definitions for your private methods here
int Table::countNonEmptyBuckets() const{
      int counter = 0;

      for(int address = 0; address < hashSize; address++){
          if(data[address] != NULL){
            ++counter;
            }
      }
      return counter;
}

int Table::findLongestChain() const{
      int max = 0;
      int counter = 0;

      for(int address = 0; address < hashSize; ++address){
          if(data[address] != NULL){
            counter = listSize(data[address]);
            if(counter >max){
                max = counter;
            }
            }
      }

    return max;
}

void Table::hashStats(ostream &out) const {
      out << "number of buckets: " << hashSize <<"\n";
      out << "number of entries: " << numEntries() <<"\n";
      out << "number of non-empty buckets: " << countNonEmptyBuckets()<<"\n";
      out << "longest chain: " << findLongestChain()<<endl;

}


