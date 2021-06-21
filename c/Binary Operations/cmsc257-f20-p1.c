////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-f20-p1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMSC257.  See the related assignment page for details.
//										
//	Fill in the author name and last modified date below
//  Author        : Tyler Griggs
//  Last Modified : 10/2/2020
//

// Include Files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Project Includes
#include "p1-support.h"


//
// Functions

////////////////////////////////////////////////////////////////////////////////
// This is a sample comment for the main function	
// You should include a similar comment for each function you imoplemented within the .h file
//
// Function     : main
// Description  : The main function for the CMSC257 project #1
// 
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure

// Function 	: ???
    


int main(int argc, char *argv[]) {

	// Local variables
	// NOTE: this is where you will want to add some new variables
	int int_array1[10], int_array2[10];
	unsigned int uint_array1[10];
	int i;

	if (argc < 11)
	{
		printf("Exiting the program, missing input");
		return 0;	
	}
	// Step a - read in the integer numbers to process
	for (i=1; i<11; i++) {
		int_array1[i-1] = atoi(argv[i]);//converting input to integer

	}

	// Step b - Convert numbers into positive values by taking their 
	//           absolute values and save them in int_array2. 
	for (i=0; i<10; i++) {
		int_array2[i] = bitwise_abs(int_array1[i]);
	}

	// Print all numbers in a single line using display_array function
	display_array(int_array2, 10);

	// Step c - Convert these positive integers to numbers 
	//           in the range 0,…,128 by implementing the  mod operation
	//           save them back into int_array2. 
	for (i=0; i<10; i++) {
		int_array2[i] = bitwise_mod128(int_array2[i]);
	}

	// Print all numbers in a single line using display_array function
	display_array(int_array2, 10);

	// Step d - for each integer in int_array2 print: 
	//           number, count of 1 bits, even or odd
	//printf("Number, Count of 1s, Even or Odd\n");
	for (i=0; i<10; i++) {
		printf("[number %10d :", int_array2[i]);
		printf("# of bits:%10d ", count_bits(int_array2[i]));
		if (even_or_odd(int_array2[i]) == 1) {
			printf("   Even]\n");
		}
		else {
			printf("   Odd]\n");
		}
		
	}

	// Step e - Cast each element of int_array2 to unsigned int
	//			 and store them into uint_array1. 
	for (i=0; i<10; i++) {
		unsigned int new_num = int_array2[i];
		uint_array1[i] = new_num;
	}

	// Step f - Reverse the order of array elements in uint_array1 
	//           using swap function. 
	for (i=0; i<5; i++) {
		swap_ints(uint_array1[i], uint_array1[9 - i]);
	}

	// Step g - Update each element of uint_array1 by using reverse_bits function. 
	for (i=0; i<10; i++) {
		uint_array1[i] = reverse_bits(uint_array1[i]);
	}

	// Step h - Print each element of uint_array1 in a separate line along with 
	//           binary representation of each of the numbers using binary_string function. 
	for (i=0; i<10; i++) {
		printf("[number %10d :reversed:   ", int_array2[i]);
		printf("%u    ", uint_array1[i]);
		char *arr[32];
		binary_string(arr, uint_array1[i]);
		printf(" ]\n");
	}

	// Return successfully
	return(0);
}
