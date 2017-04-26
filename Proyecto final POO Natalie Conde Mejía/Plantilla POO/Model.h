#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "glm.h"
#include "BMPLoader.h"


class Model {
public:
	Model(string modelPath, string texturePath = "");
	virtual ~Model();
	void Draw();
private:
	GLMmodel *model;
	BMPClass texture;
	unsigned int textureId;
	unsigned int drawMode;
};


