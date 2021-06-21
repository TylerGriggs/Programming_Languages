// Include Files
#include <stdio.h>
// Project Includes
#include "lab2header.h"
// Function Implementations

int reverse_number(int num)
{
  int reversed = 0;
  while(num > 0) {
	reversed = reversed * 10 + num % 10;
	num = num / 10;
  }
  return reversed;
}

int even_odd(int num)
{
 if (num % 2 == 0){
	printf("Your number is even\n");	
 }
 else {
	printf("Your number is odd\n");
 }
return num;
}


int is_prime(int num)
{
  int flag = 1;
  int i;
  for (i = 2; i < num; i++){
  	if (num % i == 0) {
		printf("Your number is not prime\n");
		flag = 0;
		break;
	}
  }
  if (flag == 1){
	printf("Your number is prime\n");
  } 
  
  return flag;
}

