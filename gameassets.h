#ifndef GAMEASSETS_H_
#define GAMEASSETS_H_

// for usleep function
#define DELAY 5000
#define LONG_DELAY 9999999
// color pairs
#define TXT_CLR 1
#define PLR_CLR 2
#define GRASS_CLR 3
#define WATER_CLR 4
#define ROCK_CLR 5
#define ICE_CLR 6
#define SAND_CLR 7
#define GLACIER_CLR 8
#define DARK_ROCK_CLR 9
#define LAVA_CLR 10
#define FIRE_CLR 11
#define CYAN_CLR 12
#define BLUE_CLR 13
#define RED_CLR 14
#define PLANT_CLR_1 15
#define PLANT_CLR_2 16
#define PLANT_CLR_3 17
#define PLANT_CLR_4 18
#define PLANT_CLR_5 19
#define EVIL_CLR 20
//define consts for game select screen selector coords
#define MIN_SELECT_Y 13
#define MAX_SELECT_Y 15
//define consts for max player coords 
#define MIN_PLR_X 1
#define MAX_PLR_X 140
#define MIN_PLR_Y 1
#define MAX_PLR_Y 36
//number of biomes for random generation
#define BIOME_COUNT 8

typedef struct Maps {
    /* 
    The following characters mean the corrosponding biomes: 
       - P = Plains
       - F = Forest
       - M = Mountains
       - D = Desert
       - G = ice land/Glacier (a few layers of these at the top and bottom of the world only)
       - H = Hotlands
       - W = large body of Water
    Things to add:
       - f = Flowery plains
    */
    char biome;
    char map[140][36];
} Map;

// function prototypes
//player.c stuff
void movplr(int *x, int *y, int *map_x, int *map_y);

// map.c stuff
void displayBorders();
void genMap(Map *mapin, char biomein);
void printMap(Map *mapin);
void tileDescription(Map *mapin, int x, int y);

#endif