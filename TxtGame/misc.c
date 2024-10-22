#include <stdio.h>
#include "object.h"
#include "misc.h"

int is_hold(OBJECT *container, OBJECT *obj) {
	return obj != NULL && obj->location == container;
}

OBJECT *get_passage(OBJECT *from, OBJECT *to) {
	if (from != NULL && to != NULL) {
		OBJECT *obj;
		for (obj = objs; obj < END_OF_OBJS; obj++) {
			if (is_hold(from, obj) && obj->prospect == to) return obj;
		}
	}
	return NULL;
}

DISTANCE get_dist(OBJECT *from, OBJECT *to) {
	return               to == NULL ? DIST_UNKNOWN :
	                     to == from ? DIST_SELF :
	              is_hold(from, to) ? DIST_HELD :
	              is_hold(to, from) ? DIST_LOCAL :
            is_hold(from->location, to) ? DIST_HERE :
            is_hold(from, to->location) ? DIST_HELDCONT :
  is_hold(from->location, to->location) ? DIST_HERECONT :
get_passage(from->location, to) != NULL ? DIST_THERE : DIST_NOTHERE;
}

OBJECT *actor_here() {
	OBJECT *obj;
	for (obj = objs; obj < END_OF_OBJS; obj++) {
		if (is_hold(PLAYER->location, obj) && obj != PLAYER && obj->health > 0) return obj;
	}
	return NULL;
}

int list_objects_at_location(OBJECT *location) {
	int count = 0;
	OBJECT *obj;
	for (obj = objs; obj < END_OF_OBJS; obj++) {
		if (obj != PLAYER && is_hold(location, obj)) {
			if (count++ == 0) printf("%s:\n", location->contents);
			printf("%s\n", obj->description);
		}
	}
	return count;
}
