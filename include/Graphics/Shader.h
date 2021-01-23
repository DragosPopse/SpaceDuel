#pragma once

#include <cstdint>
#include <GL/glew.h>
#include <vector>



class Shader
{
public:
	uint32_t m_program = 0;
	std::vector<GLuint> m_shaders;

public:
	bool loadFromFile(GLenum type, const char* filename);
	bool link();
};