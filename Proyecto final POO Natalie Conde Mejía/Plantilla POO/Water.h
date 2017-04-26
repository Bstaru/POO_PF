#ifndef _WATER_H_
#define _WATER_H_

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

class Water 
{
private:
GLuint texture;

public:

	Water(char *texturePath);
	~Water(void);

	void Draw();
	void Update();
};

#endif