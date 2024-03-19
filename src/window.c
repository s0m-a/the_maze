#include "../main.h"

/**
 * init_instance - creates a window and renderer
 * @instance:instance to initialize
 * Return:returns 1 on failure or 0 for success
 **/
int init_instance(SDL_Instance *instance)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1; // Error occurred
    }

    instance->window = SDL_CreateWindow("MAZE", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (instance->window == NULL)
    {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1; // Error occurred
    }

    instance->renderer = SDL_CreateRenderer(instance->window, -1,
                                            SDL_RENDERER_ACCELERATED |
                                            SDL_RENDERER_PRESENTVSYNC);
    if (instance->renderer == NULL)
    {
        fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(instance->window);
        SDL_Quit();
        return 1; // Error occurred
    }

    return 0; // Success
}
