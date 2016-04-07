#pragma once


#include <Windows.h>

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

			
		}
	protected:
		static sb6::application* app;
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