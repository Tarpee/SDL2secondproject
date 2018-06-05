/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


bool init();
bool loadMedia();
void close();
//test
//test
//test
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

bool init() {

	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL no initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("WIndow not created SDL_ERROR: %s\n", SDL_GetError());
				success = false;
				

		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			
		}
	}

	return success;
}

bool loadMedia() {

	bool success = true;
	gHelloWorld = SDL_LoadBMP("c:/Users/jason/source/repos/SDL2secondproject/hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s SDL Error %s\n", "errorry", SDL_GetError());
		success = false;
	}
	return success;
}
void close() {

	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();

}
int main(int argc, char* args[])
{
	if (!init())
	{
		printf("Failed to init!\n");
	}
	else
	{
		if (!loadMedia())
		{
			printf("Falied to load media!\n");
		}
		else {
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			SDL_UpdateWindowSurface(gWindow);
			SDL_Delay(3000);

		}
	}
	close();
	return 0;
}