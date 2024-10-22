typedef struct object {
	const char *description;
	const char **tags;
	struct object *location;
	struct object *destination;
	struct object *prospect;
	const char *details;
	const char *contents;
	const char *textgo;
	int weight;
	int capacity;
	int health;
	int value;
} OBJECT;

extern OBJECT objs[];

#define PLAYER          (objs + 0)
#define TUNDRA          (objs + 1)
#define MOUNTAIN        (objs + 2)
#define FOREST          (objs + 3)
#define TOWN            (objs + 4)
#define FIELD           (objs + 5)
#define CAVE            (objs + 6)
#define TOWN_GATE       (objs + 7)
#define FOREST_GATE     (objs + 8)
#define TOWN_PATH       (objs + 9)
#define FIELD_PATH      (objs + 10)
#define FIELD_TRAIL     (objs + 11)
#define MOUNTAIN_TRAIL  (objs + 12)
#define MOUNTAIN_PASSAGE (objs + 13)
#define CAVE_EXIT       (objs + 14)
#define MOUNTAIN_TRACK  (objs + 15)
#define TUNDRA_TRACK    (objs + 16)
#define TOWN_WALL       (objs + 17)
#define FOREST_WALL     (objs + 18)
#define FIELD_WALL      (objs + 19)
#define CAVE_WALL       (objs + 20)
#define MOUNTAIN_WALL   (objs + 21)
#define TUNDRA_WALL     (objs + 22)
#define PURSE           (objs + 23)
#define GOLD            (objs + 24)
#define LEATHER         (objs + 25)
#define IRON            (objs + 26)
#define CRYSTAL         (objs + 27)
#define EMERALD         (objs + 28)
#define GUARD           (objs + 29)
#define FOX             (objs + 30)
#define BUNNY           (objs + 31)
#define END_OF_OBJS (objs + 32)