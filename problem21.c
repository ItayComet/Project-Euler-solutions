#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

void fillD(int *d);
int sumOfAmics(int *d);

int main(){
	int *d;/*d[i] = d(i)*/
	
	d = malloc(SIZE*sizeof(int));
	fillD(d);
	printf("%d\n", sumOfAmics(d));
	free(d);
}

int findSumOfDivs(int n){
	int i;
	int sum = 1;
	for(i = 2; i <= n/2; i++){
		if(n%i == 0)
			sum += i;
	}
	return sum;
}

void fillD(int *d){
	int i;
	
	for(i = 1; i < SIZE; i++)
		d[i] = findSumOfDivs(i);
	
}

int isAmic(int *d, int a){
	int b = d[a];
	if(a != b){
		if(d[b] == a)
			return 1;
	}
	return 0;
}

int sumOfAmics(int *d){
	int i;
	int sum = 0;
	for(i = 1; i < SIZE; i++){
		if(isAmic(d, i))
			sum += i;
	}
	return sum;
}
