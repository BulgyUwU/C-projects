#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "noun.h"
#include "move.h"

void inventory_get(const char *noun) {
	OBJECT *obj = get_visible("what you want to get", noun);
	switch (get_dist(PLAYER, obj)) {
		case DIST_SELF:
			printf("i dont know how to do that.\n");
			break;
		case DIST_HELD:
			printf("%s is already mine.\n", obj->description);
			break;
		case DIST_THERE:
			printf("thats too far for me to grab.\n");
			break;
		case DIST_UNKNOWN:
			break;
		default:
			if (obj->location == GUARD) printf("you should ask %s nicely.\n", obj->location->description);
			else move_object(obj, PLAYER);
	}
}

void inventory_drop(const char *noun) {
	move_object(get_possession(PLAYER, "drop", noun), PLAYER->location);
}

void inventory_ask(const char *noun) {
	move_object(get_possession(actor_here(), "ask", noun), PLAYER);
}

void inventory_give(const char *noun) {
	move_object(get_possession(PLAYER, "give", noun), actor_here());
}

void inventory_inv() {
	if (list_objects_at_location(PLAYER) == 0) {
		printf("i dont have anyhting.\n");
	}
}
