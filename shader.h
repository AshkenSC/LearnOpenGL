#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>; // include glad.h to get necessary OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
public:
	// program ID
	unsigned int ID;

	// constructor load and build shader
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	// use/activate program
	void use();
	// uniform tool functions
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;

	Shader(const char* vertexPath, const char* fragmentPath)
	{
		/* 1. retrieve vertex/fragment shader from file path */
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		// make sure ifstream object can throw fault
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			// open file
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			// load buffer of files to data stream
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// close file processor
			vShaderFile.close();
			fShaderFile.close();
			// transfer data stream to string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		/* 2. compile shaders */
		unsigned int vertex, fragment;
		// vertex shader
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		checkCompileErrors(vertex, "VERTEX");
		// fragment Shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		checkCompileErrors(fragment, "FRAGMENT");
};

#endif

