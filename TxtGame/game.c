#include <stdio.h>
#include "parexe.h"

static char input[100] = "look around";

static int get_input() {
	printf("\nAction? :  ");
	return fgets(input, sizeof(input), stdin) != NULL;
}

int main() {
	printf("Welcome to Little Cave Adventure.\n");
	while (parse_and_execute(input) && get_input());
	printf("\nBye!\n");
	return 0;
}
