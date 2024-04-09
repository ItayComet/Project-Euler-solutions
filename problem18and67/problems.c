#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ARR_LENGTH 120 

void fill_from_file(int *arr, FILE *fp);
int maxRoute(int *arr);

int main(int argc, char **argv){
	FILE *fp;
	int *arr;
	
	fp = fopen(argv[1], "r");
	arr = malloc(ARR_LENGTH * sizeof(int));
	if(arr == NULL){
		printf("Error: couldn't allocate\n");
		return -1;
	}
	fill_from_file(arr, fp);
	printf("%d\n", maxRoute(arr));
	fclose(fp);
	free(arr);
}

void fill_from_file(int *arr, FILE *fp){
	char c;
	int i = 0, currNum = 0;
	while ((c = fgetc(fp)) != EOF){
		if(isdigit(c))
			currNum = currNum*10 + (c - '0');
		else if(currNum != 0){
			arr[i] = currNum;
			currNum = 0;
			i++;
		}
	}
}

int getLevel(int n){
	int level = 0;
	int lastInLevel = 0;
	while(1){
		if(n <= lastInLevel)
			return level;
		level++;
		lastInLevel += level + 1;
	}
}

int getLeftSon(int n, int level){
	return n + level + 1;
}

int getRightSon(int n, int level){
	return getLeftSon(n,level) + 1;
}

int max(int a, int b){
	if(a < b)
		return b;
	return a;
}

int maxRoute(int *arr){
	int *maxArr;/*An array of max routes down from each place*/
	int i, level, bottom;
	int maxRoute;
	
	bottom = getLevel(ARR_LENGTH - 1);
	maxArr = malloc(ARR_LENGTH * sizeof(int));
	if(maxArr == NULL){
		printf("Error: couldn't allocate\n");
		return -1;
	}
	for(i = ARR_LENGTH - 1; i >= 0; i--){
		level = getLevel(i);
		if(level == bottom){
			maxArr[i] = arr[i];
		}
		else{
			maxArr[i] = arr[i] + max(maxArr[getLeftSon(i,level)],maxArr[getRightSon(i,level)]);
		}
	}
	maxRoute = maxArr[0];
	free(maxArr);
	return maxRoute;
}
