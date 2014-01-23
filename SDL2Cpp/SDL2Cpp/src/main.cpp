// main.cpp

// STD Includes
#include <cstdlib>
// Project Includes
#include <SDL2Cpp\SDL2.hpp>

class Game : public SDL2::Events
{
	public:
		Game()
		{
			SDL2::Initialize(SDL_INIT_EVERYTHING);

			mWindow.Initialize("SDL2Cpp", 800, 600, SDL_WINDOW_OPENGL);
			mRenderer.Initialize(mWindow, -1, SDL_RENDERER_SOFTWARE);
			mTexture.Load(mRenderer, "asset/img/image.png");
			
			mFrameCount = 0;
			mFrameRate = 30;
			mCapFPS = false;
			mRunning = true;
		}

		~Game()
		{
			SDL2::Finalize();
		}

		void Run()
		{
			mTimer.Start();

			while(mRunning)
			{
				Poll();
				Update();
				Render();
			}
		}

		void Update()
		{
			mFPS.Start();
			mFrameCount++;

			if(mCapFPS && mFPS.GetTicks() < 1000 / mFrameRate)
				SDL_Delay(1000 / mFrameRate - mFPS.GetTicks());
			
			if(SDL2::Keyboard::IsKeyPressed(SDLK_ESCAPE))
			{
				mRunning = false;
			}

			if(SDL2::Keyboard::IsKeyPressed(SDLK_SPACE))
			{
				mCapFPS = !mCapFPS;
				mWindow.SetTitle(mCapFPS ? "SDL2Cpp : 30 FPS" : "SDL2Cpp : Unlimited FPS");
			}

			if(SDL2::Mouse::IsScrolledDown())
			{
				SDL_Log("Scroll DOWN");
			}
			
			if(SDL2::Mouse::IsScrolledUp())
			{
				SDL_Log("Scroll UP");
			}

			int x;
			int y;
			SDL2::Mouse::GetPosition(x, y);

			//SDL_Log("Mouse: %i, %i", x, y);
			//SDL_Log("Frame: %i | ElapsedTime: %.2f | Delta Time: %.4f", mFrameCount, mTimer.GetElapsedTime(), mTimer.GetDeltaTime());
		}

		void Render()
		{
			mRenderer.SetDrawColor(0, 0, 0, 255);
			mRenderer.Clear();
			mRenderer.Draw(mTexture, SDL2::Rectangle(rand() % 800, rand() % 600, 200, 200));
			for(int i = 0; i < 100; ++i)
			{
				mRenderer.SetDrawColor(rand() % 255, rand() % 255, rand() % 255, 255);
				mRenderer.DrawLine(rand() % 800, rand() % 600, rand() % 800, rand() % 600);
			}
			mRenderer.Show();
		}

	private:
		virtual void OnQuit()
		{
			mRunning = false;
		}

	private:
		SDL2::Window mWindow;
		SDL2::Renderer mRenderer;
		SDL2::Texture mTexture;
		SDL2::Timer mTimer;
		SDL2::Timer mFPS;
		int mFrameCount;
		int mFrameRate;
		bool mCapFPS;
		bool mRunning;
};

int main(int argc, char** argv)
{
	Game game;
	game.Run();

	return 0;
}