#include "core/window.h"
#include <glad.h>
#include <GLFW/glfw3.h>

namespace Hay
{
    static bool isGlfwInitialized = false;
    static bool isOpenGLLoaded = false;

    static void InitGLFW()
    {
        glfwInit();

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        isGlfwInitialized = true;
    }

    static void LoadGL()
    {
        gladLoadGL();

        isOpenGLLoaded = true;
    }

    class GLFWwindow : public Window
    {
        ::GLFWwindow* win = nullptr;

        struct WindowData
        {
            std::string cTitle;

            int vWidth;
            int vHeight;
        }windowData;

    public:
        static GLFWwindow* Create(const WindowProps& props) {
            return new GLFWwindow(props);
        }

        GLFWwindow(const WindowProps& props)
        {
            if(!isGlfwInitialized)
                InitGLFW();

            windowData.cTitle = props.title;
            windowData.vWidth = props.width;
            windowData.vHeight = props.height;

            win = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);
            glfwMakeContextCurrent(win);

            if(!isOpenGLLoaded)
                LoadGL();

            glfwSetWindowUserPointer(win, &windowData);
        }

        ~GLFWwindow()
        {
            glfwDestroyWindow(win);
        }

        const int& GetWidth() const {
            return windowData.vWidth;
        }

        const int& GetHeight() const {
            return windowData.vHeight;
        }

        void SetTitle(const std::string& title)
        {
            glfwSetWindowTitle(win, title.c_str());
        }

        bool IsOpen() const
        {
            return !glfwWindowShouldClose(win);
        }

        void PollEvents()
        {
            glfwPollEvents();
        }

        void MakeCurrent()
        {
            glfwMakeContextCurrent(win);
        }

        void SwapBuffers()
        {
            glfwSwapBuffers(win);
        }
    };

    Window* Window::Create(const WindowProps& props)
    {
        return GLFWwindow::Create(props);
    }

    void Window::Destroy(Window* win)
    {
        delete win;
    }
}


