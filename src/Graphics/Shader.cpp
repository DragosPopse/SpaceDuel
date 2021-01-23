#include "Graphics/Shader.h"
#include <fstream>
#include "Const.h"

bool Shader::loadFromFile(GLenum type, const char* filename)
{
	std::ifstream file(filename, std::ios::ate);

	if (!file.is_open())
	{
		fprintf(stderr, "Couldn't load shader: %s\n", filename);
		return false;
	}

	size_t size = (size_t)file.tellg();
	std::vector<char> shaderSource(size);
	file.seekg(0);
	file.read(shaderSource.data(), size);

	auto shader = glCreateShader(type);
	
	auto* data = shaderSource.data();
	
	glShaderSource(shader, 1, &data, nullptr);
	glCompileShader(shader);

	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char log[OPENGL_LOGBUFFER_SIZE];
		glGetShaderInfoLog(shader, OPENGL_LOGBUFFER_SIZE, nullptr, log);
		fprintf(stderr, "%s\n", log);
		return false;
	}

	m_shaders.push_back(shader);
	return true;
}


bool Shader::link()
{
	m_program = glCreateProgram();
	for (auto shader : m_shaders)
	{
		glAttachShader(m_program, shader);
	}
	glLinkProgram(m_program);

	for (auto shader : m_shaders)
	{
		glDeleteShader(shader);
	}

	GLint success;
	glGetProgramiv(m_program, GL_LINK_STATUS, &success);
	if (success)
	{
		char log[OPENGL_LOGBUFFER_SIZE];
		glGetProgramInfoLog(m_program, OPENGL_LOGBUFFER_SIZE, nullptr, log);

		return false;
	}
	return true;
}