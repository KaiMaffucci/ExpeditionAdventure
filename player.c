#include <ncurses.h>
#include "gameassets.h"

/* 
 function declarations
 for player related things
*/

// function that checks if the user pressed a key and moves the player accordingly
void movplr(int *x, int *y, int *map_x, int *map_y) {
    init_pair(PLR_CLR, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(PLR_CLR));
    int ch = getch();
    while(ch == KEY_UP) {
        mvprintw(*y, *x, " ");
        *y -= 1;
        mvprintw(*y, *x, "o");
        refresh();
        ch = getch();
    }
    while(ch == KEY_DOWN) {
        mvprintw(*y, *x, " ");
        *y += 1;
        mvprintw(*y, *x, "o");
        refresh();
        ch = getch();
    }
    while(ch == KEY_LEFT) {
        mvprintw(*y, *x, " ");
        *x -= 1;
        mvprintw(*y, *x, "o");
        refresh();
        ch = getch();
    }
    while(ch == KEY_RIGHT) {
        mvprintw(*y, *x, " ");
        *x += 1;
        mvprintw(*y, *x, "o");
        refresh();
        ch = getch();
    }
    //checks to see if the player is out of bounds and changes map if so
    //only for COMPLETELY out of bounds
    if((*x < MIN_PLR_X) && (*map_x == 0)) {
        *map_x = 49;
        mvprintw(*y, *x, " ");
        *x = MAX_PLR_X;
    }
    if((*x > MAX_PLR_X) && (*map_x == 49)) {
        *map_x = 0;
        mvprintw(*y, *x, " ");
        *x = MIN_PLR_X;
    }
    if((*y < MIN_PLR_Y) && (*map_y == 0)) {
        *map_y = 49;
        mvprintw(*y, *x, " ");
        *y = MAX_PLR_Y;
    }
    if((*y > MAX_PLR_Y) && (*map_y == 49)) {
        *map_y = 0;
        mvprintw(*y, *x, " ");
        *y = MIN_PLR_Y;
    }
    //checks if it should move to next chunk/map if out of bounds
    if((*x < MIN_PLR_X) && (*map_x != 0)) {
        *map_x -= 1;
        mvprintw(*y, *x, " ");
        *x = MAX_PLR_X;
    }
    if((*x > MAX_PLR_X) && (*map_x != 49)) {
        *map_x += 1;
        mvprintw(*y, *x, " ");
        *x = MIN_PLR_X;
    }
    if((*y < MIN_PLR_Y) && (*map_y != 0)) {
        *map_y -= 1;
        mvprintw(*y, *x, " ");
        *y = MAX_PLR_Y;
    }
    if((*y > MAX_PLR_Y) && (*map_y != 49)) {
        *map_y += 1;
        mvprintw(*y, *x, " ");
        *y = MIN_PLR_Y;
    }
    mvprintw(*y, *x, "o");
    // prints player x and y coords below everything
    mvprintw(41, 0, "                                                        ");
    mvprintw(41, 0, "current world map x: %d", *map_x);
    mvprintw(41, 30, "current world map y: %d", *map_y);
    mvprintw(42, 0, "                                                       ");
    mvprintw(42, 0, "player x: %d", *x);
    mvprintw(42, 15, "player y: %d", *y);
    refresh();
    attroff(COLOR_PAIR(PLR_CLR));
}