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
    data = new ListType[hashSize]();
    numberOfEntries = 0;

}

Table::Table(unsigned int hSize) {
    hashSize = hSize;
    data = new ListType[hashSize]();
    numberOfEntries = 0;
}

int * Table::lookup(const string &key) {
    int hashAddress = getHashAddress(key);

    return listContains(data[hashAddress], key);
}

bool Table::remove(const string &key) {
    if(lookup(key) == NULL){
        return false;
    }
    else{
        int hashAddress = getHashAddress(key);
        listRemove(data[hashAddress], key);
        --numberOfEntries;
        return true;
    }
}

bool Table::insert(const string &key, int value) {
    int hashAddress = getHashAddress(key);

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

void Table::printAll() const {

    if(numberOfEntries == 0){
        cout << "The table is empty."<<endl;
    }
    else{
        for(int address = 0; address < hashSize; ++address){
            listPrint(data[address]);
        }
    }

}

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
      out << "longest chain: " << findLongestChain() << endl;

}

int Table::getHashAddress(const string & key) const{
    int hash = hashCode(key);
    return hash % hashSize;

}


