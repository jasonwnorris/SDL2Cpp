// main.cpp

// STD Includes
#include <cstdlib>
// Project Includes
#include <SDL2Cpp\SDL2.hpp>

int main(int argc, char** argv)
{
	SDL2::Initialize(SDL_INIT_EVERYTHING);
	SDL2::Window window("SDL2Cpp", 800, 600, SDL_WINDOW_OPENGL);
	SDL2::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL2::Texture texture(renderer, "asset/img/image.png");
	SDL2::Timer timer;

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
		for(int i = 0; i < 100; ++i)
		{
			renderer.SetDrawColor(rand() % 255, rand() % 255, rand() % 255, 255);
			renderer.DrawLine(rand() % 800, rand() % 600, rand() % 800, rand() % 600);
		}
		renderer.Show();

		SDL_Log("ElapsedTime: %.6f | Delta Time: %.6f", timer.GetElapsedTime(), timer.GetDeltaTime());

		SDL_Delay(100);
	}

	SDL2::Finalize();

	return 0;
}