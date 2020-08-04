#pragma once
#include <iostream>

struct ver
{
	GLfloat x, y, z, u, v;
};

struct indi
{
	GLint dex1, dex2, dex3;
};

ver* vertex = new ver[512];
indi* index = new indi[718];

struct pixel {
	uint32_t colors;
	struct
	{
		uint8_t R, G, B;
	};
};
