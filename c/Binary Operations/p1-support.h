#ifndef CMSC257_A1SUPPORT_INCLUDED
#define CMSC257_A1SUPPORT_INCLUDED

////////////////////////////////////////////////////////////////////////////////
//
//  File          : p1-support.h
//  Description   : This is a set of general-purpose utility functions we use
//                  for the 257 assignment #1.
//

//
// Functional Prototypes
//
// Include description, input and output for each function here in this file
// You don't need to copy them into the p1-support.c file.	There is a sample
// for main function within the ..p1.c file.


////////////////////////////////////////////////////////////////////////////////
// Function     : display_array
// Description  : Print Interger Array; When passed an array containing
// 					integers, will print each integer seperated by 5 spaces.
// Inputs       : arr - integer array
//                size - the number of indexs/size of the array
void display_array(int arr[], int size);


////////////////////////////////////////////////////////////////////////////////
// Function     : count_bits
// Description  : Given an integer, using bitwise operations count the number
//					of 1's in the binary representation of the that number.
//					While there are positive bits in the integer, step through 
//					the binary number by setting equal to 0 if 1 and adding to count. 
//					This occurs until the entire binary number is 0s, aka FALSE.
// Inputs       : num1 - an unsigned int to inverse using bitwise operation
int count_bits(int num);


////////////////////////////////////////////////////////////////////////////////
// Function     : reverse_bits
// Description  : Given an unsigned integer, swap the binary digits. Using a
//					temporary reverse_num unsigned int, go bit by bit though each number,
//					setting the reverse_num to inverse outcome.
// Inputs       : num1 - an unsigned int to inverse using bitwise operation
unsigned int reverse_bits(unsigned int num);


////////////////////////////////////////////////////////////////////////////////
// Function     : binary_string
// Description  : Print Binary Reprentation of Unsigned Integer; When passed
//					an empty string, and an unsigned int, print elegantly the 
//					binary representation of the passed unsigned int
// Inputs       : arr - empty char array (string)
//                num - an unsigned int to be converted to binary and printed
void binary_string(char *arr[], unsigned int num);


////////////////////////////////////////////////////////////////////////////////
// Function     : bitwise_mod128
// Description  : Given an integer, using bitwise operations, check up to the
//						7th (value=128) bit, and return the bits that are not 0.
//						This is the bitwise Modulus function, or division with remainder.
// Inputs       : num - an integer to modulus divide by 128 using bitwise operations
int bitwise_mod128(int num);


////////////////////////////////////////////////////////////////////////////////
// Function     : bitwise_abs
// Description  : Given an integer stored using 32-bit format, by inverting all
//					the binary integers and adding a binary 1. This effectively
//					removes the left most bit, for negative 2-compliment numbers.
// Inputs       : num1 - an integer to convert to its absolute value, bitwise 
int bitwise_abs(int num);


////////////////////////////////////////////////////////////////////////////////
// Function     : bit_get
// Description  : Return Desired Bit; Passed two integers, return the binary digit
//					located at the specified integer index in the binary representation.
//					By shifting a binary 1 a number of times, end up on the desired index
//                      I did not end up needing to use this function but tried to implement.
// Inputs       : num1 - integer to be represented in binary
//                num2 - the number of the binary num1 index to return
int bit_get(int num1, int num2);


////////////////////////////////////////////////////////////////////////////////
// Function     : even_or_odd
// Description  : Given an integer, return a 0 or 1 for Odd or Even.
//					Checks to see if the last bit changes, after inverting and 
//						adding one through binary operations, then return values accordingly.
// Inputs       : num - an integer that determines the odd or even return value
int even_or_odd(int num);


////////////////////////////////////////////////////////////////////////////////
// Function     : swap_ints
// Description  : Swap Two Unsigned Integers (no temporary varible); Using the 
//						binary operator XOR (^)
// Inputs       : num1 - an unsigned int to be encoded to num2
//                num2 - an unsigned int to be encoded to num1
void swap_ints(unsigned int num1, unsigned int num2);


#endif // CMSC257_A1SUPPORT_INCLUDED
