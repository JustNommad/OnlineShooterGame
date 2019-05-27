#include "Map.h"
#include <iostream>

Map::Map()
{
	ColisionMap();
	VertexBuffer vb1(positionsRL, 4 * 4 * sizeof(float));
	VertexBuffer vb2(positionsM1, 4 * 4 * sizeof(float));
	VertexBuffer vb3(positionsM2, 4 * 4 * sizeof(float));
	VertexBuffer vb4(positionsM3, 4 * 4 * sizeof(float));
	VertexBuffer vb5(positionsM4, 4 * 4 * sizeof(float));
	VertexBuffer vb6(positionsM5, 4 * 4 * sizeof(float));
	VertexBuffer vb7E(EnemyP, 4 * 4 * sizeof(float));
	VertexBufferLayout layout1, layout2, layout3, layout4, layout5, layout6, layout7, layout8E;

	layout1.Push<float>(2);
	layout1.Push<float>(2);
	layout2.Push<float>(2);
	layout2.Push<float>(2);
	layout3.Push<float>(2);
	layout3.Push<float>(2);
	layout4.Push<float>(2);
	layout4.Push<float>(2);
	layout5.Push<float>(2);
	layout5.Push<float>(2);
	layout6.Push<float>(2);
	layout6.Push<float>(2);
	layout7.Push<float>(2);
	layout7.Push<float>(2);
	layout8E.Push<float>(2);
	layout8E.Push<float>(2);

	va1.AddBuffer(vb1, layout1);
	va2.AddBuffer(vb1, layout2);
	va3.AddBuffer(vb2, layout3);
	va4.AddBuffer(vb3, layout4);
	va5.AddBuffer(vb4, layout5);
	va6.AddBuffer(vb5, layout6);
	va7.AddBuffer(vb6, layout7);
	va8E.AddBuffer(vb7E, layout8E);
	texture_1 = Texture::textureIn("res/texture/TileR.bmp");
	texture_2 = Texture::textureIn("res/texture/TileL.bmp");
	texture_3 = Texture::textureIn("res/texture/Tile2.bmp");
	texture_4 = Texture::textureIn("res/texture/Tile1.bmp");
	texture_5 = Texture::textureIn("res/texture/Tile3.bmp");
	texture_6 = Texture::textureIn("res/texture/Tile4.bmp");
	texture_7 = Texture::textureIn("res/texture/Tile5.bmp");
	texture_8E = Texture::textureIn("res/texture/Player2Right.png");
	texture_8E2 = Texture::textureIn("res/texture/Player2Left.png");

	va1.Unbind();
	vb1.Unbind();
	va2.Unbind();
	vb2.Unbind();
	va3.Unbind();
	va4.Unbind();
	vb3.Unbind();
	va5.Unbind();
	vb4.Unbind();
	va6.Unbind();
	vb5.Unbind();
	va7.Unbind();
	vb6.Unbind();
}

Map::~Map()
{
	glDeleteTextures(1, &texture_1);
	glDeleteTextures(1, &texture_2);
	glDeleteTextures(1, &texture_3);
	glDeleteTextures(1, &texture_4);
	glDeleteTextures(1, &texture_5);
	glDeleteTextures(1, &texture_6);
	glDeleteTextures(1, &texture_7);
	glDeleteTextures(1, &texture_8E);
	glDeleteTextures(1, &texture_8E2);
}

void Map::PrintMP(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer)
{
	glm::vec3 translationR(1920, 0, 0);
	glm::vec3 translationL(0, 0, 0);
	glm::vec3 translation1(0, 0, 0);
	glm::vec3 translation2(240, 260, 0);
	glm::vec3 translation3(240, 620, 0);
	glm::vec3 translation4(480, 420, 0);
	glm::vec3 translation5(840, 620, 0);
	glm::vec3 translation6(1560, 860, 0);
	glm::vec3 translation7(1560, 260, 0);
	glm::vec3 translation8(1680, 500, 0);
	glm::vec3 translation9(1080, 380, 0);
	glm::vec3 translation10(0, 740, 0);
	glm::vec3 translation11(360, 860, 0);
	glm::vec3 translation12(840, 460, 0);
	glm::vec3 translation14(960, 140, 0);

	Texture::Bind(texture_1);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translationR);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va1, index, shader);
	}

	Texture::Bind(texture_2);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translationL);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va2, index, shader);
	}

	Texture::Bind(texture_5);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation14);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va5, index, shader);
	}

	Texture::Bind(texture_3);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation1);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va3, index, shader);
	}

	Texture::Bind(texture_7);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation12);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va7, index, shader);
	}

	Texture::Bind(texture_4);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation2);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va4, index, shader);
	}
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation4);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va4, index, shader);
	}
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation6);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va4, index, shader);
	}
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation7);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va4, index, shader);
	}

	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation9);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va4, index, shader);
	}

	Texture::Bind(texture_4);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation5);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va4, index, shader);
	}

	Texture::Bind(texture_5);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation10);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va5, index, shader);
	}
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation3);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va5, index, shader);
	}
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation8);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va5, index, shader);
	}
	Texture::Bind(texture_6);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation11);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va6, index, shader);
	}
	if (server::Get_gamestate() && server::Get_y() > 0 && server::Get_y() > 0)
	{
		EnemyCheck();
		glm::vec3 Enemy(server::Get_dx(), server::Get_dy(), 0);

		if (server::Get_Left() == true && server::Get_Right() == false)
		{
			Texture::Bind(texture_8E2);
		}
		else if (server::Get_Right() == true && server::Get_Left() == false)
		{
			Texture::Bind(texture_8E);
		}
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), Enemy);
			glm::mat4 mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(va8E, index, shader);
		}
		this->Print(shader, proj, view, index, renderer);
	}
}

void Map::ColisionMap()
{
	system("cls");
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			std::cout << ColisMap[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::SetColPoint(int x, int y, int point)
{
	ColisMap[y][x] = point;
}

int Map::GetColPoint(int x, int y)
{
	return ColisMap[y][x];
}

void Map::EnemyCheck()
{
	SetColPoint(server::Get_x(), server::Get_y(), 4);
	if (GetColPoint(server::Get_x() - 1, server::Get_y()) == 4)
	{
		SetColPoint(server::Get_x() - 1, server::Get_y(), 0);
	}
	else if (GetColPoint(server::Get_x() + 1, server::Get_y()) == 4)
	{
		SetColPoint(server::Get_x() + 1, server::Get_y(), 0);
	}
	else if (GetColPoint(server::Get_x(), server::Get_y() - 1) == 4)
	{
		SetColPoint(server::Get_x(), server::Get_y() - 1, 0);
	}
	else if (GetColPoint(server::Get_x(), server::Get_y() + 1) == 4)
	{
		SetColPoint(server::Get_x(), server::Get_y() + 1, 0);
	}
	else if (GetColPoint(server::Get_x() - 1, server::Get_y() - 1) == 4)
	{
		SetColPoint(server::Get_x() - 1, server::Get_y() + 1, 0);
	}
	else if (GetColPoint(server::Get_x() + 1, server::Get_y() + 1) == 4)
	{
		SetColPoint(server::Get_x() + 1, server::Get_y() + 1, 0);
	}
	this->SetPlayerPosPic(server::Get_fdx(), server::Get_fdy());
}