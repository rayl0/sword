#pragma once 

#include <string>
 
namespace Hay
{
	struct WindowProps
	{
		std::string title;
		int width;
		int height;

		bool vsyncEnabled;

		WindowProps() 
			: title("Hay")
			, width(1280)
			, height(720)
			{}
	};

	class Window
	{
	public:
		static Window* Create(const WindowProps& props = {});
		static void Destroy(Window* window);

		virtual const int& GetWidth() const = 0;
		virtual const int& GetHeight() const = 0;

		virtual void SetTitle(const std::string& title) = 0;

		virtual bool IsOpen() const = 0;
		virtual void PollEvents() = 0;

		virtual void MakeCurrent() = 0;
		virtual void SwapBuffers() = 0;
	};
}
