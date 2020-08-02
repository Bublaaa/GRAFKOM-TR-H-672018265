#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<GLFW/glfw3.h>

#include<glm.hpp>
#include<vec3.hpp>
#include<vec2.hpp>

//#include"Vertex.h"
bool loadfile(
    const char* path,
    std::vector < glm::vec3 >& out_pos,
    std::vector < glm::vec3 >& out_norm,
    std::vector < glm::vec3 >& out_binorm,
    std::vector < glm::vec3 >& out_tgt,
    std::vector < glm::vec2 >& out_uv
) {
    //temporary
    std::vector< unsigned int > posIndices, normIndices, binormIndices, tgtIndices, uvIndices;
    std::vector<glm::vec3> temp_pos;
    std::vector<glm::vec3> temp_norm;
    std::vector<glm::vec3> temp_binorm;
    std::vector<glm::vec3> temp_tgt;
    std::vector<glm::vec2> temp_uv;
    //buka file
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("Impossible to open the file !\n");
        return false;
    }
    while (2) {
        int indeks_1[512];
        int indeks_2[718];
        char baris[24];
        int res = fscanf(file, "%s", baris);
        if (res == EOF)
            break; //
        else if (res < 514) {
            glm::vec3 pos;
            glm::vec3 norm;
            glm::vec3 binorm;
            glm::vec3 tgt;
            glm::vec2 uv;
            fscanf(file, "%d. pos:[%f, %f, %f]; norm:[%f, %f, %f]; binorm:[%f, %f, %f]; tgt:[%f, %f, %f]; uv:[%f, %f];\n", 
                &indeks_1[res-1],
                &pos.x, &pos.y, &pos.z,
                &norm.x, &norm.y, &norm.z, 
                &binorm.x, &binorm.y, &binorm.z,
                &tgt.x, &tgt.y, &tgt.z,
                &uv.x, &uv.y);
            temp_pos.push_back(pos);
            temp_norm.push_back(norm);
            temp_binorm.push_back(binorm);
            temp_tgt.push_back(tgt);
            temp_uv.push_back(uv);
        }
        else if (res < 514 | res < 1233) {
            unsigned int posIndex[1], normIndex[1], uvIndex[1];
            int matches = fscanf(file, "   %d.    %d,    %d,    %d\n", &indeks_2[res-514], &posIndex[0], &normIndex[0], &uvIndex[0]);
            if (matches != 9) {
                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                return false;
            }
            posIndices.push_back(posIndex[0]);
            normIndices.push_back(normIndex[0]);
            uvIndices.push_back(uvIndex[0]);

            for (unsigned int i = 0; i < posIndices.size(); i++) {
                unsigned int vertexIndex = posIndices[i];
                glm::vec3 vertex = temp_pos[vertexIndex - 1];
                out_pos.push_back(vertex);
            }
        }
        
};


