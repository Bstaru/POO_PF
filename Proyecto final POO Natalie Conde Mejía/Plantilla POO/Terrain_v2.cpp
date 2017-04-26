#include "Terrain_v2.h"
#include "TextureLoader.h"

//#define REPEAT_TEXTURE

Terrain::Terrain(char* height_map_texture_path, char* texture_path)
{
	this->texture_map = LoadTexture(texture_path); // Load texture

#pragma region Loading altitude values from height map

	AUX_RGBImageRec *texture_height_map[1];
	memset(texture_height_map, 0, sizeof(void *)*1);
	texture_height_map[0] = auxDIBImageLoad(height_map_texture_path);//Load height map texture
	size_x = texture_height_map[0]->sizeX;
	size_y = texture_height_map[0]->sizeY;

	this->height_map_array = new GLubyte[size_x * size_y];

	for(unsigned int i = 0; i < size_y; i++)
	{
		for(unsigned int j = 0; j < size_x; j++)
		{
			height_map_array[(i * size_x + j)] = texture_height_map[0]->data[(i * size_x + j) * 3];
		}
	}

	free(texture_height_map[0]);
#pragma endregion

}

Terrain::~Terrain()
{
	delete this->height_map_array;
	glDeleteTextures(1, &this->texture_map);
}

void Terrain::Draw()
{
	float scaleFactor = 5.0f;
	float maxHeight = 10.0;

	glPushMatrix();
		glPushAttrib(GL_TEXTURE_BIT);
			glBindTexture(GL_TEXTURE_2D, texture_map);
			//GL_MODULATE permite que la textura se vea afectada por el valor de la normal cuando recibe luz o por glColor
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

			int avg_size = (size_x + size_y) / 2;
			for(int z = 0; z < avg_size - 1; ++z)
			{
				glBegin(GL_TRIANGLE_STRIP);
				for (int x = 0; x < avg_size; ++x)
				{
					float scaledHeight = height_map_array[z * avg_size + x] / scaleFactor;
					float nextScaledHeight = height_map_array[(z + 1) * avg_size + x] / scaleFactor;

					float color = 0.5f + 0.5f * scaledHeight / maxHeight;
					float nextColor = 0.5f + 0.5f * nextScaledHeight / maxHeight;
			  
					glColor3f(color, color, color);
#ifdef REPEAT_TEXTURE
					glTexCoord2f(((float)x / (float)avg_size * 5.0f), ((float)z / (float)avg_size * 5.0f));//REPEAT TEXTURE
#else
					glTexCoord2f(((float)x / (float)avg_size), ((float)z / (float)avg_size));//COMPLETE
#endif
					glVertex3f((float)(x - avg_size / 2), scaledHeight, (float)(z - avg_size / 2));
			  
					glColor3f(nextColor, nextColor, nextColor);
#ifdef REPEAT_TEXTURE
					glTexCoord2f(((float)x / (float)avg_size * 5.0f), ((float)(z + 1) / (float)avg_size * 5.0f)); //REPEAT TEXTURE
#else 
					glTexCoord2f(((float)(x + 1) / (float)avg_size), ((float)(z + 1) / (float)avg_size));//COMPLETE
#endif
					glVertex3f((float)(x - avg_size / 2), nextScaledHeight, (float)(z + 1 - avg_size / 2));
				}
				glEnd();
			}
		glPopAttrib();
	glPopMatrix();
}

float Terrain::GetAltitude(float x, float y)
{
	int avg_size = (size_x + size_y) / 2;
	float offset = 5.0f;
	static float altitude = offset;

	float height1 = height_map_array[((int)(y + avg_size / 2) * avg_size + (int)x + avg_size / 2)] / 5.0f;
	float height2 = height_map_array[((int)((y + avg_size / 2) + 1) * avg_size + (int)x + avg_size / 2)] / 5.0f;
	altitude = (height1 + height2) / 2.0f;

	return altitude + offset;
}