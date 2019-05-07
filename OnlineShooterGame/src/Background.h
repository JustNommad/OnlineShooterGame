#pragma once
#include "SourceFiles/Renderer.h"
#include "SourceFiles/VertexBufferLayout.h"
#include "SourceFiles/VertexBuffer.h"
#include "SourceFiles/Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


class Background
{
private:
	float BCPositions[16]{
			 -50.0f,   -50.0f, 0.0f, 0.0f,	//0
			1920.0f,   -50.0f, 1.0f, 0.0f,	//1
			1920.0f,  1080.0f, 1.0f, 1.0f,	//2
			 -50.0f,  1080.0f, 0.0f, 1.0f	//3
	};
	std::string TextFold = "res/texture/MainImage.bmp";
	GLuint texture_;
	VertexArray vabc;
public:
	Background();
	~Background();

	void PrintBC(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer);
};
