#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "gameassets.h"

int main() {

    srand(time(NULL)); // set seed for random values based on current time

    // setup variables/data
    int plrx = 70, plry = 17, x, y, r, i, new_game;
    int d1 = 50, d2 = 50; // dimensions of all maps put together
    int start_arrow_x = 53, start_arrow_y = 13; // the starting location of the start screen arrow
    char biomes[BIOME_COUNT] = { 'P', 'F', 'M', 'D', 'H', 'W', 'f', 'E' }; // only used in random generation

    // setup ncurses stuff
    initscr(); // Initialize the window
    noecho(); // Don't echo any keypresses
    curs_set(FALSE); // Don't display a cursor
    keypad(stdscr, TRUE); // Accepts special keys as one character
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color(); // starts using color

    //initilizes all of the different color pairs that are used
    init_pair(TXT_CLR, COLOR_WHITE, COLOR_BLACK);
    init_pair(GRASS_CLR, COLOR_GREEN, COLOR_BLACK);
    init_pair(WATER_CLR, COLOR_BLUE, COLOR_BLUE);
    init_pair(ROCK_CLR, COLOR_WHITE, COLOR_BLACK);
    init_pair(ICE_CLR, COLOR_CYAN, COLOR_CYAN);
    init_pair(SAND_CLR, COLOR_YELLOW, COLOR_BLACK);
    init_pair(GLACIER_CLR, COLOR_CYAN, COLOR_CYAN);
    init_pair(DARK_ROCK_CLR, COLOR_RED, COLOR_BLACK);
    init_pair(LAVA_CLR, COLOR_RED, COLOR_RED);
    init_pair(FIRE_CLR, COLOR_YELLOW, COLOR_RED);
    init_pair(CYAN_CLR, COLOR_CYAN, COLOR_BLACK);
    init_pair(BLUE_CLR, COLOR_BLUE, COLOR_BLACK);
    init_pair(RED_CLR, COLOR_RED, COLOR_BLACK);
    init_pair(PLANT_CLR_1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(PLANT_CLR_2, COLOR_RED, COLOR_BLACK);
    init_pair(PLANT_CLR_3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(PLANT_CLR_4, COLOR_CYAN, COLOR_BLACK);
    init_pair(PLANT_CLR_5, COLOR_BLUE, COLOR_BLACK);
    init_pair(EVIL_CLR, COLOR_MAGENTA, COLOR_BLACK);
    
    // the game start screen
    attron(COLOR_PAIR(TXT_CLR));
    mvprintw(10, 74, "Expedition Adventure");
    mvprintw(13, 54, "New Game");
    mvprintw(15, 54, "Exit");
    refresh();
    int ch = getch();
    int playing = 0;
    int start_screen_enter_pressed = 0;
    attron(COLOR_PAIR(TXT_CLR));
    while ( start_screen_enter_pressed != 1 ) {
        mvprintw(start_arrow_y, start_arrow_x, ">");
        refresh();
        int ch = getch();
        switch(ch) {
            case KEY_DOWN:
                mvprintw(start_arrow_y, start_arrow_x, " ");
                start_arrow_y += 2;
                if ( start_arrow_y > MAX_SELECT_Y ) {
                    start_arrow_y = MIN_SELECT_Y;
                } else if ( start_arrow_y < MIN_SELECT_Y ) {
                    start_arrow_y = MAX_SELECT_Y;
                }
                refresh();
                break;
            case KEY_UP:
                mvprintw(start_arrow_y, start_arrow_x, " ");
                start_arrow_y -= 2;
                if ( start_arrow_y > MAX_SELECT_Y ) {
                    start_arrow_y = MIN_SELECT_Y;
                } else if ( start_arrow_y < MIN_SELECT_Y ) {
                    start_arrow_y = MAX_SELECT_Y;
                }
                refresh();
                break;
            case 10:
                if ( start_arrow_y == 13 ) {
                    playing = 1;
                    new_game = 1;
                }
                if ( start_arrow_y == 15 ) {
                    playing = 0;
                }
                start_screen_enter_pressed = 1;
                break;
            default:
                break;
        }
    }

    // does everything in order to freshly clear and create everything needed to start new
    int current_world_map_x = 24, current_world_map_y = 24;
    
    //generate maps
    //allocates memory for the map of whole world, the size of Map times how big it is
    Map *maps = calloc(d1 * d2, sizeof(Map));

    //generates the individual map in each index of the allocated memory
    for (x = 0; x <  d1; x++) {
        for (y = 0; y < d2; y++) {
            if ((y < 3) || (y > 46)) {
                genMap( (maps + x*d2 + y), 'G');
            } else {
                r = rand() % BIOME_COUNT;
                genMap( (maps + x*d2 + y), biomes[r]);
            }
        }
    }

    //game loop (each iteration is basically 1 tick)
    while (playing == 1) {
        printMap((maps + current_world_map_x*d2 + current_world_map_y)); // displays map
        mvprintw(plry, plrx, "o"); //displays player
        movplr(&plrx, &plry, &current_world_map_x, &current_world_map_y); // checks if player is pressing movement key and does things accordingly
        tileDescription(maps + current_world_map_x*d2 + current_world_map_y, (plrx - 1), (plry - 1)); // shows tile description
        displayBorders(); // displays borders
        refresh();
    }

    free(maps); // returns all that precious memory to the computer
    endwin(); // ends the window to return to normal terminal
    return 0;
}