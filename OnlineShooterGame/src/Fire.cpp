#include "Fire.h"

Fire::Fire()
{
	x_ = y_ = Xf_ = Yf_ = 0;
	damage = 20;
	VertexBuffer vb(positions, 4 * 4 * sizeof(float));
	VertexBufferLayout layout;

	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);
	texture_ = Texture::textureIn(TextFold);

	va.Unbind();
	vb.Unbind();
}

Fire::~Fire()
{
	glDeleteTextures(1, &texture_);
} 

void Fire::Print(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer)
{
	glm::vec3 translationF(dx_, dy_, 0);
	Texture::Bind(texture_);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translationF);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(va, index, shader);
	}
}

void Fire::SetPlayerPos(int x, int y)
{
	x_ = x;
	y_ = y;
}

void Fire::SetPlayerPosPic(int x, int y)
{
	dx_ = x;
	dy_ = y;
}

int Fire::GetXF()
{
	return x_;
}

int Fire::GetYF()
{
	return y_;
}

int Fire::GetdXF()
{
	return dx_;
}

int Fire::GetdYF()
{
	return dy_;
}

int Fire::Hit()
{
	return damage;
}