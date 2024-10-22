#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "noun.h"


void location_look(const char *noun) {
	if (noun != NULL && strcmp(noun, "around") == 0) {
		printf("you are in %s.\n", PLAYER->location->description);
		list_objects_at_location(PLAYER->location);
	} else {
		OBJECT *obj = get_visible("what you want to look at", noun);
		switch (get_dist(PLAYER, obj)) {
			case DIST_HERECONT:
				printf("its hard to see, try getting it first.\n");
				break;
			case DIST_THERE:
				printf("its too far, try move closer.\n");
				break;
			case DIST_NOTHERE:
				printf("you dont see any %s here.\n", noun);
				break;
			case DIST_UNKNOWN:
				break;
			default:
				printf("%s\n", obj->details);
				list_objects_at_location(obj);
		}
	}
}

static void location_move(OBJECT *passage) {
	printf("%s\n", passage->details);
	if (passage->destination != NULL) {
		PLAYER->location = passage->destination;
		printf("\n");
		location_look("around");
	}
}

void location_go(const char *noun) {
	OBJECT *obj = get_visible("where you want to go", noun);
	switch (get_dist(PLAYER, obj)) {
		case DIST_THERE:
			location_move(get_passage(PLAYER->location, obj));
			break;
		case DIST_NOTHERE:
			printf("you cant see any %s here.\n", noun);
			break;
		case DIST_UNKNOWN:
			break;
		default:
			location_move(obj);
	}
}
