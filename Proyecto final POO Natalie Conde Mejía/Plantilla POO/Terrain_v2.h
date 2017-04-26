#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>

class Terrain
{
private:
	GLuint texture_map;	

	GLubyte *height_map_array;

	float scale_factor;
	int size_x;
	int size_y;	
public:
    Terrain(char* height_map_texture_path, char* texture_path);
	~Terrain();

	void Draw();
	void Update();
	float GetAltitude(float x, float y);
};

#endif