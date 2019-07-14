#include "core/window.h"

#include <glad.h>
#include <SDL.h>

namespace Hay
{
	static void InitSDL()
	{
		static bool isInitialized = false;

		if(!isInitialized)
			SDL_Init(SDL_INIT_EVERYTHING);

		isInitialized = true;
	}

	static void LoadGL()
	{
		static bool isGLLoaded = false;

		if(!isGLLoaded)
			gladLoadGL();

		isGLLoaded = true;
	}

	class SDLWindow : public Window
	{
		SDL_Window* window = nullptr;
		SDL_GLContext context;

		struct WindowData
		{
			std::string title;

			int width;
			int height;

			bool isOpen;
		}windowData;
	public:
		static SDLWindow* Create(const WindowProps& props)
		{
			return new SDLWindow(props);
		}

		SDLWindow(const WindowProps& props)
		{
			InitSDL();

			windowData.title = props.title;
			windowData.width = props.width;
			windowData.height = props.height;
			windowData.isOpen = true;

			window = SDL_CreateWindow(props.title.c_str(), SDL_WINDOWPOS_UNDEFINED,
														   SDL_WINDOWPOS_UNDEFINED,
														   props.width, props.height,
														   SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

			context = SDL_GL_CreateContext(window);

			SDL_GL_MakeCurrent(window, context);

			LoadGL();
		}

		~SDLWindow()
		{
			SDL_GL_DeleteContext(context);
			SDL_DestroyWindow(window);
		}

		const int& GetWidth() const {
			return windowData.width;
		}

		const int& GetHeight() const {
			return windowData.height;
		}

		void SetTitle(const std::string& title)
		{
			SDL_SetWindowTitle(window, title.c_str());
		}

		bool IsOpen() const
		{
			return windowData.isOpen;
		}

		void PollEvents()
		{
			static SDL_Event e;

			while(SDL_PollEvent(&e))
			{
				switch(e.type)
				{
					case SDL_QUIT:
						windowData.isOpen = false;
				}
			}
		}

		void MakeCurrent()
		{
			SDL_GL_MakeCurrent(window, context);
		}

		void SwapBuffers()
		{
			SDL_GL_SwapWindow(window);
		}
	};

	Window* Window::Create(const WindowProps& props)
	{
		return SDLWindow::Create(props);
	}

	void Window::Destroy(Window* win)
	{
		delete win;
	}

}

