#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hand_utils.h"

card *new_card(int val, char suit){
	card *cpt = malloc(sizeof(card));
	if(cpt == NULL)
		return NULL;
	cpt->val = val;
	cpt->suit = suit;
	return cpt;
}

void free_cards(card **hand){
	int i;
	for(i = 0; i < HAND_SIZE; i++){
		free(hand[i]);
	}
}

void sort_hand(card **hand){
	int i, j;
	card *currCard;
	for(i = 1; i < HAND_SIZE; i++){
		currCard = hand[i];
		j = i-1;
		while(j >= 0 && hand[j]->val > currCard->val){
			hand[j+1] = hand[j];
			j--;
		}
		hand[j+1] = currCard;
	}
}

void print_card(card *cpt){
	printf("%d%c", cpt->val, cpt->suit);
}

void print_hand(card **hand){
	int i;
	for(i = 0; i < HAND_SIZE; i++){
		print_card(hand[i]);
		putchar(' ');
	}
	putchar('\n');
}

int isS(card **hand){
	int i;
	for(i = 0; i < HAND_SIZE - 1; i++){/*assumes the hand is sorted*/
		if(hand[i]->val != ((hand[i+1]->val)-1))
			return 0;
	}
	return 1;
}
int isF(card **hand){
	int i;
	for(i = 0; i < HAND_SIZE - 1; i++){
		if(hand[i]->suit != hand[i+1]->suit)
			return 0;
	}
	return 1;
}

int isTK(card **hand){
	int i, currVal, valCnt;
	currVal = hand[0]->val;
	valCnt = 1;
	for(i = 1; i < HAND_SIZE; i++){
		if(hand[i]->val == currVal){
			valCnt++;
			if(valCnt == 3)
				return currVal;
		}
		else{
			currVal = hand[i]->val;
			valCnt = 1;
		}
	}
	return 0;
}

int isOP(card **hand){
	int i;
	for(i = 0; i < HAND_SIZE - 1; i++){
		if(hand[i]->val == hand[i+1]->val)
			return hand[i]->val;
	}
	return 0;
}

int isTP(card **hand){
	int i, found_pair = 0;
	for(i = 0; i < HAND_SIZE - 1; i++){
		if(hand[i]->val == hand[i+1]->val){
			if(found_pair)/*that's a second pair*/
				return 1;
			found_pair = 1;
			i++;/*jump one*/
		}
	}
	return 0;
}

int isSF(card **hand){
	return (isF(hand) && isS(hand));
}

int isRF(card **hand){
	return (isSF(hand) && hand[0]->val == 10);
}

int isFH(card **hand){/*assumes hand is sorted*/
	if(hand[0]->val == hand[1]->val){
		if(hand[2]->val == hand[3]->val && hand[3]->val == hand[4]->val)
		return hand[2]->val;
	}
	else if(hand[3]->val == hand[4]->val){
		if(hand[0]->val == hand[1]->val && hand[1]->val == hand[2]->val)
		return hand[0]->val;
	}
	return 0;
}

int isFK(card **hand){/*assumes hand is sorted*/
	int fk_val;
	if(hand[0]->val == hand[1]->val){
		fk_val = hand[0]->val;
		if(hand[2]->val == fk_val && hand[3]->val == fk_val)
			return fk_val;
	}
	else if(hand[3]->val == hand[4]->val){
		fk_val = hand[3]->val;
		if(hand[2]->val == fk_val && hand[1]->val == fk_val)
			return fk_val;
	}
	return 0;
}

hand_rank get_hand_rank(card **hand){
	if(isRF(hand))
		return RF;
	if(isSF(hand))
		return SF;
	if(isFK(hand))
		return FK;
	if(isFH(hand))
		return FH;
	if(isF(hand))
		return F;
	if(isS(hand))
		return S;
	if(isTK(hand))
		return TK;
	if(isTP(hand))
		return TP;
	if(isOP(hand))
		return OP;
	return HC;
}

int TP_get_high(card **hand){
	int i;
	for(i = HAND_SIZE - 1; i > 0; i--){
		if(hand[i]->val == hand[i-1]->val)
			return hand[i]->val;
	}
	return 0;
}

int TP_get_low(card **hand){
	int i;
	for(i = 0; i < HAND_SIZE - 1; i++){
		if(hand[i]->val == hand[i+1]->val)
			return hand[i]->val;
	}
	return 0;
}

/*returns the winner in terms of high card*/
int war_game(card **hand1, card **hand2){
	int i;
	for(i = HAND_SIZE-1; i >= 0; i--){
		if(hand1[i]->val > hand2[i]->val)
			return 1;
		if(hand1[i]->val < hand2[i]->val)
			return 2;
	}
	return 0;
}

int get_winner(card **hand1, card **hand2){
	hand_rank hand1_r, hand2_r;
	int hand1_rank_val, hand2_rank_val;/*the values INSIDE the rank*/
	
	hand1_r = get_hand_rank(hand1);
	hand2_r = get_hand_rank(hand2);
	printf("started %d %d\n",hand1_r, hand2_r);
	if(hand1_r > hand2_r)
		return 1;
	if(hand1_r < hand2_r)
		return 2;
	/*same rank handling*/
	if(hand1_r == FK || hand1_r == FH || hand1_r == TK || hand1_r == OP){
		if(hand1_r == FK){
			hand1_rank_val = isFK(hand1);
			hand2_rank_val = isFK(hand2);
		}
		else if(hand1_r == FH){
			hand1_rank_val = isFH(hand1);
			hand2_rank_val = isFH(hand2);
		}
		else if(hand1_r == TK){
			hand1_rank_val = isTK(hand1);
			hand2_rank_val = isTK(hand2);
		}
		else if(hand1_r == OP){
			hand1_rank_val = isOP(hand1);
			hand2_rank_val = isOP(hand2);
		}
	
		if(hand1_rank_val > hand2_rank_val)
			return 1;
		if(hand1_rank_val < hand2_rank_val)
			return 2;
	}
	else if(hand1_r == TP){
		hand1_rank_val = TP_get_high(hand1);
		hand2_rank_val = TP_get_high(hand2);
		if(hand1_rank_val > hand2_rank_val)
			return 1;
		if(hand1_rank_val < hand2_rank_val)
			return 2;
		hand1_rank_val = TP_get_low(hand1);
		hand2_rank_val = TP_get_low(hand2);
		if(hand1_rank_val > hand2_rank_val)
			return 1;
		if(hand1_rank_val < hand2_rank_val)
			return 2;
	}
	return war_game(hand1,hand2);
}
