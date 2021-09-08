//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"
#include"chunks.h"
#include <memory>
#include "blocks.h"

const unsigned int width = 800;
const unsigned int height = 800;








// Indices for vertices order
GLuint indices[25000000];
GLfloat vertices[100000000];






void GenerateCube(int CubeOffset, int X, int Y,int Z, CubeTextureCoords InputTextureData) {
	X *= 2;
	Y *= 2;
	Z *= 2;
	CubeTextureCoordsSet TOP, FRONT, BOTTON, BACK, LEFT, RIGHT;
	TOP.Xoffset = InputTextureData.TOP.Xoffset;
	TOP.Yoffset = InputTextureData.TOP.Yoffset;
	TOP.UpdateValues();

	FRONT.Xoffset = InputTextureData.FRONT.Xoffset;
	FRONT.Yoffset = InputTextureData.FRONT.Yoffset;
	FRONT.UpdateValues();

	BOTTON.Xoffset = InputTextureData.BOTTON.Xoffset;
	BOTTON.Yoffset = InputTextureData.BOTTON.Yoffset;
	BOTTON.UpdateValues();

	BACK.Xoffset = InputTextureData.BACK.Xoffset;
	BACK.Yoffset = InputTextureData.BACK.Yoffset;
	BACK.UpdateValues();

	LEFT.Xoffset = InputTextureData.LEFT.Xoffset;
	LEFT.Yoffset = InputTextureData.LEFT.Yoffset;
	LEFT.UpdateValues();

	RIGHT.Xoffset = InputTextureData.TOP.Xoffset;
	RIGHT.Yoffset = InputTextureData.TOP.Yoffset;
	RIGHT.UpdateValues();




	int offset = CubeOffset*192;
	vertices[offset + 0] = 1.0f+X; vertices[offset + 1] = 1.0f+Y; vertices[offset + 2] = 1.0f+Z; //coordinates  
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS	      //
	vertices[offset + 6] = TOP.maxX; vertices[offset + 7] = TOP.minY; //tex coords						  //
	offset += 8;																						  //
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordina// T
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		  // O
	vertices[offset + 6] = TOP.minX; vertices[offset + 7] = TOP.minY; //tex coords						  // P
	offset += 8;																						  //
	vertices[offset + 0] = 1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates //
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		  //
	vertices[offset + 6] = TOP.maxX; vertices[offset + 7] = TOP.MaxY; //tex coords						  //
	offset += 8;																					      //
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates//
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		  //
	vertices[offset + 6] = TOP.minX; vertices[offset + 7] = TOP.MaxY; //tex coords						  //

	offset += 8;
	vertices[offset + 0] = 1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates    
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS	          //
	vertices[offset + 6] = FRONT.minX; vertices[offset + 7] = FRONT.MaxY; //tex coords						  //
	offset += 8;																						      // F
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates// R
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		      // O
	vertices[offset + 6] = FRONT.maxX; vertices[offset + 7] = FRONT.MaxY; //tex coords						  // N
	offset += 8;																						      // T
	vertices[offset + 0] = 1.0f + X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates   
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		      //
	vertices[offset + 6] = FRONT.minX; vertices[offset + 7] = FRONT.minY; //tex coords						  //
	offset += 8;																					          //
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates   //
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		      //
	vertices[offset + 6] = FRONT.maxX; vertices[offset + 7] = FRONT.minY; //tex coords						  //

	offset += 8;
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordinates   
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS	          //
	vertices[offset + 6] = BOTTON.minX; vertices[offset + 7] = BOTTON.MaxY; //tex coords				      //
	offset += 8;																						      // B
	vertices[offset + 0] = 1.0f + X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordinates // O
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		      // T
	vertices[offset + 6] = BOTTON.maxX; vertices[offset + 7] = BOTTON.MaxY; //tex coords					  // T
	offset += 8;																						      // O
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinate// M
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		      //
	vertices[offset + 6] = BOTTON.minX; vertices[offset + 7] = BOTTON.minY; //tex coords				      //
	offset += 8;																					          //
	vertices[offset + 0] = 1.0f+X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates   
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		      //
	vertices[offset + 6] = BOTTON.maxX; vertices[offset + 7] = BOTTON.minY; //tex coords				      //

	offset += 8;
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordinates  //
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS	           //
	vertices[offset + 6] = BACK.minX; vertices[offset + 7] = BACK.MaxY; //tex coords				           //
	offset += 8;																						       // B
	vertices[offset + 0] = 1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordinates   // a
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		       // c
	vertices[offset + 6] = BACK.maxX; vertices[offset + 7] = BACK.MaxY; //tex coords					       // k
	offset += 8;																						       // 
	vertices[offset + 0] = -1.0f+ X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordinates     
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		       //
	vertices[offset + 6] = BACK.minX; vertices[offset + 7] = BACK.minY; //tex coords				           //
	offset += 8;																					           //
	vertices[offset + 0] = 1.0f+ X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordinates      
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		       //
	vertices[offset + 6] = BACK.maxX; vertices[offset + 7] = BACK.minY; //tex coords				           //

	offset += 8;
	vertices[offset + 0] = 1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordinates      
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS	           //
	vertices[offset + 6] = LEFT.minX; vertices[offset + 7] = LEFT.MaxY; //tex coords				           //
	offset += 8;																						       // L
	vertices[offset + 0] = 1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates  // E
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		       // F
	vertices[offset + 6] = LEFT.maxX; vertices[offset + 7] = LEFT.MaxY; //tex coords					       // T
	offset += 8;																						       // 
	vertices[offset + 0] = 1.0f + X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordinates  // 
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		       //
	vertices[offset + 6] = LEFT.minX; vertices[offset + 7] = LEFT.minY; //tex coords				           //
	offset += 8;																					           //
	vertices[offset + 0] = 1.0f + X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates //
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		       //
	vertices[offset + 6] = LEFT.maxX; vertices[offset + 7] = LEFT.minY; //tex coords				           //

	offset += 8;
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates     
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS	           //
	vertices[offset + 6] = RIGHT.minX; vertices[offset + 7] = RIGHT.MaxY; //tex coords				           //
	offset += 8;																						       // r
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = 1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordinates  // i
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		       // g
	vertices[offset + 6] = RIGHT.maxX; vertices[offset + 7] = RIGHT.MaxY; //tex coords					       // h
	offset += 8;																						       // t
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = -1.0f + Z; //coordinates// 
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		       //
	vertices[offset + 6] = RIGHT.minX; vertices[offset + 7] = RIGHT.minY; //tex coords				           //
	offset += 8;																					           //
	vertices[offset + 0] = -1.0f + X; vertices[offset + 1] = -1.0f + Y; vertices[offset + 2] = 1.0f + Z; //coordinates //
	vertices[offset + 3] = 0.0f; vertices[offset + 4] = 0.0f; vertices[offset + 5] = 0.0f; //COLORS		       //
	vertices[offset + 6] = RIGHT.maxX; vertices[offset + 7] = RIGHT.minY; //tex coords				           //

	int indicesOffset = CubeOffset * 36;
	int verticeNumberOffset = CubeOffset * 24;
	indices[0 + indicesOffset] = 0+ verticeNumberOffset;
	indices[1 + indicesOffset] = 2 + verticeNumberOffset;
	indices[2 + indicesOffset] = 3 + verticeNumberOffset; //top face
	indices[3 + indicesOffset] = 3 + verticeNumberOffset;
	indices[4 + indicesOffset] = 1 + verticeNumberOffset;
	indices[5 + indicesOffset] = 0 + verticeNumberOffset;

	indices[6 + indicesOffset] = 4 + verticeNumberOffset;
	indices[7 + indicesOffset] = 6 + verticeNumberOffset;
	indices[8 + indicesOffset] = 7 + verticeNumberOffset; //back face
	indices[9 + indicesOffset] = 7 + verticeNumberOffset;
	indices[10 + indicesOffset] = 5 + verticeNumberOffset;
	indices[11 + indicesOffset] = 4 + verticeNumberOffset;


	indices[12 + indicesOffset] = 8 + verticeNumberOffset;
	indices[13 + indicesOffset] = 10 + verticeNumberOffset;
	indices[14 + indicesOffset] = 11 + verticeNumberOffset; //bottom face 
	indices[15 + indicesOffset] = 11 + verticeNumberOffset;
	indices[16 + indicesOffset] = 9 + verticeNumberOffset;
	indices[17 + indicesOffset] = 8 + verticeNumberOffset;

	indices[18 + indicesOffset] = 12 + verticeNumberOffset;
	indices[19 + indicesOffset] = 14 + verticeNumberOffset;
	indices[20 + indicesOffset] = 15 + verticeNumberOffset; //front face  
	indices[21 + indicesOffset] = 15 + verticeNumberOffset;
	indices[22 + indicesOffset] = 13 + verticeNumberOffset;
	indices[23 + indicesOffset] = 12 + verticeNumberOffset;


	indices[24 + indicesOffset] = 16 + verticeNumberOffset;
	indices[25 + indicesOffset] = 18 + verticeNumberOffset;
	indices[26 + indicesOffset] = 19 + verticeNumberOffset; //left face
	indices[27 + indicesOffset] = 19 + verticeNumberOffset;
	indices[28 + indicesOffset] = 17 + verticeNumberOffset;
	indices[29 + indicesOffset] = 16 + verticeNumberOffset;

	indices[30 + indicesOffset] = 20 + verticeNumberOffset;
	indices[31 + indicesOffset] = 22 + verticeNumberOffset;
	indices[32 + indicesOffset] = 23 + verticeNumberOffset; //right face
	indices[33 + indicesOffset] = 23 + verticeNumberOffset;
	indices[34 + indicesOffset] = 21 + verticeNumberOffset;
	indices[35 + indicesOffset] = 20 + verticeNumberOffset;


}



int main()
{
	Chunk testchunk;
	testchunk.fillwithdirt();
	int p = 0;
	CubeTextureCoords TempTexture;
	for (int X = 0; X < 16; X++)
	{
		for (int Y = 0; Y < 255; Y++)
		{
			for (int Z = 0; Z < 16; Z++)
			{
				bool Valid = CheckForNeighbhors(testchunk,X, Y, Z); //returns true if fully surrounded
				p++;
				TempTexture.BlockNum = testchunk.ChunkData[X][Y][Z]; //load the blocknum in
				TempTexture.IdToTexure(); //generate the correct texture coordinates
				if (TempTexture.BlockDraw && Valid == false) {GenerateCube(p, X*2, Y*2, Z*2,TempTexture); } //if the block is to be drawn. generate a cube with the temporary texture
			}
		}

	}










			//GenerateCube(p, X*2, Y*2, Z*2);

	// Initialize GLFW
	glfwInit();
	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);


	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");


	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();



	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "\\YoutubeOpenGL 8 - Camera\\textures";

	// Texture
	Texture brickTex((parentDir + texPath + "\\TEXTURES.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);

	// Original code from the tutorial
	/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);*/

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 1021.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		double lastTime = glfwGetTime();
		int nbFrames = 0;




		std::cout << (int) camera.Position.x;
		std::cout << ",";
		std::cout << (int) camera.Position.y;
		std::cout << ",";
		std::cout << (int) camera.Position.z;
		std::cout << "\n";

		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.Matrix(45.0f, 0.1f, 1000.0f, shaderProgram, "camMatrix");

		// Binds texture so that is appears in rendering
		brickTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	brickTex.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}