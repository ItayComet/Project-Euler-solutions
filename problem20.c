#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int len);
int mult(int *num, int len, int num2);
int sumArr(int *arr, int len);

int main(){
	int *fact;
	int counter = 99;
	int sum;
	int currLen = 3;
	fact = malloc(sizeof(int)*200);
	fact[0] = 0;
	fact[1] = 0;
	fact[2] = 1;
	printf("%d\n", sumArr(fact, currLen));
	while(counter > 1){
		printArr(fact, currLen);
		currLen = mult(fact,currLen, counter);
		counter--;
	}
	sum = sumArr(fact, currLen);
	free(fact);
	printf("%d\n", sum);
	
}

/*length of num2 will always be less than length of num1*/
int addNumArrays(int *num1, int *num2, int len1, int len2){
	int i, currAdded;
	int offset = 0;
	for(i = 0; i < len2; i++){
		currAdded = (num1[i]+num2[i]+offset);
		num1[i] = currAdded%10;
		offset = currAdded/10;
	}
	while((offset != 0) && (i < len1)){
		currAdded = num1[i]+offset;
		num1[i] = currAdded%10;
		offset = currAdded/10;
		i++;
	}
	if(offset != 0){
		num1[i] = offset;
		return len1 + 1;
	}
	return len1;
}

int mult(int *num, int len, int num2){
	int i;
	int *tempNum;
	int currLen = len;
	tempNum = malloc(sizeof(int)*len);
	for(i = 0; i < len; i++)
		tempNum[i] = num[i];
	for(i = 1; i < num2; i++)
		currLen = addNumArrays(num, tempNum, currLen, len);
	free(tempNum);
	return currLen;
}

int sumArr(int *arr, int len){
	int i, sum = 0;
	for(i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

void printArr(int *arr, int len){
	int i;
	for(i = len - 1; i >= 0; i--)
		printf("%d", arr[i]);
	printf("\n");
}
