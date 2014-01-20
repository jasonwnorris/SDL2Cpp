// main.cpp

// STD Includes
#include <cstdlib>
// Project Includes
#include <SDL2Cpp\SDL2.hpp>

void keyHit(SDL_Keycode key, Uint16 sym, Uint8 mod)
{
	SDL_Log("Key: %s", SDL_GetKeyName(key));
}

int main(int argc, char** argv)
{
	SDL2::Initialize(SDL_INIT_EVERYTHING);
	SDL2::Window window("SDL2Cpp", 800, 600, SDL_WINDOW_OPENGL);
	SDL2::Renderer renderer(window, -1, SDL_RENDERER_SOFTWARE);
	SDL2::Texture texture(renderer, "asset/img/image.png");
	SDL2::Timer timer;

	bool running = true;

	SDL2::Events::OnQuit.Register([&running]() { running = false; });
	SDL2::Events::OnKeyDown.Register(keyHit);

	while(running)
	{
		SDL2::Events::Update();

		renderer.SetDrawColor(0, 0, 0, 255);
		renderer.Clear();
		renderer.Draw(texture, SDL2::Rectangle(rand() % 800, rand() % 600, 200, 200));
		for(int i = 0; i < 100; ++i)
		{
			renderer.SetDrawColor(rand() % 255, rand() % 255, rand() % 255, 255);
			renderer.DrawLine(rand() % 800, rand() % 600, rand() % 800, rand() % 600);
		}
		renderer.Show();

		//SDL_Log("ElapsedTime: %.6f | Delta Time: %.6f", timer.GetElapsedTime(), timer.GetDeltaTime());

		SDL_Delay(100);
	}

	SDL2::Finalize();

	return 0;
}