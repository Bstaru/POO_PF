#include "Water.h"
#include "TextureLoader.h"


Water::Water(char *texturePath) 
{
	texture = LoadTexture(texturePath);
}


Water::~Water(void)
{
	glDeleteTextures(1, &texture);
}

void Water::Draw()
{
	glPushAttrib(GL_CURRENT_BIT | GL_TEXTURE_BIT);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	static float water_factor_min = 0.0f;
	static float water_factor_max = 20.0f;
	static float water_size = 30;
	
	glBegin(GL_QUADS);
		glTexCoord2f(water_factor_min, water_factor_min);
		glColor4f(0.1f, 0.3f, 0.6f, 0.2f);
		glVertex3f(-water_size, 0.0f, water_size);

		glTexCoord2f(water_factor_max, water_factor_min);
		glColor4f(0.1f, 0.3f, 0.6f, 0.2f);
		glVertex3f(water_size, 0.0f, water_size);

		glTexCoord2f(water_factor_max, water_factor_max);
		glColor4f(0.1f, 0.3f, 0.6f, 0.2f);
		glVertex3f(water_size, 0.0f, -water_size);

		glTexCoord2f(water_factor_min, water_factor_max);
		glColor4f(0.1f, 0.3f, 0.6f, 0.2f);
		glVertex3f(-water_size, 0.0f, -water_size);
	glEnd();
	glPopAttrib();
}