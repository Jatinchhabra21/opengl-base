#pragma once

#include<string>
#include<glm/glm.hpp>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RenderedId;

public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	// Set uniforms
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1f(const std::string& name, float f1);
	void SetUniform2f(const std::string& name, float v0, float v1);
	void SetUniformMat4f(const std::string& name, glm::mat4 matrix);

private:
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& location);
};