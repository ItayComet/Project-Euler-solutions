#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void fill_from_file(char *st, FILE *fp);

int main(int argc, char **argv){
	FILE *fp;
	char *st;
	char *s;
	int arr[50];
	int i = 0;
	int j = 0;
	int offset = 0;
	int currNum = 0;
	fp = fopen(argv[1], "r");
	s = malloc(sizeof(char)*5000);
	st = malloc(sizeof(char)*10000);
	fill_from_file(st, fp);
	while(st[i] != '\0'){
		if(isdigit(st[i])){
			s[j] = st[i];
			j++;
		}
		i++;
	}
	for(i = 49; i >= 0; i--){
		for(j = 0; j < 100; j++){
			currNum += (s[i + (50*j)] - '0');
		}
		currNum += offset;
		arr[i] = currNum % 10;
		offset = currNum / 10;
		currNum = 0;
	}
	printf("%d", offset);
	for(i = 0; i < 50; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
	fclose(fp);
	free(s);
	free(st);
	
}

void fill_from_file(char *st, FILE *fp){
	char c;
	int i = 0;
	while ((c = fgetc(fp)) != EOF){
		st[i] = c;
		i++;
	}
	st[i] = '\0';
}
