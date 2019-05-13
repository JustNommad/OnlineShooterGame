#pragma once
#include "SourceFiles/Renderer.h"
#include "SourceFiles/VertexBufferLayout.h"
#include "SourceFiles/VertexBuffer.h"
#include "SourceFiles/Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <windows.h>
#include "Map.h"

#include <GLFW/glfw3.h>



class Player1
{
private:
	float positions[16]{
	 -65.0f,  -65.0f, 0.0f, 0.0f,	//0
	  65.0f,  -65.0f, 1.0f, 0.0f,	//1
	  65.0f,   65.0f, 1.0f, 1.0f,	//2
	 -65.0f,   65.0f, 0.0f, 1.0f,	//3
	};
	std::string TextFold = "res/texture/Marine1.png";
	GLuint texture_;
	VertexArray vabc;
	int dx_, dy_;
	int x_, y_;
	bool UP_c = false, DOWN_c = false, LEFT_c = false, RIGHT_c = false;
	int AnimCount = 0;
	int checkPush = 0, drop_mode = 0;
	int Up_count = 0, Down_count = 0, Right_count = 0, Left_count = 0;
public:
	Player1();
	~Player1();

	void MCheck(Map& map, GLFWwindow& window);
	void PrintBC(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer);

};
