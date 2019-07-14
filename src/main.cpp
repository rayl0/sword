#include <spdlog/spdlog.h>
#include <glad.h>
#include "core/window.h"

int main(int argc, char const *argv[])
{
	Hay::Window* win = Hay::Window::Create();

    glClearColor(0.0f, 0.5f, 0.3f, 1.0f);

    while(win->IsOpen())
    {
    	win->PollEvents();

    	glClear(GL_COLOR_BUFFER_BIT);

    	win->SwapBuffers();
    }

    Hay::Window::Destroy(win);

	return 0;
}