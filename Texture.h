#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include<glad/glad.h>
#include<stb/stb_image.h>

#include"shaderClass.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	// Assigns a texture unit to a texture
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	// Binds a texture
	void Bind();
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();
};

class CubeTextureCoordsSet {
public:
	int Xoffset = 0;
	int Yoffset = 0;
	GLfloat MaxY = 0.1f;
	GLfloat maxX = 0.1f;
	GLfloat minY = 0.0625;
	GLfloat minX = 0;



	void UpdateValues() 
	{
			minY = 0.0625* Yoffset;
			minX = 0.0625* Xoffset;
			maxX = minX+0.0625;
			MaxY = minY+0.0625;


	

	};
};

#endif