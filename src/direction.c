#include "../main.h"

/**
 * rotation - Rotate the camera left/right
 * @plane: The projection plane
 * @dir: The players direction vector
 * @rot_dir: Rotation direction, -1 for right, 1 for left
 **/
void rotation(DoubleStruct *plane, DoubleStruct *dir, int rDir)
{
    // Rotation speed
    double rspeed;
    double prevXdir;
    double preXplane;
    
    // Calculate rotation speed
    rspeed = 0.05 * rDir;
    prevXdir = dir->x;
    
    // Perform rotation for direction vector
    dir->x = dir->x * cos(rspeed) - dir->y * sin(rspeed);
    dir->y = prevXdir * sin(rspeed) + dir->y * cos(rspeed);
    preXplane = plane->x;
    
    // Perform rotation for projection plane
    plane->x = plane->x * cos(rspeed) - plane->y * sin(rspeed);
    plane->y = preXplane * sin(rspeed) + plane->y * cos(rspeed);
}

/**
 * move_forward_backward - Moves the player forward or backward based on input key
 * @play: Pointer to the player's position struct
 * @dir: Pointer to the player's direction struct
 * @map: 2D array representing the game map
 * @mspeed: Movement speed
 **/
void move_forward_backward(DoubleStruct *play, DoubleStruct *dir, char **map, double mspeed)
{
 // Move the player forward or backwards along the direction vector if there's no wall in the way
    if (map[(int)(play->x + dir->x * mspeed)][(int)play->y] == '0')
    {
        play->x += dir->x * mspeed;
    }
    if (map[(int)play->x][(int)(play->y + dir->y * mspeed)] == '0')
    {
        play->y += dir->y * mspeed;
    }
}

/**
 * movement - Handles player movement based on input keys
 * @key: Struct representing the keyboard input
 * @plane: Pointer to the projection plane struct
 * @dir: Pointer to the player's direction struct
 * @play: Pointer to the player's position struct
 * @map: 2D array representing the game map
 **/

void movement(keys key, DoubleStruct *plane, DoubleStruct *dir, DoubleStruct *play,
              char **map)
{
    //movement speed
    double mspeed = 0.07;

    if (key.right)
    {
        rotation(plane, dir, -1); // Rotate camera to the right
    }
    if (key.left)
    {
        rotation(plane, dir, 1); // Rotate camera to the left
    }

    // Forward movement
    if (key.up)
    {
        move_forward_backward(play, dir, map, mspeed);
    }

    // Backward movement
    if (key.down)
    {
        // Adjust speed if needed for backward movement
        move_forward_backward(play, dir, map, -mspeed);
    }
}
