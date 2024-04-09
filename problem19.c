#include <stdio.h>

#define endOfYear(day,month) ((day == 31 && month == 12)? 1 : 0)

int countSundays(int firstDay, int firstYear,int lastYear);

int main(){
	printf("%d\n", countSundays(2, 1901, 2000));
}

int endOfMonth(int d, int m, int y){
	if(m == 4 || m == 6 || m == 9 || m == 11){
		return ((d == 30)? 1 : 0);
	}
	else if(m == 2){
		if((y % 4 == 0) && !((y % 100 == 0) && (y % 400 != 0))){/*leap year*/
			if(d == 29)
				return 1;
			else
				return 0;
			}
		return ((d == 28)? 1 : 0);
	}
	return ((d == 31)? 1 : 0);
}

int countSundays(int firstDay, int firstYear,int lastYear){
	int currDay = firstDay;
	int currDayInMonth = 1;
	int currMonth = 1;
	int currYear = firstYear;
	int sundays = 0;
	while(currYear <= lastYear){
		if(currDay == 0 && currDayInMonth == 1){
			sundays++;
		}
		
		/*proceed to next day*/
		if(endOfYear(currDayInMonth, currMonth)){
			currYear++;
			currDayInMonth = 1;
			currMonth = 1;
		}
		else if(endOfMonth(currDayInMonth, currMonth, currYear)){
			currDayInMonth = 1;
			currMonth++;
		}
		else
			currDayInMonth++;
		currDay = (currDay + 1) % 7;
	}
	return sundays;
}
