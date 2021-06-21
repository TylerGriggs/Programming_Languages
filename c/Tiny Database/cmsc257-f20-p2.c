// Author: Tyler Griggs
// Last Edited: 10/23/2020
//  This program is the main driving program for CMSC257 project #2 
//    The function creates a Database to store Employee information
//    and calling functions to initialize the Database
//    and output a menu to the user in order to access
//    and modify the Database.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"


int main ()
{
  struct DataBase* db; 
  db = malloc(sizeof(struct DataBase));
  initialize (db);
  displayMenu (db);
  return 0;
}
