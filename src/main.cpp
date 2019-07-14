#include <spdlog/spdlog.h>
#include <glad.h>
#include <GLFW/glfw3.h>

int main(int argc, char const *argv[])
{
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow* win = glfwCreateWindow(1280, 720, "Window", nullptr, nullptr);
	glfwMakeContextCurrent(win);

    gladLoadGL();

    glClearColor(0.0f, 0.5f, 0.3f, 1.0f);

    while(!glfwWindowShouldClose(win))
    {
    	glfwPollEvents();

    	glClear(GL_COLOR_BUFFER_BIT);

    	glfwSwapBuffers(win);
    }

    glfwTerminate();

	return 0;
}