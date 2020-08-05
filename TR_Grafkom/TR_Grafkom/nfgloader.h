#pragma once
#include <vector>
#include <string>
#include <fstream>
#include"vertex.h"

GLuint textureID; 
using namespace std;

GLuint loadtga(const char* Path) {
	pixel* pixelsData;
	vector<uint8_t> pixels; 
	uint32_t width, height, size, bitperpixel;
	fstream inFile(Path, ios::in | ios::binary);

	uint8_t header[18] = { 0 }; 

	vector<uint8_t> colorData;
	inFile.read(reinterpret_cast<char*>(&header), sizeof(header));
	bitperpixel = header[16];
	width = header[13] * 256 + header[12];
	height = header[15] * 256 + header[14];
	size = size = ((width * bitperpixel + 31) / 32) * 4 * height;

	if ((bitperpixel != 24) && (bitperpixel != 32)) {
		inFile.close();
		printf("Not a TGA File");
		return 0;
	}
	colorData.resize(size);
	inFile.read(reinterpret_cast<char*>(colorData.data()), size);
	inFile.close();
	pixels = colorData;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels.data()); 
}
