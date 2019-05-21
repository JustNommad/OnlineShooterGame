#pragma once
#include "SourceFiles/Renderer.h"
#include "SourceFiles/VertexBufferLayout.h"
#include "SourceFiles/VertexBuffer.h"
#include "SourceFiles/Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Map.h"
#include "Fire.h"
#include "HUD.h"
#include "ClientS.h"

#include <GLFW/glfw3.h>


class Player1 : public Fire, public HUD
{
private:
	float positions[16]{
	 -65.0f,  -65.0f, 0.0f, 0.0f,	//0
	  65.0f,  -65.0f, 1.0f, 0.0f,	//1
	  65.0f,   65.0f, 1.0f, 1.0f,	//2
	 -65.0f,   65.0f, 0.0f, 1.0f,	//3
	};
	GLuint texture_1, texture_2;
	VertexArray vabc;
	Shader* playShad;
	glm::mat4 p, v;
	IndexBuffer* ind;
	Renderer* rend;
	glm::mat4 trans;
	glm::vec4 result;
	int health;
	int dx_, dy_;
	int x_, y_;
	bool UP_c = false, DOWN_c = false, LEFT_c = true, RIGHT_c = false;
	bool checkShoot = false;
	bool gamestat = true;
	int checkPush = 0;
	int Up_count = 0, Down_count = 0, Right_count = 0, Left_count = 0, Shoot_count = 0;
public:
	Player1(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer);
	~Player1();

	void MCheck(Map& map, GLFWwindow& window);
	void PrintBC();
	void ShootLeft(Map& map);
	void ShootRight(Map& map);
};
