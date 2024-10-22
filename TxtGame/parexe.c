#include <stdio.h>
#include <string.h>
#include "location.h"
#include "inventory.h"

int parse_and_execute(char *input) {
	char *verb = strtok(input, " \n");
	char *noun = strtok(NULL, "\n");
	if (verb != NULL) {
		if (strcmp(verb, "quit") == 0) return 0;
		else if (strcmp(verb, "look") == 0) location_look(noun);
		else if (strcmp(verb, "go") == 0) location_go(noun);
		else if (strcmp(verb, "get") == 0) inventory_get(noun);
		else if (strcmp(verb, "drop") == 0) inventory_drop(noun);
		else if (strcmp(verb, "give") == 0) inventory_give(noun);
		else if (strcmp(verb, "ask") == 0) inventory_ask(noun);
		else if (strcmp(verb, "inventory") == 0) inventory_inv();
		else printf("i dont know how to '%s'.\n", verb);	
	}
	return 1;
}
