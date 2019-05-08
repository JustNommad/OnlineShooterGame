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
	int checkPush = 0;
public:
	Player1();
	~Player1();

	void MCheck(int key, Map& map);
	void PrintBC(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer);
};
