#include  "Texture.h"
#include  "stb_image.h"
#include <iostream>

Texture::Texture()
{
	m_RenderedID = 0;
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_RenderedID);
}

void Texture::Bind(const std::string& path, unsigned int slot)
{
	stbi_set_flip_vertically_on_load(1);

	int m_Width, m_Height, m_BPP;
	unsigned char* m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

	if (m_LocalBuffer == 0) { cout << "Error: couldn't load texture. m_LocalBuffer is empty. Check if path is correct/Correct image format!" << endl; }

	glGenTextures(1, &m_RenderedID);

	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_RenderedID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);

	if (m_LocalBuffer) { stbi_image_free(m_LocalBuffer); }
}

void Texture::Unbind(unsigned int slot)
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, 0);
}