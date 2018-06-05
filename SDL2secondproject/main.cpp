//#include <SDL.h>

//SDL_Window* g_pWindow = 0;
//SDL_Renderer* g_pRenderer = 0;




bool g_bRunning = true;

int main()
{
	init();

	while (g_bRunning)
	{
		handleEvents();
		update();
		render();
	}
	clean();
		
		
		return 0;
}
	
	


