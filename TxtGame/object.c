#include <stdio.h>
#include "object.h"

static const char *tags0[] = {"yourself", "me", "myself", "you", NULL };
static const char *tags1[] = {"tundra", NULL };
static const char *tags2[] = {"mountain", NULL };
static const char *tags3[] = {"forest", NULL };
static const char *tags4[] = {"town", NULL };
static const char *tags5[] = {"field", NULL };
static const char *tags6[] = {"cave", NULL };
static const char *tags7[] = {"gate", "main gate", "town gate", NULL };
static const char *tags8[] = {"gate", "main gate", "town gate", NULL };
static const char *tags9[] = {"path", "town path", NULL };
static const char *tags10[] = {"path", "town path", NULL };
static const char *tags11[] = {"trail", NULL };
static const char *tags12[] = {"trail", NULL };
static const char *tags13[] = {"passage", "hole", "hole?", NULL };
static const char *tags14[] = {"exit", NULL };
static const char *tags15[] = {"track", NULL };
static const char *tags16[] = {"track", NULL };
static const char *tags17[] = {"east", "west", NULL };
static const char *tags18[] = {"north", "east", "west", NULL };
static const char *tags19[] = {"south", "west", NULL };
static const char *tags20[] = {"east", "south", "west", NULL };
static const char *tags21[] = {"west", NULL };
static const char *tags22[] = {"north", "east", "west", NULL };
static const char *tags23[] = {"bag", "purse", NULL };
static const char *tags24[] = {"gold", "coin", NULL };
static const char *tags25[] = {"leather", "leather scraps", "scraps", NULL };
static const char *tags26[] = {"iron", "ingot", "iron ingot", NULL };
static const char *tags27[] = {"crystal", "ice", NULL };
static const char *tags28[] = {"emerald", "gem", "gemstone", NULL };
static const char *tags29[] = {"guard", "guardsman", NULL };
static const char *tags30[] = {"fox", "vulpine", NULL };
static const char *tags31[] = {"bunny", "rabbit", NULL };

OBJECT objs[] = {
	{"it's you", tags0, TOWN, NULL, NULL, "after all this time it's still you", "you have", "you cant get any closer", 0, 20, 100, 0 },
	{"a frigid tundra", tags1, NULL, NULL, NULL, "icy wind blows down from the highest peaks of the mountain, leaving a barren icy wasteland", "you see", "you cant get any closer", 0, 9999, 0, 0 },
	{"a jagged rocky mountain", tags2, NULL, NULL, NULL, "its a mountain man idk", "you see", "you cant get any closer", 0, 9999, 0, 0 },
	{"a lush green forest", tags3, NULL, NULL, NULL, "its a forest idk", "you see", "you cant get any closer", 0, 9999, 0, 0 },
	{"a bustling small town", tags4, NULL, NULL, NULL, "small town, theres people idk", "you see", "you cant get any closer", 0, 9999, 0, 0 },
	{"a vast amber field, growing all the towns wheat", tags5, NULL, NULL, NULL, "field, food grow here", "you see", "you cant get any closer", 0, 9999, 0, 0 },
	{"a dark cave, quiet and still", tags6, NULL, NULL, NULL, "dark, its a cave", "you see", "you cant get any closer", 0, 9999, 0, 0 },
	{"the town gate leading north to the forest", tags7, TOWN, FOREST, FOREST, "the towns main defense, an iron barred gate", "you see", "the gate swings open to allow you through", 0, 0, 0, 0 },
	{"the town gate, leading south into town", tags8, FOREST, TOWN, TOWN, "the towns main defense, an iron barred gate", "you see", "the gate swings open to allow you through", 0, 0, 0, 0 },
	{"a path leading south to the towns fields", tags9, TOWN, FIELD, FIELD, "a brick paved path winding around the back of the town", "you see", "you follow the path to its end", 0, 0, 0, 0 },
	{"the path leading north back into town", tags10, FIELD, TOWN, TOWN, "a brick paved path winding back into town", "you see", "you follow the path back into town", 0, 0, 0, 0 },
	{"a trail tucked away leading to the east, up into the mountain", tags11, FIELD, MOUNTAIN, MOUNTAIN, "a worn old train at the back of the field, obscured by trees and bushes", "you see", "you push past the bushes and begin to follow the trail", 0, 0, 0, 0 },
	{"the trail leading west, back into the towns fields", tags12, MOUNTAIN, FIELD, FIELD, "a gravelly steep trail, leading down the mountain", "you see", "you begin to careful decend following the trail", 0, 0, 0, 0 },
	{"a small passage on the south of the mountain, barely enough to squeeze through", tags13, MOUNTAIN, CAVE, CAVE, "the passage is very tight, you should be able to squeeze through", "you see", "you begin to shimmy through the passage, but as you get through you realise you wont be able to squeeze back out", 0, 0, 0, 0 },
	{"the only way out of the cave, taking you up north", tags14, CAVE, FOREST, FOREST, "the sound of life, birds chirping and trees swaying can be heard ahead, light floods in through the opening", "you see", "you wander out through the exit, the bright light of day blinding you for a moment", 0, 0, 0, 0 },
	{"a track going north along a precarious rock face", tags15, MOUNTAIN, TUNDRA, TUNDRA, "the track is along a sheer cliff, you can cross, but you feel uneasy about it", "you see", "you begin to shuffle along the track, back against the wall, careful not to lose your balance", 0, 0, 0, 0 },
	{"a track along a precarious rock face, leading south to the mountain", tags16, TUNDRA, MOUNTAIN, MOUNTAIN, "the track is along a sheer cliff, you can cross, but you feel uneasy about it", "you see", "you begin to shuffle along the track, back against the wall, careful not to lose your balance", 0, 0, 0, 0 },
	{"the towns wall", tags17, TOWN, NULL, NULL, "the wall is sturdy, it encompasses the whole town", "you see", "its a wall, theres no where to go", 0, 0, 0, 0 },
	{"a thick wall of trees", tags18, FOREST, NULL, NULL, "the forest is so thick past here, its no traversable by humans", "you see", "you cant, the foliage is too thick to move through", 0, 0, 0, 0 },
	{"part of the towns wall", tags19, FIELD, NULL, NULL, "the wall is sturdy, it encompasses the whole town and the towns field, apparently", "you see", "still a wall", 0, 0, 0, 0 },
	{"the walls of the cave", tags20, CAVE, NULL, NULL, "a cold wall of stone, you are in a cave", "you see", "you cant dig through solid rock, or at all but you know", 0, 0, 0, 0 },
	{"a sheer cliff", tags21, MOUNTAIN, NULL, NULL, "the cliff is a sheer drop, it goes down a long way", "you see", "theres no way you can climb down there", 0, 0, 0, 0 },
	{"frozen wasteland", tags22, TUNDRA, NULL, NULL, "a vast freezing wasteland, no one could survive out there", "you see", "you begin to walk out into the wasteland, but you realise you didnt bring a jacket and turn back", 0, 0, 0, 0 },
	{"a leather purse", tags23, FIELD, NULL, NULL, "a small black leather purse, with an iron buckle holding it shut", "you unbuckle the purse and open it to see", "you cant get any closer", 2, 0, 0, 5},
	{"some shiny gold coins", tags24, PURSE, NULL, NULL, "some shiny gold coins, each one stamped with the kingdoms crest, a fierce dragon breathing fire onto a shield", "you see", "you cant get any closer", 5, 0, 0, 50},
	{"leather", tags25, FOREST, NULL, NULL, "some scraps of leather, enough to work with", "you see", "you cant get any closer", 3, 0, 0, 2},
	{"an ingot of iron", tags26, CAVE, NULL, NULL, "a silvery grey bar of metal, cold and hard", "you see", "you cant get any closer", 10, 0, 0, 10},
	{"crystal", tags27, TUNDRA, NULL, NULL, "a light blue crystal, cold to the touch", "you see", "you cant get any closer", 1, 0, 0, 30},
	{"gemstone", tags28, MOUNTAIN, NULL, NULL, "the gem shines with a brilliant green hue", "you see", "you cant get any closer", 1, 0, 0, 75},
	{"city guardsman", tags29, TOWN, NULL, NULL, "the guard is fitted in plate armour and bares the kingdoms crest, a fire breathing dragon", "he has", "you cant get any closer", 0, 20, 150, 0 },
	{"fox", tags30, FOREST, NULL, NULL, "a purple fox? very strange", "he has", "you cant get any closer", 0, 5, 20, 0 },
	{"bunny", tags31, FIELD, NULL, NULL, "this bunny is actually really big for a rabbit, cute though", "he has", "you cant get any closer", 0, 50, 500, 0 }
};