#pragma once
#include "SourceFiles/Renderer.h"
#include "SourceFiles/VertexBufferLayout.h"
#include "SourceFiles/VertexBuffer.h"
#include "SourceFiles/Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


class HUD
{
private:
	float positions[16]{
		-10.0f, -10.0f, 0.0f, 0.0f,	//0
		400.0f, -10.0f, 1.0f, 0.0f,	//1
		400.0f,  20.0f, 1.0f, 1.0f,	//2
	    -10.0f,  20.0f, 0.0f, 1.0f	//3
	};
	int HP;
	GLuint texture_1, texture_2, texture_3, texture_4, texture_5, texture_6;
	VertexArray va;
public:
	HUD();
	~HUD();

	void PrintHUD(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer);
	void HealthStat(int health);
};
