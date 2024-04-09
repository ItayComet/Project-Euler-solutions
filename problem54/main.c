#include <stdlib.h>
#include <stdio.h>
#include "hand_utils.h"
#include "str_utils.h"

int main(){
	FILE *fp;
	char* line;
	card **hand1, **hand2;
	int hand1wins = 0;
	
	line = malloc(sizeof(char)*40);
	fp = fopen("poker.txt", "r");
	hand1 = malloc(sizeof(card*)*HAND_SIZE);
	hand2 = malloc(sizeof(card*)*HAND_SIZE);
	
	while(fgets(line, 40, fp)){
		printf("here\n");
		get_hands(line, hand1, hand2);
		print_hand(hand1);
		print_hand(hand2);
		if(get_winner(hand1,hand2) == 1){
			hand1wins++;
			printf("hand1 won\n");
		}
		free_cards(hand1);
		free_cards(hand2);
	}
	printf("hand 1 won %d times\n", hand1wins);
	
	free(hand1);
	free(hand2);
	free(line);
	fclose(fp);
	return 0;
}
