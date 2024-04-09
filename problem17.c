#include <stdio.h>

int sumLetters(int num);

int main(){
	int i, sum = 0;
	for(i = 1; i < 1000; i++){
		sum += sumLetters(i);
	}
	sum += 11;/*add one thousand*/
	printf("%d\n", sum);
}

int sumOneDig(int num){
	if(num == 0)
		return 0;
	else if(num == 1 || num == 2 || num == 6)
		return 3;
	else if(num == 4 || num == 5 || num == 9)
		return 4;
	else/*3,7,8*/
		return 5;
}

int sumTwoDig(int num){
	int tens, units;
	if(num < 10)
		return sumOneDig(num);
	units = num % 10;
	tens = num / 10;
	if(tens == 1){
		if(units == 0)
			return 3;
		else if(units == 1 || units == 2)
			return 6;
		else if(units == 3 || units == 8)
			return 8;
		else if(units == 5)
			return 7;
		else
			return (4 + sumOneDig(units));
	}
	else if(tens == 2 || tens == 3 || tens == 8 || tens == 9)
		return (6 + sumOneDig(units));
	else if(tens == 4 || tens == 5 || tens == 6)
		return (5 + sumOneDig(units));
	else/*7*/
		return (7 + sumOneDig(units));
}

int sumThreeDig(int num){
	int twoLastDigs, hundreds;
	hundreds = num / 100;
	twoLastDigs = num % 100;
	if(twoLastDigs == 0)
		return(sumOneDig(hundreds) + 7);
	return (10 + sumOneDig(hundreds) + sumTwoDig(twoLastDigs));/*hundred and == 10*/
}

int sumLetters(int num){
	if(num < 10)
		return sumOneDig(num);
	if(num >= 10 && num < 100)
		return sumTwoDig(num);
	else
		return sumThreeDig(num);
}
