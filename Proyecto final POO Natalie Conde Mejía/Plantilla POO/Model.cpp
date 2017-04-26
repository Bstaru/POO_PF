#include "Model.h"


Model::~Model() {
	glmDelete(model);
}

Model::Model(string modelPath, string texturePath) : textureId(0) {
	drawMode = GLM_SMOOTH | GLM_MATERIAL;
	//Load 3D Model
	//model = glmReadOBJ("models//Cyborg_Riffle2//Cyborg_Riffle.obj");
	model = glmReadOBJ((char*)modelPath.c_str());
	//glmUnitize(model);
	glmFacetNormals(model);
	glmVertexNormals(model, 90.0);
	//Load Texture
	BMPError e = BMPLoad(texturePath, texture);;
	if (e == BMPNOERROR) {
		drawMode |= GLM_TEXTURE;
		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, texture.width, texture.height, 0, GL_RGB,GL_UNSIGNED_BYTE, texture.bytes);
	}
}

void Model::Draw() {
	if (drawMode & GLM_TEXTURE) {
		glBindTexture(GL_TEXTURE_2D, textureId);
	}
	glmDraw(model, drawMode);
	glBindTexture(GL_TEXTURE_2D, NULL);
}