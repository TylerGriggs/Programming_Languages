// Author: Tyler Griggs
// Last Edited: 10/23/2020
//    This header file contains descriptions of the functions used in 
//     CMSC257 Project #2.

#define dbSIZE 100
#define idSIZE 6
#define nameSIZE 11
#define emailSIZE 21

struct Employee
{
  char ID[idSIZE];
  char FirstName[nameSIZE];
  char LastName[nameSIZE];
  char Email[emailSIZE];
  double Salary;
};

struct DataBase
{
  struct Employee **emp;
  int total;
};



/////////////////////////////////////////////////////////////////////////////////////
// Function     : initialize
// Description  : Initializes the database for CMSC257 project #2 by manually entering 
//                the records using createRecord function
// Inputs       : struct DataBase * - pointer to the database    
// Outputs      : void
void initialize (struct DataBase *db);


/////////////////////////////////////////////////////////////////////////////////////
// Function     : createRecord
// Description  : Creates and appends a new employee record or entry in the Employee Database
// Inputs       : char id * - pointer to charactar array
//              : char first * - pointer to charactar array
//              : char last * - pointer to charactar array
//              : char email * - pointer to charactar array
//              : double salary - floating point salary number
//              : struct DataBase * - pointer to the database
// Outputs      : void
void createRecord (char *id, char *first, char *last, char *email, double salary, struct DataBase *db);


/////////////////////////////////////////////////////////////////////////////////////
// Function     : makeFullName
// Description  : Concatenates two char arrays with a space in between
// Inputs       : char * - pointer to char array, First name (string) to append a ' ' after   
//              : char * - pointer to char array, Last name (string) to append on the end 
// Outputs      : char * - pointer to char array, Full Name, (first + ' ' + last)
char* makeFullName (char *first, char *last, char *temp);


/////////////////////////////////////////////////////////////////////////////////////
// Function     : displayDatabase
// Description  : Prints out each entry in the database with human-readable formatting
// Inputs       : struct DataBase * - pointer to the database
// Outputs      : void
void displayDatabase (struct DataBase *db);


/////////////////////////////////////////////////////////////////////////////////////
// Function     : sortByID
// Description  : Sorts all entries in the Database by Employee ID, from lowest to highest
// Inputs       : struct DataBase * - pointer to the database
// Outputs      : void
void sortByID (struct DataBase *db);


/////////////////////////////////////////////////////////////////////////////////////
// Function     : searchByID
// Description  : Prints out each entry in the Database with a matching Employee ID
// Inputs       : struct DataBase * - pointer to the database
//              : char * - pointer to char array, Employee ID to search in Database
// Outputs      : void
void searchByID (struct DataBase *db, char *id);


/////////////////////////////////////////////////////////////////////////////////////
// Function     : searchByLastName
// Description  : Prints out each entry in the Database with a matching Employee LastName
// Inputs       : struct DataBase * - pointer to the database
//              : char * - pointer to char array, Employee LastName to search in Database
// Outputs      : void
void searchByLastName (struct DataBase *db, char *lastname);


/////////////////////////////////////////////////////////////////////////////////////
// Function     : deleteByID
// Description  : Deletes the first entry in the Database with a matching Employee ID
// Inputs       : struct DataBase * - pointer to the database
//              : char * - pointer to char array, Employee ID to search in Database
// Outputs      : void
void deleteByID (struct DataBase *db, char *id);


/////////////////////////////////////////////////////////////////////////////////////
// Function     : deleteByLastName
// Description  : Deletes the first entry in the Database with a matching Employee Lastname
// Inputs       : struct DataBase * - pointer to the database
//              : char * - pointer to char array, Employee LastName to search in Database
// Outputs      : void
void deleteByLastName (struct DataBase *db, char *lastname);


/////////////////////////////////////////////////////////////////////////////////////
// Function     : quit
// Description  : Frees memory associated with each Employee, Then the Employee array,
//                  Then the Database itself. This function is only called right before
//                  the program exits.
// Inputs       : struct DataBase * - pointer to the database
// Outputs      : void
void quit(struct DataBase *db);


/////////////////////////////////////////////////////////////////////////////////////
// Function     : displayMenu
// Description  : Prints out a textual user interface for the user to access the database
//                  Allows user to view and perform functions on data in the database
// Inputs       : struct DataBase * - pointer to the database    
// Outputs      : void
void displayMenu (struct DataBase *db);
