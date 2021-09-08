#ifndef Chunk_CLASS_H
#define Chunk_CLASS_H
class Chunk {

public:
	int ChunkData[16][255][16];
	int total = 0;
	void fillwithdirt() {
		total = 0;
		for (int X = 0; X < 16; X++)
		{
			for (int Y = 0; Y < 255; Y++)
			{
				for (int Z = 0; Z < 16; Z++)
				{
					total++;
					ChunkData[X][Y][Z] = 1;
				}
			}

		}
	}
};
#endif