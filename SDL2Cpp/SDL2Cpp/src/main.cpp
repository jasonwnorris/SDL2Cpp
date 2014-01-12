// main.cpp

// Project Includes
#include <SDL2Cpp\SDL2.hpp>

int main(int argc, char** argv)
{
	SDL2::Initialize(SDL_INIT_EVERYTHING);
	SDL2::Window window("SDL2Cpp", 800, 600, SDL_WINDOW_OPENGL);
	SDL2::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL2::Texture texture(renderer, "asset/img/image.png");

	bool running = true;
	SDL_Event evt;

	while(running)
	{
		while(SDL_PollEvent(&evt))
			if(evt.type == SDL_QUIT)
				running = false;
		
		renderer.SetDrawColor(0, 0, 0, 255);
		renderer.Clear();
		renderer.Draw(texture, SDL2::Rectangle(rand() % 800, rand() % 600, 200, 200));
		renderer.SetDrawColor(255, 0, 0, 255);
		renderer.DrawLine(rand() % 800, rand() % 600, rand() % 800, rand() % 600);
		renderer.SetDrawColor(0, 255, 0, 255);
		renderer.DrawLine(rand() % 800, rand() % 600, rand() % 800, rand() % 600);
		renderer.SetDrawColor(0, 0, 255, 255);
		renderer.DrawLine(rand() % 800, rand() % 600, rand() % 800, rand() % 600);
		renderer.Show();

		SDL_Delay(500);
	}

	SDL2::Finalize();

	return 0;
}