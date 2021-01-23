#include <iostream>
#include <entt/entt.hpp>
#include <GL/glew.h>
#include <SDL.h>


int main()
{
	SDL_Window* window = SDL_CreateWindow("Bruh", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(window);

	auto err = glewInit();
	if (GLEW_OK != err)
	{
		std::cout << "Error loading GLEW\n";
	}

	glClearColor(0.7f, 1.f, 1.f, 1.f);
	
	bool quit = false;
	while (!quit)
	{
		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		glClear(GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);

	return 0;
}