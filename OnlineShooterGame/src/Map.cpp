#include "Map.h"

Map::Map()
{
	VertexBuffer vb1(positionsRL, 4 * 4 * sizeof(float));
	VertexBuffer vb2(positionsM1, 4 * 4 * sizeof(float));
	VertexBuffer vb3(positionsM2, 4 * 4 * sizeof(float));
	VertexBuffer vb4(positionsM3, 4 * 4 * sizeof(float));
	VertexBuffer vb5(positionsM4, 4 * 4 * sizeof(float));
	VertexBuffer vb6(positionsM5, 4 * 4 * sizeof(float));
	VertexBufferLayout layout1, layout2, layout3, layout4, layout5, layout6, layout7;

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

	va1.AddBuffer(vb1, layout1);
	va2.AddBuffer(vb1, layout2);
	va3.AddBuffer(vb2, layout3);
	va4.AddBuffer(vb3, layout4);
	va5.AddBuffer(vb4, layout5);
	va6.AddBuffer(vb5, layout6);
	va7.AddBuffer(vb6, layout7);
	texture_1 = Texture::textureIn("res/texture/TileR.bmp");
	texture_2 = Texture::textureIn("res/texture/TileL.bmp");
	texture_3 = Texture::textureIn("res/texture/Tile2.bmp");
	texture_4 = Texture::textureIn("res/texture/Tile1.bmp");
	texture_5 = Texture::textureIn("res/texture/Tile3.bmp");
	texture_6 = Texture::textureIn("res/texture/Tile4.bmp");
	texture_7 = Texture::textureIn("res/texture/Tile5.bmp");

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
}

void Map::PrintMP(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer)
{
	glm::vec3 translationR(1920, 0, 0);
	glm::vec3 translationL(0, 0, 0);
	glm::vec3 translation1(0, 0, 0);
	glm::vec3 translation2(300, 280, 0);
	glm::vec3 translation3(230, 590, 0);
	glm::vec3 translation4(600, 450, 0);
	glm::vec3 translation5(1017, 713, 0);
	glm::vec3 translation6(1550, 970, 0);
	glm::vec3 translation7(1550, 280, 0);
	glm::vec3 translation8(1750, 590, 0);
	glm::vec3 translation9(1200, 440, 0);
	glm::vec3 translation10(50, 750, 0);
	glm::vec3 translation11(370, 910, 0);
	glm::vec3 translation12(980, 483, 0);
	glm::vec3 translation13(630, 685, 0);
	glm::vec3 translation14(1000, 200, 0);

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

	Texture::Bind(texture_3);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation1);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va3, index, shader);
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

	Texture::Bind(texture_7);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation12);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va7, index, shader);
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
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation13);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va5, index, shader);
	}
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation14);
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
}