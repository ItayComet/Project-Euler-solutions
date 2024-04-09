#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_PRIMES 100000

void fillPrimes(int *primes, int numOfPrimes);
int numOfDivisors(int n, int *primes);

int main(){
	int i;
	int *primes;
	int serNum = 1;
	int numOfDivs;
	primes = malloc(sizeof(int) * NUM_OF_PRIMES);
	if(primes == NULL){
		printf("Error: space wasn't allocated\n");
		return -1;
	}
	fillPrimes(primes, NUM_OF_PRIMES);
	printf("Primes array filled.\n");
	while(1){
		currTri += serNum;
		numOfDivs = numOfDivisors(currTri, primes);
		if(numOfDivs > 500){
			printf("Num is %d and serial num is %d\n", currTri, serNum);
			break;
		}
		if(numOfDivs < 0){
			printf("Error: Over %d primes used\n", NUM_OF_PRIMES);
			printf("Num is %d and serial num is %d, divided : %d\n", currTri, serNum, numOfDivs*(-1));
			break;
		}
		serNum++;
	}
	free(primes);
}

//uses previously found primes to determine if n is a prime, if it isn't divisable by any smaller prime, then it is a prime
int isPrime(int n, int *primes, int length){
	int i;
	for(i = 0; i < length; i++){
		if(n%primes[i] == 0)
			return 0;
	}
	return 1;
}

//fills int* primes with numOfPrimes primes
void fillPrimes(int *primes, int numOfPrimes){
	int i;
	primes[0] = 2;
	primes[1] = 3;
	int currPrime = 2;
	for(i = 5; currPrime < numOfPrimes; i += 2){
		if(isPrime(i, primes, currPrime)){
			primes[currPrime] = i;
			currPrime++;
		}
	}
}

int numOfDivisors(int n, int *primes){
	int divs = 1;
	int currTimesDivided = 0;
	int i = 0;
	int dividedNum = n;
	while(primes[i] < n && i < NUM_OF_PRIMES){
		if(dividedNum % primes[i] == 0){
			dividedNum /= primes[i];
			currTimesDivided++;
		}
		else{
			divs *= (currTimesDivided + 1);
			currTimesDivided = 0;
			i++;
		}
	}
	if(i == NUM_OF_PRIMES){
		return -divs;
	}
	return divs;
}
