#pragma once
#include <iostream>

struct ver
{
	float x, y, z, u, v;
};

struct indi
{
	int dex1, dex2, dex3;
};

ver* vertex = new ver[512];
indi* index = new indi[718];
