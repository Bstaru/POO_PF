#include <windows.h>
#include <iostream>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\GLAUX.h>

static GLuint LoadTexture(char* pathTexture)
{
	FILE *File=NULL;
	if (pathTexture)
	{
		File=fopen(pathTexture,"r");
		if (File)
		{
			fclose(File);

			AUX_RGBImageRec *TextureImage[1];
			memset(TextureImage, 0, sizeof(void *)*1);          // Se instancia con NULL

			TextureImage[0] = auxDIBImageLoad(pathTexture);	// Load The Bitmap And Return A Pointer

			if (TextureImage[0])									// If Texture is set
			{
				GLuint texture = 0;
				if (TextureImage[0]->data)							// If Texture Image Exists
				{
					glGenTextures(1, &texture);					// Create The Texture (n = how many textures, gluint = where storage the texture)

					// Typical Texture Generation Using Data From The Bitmap // http://open.gl/textures
					glBindTexture(GL_TEXTURE_2D, texture);
					glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
					// Interpolation 
					// GL_NEAREST, GL_LINEAR, GL_NEAREST_MIPMAP_NEAREST, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
					//glGenerateMipmap( GL_TEXTURE_2D );

					free(TextureImage[0]->data);					// Free The Texture Image Memory
				}
				free(TextureImage[0]);			
				
				return texture;
			}
		}
	}
}