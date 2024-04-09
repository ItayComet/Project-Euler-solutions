#ifndef HAND_H
#define HAND_H

#define HAND_SIZE 5

typedef enum hand_rank{
	HC, OP, TP, TK, S, F, FH, FK, SF, RF
} hand_rank;

typedef struct card{
	int val;
	char suit;
} card;

card *new_card(int val, char suit);

void free_cards(card **hand);

void sort_hand(card **hand);

void print_hand(card **hand);

int get_winner(card **hand1, card **hand2);

#endif
