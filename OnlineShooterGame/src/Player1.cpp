#include "Player1.h"


Player1::Player1()
{
	dx_ = 120;
	dy_ = 140;
	x_ = 1;
	y_ = 11;
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

void Player1::MCheck(Map& map, GLFWwindow& window)
{
	map.SetColPoint(x_, y_, 0);
	int check;
	check = map.GetColPoint(x_, y_ + 1);
	if (check != 1 && checkPush == 2)
	{
		map.SetColPoint(x_, y_, 0);
		dy_ = dy_ - 28;
		Down_count++;
		if (Down_count == 3)
		{
			y_ = y_ + 1;
			Down_count = 0;
		}
	}
	else if (check == 1)
	{
		checkPush = 0;
	}
	/*if (glfwGetKey(&window, GLFW_KEY_UP) && glfwGetKey(&window, GLFW_KEY_RIGHT))
	{
		if (checkPush == 1)
		{
			for (int i = 1; i <= 3; i++)
			{
				int check = map.GetColPoint((int)x_, (int)y_ - 1);
				if (check != 1)
				{
					y_ = y_ - 0.1;
					dy_ = dy_ + 10;
				}
			}
			int check = map.GetColPoint((int)x_ + 1, (int)y_);
			if (check != 1)
			{
				x_ = x_ + 0.1;
				dx_ = dx_ + 12;
			}
		}
	}*/
	/*if (glfwGetKey(&window, GLFW_KEY_UP) && glfwGetKey(&window, GLFW_KEY_LEFT))
	{
		if (checkPush == 1)
		{
			for (int i = 1; i <= 3; i++)
			{
				int check = map.GetColPoint((int)x_ + 1, (int)y_ - 1);
				if (check != 1)
				{
					y_ = y_ - 0.1;
					dy_ = dy_ + 10;
				}
			}
			int check = map.GetColPoint((int)x_ - 1, (int)y_);
			if (check != 1)
			{
				x_ = x_ - 0.1;
				dx_ = dx_ - 12;
			}
		}
	}*/
	if (glfwGetKey(&window, GLFW_KEY_LEFT))
	{
		int check = map.GetColPoint(x_ - 1, y_);
		if (check != 1)
		{
			dx_ = dx_ - 40;
			Left_count++;
			if (Left_count == 3)
			{
				x_ = x_ - 1;
				Left_count = 0;
				if (Up_count > 0)
				{
					Up_count = 0;
					checkPush = 2;
					//dy_ = dy_ + 28;
				}
			}
		}
		if (map.GetColPoint(x_ + 1, y_ + 1) == 1 && map.GetColPoint(x_, y_ + 1) != 1)
		{
			checkPush = 2;
		}
	}
	if (glfwGetKey(&window, GLFW_KEY_RIGHT))
	{
		int check = map.GetColPoint(x_ + 1, y_);
		if (check != 1)
		{
			dx_ = dx_ + 40;
			Right_count++;
			if (Right_count == 3)
			{
				x_ = x_ + 1; 
				Right_count = 0;
				if (Up_count > 0)
				{
					checkPush = 2;
					Up_count = 0;
					//dy_ = dy_ + 28;
				}
			}
		}
		if (map.GetColPoint(x_ - 1, y_ + 1) == 1 && map.GetColPoint(x_, y_ + 1) != 1)
		{
			checkPush = 2;
		}
	}
	if (glfwGetKey(&window, GLFW_KEY_UP) && checkPush == 0)
	{
		checkPush = 1;
		int check = map.GetColPoint(x_, y_ - 1);
		if (check != 1)
		{
			y_ = y_ - 1;
		}
	}
	if (checkPush == 1)
	{
		int check = map.GetColPoint(x_, y_ - 1);
		if (check != 1)
		{
			dy_ = dy_ + 28;
			Up_count = Up_count + 1;
			if (Up_count == 5 || Up_count == 8)
			{
				y_ = y_ - 1;
			}
			else if (Up_count == 9)
			{
				Up_count = 0;
				checkPush = 2;
			}
		}
		else if (map.GetColPoint(x_, y_ - 1) == 1 && map.GetColPoint(x_, y_ + 1) == 0 && Up_count >= 5)
		{
			dy_ = dy_ + 28;
			Up_count = 0;
			checkPush = 2;
		}
		else if (map.GetColPoint(x_, y_ - 1) == 1 && map.GetColPoint(x_, y_ + 1) == 0 && Up_count < 5)
		{
			dy_ = dy_ + 84;
			Up_count = 0;
			checkPush = 2;
		}
		else 
		{
			Up_count = 0;
			checkPush = 2;
		}
	}
	map.SetColPoint(x_, y_, 2);
}


