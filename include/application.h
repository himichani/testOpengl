#pragma once


#include <Windows.h>

#include <GLFW\glfw3.h>

#include <stdio.h>
#include <string.h>

namespace sb6
{
	class application
	{
	public:
		application() {}
		virtual ~application() {}
		virtual void run(sb6::application* the_app)
		{
			bool running = true;
			app = the_app;

			if (!glfwInit())
			{
				fprintf(stderr, "Failed to initialize GLFW\n");
				return;
			}

			init();

			window = glfwCreateWindow(640, 480, "Hellow World", NULL, NULL);

			if (!window)
			{
				glfwTerminate();
				return;
			}

			glfwMakeContextCurrent(window);

			while (! glfwWindowShouldClose(window))
			{
				glfwSwapBuffers(window);
				glfwPollEvents();
			}

			glfwTerminate();

		}

		virtual void init()
		{
			strcpy(info.title, "SuperBible6 Example");
			info.windowWidth = 800;
			info.windowHeight = 600;

			info.majorVersion = 4;
			info.minorVersion = 3;

			info.samples = 0;
			info.flags.all = 0;
			info.flags.cursor = 1;
#ifdef _DEBUG
			info.flags.debug = 1;
#endif
		}
	public :
		struct APPINFO
		{
			char title[128];
			int windowWidth;
			int windowHeight;
			int majorVersion;
			int minorVersion;
			int samples;
			union
			{
				struct
				{
					unsigned int    fullscreen : 1;
					unsigned int    vsync : 1;
					unsigned int    cursor : 1;
					unsigned int    stereo : 1;
					unsigned int    debug : 1;
				};
				unsigned int        all;
			} flags;
		};
	protected:
		APPINFO info;
		static sb6::application* app;
		GLFWwindow* window;
	};
}




#define DECLARE_MAIN(a)                             \
sb6::application *app = 0;                          \
int CALLBACK WinMain(HINSTANCE hInstance,           \
                     HINSTANCE hPrevInstance,       \
                     LPSTR lpCmdLine,               \
                     int nCmdShow)                  \
{                                                   \
    a *app = new a;                                 \
    app->run(app);                                  \
    delete app;                                     \
    return 0;                                       \
}