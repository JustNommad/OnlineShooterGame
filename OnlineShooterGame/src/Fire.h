#pragma once
#include "SourceFiles/Renderer.h"
#include "SourceFiles/VertexBufferLayout.h"
#include "SourceFiles/VertexBuffer.h"
#include "SourceFiles/Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


class Fire
{
private:
	float positions[16]{
		  -10.0f, -10.0f, 0.0f, 0.0f,	//0
			1.0f, -10.0f, 1.0f, 0.0f,	//1
			1.0f,	1.0f, 1.0f, 1.0f,	//2
		  -10.0f,	1.0f, 0.0f, 1.0f	//3
	};
	std::string TextFold = "res/texture/Bullet.png";
	GLuint texture_;
	VertexArray va;
	int x_, y_;
	int dx_, dy_;
	int Xf_, Yf_;
	int Xdf_, Ydf_;
	int damage;
public:
	Fire();
	~Fire();

	void Print(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer);
	void SetPlayerPos(int x, int y);
	int GetXF();
	int GetYF();
	int GetdXF();
	int GetdYF();
	void SetPlayerPosPic(int x, int y);
	int Hit();
};
