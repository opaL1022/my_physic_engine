#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

const unsigned int width = 800;
const unsigned int height = 800;

int main()
{
	glfwInit();
	
	//get OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//use CORE profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//create GLFWwindow object
	GLFWwindow* window = glfwCreateWindow(width, height, "my physic engine", NULL, NULL);
	//error check
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//set window into current context
	glfwMakeContextCurrent(window);

	//load GLAD
	gladLoadGL();
	//specify the viewport of OpenGL in the window
	glViewport(0, 0, width, height);

	//main while loop
	while (!glfwWindowShouldClose(window))
	{
		//specify the background color
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		//clean the back buffer assign the new color
		glClear(GL_COLOR_BUFFER_BIT);

		//swap back and front buffer
		glfwSwapBuffers(window);
		//take care of all GLFW events
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}