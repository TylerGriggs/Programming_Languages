#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define CHAR_BIT 8 


void display_array(int arr[], int size) {
	int i;
	for (i=0;i<size;i++){
		printf("%5d ", arr[i]); 
	}
	printf("\n");
}


int bit_get(int num1, int num2) {
	((num1 & ( 1 << num2 )) >> num2);
	return num1;
}


void binary_string(char *arr[], unsigned int num) {
	unsigned i;
	int count = 0;

	printf("0b");

    for (i = (1 << 31) ; i > 0; i = (i >> 1)) {
		if (num & i) {
			arr[count] = "1";
			printf("1");
		} else {
			arr[count] = "0";
			printf("0");
		}
		count = count + 1;
	}
}


void swap_ints(unsigned int num1, unsigned int num2) {
	num1 ^= num2; //num1 = (num1 ^ num2)
    num2 ^= num1;
    num1 ^= num2;
}


unsigned int reverse_bits(unsigned int num){
	unsigned int NO_OF_BITS = sizeof(num) * CHAR_BIT; 
    unsigned int reverse_num = 0, i; 
  
    for (i = 0; i < NO_OF_BITS; i++) 
    {
        if( (num & (1 << i)) ) {
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
		}
    }
    return reverse_num; 
}


int count_bits(int num){
	unsigned int count = 0; 
    while (num) { 
        count += num & 1; 	//if last bit is 1, increment count 
        num >>= 1; 			//shift binary right
    } 
    return count;
}


int bitwise_abs(int num) 
{ 
    int const mask = num >> (sizeof(int) * CHAR_BIT - 1); 
    return ((num ^ mask) - mask); 
}


int bitwise_mod128(int num) { 
	return ( num & (128 - 1) ); 
}


int even_or_odd(int num){
    if ((num ^ 1) == num + 1)
        return 1;
    else
        return 0;
}
