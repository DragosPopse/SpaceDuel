#include "Graphics/Image.h"
#include <stb_image.h>
#include <iostream>


bool Image::loadFromFile(const char* filename)
{
	m_image = stbi_load(filename, &m_width, &m_height, &m_channels, 0);
	if (!m_image)
	{
		fprintf(stderr, "Couldn't load %s\n", filename);
		return false;
	}
	return true;
}


int32_t Image::width() const
{
	return m_width;
}


int32_t Image::height() const
{
	return m_height;
}


int32_t Image::channels() const
{
	return m_channels;
}
