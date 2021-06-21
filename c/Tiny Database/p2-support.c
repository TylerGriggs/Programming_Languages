// Author: Tyler Griggs
// Last Edited: 10/23/2020
//  This file contains the logic for initialization a Database of Employee information
//      with functions to access/view, sort, and delete items from the Database
//      through a Textual User Interface.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"


void initialize (struct DataBase *db)
{
  db->emp = (struct Employee*) malloc(sizeof(struct Employee)*dbSIZE);
  //allocate memory for 100 employees

  db->total = 0;
  //there are 0 employees at the beginning
  
  createRecord ("00306", "Wei", "Martin", "wm@aol.com", 98999.99, db);
  createRecord ("00307", "Mitch", "Martinez", "mitch@aol.com", 78999.88, db);
  createRecord ("00408", "David", "Boyle", "db@aol.com", 100000.01, db);
  createRecord ("00204", "Christine", "Bluer", "cb@aol.com", 40009.99, db);
  createRecord ("00305", "Stephen", "Black", "sb@aol.com", 8500.01, db);
  createRecord ("00409", "Chris", "Boyle", "cb@aol.com", 200000.01, db);
  createRecord ("00101", "Paula", "Brown", "pb@aol.com", 1000.37, db);
  createRecord ("00102", "Paul", "Green", "pg@aol.com", 2700.45, db);
  createRecord ("00203", "Chris", "Reddy", "cr@aol.com", 2304.67, db);
  
}


void createRecord (char *id, char *first, char *last, char *email, double salary, struct DataBase *db)
{
    struct Employee* new_emp = (struct Employee*) malloc(sizeof(struct Employee));

	// Set the New Employee with the new data
	strncat(new_emp->ID, id, idSIZE);
    strncat(new_emp->FirstName, first, nameSIZE);
    strncat(new_emp->LastName, last, nameSIZE);
    strncat(new_emp->Email, email, emailSIZE);
    new_emp->Salary = salary;
    
	// Push the New_Employee data into the list
	db->emp[db->total] = new_emp;
    db->total++;

    // Free the temp Heap memory for Employee
    //free(new_emp);
    //new_emp = NULL;
}


char* makeFullName(char *first, char *last, char *temp)
{
    strncpy(temp, first, 20);
    strcat(temp, " ");
    strcat(temp, last);
    return temp;
}


void displayDatabase(struct DataBase *db)
{
    int i;
    printf("No. EmpID Employee Name        Email                Salary\n");
    printf("--- ----- -------------------- -------------------- ----------\n");
    for (i=0; i < db->total; i++)
    {
        char temp[20];
        printf("%-3d %-5s %-20s %-20s $%10.2f\n", i, db->emp[i]->ID, makeFullName(db->emp[i]->FirstName, db->emp[i]->LastName, temp), db->emp[i]->Email, db->emp[i]->Salary);
    }
    printf("\n");
    return;
}


void sortByID(struct DataBase *db)
{
    int i, j;
    struct Employee *temp;
    for (i=0; i < db->total-1; i++)
    {
        for (j=i+1; j < db->total; j++)
        {
            if (strcmp(db->emp[i]->ID, db->emp[j]->ID) > 0)
            {
                temp =  db->emp[i];
                db->emp[i] = db->emp[j];
                db->emp[j] = temp;
            }
        }
    }
    //free(temp);
    //temp = NULL;
    return;
}


void searchByID(struct DataBase *db, char *id)
{
    int i;
    printf("No. EmpID Employee Name        Email                Salary\n");
    printf("--- ----- -------------------- -------------------- ----------\n");
    for (i=0; i < db->total; i++)
    {
        if (strcmp(db->emp[i]->ID, id) == 0)
        {
            char temp[20];
            printf("%-3d %-5s %-20s %-20s $%10.2f\n", i, db->emp[i]->ID, makeFullName(db->emp[i]->FirstName, db->emp[i]->LastName, temp), db->emp[i]->Email, db->emp[i]->Salary);
        }
    }
    printf("\n");
    return;
}


void searchByLastName(struct DataBase *db, char *lastname)
{
    int i;
    printf("No. EmpID Employee Name        Email                Salary\n");
    printf("--- ----- -------------------- -------------------- ----------\n");
    for (i=0; i < db->total; i++)
    {
        if (strcmp(db->emp[i]->LastName, lastname) == 0)
        {
            char temp[20];
            printf("%-3d %-5s %-20s %-20s $%10.2f\n", i, db->emp[i]->ID, makeFullName(db->emp[i]->FirstName, db->emp[i]->LastName, temp), db->emp[i]->Email, db->emp[i]->Salary);
            // Include other employees in search results by iterating through list
        }
    }
    printf("\n");
    return;
}


void deleteByID(struct DataBase *db, char *id)
{
    int i, j;
    printf("No. EmpID Employee Name        Email                Salary\n"); 
    printf("--- ----- -------------------- -------------------- ----------\n");
    for (i=0; i < db->total; i++)
    {
        if (db->emp[i] != NULL && strcmp(db->emp[i]->ID, id) == 0)
        {   
            char temp[20];
            printf("%-3d %-5s %-20s %-20s $%10.2f\n", i, db->emp[i]->ID, makeFullName(db->emp[i]->FirstName, db->emp[i]->LastName, temp), db->emp[i]->Email, db->emp[i]->Salary);
            
            // For the rest of the Database
            for (j=i; j < db->total-1; j++)
            {   
                //Put the next Employee into the current slot
                db->emp[i] = db->emp[j+1];
            }

            db->total--;
            printf("\n");
            return;
        }
    }
    printf("\n");
    return;
}


void deleteByLastName(struct DataBase *db, char *lastname)
{
    int i, j;
    printf("No. EmpID Employee Name        Email                Salary\n");
    printf("--- ----- -------------------- -------------------- ----------\n");
    for (i=0; i < db->total; i++)
    {
        if (db->emp[i] != NULL && strcmp(db->emp[i]->LastName, lastname) == 0)
        {
            char temp[20];
            printf("%-3d %-5s %-20s %-20s $%10.2f\n", i, db->emp[i]->ID, makeFullName(db->emp[i]->FirstName, db->emp[i]->LastName, temp), db->emp[i]->Email, db->emp[i]->Salary);
            
            // For the rest of the Database
            for (j=i; j < db->total-1; j++)
            {
                //Put the next Employee into the current slot
                db->emp[i] = db->emp[j+1];
            }
            
            db->total--;
            printf("\n");
            return;
        }
    }
    printf("\n");
    return;
}


void quit(struct DataBase *db)
{
    int i;
    for (i=0; i < db->total2; i++)
    {
        free(db->emp[i]);
        db->emp[i] = NULL;
    }

    free(db->emp);
    free(db);
    db = NULL;
}


void displayMenu (struct DataBase *db)
{
    int i;
    char id_string[idSIZE];
    char name_string[nameSIZE];
    while(1)
    {
        printf("**************************************************************\n****** USERNAME Employee Database - Total Employees:  %d ******\n**************************************************************\n\n", db->total);
        printf("Choose one of the menu options below:\n");
        printf("1. Sort with ID\n");
        printf("2. Display all employees\n");
        printf("3. Search employee by ID\n");
        printf("4. Search employee by Last Name\n");
        printf("5. Delete employee by ID\n");
        printf("6. Delete employee by last Name\n");
        printf("7. Exit\n");
        if (scanf("%d", &i) <= 0)
		{
			printf("Enter only an Integer\n");
			exit(0);
		}
		else
		{
			switch (i)
			{
			case 1:
				sortByID(db);
				break;

			case 2:
				displayDatabase(db);
				break;

			case 3:
                printf("Enter the ID you are searching for\n");
                scanf("%s", id_string);
				searchByID(db, id_string);
				break;

			case 4:
				printf("Enter the Lastname you are searching for\n");
                scanf("%s", name_string);
                searchByLastName(db, name_string);
				break;

			case 5:
				printf("Enter the ID you are searching for\n");
                scanf("%s", id_string);
                deleteByID(db, id_string);
                sortByID(db);
				break;

            case 6:
				printf("Enter the Last Name you are searching for\n");
                scanf("%s", name_string);
                deleteByLastName(db, name_string);
                sortByID(db);
				break;

			case 7:
				quit(db);
                printf("Bye!\n");
				return;

			default:
				printf("Invalid option\n");
			}
		}
    }
}
