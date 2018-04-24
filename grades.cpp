// Name: Matt Bladek
// USC NetID: bladek
// CSCI 455 PA5
// Spring 2018

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

void startUp(Table * &);

void executeOptions(Table * &);

void displayHelp();

void displaySize(int &);

bool processCommand(Table * &, string &, string &, int &);

void executeChange(Table * &, string &, int &);

void executeLookup(Table * &, string &);

void executeRemove(Table * &, string &);

int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number" 
	   << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }

  executeOptions(grades);

  return 0;
}

/**
 * Gets user input and process the command
 * PRE: user entry is in the form <command> or <command> <name> <score> or <command> <name>
 * PRE: name has no spaces in it
 * PRE: a well-formed Hash Table grades
 * PRE: there are no extra spaces after just a <command> input or in between the parameter inputs
 * @param grades HashTable instance
 */
void executeOptions(Table * & grades){
    string input = "";
    const string DELIMITER = " ";
    const int START = 0;
    const int OFFSET = 1;
    size_t foundLocation = 0;
    size_t nameEndLocation = 0;
    string command = "";
    string name = "";
    int score = 0;

    bool running = true;

    while(running){
        cout << "cmd> ";
        getline(cin, input);

        foundLocation = input.find(DELIMITER);

        // if there are spaces in the input
        if(foundLocation != string::npos){

            command = input.substr(START, foundLocation);
            string restOfWord = input.substr(foundLocation + OFFSET, input.length());
            nameEndLocation= restOfWord.find(DELIMITER);

            if(command == "change" || command == "insert"){
                name = restOfWord.substr(START, nameEndLocation);
                score = stoi(restOfWord.substr(nameEndLocation + OFFSET, restOfWord.length()));
            }
            else if(command == "lookup" || command == "remove"){
                name = restOfWord.substr(START, nameEndLocation);
            }
        }
        else{
            command = input;
        }
        running = processCommand(grades, command, name, score);
    }

}

/**
 * processes the user inputted command
 * PRE: name has no spaces
 * PRE: a well-formed Hash-Table grades
 * @param grades a Hash Table which will be used to store names and scores
 * @param command the user inputted command
 * @param name the key of the table
 * @param score the value associated with the name
 * @return whether or not to continue processing commands, will only be false on the command quit
 */
bool processCommand(Table * & grades, string & command, string & name, int & score){
    bool keepRunning = true;

    if(command == "change") {
        executeChange(grades, name, score);
    }
    else if(command == "insert") {
        grades -> insert(name, score);
    }
    else if(command == "lookup") {
        executeLookup(grades, name);
    }
    else if (command == "remove") {
        executeRemove(grades, name);
    }
    else if (command == "print") {
        grades -> printAll();
    }
    else if( command == "size") {
        int size = grades -> numEntries();
        displaySize(size);
    }
    else if (command == "stats") {
        grades -> hashStats(cout);
    }
    else if(command == "help") {
        displayHelp();
    }
    else if (command == "quit") {
        cout <<"Exiting program."<<endl;
        keepRunning = false;
    }
    else{
        cout << "ERROR: invalid command"<<endl;
        displayHelp();
    }

    return keepRunning;

}

/**
 * prints out the size of the table
 * PRE: size is non-negative
 * @param size the size of the table
 */
void displaySize(int & size){
    if(size == 0){
        cout << "The table is empty."<<endl;
    }
    else if (size ==1){
        cout << "There is "<< size << " entry in the table."<<endl;
    }
    else{
        cout << "There are " << size << " entries in the table." <<endl;
    }
}

/**
 * displays the help command summary
 */
void displayHelp(){
    cout << "COMMAND SUMMARY:\n";
    cout << "insert <name> <score>      Insert this name and score in the grade table. ";
    cout << "If this name was already present, doesn't do the insert.\n";
    cout << "change <name> <score>      Changes the score for name if present.\n";
    cout << "lookup <name>              Prints out the name prints out his or her score if present.\n";
    cout << "remove <name>              Remove the student if present.\n";
    cout << "print      Print all the names and scores in the table\n";
    cout << "size       Prints out the number of entries in the table.\n";
    cout << "stats      Prints out statistics about the hash table at this point.\n";
    cout << "help       Prints out a brief command summary.\n";
    cout << "quit       Exits the program\n";
}

/**
 * removes the name if present and inserts the new name and score
 * @param grades a well-formed HashTable
 * @param name a valid name with no spaces
 * @param score the score to be inserted into the table associated with the name
 */
void executeChange(Table * & grades, string & name, int & score){
    int * result = grades -> lookup(name);

    if(result == NULL){
        cout << name << " is not present. Cannot change."<<endl;
    }
    else{
        grades -> remove(name);
        grades -> insert(name, score);
    }
}

/**
 * executes a lookup with a given name on the Table and prints the his or her score
 * or indicates if the student is not present
 * @param grades the Table for the lookup to be performed on
 * @param name key to be looked up
 */
void executeLookup(Table * & grades, string & name){

    int * result = grades ->lookup(name);

    if(result == NULL){
        cout << "The result is not present"<<endl;
    }
    else{
        cout<< "Score: "<< * result <<endl;
    }
}

/**
 * executes the remove of a key from the table.  Prints whether or not it worked.
 * @param grades the table from which to remove from
 * @param name the key to be removed from the table
 */
void executeRemove(Table * & grades, string & name){
    bool result = grades -> remove(name);
    if(result){
        cout << name <<" successfully removed."<<endl;
    }
    else{
        cout << name <<" not present. Please try again."<<endl;
    }
}

