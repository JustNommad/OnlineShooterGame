#include "HUD.h"

HUD::HUD()
{
	HP = 100;
	VertexBuffer vb(positions, 4 * 4 * sizeof(float));
	VertexBufferLayout layout;

	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);
	texture_1 = Texture::textureIn("res/texture/HUD1.png");
	texture_2 = Texture::textureIn("res/texture/HUD2.png");
	texture_3 = Texture::textureIn("res/texture/HUD3.png");
	texture_4 = Texture::textureIn("res/texture/HUD4.png");
	texture_5 = Texture::textureIn("res/texture/HUD5.png");
	texture_6 = Texture::textureIn("res/texture/HUD6.png");

	va.Unbind();
	vb.Unbind();
}

HUD::~HUD()
{
	glDeleteTextures(1, &texture_1);
	glDeleteTextures(1, &texture_2);
	glDeleteTextures(1, &texture_3);
	glDeleteTextures(1, &texture_4);
	glDeleteTextures(1, &texture_5);
	glDeleteTextures(1, &texture_6);
}

void HUD::PrintHUD(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer)
{
	glm::vec3 translationH(80, 1030, 0);
	if (HP >= 81)
	{
		Texture::Bind(texture_1);
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationH);
			glm::mat4 mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(va, index, shader);
		}
	}
	else if (HP >= 61 && HP <= 80)
	{
		Texture::Bind(texture_2);
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationH);
			glm::mat4 mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(va, index, shader);
		}
	}
	else if (HP >= 41 && HP <= 60)
	{
		Texture::Bind(texture_3);
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationH);
			glm::mat4 mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(va, index, shader);
		}
	}
	else if (HP >= 21 && HP <= 40)
	{
		Texture::Bind(texture_4);
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationH);
			glm::mat4 mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(va, index, shader);
		}
	}
	else if (HP <= 20 && HP > 0)
	{
		Texture::Bind(texture_5);
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationH);
			glm::mat4 mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(va, index, shader);
		}
	}
	else if (HP <= 0)
	{
		Texture::Bind(texture_6);
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationH);
			glm::mat4 mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(va, index, shader);
		}
	}
}

void HUD::HealthStat(int health)
{
	HP = health;
}
