#include "Background.h"

Background::Background()
{
	VertexBuffer vbc(BCPositions, 4 * 4 * sizeof(float));
	VertexBufferLayout BClayout;

	BClayout.Push<float>(2);
	BClayout.Push<float>(2);
	vabc.AddBuffer(vbc, BClayout);
	texture_ = Texture::textureIn(TextFold);

	vabc.Unbind();
	vbc.Unbind();
}

Background::~Background()
{
	glDeleteTextures(1, &texture_);
}

void Background::PrintBC(Shader& shader, glm::mat4 proj, glm::mat4 view, IndexBuffer& index, Renderer& renderer)
{
	glm::vec3 translationBC(0, 0, 0);
	Texture::Bind(texture_);
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translationBC);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(vabc, index, shader);
	}
}