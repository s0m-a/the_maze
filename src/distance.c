#include "../main.h"
/**
 * rayDir - cal the step dir and distance to the next side for the ray
 * @step: The direction to move
 * @distSide: Distance to next square on the grid
 * @rayP: The start position of the ray being cast
 * @mapCoord: Coordinates on the grid
 * @distIntersect: The difference in distance between two sides of a grid
 * @rayD: The ray's vector direction
 **/
void rayDir(IntStruct *step, DoubleStruct *distSide, DoubleStruct rayP,
		   IntStruct mapCoord, DoubleStruct distIntersect, DoubleStruct rayD)
{
	if (rayD.x < 0)
	{
		step->x = -1;
		distSide->x = (rayP.x - mapCoord.x) * distIntersect.x;
	}
	else
	{
		step->x = 1;
		distSide->x = (mapCoord.x + 1.0 - rayP.x) * distIntersect.x;
	}
	if (rayD.y < 0)
	{
		step->y = -1;
		distSide->y = (rayP.y - mapCoord.y) * distIntersect.y;
	}
	else
	{
		step->y = 1;
		distSide->y = (mapCoord.y + 1 - rayP.y) * distIntersect.y;
	}
}

/**
 * checkWallDist - Calculate the distance between the player and the wall
 * @map: 2D Array representing the map
 * @distSide: Distance to the next side of the map grid along the X and Y-axis
 * @mapCoord: x/y coordinate of the player in the map
 * @step: direction player will move in on the x/y axes
 * @distIntersect: The x/y change between two sides of the map grid
 * @hit: Hit N/S or  E/W wall
 * @rayD: Direction of the ray vector from the player
 * @rayP: X/Y coordinate of the ray
 * Return: returns Distance from player to the wall
 **/
double checkWallDist(char **map, DoubleStruct *distSide, IntStruct *mapCoord,
		      IntStruct *step, DoubleStruct *distIntersect, int *hit,
		      DoubleStruct *rayD, DoubleStruct *rayP)
{
	int hitWall = 0;
	double wallDist;

	while (hitWall == 0)
	{
		if (distSide->x < distSide->y)
		{
			distSide->x += distIntersect->x;
			mapCoord->x += step->x;
			*hit = 0;
		}
		else
		{
			distSide->y += distIntersect->y;
			mapCoord->y += step->y;
			*hit = 1;
		}
		if (map[mapCoord->x][mapCoord->y] > '0')
			hitWall = 1;
	}
	if (*hit == 0)
		wallDist = (mapCoord->x - rayP->x + (1 - step->x) / 2) / rayD->x;
	else
		wallDist = (mapCoord->y - rayP->y + (1 - step->y) / 2) / rayD->y;
	return (wallDist);
}
