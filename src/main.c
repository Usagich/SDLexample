/** @file main.c
 *
 *  A simple SDL 2.0.x sample project.
 *
 *  To the extent possible under law, Michael Fitzmayer has waived all
 *  copyright and related or neighboring rights to SDLexample.  This
 *  work is published from: Germany.
 *
 *  CC0 http://creativecommons.org/publicdomain/zero/1.0/
 *  SPDX-License-Identifier: CC0-1.0
 *
 **/

#include <stdlib.h>
#include "SDL.h"
#include "SDL_main.h"

#define WINDOW_WIDTH  320
#define WINDOW_HEIGHT 240

int main(int argc, char* argv[])
{
    int           status     = EXIT_SUCCESS;
    SDL_bool      is_running = SDL_TRUE;
    SDL_Window   *window     = NULL;
    SDL_Renderer *renderer   = NULL;
    SDL_Event     event;

    if (0 != SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Unable to initialise SDL: %s", SDL_GetError());
        status = EXIT_FAILURE;
        goto quit;
    }

    window = SDL_CreateWindow(
        "SDLexample",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        176,
        208,
        0);

    if (NULL == window)
    {
        SDL_Log("Could not create window: %s", SDL_GetError());
        status = EXIT_FAILURE;
        goto quit;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (NULL == renderer)
    {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        status = EXIT_FAILURE;
        goto quit;
    }

    while (SDL_TRUE == is_running)
    {
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                is_running = SDL_FALSE;
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

quit:
    if (NULL != window)
    {
        SDL_DestroyWindow(window);
    }

    if (NULL != renderer)
    {
        SDL_DestroyRenderer(renderer);
    }

    SDL_Quit();

    return status;
}
