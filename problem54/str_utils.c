#include <ctype.h>
#include <string.h>
#include "hand_utils.h"

void delete_newline(char* str){
	char *newline = strchr(str, '\n');
	if (newline)
  	*newline = '\0';
}

int get_card_val(char c){
	if(c - '0' >= 2 && c - '0' <= 9)
		return c - '0';
	if(c == 'T')
		return 10;
	if(c == 'J')
		return 11;
	if(c == 'Q')
		return 12;
	if(c == 'K')
		return 13;
	return 14;
	
}

void get_hands(char* str, card** hand1, card** hand2){
	char* token;
	int i, cardVal;
	char cardSuit;
	
	delete_newline(str);
	token = strtok(str, " ");
	for(i = 0; i < HAND_SIZE; i++){
		/*check val*/
		cardVal = get_card_val(token[0]);
		/*check suit*/
		cardSuit = tolower(token[1]);
		
		hand1[i] = new_card(cardVal,cardSuit);
		token = strtok(NULL," ");
	}
	for(i = 0; i < HAND_SIZE; i++){
		/*check val*/
		cardVal = get_card_val(token[0]);
		/*check suit*/
		cardSuit = tolower(token[1]);
		
		hand2[i] = new_card(cardVal,cardSuit);
		token = strtok(NULL," ");
	}
	sort_hand(hand1);
	sort_hand(hand2);
}


