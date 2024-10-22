#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"

static int has_tag(OBJECT *obj, const char *noun) {
	if (noun != NULL && *noun != '\0') {
			const char **tag;
			for (tag = obj->tags; *tag != NULL; tag++) if (strcmp(*tag, noun) == 0) return 1;
	}
	return 0;
}

static OBJECT AMBIGUOUS_NOUN;

static OBJECT *get_object(const char *noun, OBJECT *from, DISTANCE max_dist) {
	OBJECT *obj, *res = NULL;
	for (obj = objs; obj < END_OF_OBJS; obj++) if (has_tag(obj, noun) && get_dist(from, obj) <= max_dist) res = res == NULL ? obj : &AMBIGUOUS_NOUN;
	return res;
}

OBJECT *get_visible(const char *intention, const char *noun) {
	OBJECT *obj = get_object(noun, PLAYER, DIST_HERE);
	if (obj == NULL) {
		if (get_object(noun, PLAYER, DIST_NOTHERE) == NULL) printf("i dont understand %s.\n", intention);
		else printf("you dont see any %s here.\n", noun);
	} else if (obj == &AMBIGUOUS_NOUN) {
		printf("please be specific about which %s you mean.\n", noun);
		obj = NULL;
	}
	return obj;
}

OBJECT *get_possession(OBJECT *from, const char *verb, const char *noun) {
	OBJECT *obj = NULL;
	if (from == NULL) printf("im not sure who you wanna %s.\n", verb);
	else if ((obj = get_object(noun, from, DIST_HELDCONT)) == NULL) {
		if (get_object(noun, PLAYER, DIST_NOTHERE) == NULL) printf("im not sure what you wanna %s.\n", verb);
		else if (from == PLAYER) printf("youre not holding any %s.\n", noun);
		else printf("%s doesnt have any %s for you.\n", from->description, noun);
	} else if (obj == &AMBIGUOUS_NOUN) {
		printf("please be more specific about which %s you wanna %s.\n", noun, verb);
		obj = NULL;
	} else if (obj == from) {
		printf("you shouldnt do that to %s.\n", obj->description);
		obj = NULL;
	}
	return obj;
}
