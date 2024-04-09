#include <stdio.h>
#include <math.h>
#define MAX_INT 28123

int sum_divs(int n){
	int i, sum = 0;
	double lim = sqrt(n);//for each divisor x<sqrt(n) of n there is a number y>sqrt(n) that x*y=n
	for(i = 1; i <= lim; i++){
		if(n%i == 0){
			sum += i;
			if(n/i != i)//To avoid adding sqrt(n) twice
				sum += n/i;
		}
	}
	sum -= n;
	return sum;
}

int is_abundant(int n){
	if(sum_divs(n) > n)
		return 1;
	return 0;
}

int main(){
	int abundants[6965];//There are exactly 6925 abundants with a value less than MAX_INT
	int abund_ind = 0;
	int can_be_sum_of_abunds[MAX_INT + 1];
	int i, j, sum = 0, sum_abundants = 0;
	for(i = 0; i <= MAX_INT; i++)
		can_be_sum_of_abunds[i] = 0;
		
	for(i = 1; i <= MAX_INT; i++){
		if(is_abundant(i)){
			abundants[abund_ind] = i;
			abund_ind++;
			for(j = 0; j < abund_ind; j++)
				if(i + abundants[j] <= MAX_INT)
					can_be_sum_of_abunds[i + abundants[j]] = 1;
				else
					break;
		}
	}
	
	sum = 0;
	for(i = 1; i <= MAX_INT; i++){
		if(can_be_sum_of_abunds[i] == 0)
			sum += i;
	}
	printf("%d\n", sum);
	return 0;
}
