#include <stdio.h>
#include <stdlib.h>
#define N_DIGITS 1000

/*should return number of digits*/
int add_fibs(int **fib1, int **fib2){
	int i, offset = 0, curr_result, *temp_pt;
	/*
	for(i = 0; *fib2[i] >= 0 && i < N_DIGITS; i++){
		*temp_fib[i] = *fib2[i];
	}
	*/
	i = 0;
	while((*fib1)[i] >= 0){
		curr_result = (*fib1)[i] + (*fib2)[i] + offset;
		offset = curr_result/10;
		(*fib1)[i] = curr_result%10;
		i++;
	}
	if((*fib2)[i] >= 0 || offset != 0){/*second fib has more digits than the first*/
		if((*fib2)[i] >= 0)
			(*fib1)[i] = (*fib2)[i] + offset;
		else
			(*fib1)[i] = offset;
		i++;	
	}
	temp_pt = *fib1;
	*fib1 = *fib2;
	*fib2 = temp_pt;
	return i;
}

int main(){
	int i;
	int *fib1, *fib2;
	int fib_ind = 3;
	
	fib1 = malloc(sizeof(int)*N_DIGITS);
	fib2 = malloc(sizeof(int)*N_DIGITS);
	fib1[0] = 1;
	fib2[0] = 1;
	/*fill rest of array with negatives, as a stop condition*/
	for(i = 1; i < N_DIGITS; i++){
		fib1[i] = -1;
		fib2[i] = -1;
	}
	while(add_fibs(&fib1, &fib2) < N_DIGITS)
		fib_ind++;
	printf("%d\n", fib_ind);
	free(fib1);
	free(fib2);
}
