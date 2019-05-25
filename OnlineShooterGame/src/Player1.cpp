#include "Player1.h"

server::PlayerData Player;

Player1::Player1(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer)
{
	playShad = &shader;
	p = proj;
	v = view;
	ind = &index;
	rend = &renderer;

	health = Player.health = 100;
	dx_ = Player.Pic_x = 120;
	dy_ = Player.Pic_y = 140;
	x_ = Player.Col_x = 1;
	y_ = Player.Col_y = 11;
	Player.gamestate = true;
	Player.right_c = false;
	Player.left_c = true;

	if (server::ClientS())
	{
		system("pause");
	}

	trans = glm::mat4(1.0f);
	trans = glm::rotate(trans, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	result = trans * glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);

	VertexBuffer vb(positions, 4 * 4 * sizeof(float));
	VertexBufferLayout layout;

	layout.Push<float>(2);
	layout.Push<float>(2);
	vabc.AddBuffer(vb, layout);

	texture_1 = Texture::textureIn("res/texture/Marine1.png");
	texture_2 = Texture::textureIn("res/texture/Marine1Left.png");

	vabc.Unbind();
	vb.Unbind();
}

Player1::~Player1()
{
	glDeleteTextures(1, &texture_1);
	glDeleteTextures(1, &texture_2);
}

void Player1::PrintBC()
{
	if (gamestat == true)
	{
		server::SendingPos(P_PlayerData, Player);
		glm::vec3 translationA(dx_, dy_, 0);
		if (LEFT_c == true && RIGHT_c == false)
		{
			Texture::Bind(texture_2);
			{
				glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
				glm::mat4 mvp = p * v * model;
				playShad->SetUniformMat4f("u_MVP", mvp);
				rend->Draw(vabc, *ind, *playShad);
			}
		}
		else if (LEFT_c == false && RIGHT_c == true)
		{
			Texture::Bind(texture_1);
			{
				glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
				glm::mat4 mvp = p * v * model;
				playShad->SetUniformMat4f("u_MVP", mvp);
				rend->Draw(vabc, *ind, *playShad);
			}
		}
	}
	CheckPlayerGameStat();
}

void Player1::MCheck(Map& map, GLFWwindow& window)
{
	if (gamestat == true)
	{
		map.SetColPoint(x_, y_, 0);
		int check;
		check = map.GetColPoint(x_, y_ + 1);
		if (check != 1 && checkPush == 2)
		{
			map.SetColPoint(x_, y_, 0);
			dy_ = dy_ - 28;
			Player.Pic_y = dy_;
			Down_count++;
			if (Down_count == 3)
			{
				y_ = y_ + 1;
				Player.Col_y = y_;
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
			LEFT_c = Player.left_c = true;
			RIGHT_c = Player.right_c = false;
			int check = map.GetColPoint(x_ - 1, y_);
			if (check != 1)
			{
				dx_ = dx_ - 40;
				Player.Pic_x = dx_;
				Left_count++;
				if (Left_count == 3)
				{
					x_ = x_ - 1;
					Player.Col_x = x_;
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
			RIGHT_c = Player.right_c = true;
			LEFT_c = Player.left_c = false;
			int check = map.GetColPoint(x_ + 1, y_);
			if (check != 1)
			{
				dx_ = dx_ + 40;
				Player.Pic_x = dx_;
				Right_count++;
				if (Right_count == 3)
				{
					x_ = x_ + 1;
					Player.Col_x = x_;
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
				Player.Col_y = y_;
			}
		}
		if (checkPush == 1)
		{
			int check = map.GetColPoint(x_, y_ - 1);
			if (check != 1)
			{
				dy_ = dy_ + 28;
				Player.Pic_y = dy_;
				Up_count = Up_count + 1;
				if (Up_count == 5 || Up_count == 8)
				{
					y_ = y_ - 1;
					Player.Col_y = y_;
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
				Player.Pic_y = dy_;
				Up_count = 0;
				checkPush = 2;
			}
			else if (map.GetColPoint(x_, y_ - 1) == 1 && map.GetColPoint(x_, y_ + 1) == 0 && Up_count < 5)
			{
				dy_ = dy_ + 84;
				Player.Pic_y = dy_;
				Up_count = 0;
				checkPush = 2;
			}
			else
			{
				Up_count = 0;
				checkPush = 2;
			}
		}
		if (checkShoot == true)
		{
			if (OneMove == 1)
			{
				ShootLeft(map);
			}
			else if (OneMove == 2)
			{
				ShootRight(map);
			}
		}
		if (glfwGetKey(&window, GLFW_KEY_SPACE) && checkShoot == false)
		{
			if (LEFT_c == true && RIGHT_c == false)
			{
				OneMove = 1;
				ShootLeft(map);
			}
			else if (LEFT_c == false && RIGHT_c == true)
			{
				OneMove = 2;
				ShootRight(map);
			}
			checkShoot = true;
		}
		map.SetColPoint(x_, y_, 2);
	}
}

void Player1::ShootLeft(Map& map)
{
	if (checkShoot == false)
	{
		this->SetPlayerPos(x_ - 1, y_);
		Player.Fire_x = x_ - 1;
		Player.Fire_y = y_;
		this->SetPlayerPosPic(dx_ - 80, dy_ - 17);
		Player.FirePic_x = dx_ - 80;
		Player.FirePic_y = dy_ - 17;
	}

	if (map.GetColPoint(x_ - 1, y_) != 1)
	{
		map.SetColPoint(GetXF(), GetYF(), 0);
	}

	Shoot_count = Shoot_count + 1;
	if (Shoot_count == 3)
	{
		this->SetPlayerPos(GetXF() - 1, GetYF());
		Player.Fire_x = GetXF() - 1;
		Player.Fire_y = GetYF();
		Shoot_count = 0;
	}

	if (map.GetColPoint(GetXF(), GetYF()) == 1)
	{
		map.SetColPoint(GetXF(), GetYF(), 1);
		this->SetPlayerPos(x_ - 1, y_);
		Player.Fire_x = x_ - 1;
		Player.Fire_y = y_;
		this->SetPlayerPosPic(dx_ - 80, dy_ - 17);
		Player.FirePic_x = dx_ - 80;
		Player.FirePic_y = dy_ - 17;
		checkShoot = false;
		OneMove = 0;
	}
	else
	{
		this->SetPlayerPosPic(GetdXF() - 40, GetdYF());
		Player.FirePic_x = GetdXF() - 40;
		Player.FirePic_y = GetdYF();
		this->Print(*playShad, p, v, *ind, *rend);
		map.SetColPoint(GetXF(), GetYF(), 3);
	}
}

void Player1::ShootRight(Map& map)
{
	if (checkShoot == false)
	{
		this->SetPlayerPos(x_ + 1, y_);
		Player.Fire_x = x_ + 1;
		Player.Fire_y = y_;
		this->SetPlayerPosPic(dx_ + 80, dy_ - 17);
		Player.FirePic_x = dx_ + 80;
		Player.FirePic_y = dy_ - 17;
	}

	if (map.GetColPoint(x_ + 1, y_) != 1)
	{
		map.SetColPoint(GetXF(), GetYF(), 0);
	}

	Shoot_count = Shoot_count + 1;
	if (Shoot_count == 3)
	{
		this->SetPlayerPos(GetXF() + 1, GetYF());
		Player.Fire_x = GetXF() + 1;
		Player.Fire_y = GetYF();
		Shoot_count = 0;
	}

	if (map.GetColPoint(GetXF(), GetYF()) == 1 || map.GetColPoint(GetXF(), GetYF()) == 4)
	{
		map.SetColPoint(GetXF(), GetYF(), 1);
		this->SetPlayerPos(x_ + 1, y_);
		Player.Fire_x = x_ + 1;
		Player.Fire_y = y_;
		this->SetPlayerPosPic(dx_ + 80, dy_ - 17);
		Player.FirePic_x = dx_ + 80;
		Player.FirePic_y = dy_ - 17;
		checkShoot = false;
		OneMove = 0;
	}
	else
	{
		this->SetPlayerPosPic(GetdXF() + 40, GetdYF());
		Player.FirePic_x = GetdXF() + 40;
		Player.FirePic_y = GetdYF();
		this->Print(*playShad, p, v, *ind, *rend);
		map.SetColPoint(GetXF(), GetYF(), 3);
	}
}

void Player1::CheckPlayerGameStat()
{
	if (server::Get_fx() == x_ && server::Get_fy() == y_)
	{
		if (health > 0)
		{
			health = Player.health = health - this->Hit();
		}
		else if (health == 0)
		{
			gamestat = Player.gamestate = false;
			gamestatCounter = 0;
		}
	}
	if (gamestat == false)
	{
		if (gamestatCounter == 5)
		{
			gamestat = Player.gamestate = true;
		}
		Sleep(1000);
		gamestatCounter++;
	}
}
