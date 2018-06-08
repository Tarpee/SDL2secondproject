
	
#include <SDL.h>

int main(int argc, char ** argv)
{
	// variables

	bool quit = false;
	SDL_Event event;
	int x = 288;
	int y = 208;
	int xvel = 0;
	int yvel = 0;
	

	// init SDL

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Surface * image = SDL_LoadBMP("c:/Users/jason/source/repos/SDL2secondproject/spaceship.bmp");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
		image);
	SDL_FreeSurface(image);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// handle events

	while (!quit)
	{
		SDL_Delay(5);
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:  xvel = -2; break;
			case SDLK_RIGHT: xvel = 1; break;
			case SDLK_UP:    yvel = -1; break;
			case SDLK_DOWN:  yvel = 1; break;
			default:
				break;


			}

		//	break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				if (xvel > 0)
					xvel = 0;
				break;
			case SDLK_RIGHT:
				if (xvel > 0)
					xvel = 0;
				break;
			case SDLK_UP:
				if (xvel > 0)
					xvel = 0;
				break;
			case SDLK_DOWN:
				if (xvel > 0)
					xvel = 0;
				break;
			default:
				break;
			}
			break;
		  default:
			break;
		}
		x += xvel;
		y += yvel;

		


		SDL_Rect dstrect = { x, y, 64, 64 };

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_RenderPresent(renderer);
	}
 

	// cleanup SDL

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();



	return 0;
}