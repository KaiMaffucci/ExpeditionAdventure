#include <ncurses.h>
#include <stdio.h>
#include "gameassets.h"

// function declarations for map things

//display borders function definition
void displayBorders() {
    int i;
    attron(COLOR_PAIR(TXT_CLR));
    mvprintw(0, 0, "+--------------------------------------------------------------------------------------------------------------------------------------------+");
    for (i = 0; i <= 36; i++ ) {
        mvprintw((i+1), 0, "|");
        mvprintw((i+1), 141, "|");
    }
    mvprintw(37, 0, "+--------------------------------------------------------------------------------------------------------------------------------------------+");
    attroff(COLOR_PAIR(TXT_CLR));
    refresh();
}

//generate map function definition
void genMap(Map *mapin, char biomein) {
    int x, y; // used for map/chunk generation
    int r, r2; // used for generating random numbers
    //map/chunk generation; needs to be like this so it can check what its coords are before it generates its biome
    mapin->biome = biomein;
    for (x = 0; x < 140; x++) {
        for (y = 0; y < 36; y++) {
            switch (biomein) {
                case 'P':
                    //if biome is plains
                    r = rand() % 600;
                    if ( r == 1 ) {
                        mapin->map[x][y] = '~';
                    } else if ( r == 2 ) {
                        mapin->map[x][y] = '.';
                    }
                    else {
                        mapin->map[x][y] = ',';
                    }
                    break;
                case 'F':
                    //if biome is forest
                    r = rand() % 400;
                    r2 = rand() % 10;
                    if ( r2 == 1 ) {
                        mapin->map[x][y] = '^';
                    } else if ( r == 1 ) {
                        mapin->map[x][y] = '~';
                    } else {
                        mapin->map[x][y] = ',';
                    }
                    break;
                case 'M':
                    //if biome is mountains
                    r = rand() % 500;
                    r2 = rand() % 100;
                    if ( r2 == 1 ) {
                        mapin->map[x][y] = 'O';
                    } else if (r == 2) {
                        mapin->map[x][y] = 'I';
                    } else {
                        mapin->map[x][y] = '.';
                    }
                    break;
                case 'D':
                    //if biome is desert
                    r = rand() % 2;
                    if (r == 1) {
                        mapin->map[x][y] = '.';
                    } else {
                        mapin->map[x][y] = ',';
                    }
                    break;
                case 'G':
                    //if biome is glacier
                    mapin->map[x][y] = 'G';
                    break;
                case 'H':
                    //if biome is hotlands
                    r = rand() % 4;
                    if (r == 1) {
                        mapin->map[x][y] = 'V';
                    } else if (r == 2) {
                        mapin->map[x][y] = '~';
                    } else if (r == 3) {
                        mapin->map[x][y] = '.';
                    } else {
                        mapin->map[x][y] = ',';
                    }
                    break;
                case 'W':
                    //if biome is body of water
                    mapin->map[x][y] = '~';
                    break;
                case 'f':
                    r = rand() % 5;
                    r2 = rand() % 400;
                    if (r == 1) {
                        mapin->map[x][y] = 'v';
                    } else if (r == 2) {
                        mapin->map[x][y] = '%';
                    } else {
                        mapin->map[x][y] = ',';
                    }
                    if (r2 == 1) {
                        mapin->map[x][y] = '~';
                    }
                    break;
                case 'E':
                    r = rand() % 6;
                    if (r == 1) {
                        mapin->map[x][y] = 'v';
                    } else if (r == 2) {
                        mapin->map[x][y] = '%';
                    } else if (r == 3) {
                        mapin->map[x][y] = '~';
                    } else {
                        mapin->map[x][y] = ',';
                    }
                    break;
                default:
                    //maybe add some kind of error handling? maybe recursion?
                    break;
            }
        }
    }
}

//print map function definition
void printMap(Map *mapin) {
    int x, y, r;
    for (x = 0; x < 140; x++) {
        for (y = 0; y < 36; y++) {
            //change color based on biome
            switch (mapin->biome) {
                case 'E':
                    //evil biome
                    switch (mapin->map[x][y]) {
                        case 'v':
                            attron(COLOR_PAIR(EVIL_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(EVIL_CLR));
                            break;
                        case '%':
                            attron(COLOR_PAIR(EVIL_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(EVIL_CLR));
                            break;
                        case ',':
                            attron(COLOR_PAIR(EVIL_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(EVIL_CLR));
                            break;
                        case '~':
                            attron(COLOR_PAIR(LAVA_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(LAVA_CLR));
                            break;
                        default:
                            break;
                    }
                    break;
                case 'D':
                    //desert
                    switch (mapin->map[x][y]) {
                        case '.':
                            // if the tile is sand then make it yellow and display it
                            attron(COLOR_PAIR(SAND_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(SAND_CLR));
                            break;
                        case ',':
                            // if the tile is sand then make it yellow and display it
                            attron(COLOR_PAIR(SAND_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(SAND_CLR));
                            break;
                        default:
                            // if the tile is sand then make it yellow and display it
                            attron(COLOR_PAIR(SAND_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(SAND_CLR));
                            break;
                    }
                    break;
                case 'H':
                    //hotlands
                    switch (mapin->map[x][y]) {
                        case '.':
                            // if the tile is rock then make it black and display it
                            attron(COLOR_PAIR(DARK_ROCK_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(DARK_ROCK_CLR));
                            break;
                        case 'V':
                            // if the tile is fire then make it fire color and display it
                            attron(COLOR_PAIR(FIRE_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(FIRE_CLR));
                            break;
                        default:
                            // if the tile is anything else then make it lava color and display it
                            attron(COLOR_PAIR(LAVA_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(LAVA_CLR));
                            break;
                    }
                    break;
                case 'f':
                    switch (mapin->map[x][y]) {
                        case 'v':
                            switch ((x + y) % 5) {
                                case 0:
                                    attron(COLOR_PAIR(PLANT_CLR_1));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(PLANT_CLR_1));
                                    break;
                                case 1:
                                    attron(COLOR_PAIR(PLANT_CLR_2));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(PLANT_CLR_2));
                                    break;
                                case 2:
                                    attron(COLOR_PAIR(PLANT_CLR_3));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(PLANT_CLR_3));
                                    break;
                                case 3:
                                    attron(COLOR_PAIR(PLANT_CLR_4));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(PLANT_CLR_4));
                                    break;
                                case 4:
                                    attron(COLOR_PAIR(PLANT_CLR_5));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(PLANT_CLR_5));
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case '%':
                            switch ((x + y) % 6) {
                                case 0:
                                    attron(COLOR_PAIR(PLANT_CLR_1));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(PLANT_CLR_1));
                                    break;
                                case 1:
                                    attron(COLOR_PAIR(PLANT_CLR_2));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(PLANT_CLR_2));
                                    break;
                                case 2:
                                    attron(COLOR_PAIR(PLANT_CLR_3));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(PLANT_CLR_3));
                                    break;
                                case 3:
                                    attron(COLOR_PAIR(PLANT_CLR_4));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(PLANT_CLR_4));
                                    break;
                                case 4:
                                    attron(COLOR_PAIR(PLANT_CLR_5));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(PLANT_CLR_5));
                                    break;
                                case 5:
                                    attron(COLOR_PAIR(GRASS_CLR));
                                    mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                                    attroff(COLOR_PAIR(GRASS_CLR));
                                default:
                                    break;
                            }
                            break;
                        case ',':
                            attron(COLOR_PAIR(GRASS_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(GRASS_CLR));
                            break;
                        case '~':
                            // if the tile is water then make it blue and display it
                            attron(COLOR_PAIR(WATER_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(WATER_CLR));
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    //everything else
                    switch (mapin->map[x][y]) {
                        case '~':
                            // if the tile is water then make it blue and display it
                            attron(COLOR_PAIR(WATER_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(WATER_CLR));
                            break;
                        case ',':
                            // if the tile is grass then make it green and display it
                            attron(COLOR_PAIR(GRASS_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(GRASS_CLR));
                            break;
                        case '.':
                            // if the tile is rock then make it grey and display it
                            attron(COLOR_PAIR(ROCK_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(ROCK_CLR));
                            break;
                        case '^':
                            //if the tile is a tree then make it green and display it
                            attron(COLOR_PAIR(GRASS_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(GRASS_CLR));
                            break;
                        case 'I':
                            //if the tile is ice then make it ice color and display it
                            attron(COLOR_PAIR(ICE_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(ICE_CLR));
                            break;
                        case 'O':
                            //if the tile is a boulder then make it grey and display it
                            attron(COLOR_PAIR(ROCK_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(ROCK_CLR));
                            break;
                        case 'G':
                            //if the tile is glacier then make it glacier color pair and display it
                            attron(COLOR_PAIR(GLACIER_CLR));
                            mvprintw(y+1, x+1, "%c", mapin->map[x][y]);
                            attroff(COLOR_PAIR(GLACIER_CLR));
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }
    }
}

//tile description display function definition
void tileDescription(Map *mapin, int x, int y) {
    attron(COLOR_PAIR(TXT_CLR));
    mvprintw(40, 0, "                                  ");
    attroff(COLOR_PAIR(TXT_CLR));
    //displays tile description now based off of biome and tile char
    switch (mapin->biome) {
        case 'D':
            switch(mapin->map[x][y]) {
                default:
                    attron(COLOR_PAIR(SAND_CLR));
                    mvprintw(40, 0, "sand");
                    attroff(COLOR_PAIR(SAND_CLR));
                    break;
            }
            break;
        case 'H':
            switch(mapin->map[x][y]) {
                case '.':
                    attron(COLOR_PAIR(DARK_ROCK_CLR));
                    mvprintw(40, 0, "dark rock");
                    attron(COLOR_PAIR(DARK_ROCK_CLR));
                    break;
                case 'V':
                    attron(COLOR_PAIR(FIRE_CLR));
                    mvprintw(40, 0, "fire");
                    attron(COLOR_PAIR(FIRE_CLR));
                    break;
                default:
                    // if the tile is anything else then make it fire color and display description
                    attron(COLOR_PAIR(RED_CLR));
                    mvprintw(40, 0, "magma");
                    attroff(COLOR_PAIR(RED_CLR));
                    break;
            }
            break;
        case 'f':
            switch(mapin->map[x][y]) {
                case 'v':
                    attron(COLOR_PAIR(GRASS_CLR));
                    mvprintw(40, 0, "flowers");
                    attroff(COLOR_PAIR(GRASS_CLR));
                    break;
                case '%':
                    attron(COLOR_PAIR(GRASS_CLR));
                    mvprintw(40, 0, "bush");
                    attroff(COLOR_PAIR(GRASS_CLR));
                    break;
                case ',':
                    attron(COLOR_PAIR(GRASS_CLR));
                    mvprintw(40, 0, "grass");
                    attroff(COLOR_PAIR(GRASS_CLR));
                    break;
                case '~':
                    // if the tile is water then make it blue and display it
                    attron(COLOR_PAIR(BLUE_CLR));
                    mvprintw(40, 0, "water");
                    attroff(COLOR_PAIR(BLUE_CLR));
                    break;
                default:
                    break;
            }
            break;
        case 'E':
            switch(mapin->map[x][y]) {
                case 'v':
                    attron(COLOR_PAIR(EVIL_CLR));
                    mvprintw(40, 0, "srewolf");
                    attroff(COLOR_PAIR(EVIL_CLR));
                    break;
                case '%':
                    attron(COLOR_PAIR(EVIL_CLR));
                    mvprintw(40, 0, "hsub");
                    attroff(COLOR_PAIR(EVIL_CLR));
                    break;
                case ',':
                    attron(COLOR_PAIR(EVIL_CLR));
                    mvprintw(40, 0, "ssarg");
                    attroff(COLOR_PAIR(EVIL_CLR));
                    break;
                case '~':
                    // if the tile is water then make it blue and display it
                    attron(COLOR_PAIR(EVIL_CLR));
                    mvprintw(40, 0, "retaw");
                    attroff(COLOR_PAIR(EVIL_CLR));
                    break;
                default:
                    break;
            }
            break;
        default:
            switch(mapin->map[x][y]) {
                case '~':
                    // if the tile is water then make it blue and display it
                    attron(COLOR_PAIR(BLUE_CLR));
                    mvprintw(40, 0, "water");
                    attroff(COLOR_PAIR(WATER_CLR));
                    break;
                case ',':
                    // if the tile is grass then make it green and display it
                    attron(COLOR_PAIR(GRASS_CLR));
                    mvprintw(40, 0, "grass");
                    attroff(COLOR_PAIR(GRASS_CLR));
                    break;
                case '.':
                    // if the tile is rock then make it grey and display it
                    attron(COLOR_PAIR(ROCK_CLR));
                    mvprintw(40, 0, "rock");
                    attroff(COLOR_PAIR(ROCK_CLR));
                    break;
                case '^':
                    //if the tile is a tree then make it green and display it
                    attron(COLOR_PAIR(GRASS_CLR));
                    mvprintw(40, 0, "tree");
                    attroff(COLOR_PAIR(GRASS_CLR));
                    break;
                case 'I':
                    //if the tile is ice then make it cyan and display it
                    attron(COLOR_PAIR(CYAN_CLR));
                    mvprintw(40, 0, "ice");
                    attroff(COLOR_PAIR(CYAN_CLR));
                    break;
                case 'O':
                    //if the tile is a boulder then make it grey and display it
                    attron(COLOR_PAIR(ROCK_CLR));
                    mvprintw(40, 0, "boulder/large rock");
                    attroff(COLOR_PAIR(ROCK_CLR));
                    break;
                case 'G':
                    //if the tile is glacier then make it glacier color pair and display it
                    attron(COLOR_PAIR(CYAN_CLR));
                    mvprintw(40, 0, "glacier ice");
                    attroff(COLOR_PAIR(CYAN_CLR));
                default:
                    break;
            }
            break;
    }
}