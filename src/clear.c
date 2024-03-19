
#include "../main.h"

/**
 * freeMemory - Free allocated momery
 * @instance: SDL_Instance for window and renderer
 * @map: 2D array representing map of play space
 * @map_h: The height of the map
 **/
void freeMemory(SDL_Instance instance, char **map, size_t map_h)
{
	freeMap(map, map_h);
	close_SDL(instance);
}

/**
 * freeMap - Free the map 2D
 * @map: 2D array representing the map
 * @map_h: map height
 **/
void freeMap(char **map, size_t map_h)
{
	size_t i = 0;

	while (i < map_h)
	{
		free(map[i]);
		i++;
	}
}

/**
 * close_SDL - closes the SDL window & renderer
 * @instance: Struct containing window & renderer
 **/
void close_SDL(SDL_Instance instance)
{
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
}
