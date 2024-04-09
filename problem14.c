#include <stdio.h>
#include <stdlib.h>
#define ARR_LENGTH 500000000

unsigned int collatz(unsigned int n, unsigned int *arr);

int main(){
	unsigned int *collatzArr;
	unsigned int i;
	unsigned int maxNum = 2;
	collatzArr = calloc(ARR_LENGTH, sizeof(unsigned int));
	if(collatzArr == NULL){
		printf("Error: couldn't allocate\n");
		return -1;
	}
	collatzArr[1] = 1;
	for(i = 2; i < 1000000; i++){
		if(collatzArr[i] == 0)
			collatz(i, collatzArr);
	}
	for(i = 2; i < 1000000; i++){
		if(collatzArr[i] > collatzArr[maxNum])
			maxNum = i;
	}
	printf("%d\n", maxNum);
	free(collatzArr);
}

/*return how many numbers are in the collatz sequence after itself*/
unsigned int collatz(unsigned int n, unsigned int *arr){
	unsigned int length;
	if(n >= ARR_LENGTH){
		if(n%2 == 0)
			return collatz(n/2, arr) + 1;
		else
			return collatz(3*n+1, arr) + 1;
	}
	if(arr[n] != 0)
		return arr[n] + 1;
	else if(n%2 == 0)
		length = collatz(n/2, arr);
	else
		length = collatz(3*n+1, arr);
	arr[n] = length + 1;
	return arr[n];
	
}
