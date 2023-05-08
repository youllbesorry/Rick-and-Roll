/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:49:26 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/29 02:31:06 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <SDL/SDL.h>
#include <stdio.h>

int main()
{
    SDL_Surface* screen = NULL;
    SDL_Surface* image = NULL;
    SDL_Event event;
    int mouseX, mouseY;
    int running;

    running = 1;
     if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Erreur d'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    }
    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL)
    {
        SDL_Quit();
        return 1;
    }
    image = SDL_LoadBMP("image.bmp");
    if (image == NULL)
    {
        printf("Erreur de chargement de l'image : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
                break;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                printf("Clic de souris détecté à la position : x = %d, y = %d\n", x, y);
				SDL_GetMouseState(&mouseX, &mouseY);
				SDL_Rect dstRect = { mouseX - image->w/2, mouseY - image->h/2, image->w, image->h };
				SDL_BlitSurface(image, NULL, screen, &dstRect);
				SDL_Flip(screen);

            }
        }
    }
    SDL_FreeSurface(image);
    SDL_Quit();
    return 0;
}

