
#include "../main.h"

/**
 * key_release - Check for what key was released
 * @event: The event element containing which key was released
 * @key_press: Struct containing significant keys to check if they were pressed
 **/
void key_release(SDL_Event e, keys *key)
{
	 // Update the 'key' field to indicate key release
    switch (e.key.keysym.sym)
    {
        case SDLK_w:
        case SDLK_UP:
            key->up = 0;
            break;
        case SDLK_s:
        case SDLK_DOWN:
            key->down = 0;
            break;
        case SDLK_a:
        case SDLK_LEFT:
            key->left = 0;
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            key->right = 0;
            break;
        default:
            break;
    }
}

/**
 * key_press - Check the key that was pressed down
 * @e event element containing which key was pressed
 * @key_press: Struct containing significant keys to check if they were pressed
 * Return: 1 if ESC is pressed, 0 otherwise
 **/
int key_press(SDL_Event e, keys *key)
{
    // Check if the pressed key is ESC
    if (e.key.keysym.scancode == 0x29)
        return (1);
    // If key was pressed,Update the field to indicate key press
    // Handle other key presses
    switch (e.key.keysym.sym)
    {
        case SDLK_w:
        case SDLK_UP:
            key->up = 1;
            break;
        case SDLK_s:
        case SDLK_DOWN:
            key->down = 1;
            break;
        case SDLK_a:
        case SDLK_LEFT:
            key->left = 1;
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            key->right = 1;
            break;
        default:
            break;
    }
    return (0);

}

/**
 * read_key_input - reads  key presses
 * @key: Struct for up/down/left/right key presses
 * Return: 0 for standard events, 1 for exit events
 **/
int read_key_input(keys *key)
{
    SDL_Event e;


    // Loop to continuously poll for events
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                return (1);
			//event type is triggered when a key on the keyboard is pressed down.
            case SDL_KEYDOWN:
                if (key_press(e, key))
                    return (1);
                break;
			//event type is triggered when a key on the keyboard is released after being pressed.
            case SDL_KEYUP:
                key_release(e, key);
                break;
            default:
                break;
        }
    }
    return (0);
}
