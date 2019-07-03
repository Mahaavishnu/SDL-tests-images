#include <stdio.h>
#include <stdlib.h>
#include "SDL2/include/SDL.h"

int			main(int argc, char *argv[])
{
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_Surface *screen;
	SDL_Surface *img;
	SDL_Rect position;

	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "SDL_Init Error : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	win = SDL_CreateWindow("Hellow World", 100, 100, 700, 256, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error : %s\n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	screen = SDL_GetWindowSurface(win);
	if (screen == NULL)
	{
		fprintf(stderr, "SDL_GetWindowSurface Error : %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	/*for (x = 0; x < 256; x++)
	{
		for (y = 0; y < 700; y++)
		{
			position.x = y;
			position.y = x;
			drawing[x][y] = SDL_CreateRGBSurface(SDL_SWSURFACE, 1, 1, 32, 0, 0, 0, 0);
			SDL_FillRect(drawing[x][y], NULL, SDL_MapRGB(screen->format, x, x, x));
			SDL_BlitSurface(drawing[x][y], NULL, screen, &position);
			SDL_FreeSurface(drawing[x][y]);
		}
		y = 0;
	}*/

	if (SDL_UpdateWindowSurface(win) != 0)
	{
		fprintf(stderr, "SDL_UpdateWindowSurface Error : %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	SDL_Delay(8000);

	SDL_Quit();

	return EXIT_SUCCESS;
}