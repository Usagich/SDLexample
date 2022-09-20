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

#if defined (__NGAGE__)
#  define WINDOW_WIDTH  176
#  define WINDOW_HEIGHT 208
#else
#  define WINDOW_WIDTH  640
#  define WINDOW_HEIGHT 480
#endif

int main(int argc, char* argv[])
{
    int           status     = EXIT_SUCCESS;
    SDL_bool      is_running = SDL_TRUE;
    SDL_Window   *window     = NULL;
    SDL_Renderer *renderer   = NULL;
    SDL_Event     event;

#if !defined (__NGAGE__)
    SDL_Surface  *frame_sf   = NULL;
    SDL_Texture  *frame      = NULL;
#endif

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
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0);

    if (NULL == window)
    {
        SDL_Log("Could not create window: %s", SDL_GetError());
        status = EXIT_FAILURE;
        goto quit;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (NULL == renderer)
    {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        status = EXIT_FAILURE;
        goto quit;
    }

#if !defined (__NGAGE__)
    frame_sf = SDL_LoadBMP("frame.bmp");
    if (NULL == frame_sf)
    {
        SDL_Log("Unable to load file: %s", SDL_GetError());
        status = EXIT_FAILURE;
        goto quit;
    }

    if (0 != SDL_SetColorKey(frame_sf, SDL_TRUE, SDL_MapRGB(frame_sf->format, 0xff, 0x00, 0xff)))
    {
        SDL_Log("Failed to set color key: %s", SDL_GetError());
    }

    if (0 != SDL_SetSurfaceRLE(frame_sf, 1))
    {
        SDL_Log("Could not enable RLE for surface: %s", SDL_GetError());
    }

    frame = SDL_CreateTextureFromSurface(renderer, frame_sf);
    if (NULL == frame)
    {
        SDL_Log("Unable to convert surface to texture: %s", SDL_GetError());
        status = EXIT_FAILURE;
        SDL_FreeSurface(frame_sf);
        goto quit;
    }
    SDL_FreeSurface(frame_sf);
#endif

    while (SDL_TRUE == is_running)
    {
        if (SDL_PollEvent(&event) > 0)
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    is_running = SDL_FALSE;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        case SDLK_SOFTLEFT:
                        case SDLK_SOFTRIGHT:
                            is_running = SDL_FALSE;
                            break;
                    }
                    break;
            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xff, 00, 0x51, 0xff);
        SDL_RenderClear(renderer);
#if !defined (__NGAGE__)
        SDL_RenderCopy(renderer, frame, NULL, NULL);
#endif
        SDL_RenderPresent(renderer);
    }

quit:
#if !defined (__NGAGE__)
    if (NULL != frame)
    {
        SDL_DestroyTexture(frame);
    }
#endif

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
