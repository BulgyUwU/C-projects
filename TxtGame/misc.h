typedef enum {
	DIST_SELF,
	DIST_HELD,
	DIST_HELDCONT,
	DIST_LOCAL,
	DIST_HERE,
	DIST_HERECONT,
	DIST_THERE,
	DIST_NOTHERE,
	DIST_UNKNOWN
} DISTANCE;

extern int is_hold(OBJECT *container, OBJECT *obj);
extern DISTANCE get_dist(OBJECT *from, OBJECT *to);
extern OBJECT *get_passage(OBJECT *from, OBJECT *to);
extern OBJECT *actor_here();
extern int list_objects_at_location(OBJECT *location);
