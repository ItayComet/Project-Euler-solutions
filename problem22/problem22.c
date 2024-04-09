#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define SIZE_OF_ARR 8000
#define MAX_STRING_SIZE 30

char** allocStringArr(int size);
unsigned long long int sumOfNameScores(char** arr, int numOfNames);
void freeStringArr(char** pt, int size);
void quickSort(char** arr, int low, int high);
int fillFromFile(char** arr, FILE *fp);
void printNames(char** arr, int numOfNames);

int main(int argc, char **argv){
	FILE *fp;
	char** arr;
	int numOfNames;
	
	fp = fopen(argv[1], "r");
	arr = allocStringArr(SIZE_OF_ARR);
	if(arr == NULL){
		printf("Error: couldn't allocate memory\n");
		return 1;
	}
	printf("Memory allocated\n");
	numOfNames = fillFromFile(arr, fp);
	printf("Filled %d names\n", numOfNames);
	quickSort(arr, 0, numOfNames - 1);
	printf("Score is %llu\n", sumOfNameScores(arr, numOfNames));
	fclose(fp);
	freeStringArr(arr, SIZE_OF_ARR);
}

/*returns number of names filled*/
int fillFromFile(char** arr, FILE *fp){
	int word = 0;
	int letter = 0;
	char c;
	while ((c = fgetc(fp)) != EOF){
		if(isalpha(c)){
			arr[word][letter] = c;
			letter++;
		}
		else if(letter > 0){
			arr[word][letter] = '\0';
			letter = 0;
			word++;
		}
	}
	return word;
}

char** allocStringArr(int size){
	char** pt;
	int i;
	
	pt = malloc(size*sizeof(char*));
	if(pt == NULL)
		return NULL;
	for(i = 0; i < size; i++){
		pt[i] = malloc(MAX_STRING_SIZE * sizeof(char));
		if(pt[i] == NULL){
			while(i > 0){
				i--;
				free(pt[i]);
			}
			free(pt);
			return NULL;
		}
	}
	return pt;
}

void freeStringArr(char** pt, int size){
	int i;
	for(i = 0; i < size; i++){
		free(pt[i]);
	}
	free(pt);
}

void swap(char** arr, int i, int j){
	char* temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

/*returns true if a comes before b in the alphabetical order*/
int isBefore(char* a, char* b){
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0'){
		if(a[i] < b[i])
			return 1;
		else if(a[i] > b[i])
			return 0;
		i++;
	}
	if(a[i] != '\0')
		return 0;
	return 1;
}

int partition(char** arr, int low, int high){
	int pivot, j;
	int i = low;

	pivot = (rand() % (high - low + 1)) + low;
	swap(arr, pivot, high);
	for(j = low; j < high; j++){
		if(isBefore(arr[j],arr[high])){
			swap(arr,i,j);
			i++;
		}
	}
	swap(arr,i,high);
	return i;
}

void quickSort(char** arr, int low, int high){
	int prt;
	if(high > low){
		prt = partition(arr,low,high);
		quickSort(arr,low,prt - 1);
		quickSort(arr,prt + 1, high);
	}
}

int sumOfLetters(char* str){
	int i = 0;
	int sum = 0;
	while(str[i] != '\0'){
		sum += ((str[i] - 'A') + 1);
		i++;
	}
	return sum;
}

unsigned long long int sumOfNameScores(char** arr, int numOfNames){
	int i;
	unsigned long long int sum = 0;
	printf("COLLIN test: 53 == %d\n", sumOfLetters(arr[937]));
	for(i = 0; i < numOfNames; i++)
		sum += ((i+1)*sumOfLetters(arr[i]));
	return sum;
}

void printNames(char** arr, int numOfNames){
	int i, j;
	for(i = 0; i < numOfNames; i++){
		j = 0;
		printf("%d. ", i + 1);
		while(j != '\n'){
			printf("%c", arr[i][j]);
			j++;
		}
		printf("\n");
	}
}
