#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Background.h"
#include "Player1.h"

GLFWwindow* window;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int argc, char* argv[])
{

	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1920, 1080, "Space War: Arena", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		std::cout << "Error!" << std::endl;
	}
	std::cout << glGetString(GL_VERSION) << std::endl;

	{
		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		Background background;
		Map map;

		IndexBuffer ib(indices, 6);

		glm::mat4 proj = glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

		Shader shader("res/shaders/Basic.shader");
		shader.Bind();
		
		shader.SetUniform1i("u_Texture", 0);

		ib.Unbind();
		shader.Unbind();
		
		Renderer renderer;
		Player1 player1(shader, proj, view, ib, renderer);

		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
			renderer.Clear();

			shader.Bind();

			background.PrintBC(shader, proj, view, ib, renderer);
			map.PrintMP(shader, proj, view, ib, renderer);
			map.ColisionMap();
			player1.PrintHUD(shader, proj, view, ib, renderer);
			player1.MCheck(map, *window);
			player1.PrintBC();
			
			Sleep(15);
			glfwSwapBuffers(window);

		}
	}

	glfwTerminate();
	return 0;
}

 
