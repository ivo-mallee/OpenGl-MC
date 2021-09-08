#pragma once
#include "texture.h"
#include"chunks.h"
class CubeTextureCoords {

public:
	CubeTextureCoordsSet TOP, FRONT, BOTTON, BACK, LEFT, RIGHT;
	int BlockNum = 0; // standard air
	bool BlockDraw = true;
	void IdToTexure() 
	{
		switch (BlockNum) {
		case 0:
			//do nothing or return that its air (aka place no block)
			BlockDraw = false;
			break;
		case 1:
			TOP.Xoffset = 2;
			TOP.Yoffset = 15;
			TOP.UpdateValues();

			FRONT.Xoffset = 2;
			FRONT.Yoffset = 15;
			FRONT.UpdateValues();

			BOTTON.Xoffset = 2;
			BOTTON.Yoffset = 15;
			BOTTON.UpdateValues();

			BACK.Xoffset = 2;
			BACK.Yoffset = 15;
			BACK.UpdateValues();

			LEFT.Xoffset = 2;
			LEFT.Yoffset = 15;
			LEFT.UpdateValues();

			RIGHT.Xoffset = 2;
			RIGHT.Yoffset = 15;
			RIGHT.UpdateValues();
			break;
		default:
		break;
		}
	
	}

};

bool CheckForNeighbhors(Chunk TEMP,int X, int Y,int Z)
{
	int totalNeighbhors = 0;
	if (X > 0) { if (TEMP.ChunkData[X - 1][Y][Z] != 0) { totalNeighbhors++; } } //if at X - 1 there is a block
	if (Y > 0) { if (TEMP.ChunkData[X][Y-1][Z] !=   0) { totalNeighbhors++; } } //if at Y - 1 there is a block
	if (Z > 0) { if (TEMP.ChunkData[X][Y][Z-1] !=   0) { totalNeighbhors++; } } //if at Z - 1 there is a block

	if (X < 15) { if (TEMP.ChunkData[X + 1][Y][Z] != 0) { totalNeighbhors++; } } //if at X + 1 there is a block
	if (Y < 15) { if (TEMP.ChunkData[X][Y + 1][Z] != 0) { totalNeighbhors++; } } //if at Y + 1 there is a block
	if (Z < 15) { if (TEMP.ChunkData[X][Y][Z + 1] != 0) { totalNeighbhors++; } } //if at Z + 1 there is a block

	if (totalNeighbhors > 4) { 
		return true; 
	} //if the block is fully surrounded
	return false;
	
}