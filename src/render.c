#include "../main.h"

/**
 * create - run necessary draw functions to create the game visuals
 * @instance: The SDL Instance containing game window & renderer
 * @map: 2D array representing the play space
 * @play: position of the player
 * @dir:direction vector the player is facing
 * @plane:projection plane
 **/
void create(SDL_Instance instance, char **map, DoubleStruct player, DoubleStruct dir,
	  DoubleStruct plane)
{
	render_background(instance);
	render_maze_walls(map, player, instance, dir, plane);
	SDL_RenderPresent(instance.renderer);
}

/**
 * draw_background - Draw the sky and floor
 * @instance: An SDL_Instance containing the window and renderer objects
 **/
void render_background(SDL_Instance instance)
{
    size_t x;

    // Draw the sky
    SDL_SetRenderDrawColor(instance.renderer,  0x44, 0x8C, 0xD9, 0xFF); // Sky blue color
    for (x = 0; x <= SCREEN_WIDTH; x++)
    {
        SDL_RenderDrawLine(instance.renderer, x, 0, x, SCREEN_HEIGHT / 2);
    }

    // Draw the floor
    SDL_SetRenderDrawColor(instance.renderer, 0x00, 0x64, 0x00, 0xFF); // Green color
    for (x = 0; x <= SCREEN_WIDTH; x++)
    {
        SDL_RenderDrawLine(instance.renderer, x, SCREEN_HEIGHT / 2, x, SCREEN_HEIGHT);
    }
}

/**
 * draw_walls - Draw the walls
 * @map: The 2D array representing the map
 * @player: The position of the player
 * @instance: An SDL_Instance containing window and renderer objects
 * @dir: The direction vector indicating the player's facing direction
 * @plane: The projection plane vector.
 **/
void render_maze_walls(char **map, DoubleStruct player, SDL_Instance instance, DoubleStruct dir,
                DoubleStruct plane)
{
    IntStruct mapCoord,
              step;
    DoubleStruct
          rayP,
          rayD,
          distIntersect,
          dist_side;

    double wallDist,
           camera;

    int wHeight,
        wStart,
        wEnd,
        screenX,
        hit;

    // Loop through each screen column
    for (screenX = 0; screenX < SCREEN_WIDTH; screenX++)
    {
        hit = 0;

        // cal to dtmine the dir of the ray for the current screen 
        camera = 2 * screenX / (double)SCREEN_WIDTH - 1;

        // Calculate the direction of the ray from the player's position
        rayD.x = dir.x + plane.x * camera;
        rayD.y = dir.y + plane.y * camera;
        rayP.x = player.x;
        rayP.y = player.y;

        // Convert ray position to map grid coordinates
        //tracing the ray
        mapCoord.x = (int)rayP.x;
        mapCoord.y = (int)rayP.y;

        // Calculate the distance between grid intersections
        distIntersect.x = sqrt(1 + (rayD.y * rayD.y) / (rayD.x * rayD.x));
        distIntersect.y = sqrt(1 + (rayD.x * rayD.x) / (rayD.y * rayD.y));

        // Determine the direction and step of the ray
        rayDir(&step, &dist_side, rayP, mapCoord, distIntersect, rayD);

        // Find the distance to the nearest wall
        wallDist = checkWallDist(map, &dist_side, &mapCoord, &step,
                                  &distIntersect, &hit, &rayD, &rayP);

        // Calculate the height of the wall on the screen
        wHeight = (int)(SCREEN_HEIGHT / wallDist);

        // Calculate the starting and ending points of the wall on the screen
        wStart = -wHeight / 2 + SCREEN_HEIGHT / 2;
        if (wStart < 0)
            wStart = 0;
        wEnd = wHeight / 2 + SCREEN_HEIGHT / 2;
        if (wEnd >= SCREEN_HEIGHT)
            wEnd = SCREEN_HEIGHT - 1;

        // Choose color for the wall based on map content
        select_color(instance, map, mapCoord, hit);

        // Draw the wall on the screen
        SDL_RenderDrawLine(instance.renderer, screenX, wStart,
                           screenX, wEnd);
    }
}





/**
 * select_color - Determine the color to be used for drawing the wall
 * @instance:SDL_Instance, the renderer used for drawing
 * @map: 2D array representing the map
 * @mapCoord: map_coordinates
 * @hit: checks if the ray hit the wall of  N/S or E/W
 **/
void select_color(SDL_Instance instance, char **map, IntStruct mapCoord, int hit)
{
		switch (map[mapCoord.x][mapCoord.y])
		{
		case '1':
			/* gray walls */
			if (hit == 0)
				SDL_SetRenderDrawColor(instance.renderer,  0x40, 0x40, 0x40, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer,  0x30, 0x30, 0x30, 0xFF);
			break;
		case '4':
			if (hit == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0x88, 0x88, 0, 0xFF);
			break;
		default:
			/* White Walls */
			if (hit == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0x88, 0x88, 0x88, 0xFF);
			break;
		}
}
