#include "Player1.h"


Player1::Player1()
{
	dx_ = 120;
	dy_ = 140;
	x_ = 1;
	y_ = 7;
	VertexBuffer vb(positions, 4 * 4 * sizeof(float));
	VertexBufferLayout layout;

	layout.Push<float>(2);
	layout.Push<float>(2);
	vabc.AddBuffer(vb, layout);

	texture_ = Texture::textureIn(TextFold);

	vabc.Unbind();
	vb.Unbind();
}

Player1::~Player1()
{
	glDeleteTextures(1, &texture_);
}

void Player1::PrintBC(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer)
{
	glm::vec3 translationA(dx_, dy_, 0);
	Texture::Bind(texture_);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(vabc, index, shader);
	}
}

void Player1::MCheck(int key, Map& map)
{
	map.SetColPoint(x_, y_, 2);
	int check = map.GetColPoint(x_, y_ + 1);
	if (check != 1)
	{
		y_ = y_ + 1;
		dy_ = dy_ - 120;
		map.SetColPoint(x_, y_ - 1, 0);
		Sleep(50);
	}
	if (check == 1)
	{
		checkPush = 0;
	}
	switch (key)
	{
	/*case 1:
	{
		dy_ = dy_ - 7;
		break;
	}*/
	case 3:
	{
		if (checkPush == 0)
		{
			for (int i = 1; i <= 2; i++)
			{
				Sleep(50);
				int check = map.GetColPoint(x_, y_ - 1);
				if (check != 1)
				{
					y_ = y_ - 1;
					dy_ = dy_ + 120;
					map.SetColPoint(x_, y_ + 1, 0);
					checkPush = 1;
				}
			}
		}
		break;
	}
	case 2:
	{
		int check = map.GetColPoint(x_ - 1, y_);
		if (check != 1)
		{
			x_ = x_ - 1;
			dx_ = dx_ - 120;
			map.SetColPoint(x_ + 1, y_, 0);
			Sleep(50);
		}
		break;
	}
	case 4:
	{
		int check = map.GetColPoint(x_ + 1, y_);
		if (check != 1)
		{
			x_ = x_ + 1;
			dx_ = dx_ + 120;
			map.SetColPoint(x_ - 1, y_, 0);
			Sleep(50);
		}
		break;
	}
	}
}
