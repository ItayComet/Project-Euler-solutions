#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int main(){
	long **arr;
	long i, j;
	arr = malloc(sizeof(long *) * (SIZE + 1));
	if(arr == NULL){
		printf("Error: allocation failed.\n");
		return -1;
	}
	for(i = 0; i < (SIZE + 1); i++){
		arr[i] = malloc((SIZE + 1)*sizeof(long));
		if(arr[i] == NULL){
			i--;
			while (i >= 0){
				free(arr[i]);
				i--;
			}
			free(arr);
			printf("Error: allocation failed.\n");
			return -1;
		}
	}
	for(i = SIZE; i >= 0; i--){
		for(j = SIZE; j >= 0; j--){
			if(i == SIZE || j == SIZE)
				arr[i][j] = 1;
			else
				arr[i][j] = (arr[i+1][j] + arr[i][j+1]);
		}
	}
	printf("%ld\n", arr[0][0]);
	
	for(i = 0; i < SIZE + 1; i++){
		free(arr[i]);
	}
	free(arr);
}
