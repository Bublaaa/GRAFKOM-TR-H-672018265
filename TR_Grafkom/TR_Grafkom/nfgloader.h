#pragma once
#include <iostream>
#include "vertex.h"

int load(const char* path)
{
	float baris, nrmx, nrmy, nrmz, binrmx, binrmy, binrmz, tgtx, tgty, tgtz;
	int nvertices, nrindices;
	FILE* NFG;
	fopen_s(&NFG, path, "r");
	if (!NFG)
	{
		printf("Can't open the file !\n");
		return 0;
	}

	fscanf_s(NFG, "NrVertices:%d", &nvertices);
	for (int a = 0; a < nvertices; a++)
	{
		//0. pos: [0.134000, 1.020300, -0.083900] ; norm: [0.662725, 0.317712, -0.678126] ; binorm: [0.014559, 0.899903, 0.435847] ; tgt: [-0.748721, 0.298719, -0.591763] ; uv: [0.611900, 0.886700] ;
		fscanf_s(NFG, "   %d. pos: [%f, %f, %f] ; norm: [%f, %f, %f] ; binorm: [%f, %f, %f] ; tgt: [%f, %f, %f] ; uv: [%f, %f] ;",
			&baris, &vertex[a].x, &vertex[a].y, &vertex[a].z, &nrmx, &nrmy, &nrmz, &binrmx, &binrmy, &binrmz, &tgtx, &tgty, &tgtz, &vertex[a].u, &vertex[a].v);
	}

	fscanf_s(NFG, "\nNrIndices:%d\n", &nrindices);
	for (int b = 0; b < (nrindices / 3); b++)
	{
		//0.    0, 1, 2
		fscanf_s(NFG, "   %d.    %d,    %d,    %d", &baris, &index[b].dex1, &index[b].dex2, &index[b].dex3);
	}

}
