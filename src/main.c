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
#  define WINDOW_WIDTH  320
#  define WINDOW_HEIGHT 240
#endif

int main(int argc, char* argv[])
{
    int           status        = EXIT_SUCCESS;
    SDL_bool      is_running    = SDL_TRUE;
    SDL_Window*   window        = NULL;
    SDL_Renderer* renderer      = NULL;
    SDL_Texture*  render_target = NULL;
    SDL_Event     event;

#if !defined (__NGAGE__)
    SDL_Surface  *frame_sf = NULL;
    SDL_Texture  *frame    = NULL;
    SDL_Rect      viewport = { 72, 11, 176, 208 };
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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_TARGETTEXTURE);
    if (NULL == renderer)
    {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        status = EXIT_FAILURE;
        goto quit;
    }

    render_target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB444, SDL_TEXTUREACCESS_TARGET, 176, 208);
    if (NULL == render_target)
    {
        SDL_Log("Unable to create render target: %s", SDL_GetError());
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
    if (SDL_RenderClear(renderer) < 0)
    {
        SDL_Log("Unable to clear current rendering target: %s", SDL_GetError());
    }

    if (SDL_RenderCopy(renderer, frame, NULL, NULL) < 0)
    {
        SDL_Log("Unable to copy to current rendering target: %s", SDL_GetError());
    }
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

        if (SDL_SetRenderTarget(renderer, render_target) < 0)
        {
            SDL_Log("Unable to set render target: %s", SDL_GetError());
        }

        if (SDL_SetRenderDrawColor(renderer, 0xff, 00, 0x51, 0xff) < 0)
        {
            SDL_Log("Unable to set draw color: %s", SDL_GetError());
        }

        if (SDL_RenderClear(renderer) < 0)
        {
            SDL_Log("Unable to clear current rendering target: %s", SDL_GetError());
        }

        // Render magic should happen here.

        if (SDL_SetRenderTarget(renderer, NULL) < 0)
        {
            SDL_Log("Unable to set render target: %s", SDL_GetError());
        }
#if !defined (__NGAGE__)
        if (SDL_RenderCopy(renderer, render_target, NULL, &viewport) < 0)
#else
        if (SDL_RenderCopy(renderer, render_target, NULL, NULL) < 0)
#endif
        {
            SDL_Log("Unable to copy to current rendering target: %s", SDL_GetError());
        }
        SDL_RenderPresent(renderer);
    }

quit:
    if (NULL != render_target)
    {
        SDL_DestroyTexture(render_target);
    }

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
