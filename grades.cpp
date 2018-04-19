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

bool processCommand(Table * &, string &, string &, int &);

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

  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*

  return 0;
}

void startUp(Table * & grades){
    grades->hashStats(cout);

    grades->insert("Matt", 100);
    grades->insert("Deborah", 300);
    grades->insert("Ceasar", 3400);
    grades->insert("God", 500);
    grades->insert("Matt", 103);

    grades->printAll();

    grades->hashStats(cout);
}

/**
 * Gets user input and process the command
 * PRE: user entry is in the form <command> <name> <score>
 * or <name> <score>
 * PRE: name must no have any spaces in it
 * @param grades
 */
void executeOptions(Table * & grades){
    string line = "";
    string delimiter = " ";
    size_t found = 0;
    size_t nameEnd = 0;
    string command = "";
    string name = "";
    int score = 0;

    bool running = true;

    while(running){
        cout << "cmd> ";
        getline(cin, line);
        found = line.find(delimiter);

        if(found != string::npos){
            command = line.substr(0, found);
            string rest = line.substr(found + 1, line.length());
            nameEnd= rest.find(delimiter);

            if(command == "change" || command == "insert"){
                name = rest.substr(0, nameEnd);
                score = stoi(rest.substr(nameEnd + 1, rest.length()));
            }
            else if(command == "lookup" || command == "remove"){
                name = rest.substr(0, nameEnd);
            }
        }
        else{
            command = line;
        }

        running = processCommand(grades, command, name, score);
    }

}

bool processCommand(Table * & grades, string & command, string & name, int & score){
    bool keepRunning = true;

    if(command == "change") {

    }
    else if(command == "insert") {
        grades -> insert(name, score);
    }
    else if(command == "lookup") {

    }
    else if (command == "remove") {

    }
    else if (command == "print") {
        grades -> printAll();
    }

    else if( command == "size") {
        grades -> numEntries();
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
    }

    return keepRunning;

}

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



