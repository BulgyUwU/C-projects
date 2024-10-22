#include <stdio.h>
#include "object.h"
#include "misc.h"

static int weight_of_contents(OBJECT *container) {
	int sum = 0;
	OBJECT *obj;
	for (obj = objs; obj < END_OF_OBJS; obj++) {
		if (is_hold(container, obj)) sum += obj->weight;
	}
	return sum;
}

static void move_describe(OBJECT *obj, OBJECT *to) {
	if (to == PLAYER->location) printf("you drop %s.\n", obj->description);
	else if (to != PLAYER) printf(to->health > 0 ? "you give %s to %s.\n" : "you toss the %s in the %s.\n", obj->description, to->description);
	else if (obj->location == PLAYER->location) printf("you pick %s up.\n", obj->description);
	else printf("you get %s from %s.\n", obj->description, obj->location->description);
}

void move_object(OBJECT *obj, OBJECT *to) {
	if (obj == NULL) {
	} else if (to == NULL) printf("there's no one to give it to.\n");
	else if (obj->weight > to->capacity) printf("thats way too heavy.\n");
	else if (obj->weight + weight_of_contents(to) > to->capacity) printf("that would make the %s too heavy.\n", to)
	else {
		move_describe(obj, to);
		obj->location = to;
	}
}
