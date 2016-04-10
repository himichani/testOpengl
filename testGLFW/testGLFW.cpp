// testGLFW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "application.h"
#ifdef  TEST_CONSOLE
#include <GLFW\glfw3.h>

int main()
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Hellow World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;			 
	}
	

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))	
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

    return 0;
}
#endif
class simpleclear : public sb6::application
{

};

DECLARE_MAIN(simpleclear);