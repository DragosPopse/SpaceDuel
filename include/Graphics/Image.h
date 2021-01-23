#pragma once

#include <cstdint>

class Image
{
	uint8_t* m_image = nullptr;
	int32_t m_width = 0;
	int32_t m_height = 0;
	int32_t m_channels = 0;

public:
	bool loadFromFile(const char* filename);

	int32_t width() const;
	int32_t height() const;
	int32_t channels() const;
};