#pragma once

#include "Render.h"

class Texture
{
private:
	unsigned int m_RenderedID;

public:
	Texture();
	~Texture();

	/*Binds Texture to specific slot*/
	void Bind(const std::string& path, unsigned int slot);
	void Unbind(unsigned int slot);
};