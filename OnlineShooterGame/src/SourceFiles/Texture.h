#pragma once
#include "Renderer.h"

class Texture
{
public:
	static GLuint textureIn(const std::string& path);
	static void Bind(GLuint rendererID, unsigned int slot = 0);
	void Unbind() const;
};