#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <fcntl.h>

#define SCREEN_HEIGHT 1000
#define SCREEN_WIDTH 1000
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/**
 * struct SDL_Instance - SDL window and rendering in window
 * @window: The window to display rendering in
 * @renderer: The renderer to render graphics with
 **/
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;


/**
 * struct IntStruct - players int values
 * @x: X value
 * @y: Y value
 **/
typedef struct IntStruct
{
	int x;
	int y;
} IntStruct;

/**
 * struct DoubleStruct - players double vaues
 * @x: X value
 * @y: Y value
 **/
typedef struct DoubleStruct
{
	double x;
	double y;
} DoubleStruct;


/**
 * struct keys - checks for  key presses
 * @up: up key
 * @down: down key
 * @right:right key
 * @left: left key
 **/
typedef struct keys
{
	int up;
	int down;
	int right;
	int left;
} keys;

/**
 * struct level - Struct to contain the level and all starting values
 * @map: The map of the level
 * @height: height of that map
 * @win: The x/y coordinate of the win space
 * @play: The x/y starting position of the player
 * @dir: The x/y of the direction vector the player is looking
 * @plane: The x/y direction vector of the projection plane
 **/

typedef struct {
    char **map;
    size_t height;
    IntStruct win;
    DoubleStruct play;
    DoubleStruct dir;
    DoubleStruct plane;
} attribute;
int init_instance(SDL_Instance *);
int read_key_input(keys *);
void key_release(SDL_Event, keys *);
int key_press(SDL_Event, keys *);
char **create_map(char *, DoubleStruct *, size_t *);
void draw_grid(char **, DoubleStruct *, size_t, size_t, char *);
size_t count_line(char *);
size_t count_char(char *);
attribute *create_world(int, char **);
void create(SDL_Instance, char **, DoubleStruct, DoubleStruct, DoubleStruct);
void render_maze_walls(char **, DoubleStruct, SDL_Instance, DoubleStruct, DoubleStruct);
void select_color(SDL_Instance, char **, IntStruct, int);
void render_background(SDL_Instance);
void rotation(DoubleStruct *, DoubleStruct *, int);
void move_forward_backward(DoubleStruct *, DoubleStruct *, char **, double);
void movement(keys, DoubleStruct *, DoubleStruct *, DoubleStruct *, char **);
double checkWallDist(char **, DoubleStruct *, IntStruct *, IntStruct *, DoubleStruct *, int *,
		     DoubleStruct *, DoubleStruct *);
void rayDir(IntStruct *, DoubleStruct *, DoubleStruct, IntStruct, DoubleStruct, DoubleStruct);
void freeMemory(SDL_Instance, char **, size_t);
void freeMap(char **, size_t);
void close_SDL(SDL_Instance);
#endif
