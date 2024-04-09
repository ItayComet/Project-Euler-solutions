#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGTH 1000
#define POWER 1000

int multBy2(int *arr, int len);

int main(){
	int *arr;
	int i, len, sum = 0;
	arr = malloc(ARR_LENGTH * sizeof(int));
	if(arr == NULL){
		printf("couldn't allocate\n");
		return -1;
	}
	len = 1;
	arr[0] = 2;
	for(i = 0; i < POWER - 1; i++){
	len = multBy2(arr, len);
	}
	for(i = 0; i < len; i++){
		sum += arr[i];
	}
	printf("%d\n", sum);
}

int multBy2(int *arr, int len){
	int i, curr, offset = 0;
	for(i = 0; i < len; i++){
		curr = arr[i]*2+offset;
		arr[i] = curr % 10;
		offset = curr / 10;
	}
	if (offset > 0){
		arr[len] = offset;
		return len + 1;
	}
	return len;
}
