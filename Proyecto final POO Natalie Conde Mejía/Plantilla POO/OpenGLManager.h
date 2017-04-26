#ifndef _OPENGL_MANAGER_H
#define _OPENGL_MANAGER_H

#include <windows.h>
#include <gl\GLU.h>
#include <gl\GL.h>
#include "Terrain_v2.h"
#include "Camera_v2.h"
#include "Dome.h"
#include "Model.h"
#include "Water.h"
//#include "Objetos.h"

////camara
//float alt,anch,hue;

//mov objs
int z,a,c, x;
float wuh;

void neblina();

#define velocidad 2.0f

class OpenGLManager
{
public:
	Terrain*piso;
	Terrain*piso2;
	Camera*MainCamera;
	Dome*Domito;
	Model*casa;
	Model*casa3;
	Model*palm;
	Water*agua;
	Model*pato;
	Model*ovni;
	Model*calle;
	Model*fen;
	Model*puente;
	Model*car1;
	Model*car2;
	Model*casa2;
	Model*umbre;
	Model*silla1;
	Model*silla2;
	Model*cama;
	Model*buro;
	Model*piedra;
	Model*isla;
	Model*makar;
	
public:
	OpenGLManager(HWND hWnd)
	{
		glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping ( NEW )
		glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
		glClearDepth(1.0f);									// Depth Buffer Setup
		glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
		glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
		//glEnable(GL_BLEND);									//Niebla
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	//Niebla
		//glEnable(GL_FOG);									//Niebla
		////iluminacion
		//glEnable(GL_LIGHTING);

		Initialize();

	}

	~OpenGLManager()
	{

	}

	void Initialize()
	{
		wuh=0;

		MainCamera=new Camera();

		agua=new Water("Texturas/water.bmp");
		Domito=new Dome("Texturas/sky.bmp",200.0f,90,90);
		piso=new Terrain("Texturas//hmap4.bmp","Texturas//arena.bmp");
		piso2=new Terrain("Texturas//hmap4.bmp","Texturas//mountain.bmp");
		casa = new Model ("modelos//CasaSimples.obj" , "Texturas//casaSimples_D.bmp");
		casa3 = new Model ("modelos//casaabrida.obj" , "Texturas//casaSimples_D2.bmp");
		casa2 = new Model ("modelos//house_obj.obj" , "Texturas//houseje.bmp");
		palm = new Model ("modelos/palmera.obj" , "Texturas//hoja.bmp");
		ovni = new Model("modelos//avonds.obj","Texturas//avondstext.bmp");
		pato = new Model("modelos//barcozelda.obj","Texturas//barcofome.bmp");
		calle = new Model("modelos//cashelil.obj" , "Texturas//cashe.bmp");
		fen = new Model ("modelos//fence.obj","Texturas//hue5.bmp");
		puente = new Model ("modelos//bridge.obj","Texturas//puentee.bmp");
		car1 = new Model ("modelos//dacia.obj","Texturas//carrochido.bmp");
		car2 = new Model ("modelos//dacia.obj","Texturas//carrochido2.bmp");
		cama = new Model ("modelos//Bed.obj","Texturas//bed.bmp");
		buro = new Model ("modelos//buroese.obj","Texturas//wud2.bmp");
		umbre= new Model ("modelos//umbrella.obj","Texturas//umbre.bmp");
		silla2 = new Model ("modelos//patio.obj","Texturas//wud.bmp");
		silla1 = new Model ("modelos//mesafuera.obj","Texturas//wud.bmp");
		piedra = new Model ("modelos//estone.obj","Texturas//ekaoSS00.bmp");
		isla = new Model ("modelos//isla.obj","Texturas//textis.bmp");
		makar = new Model ("modelos//makars.obj","Texturas//makarss.bmp");
	}

	void Draw(HDC hDC)
	{
		//borramos el biffer de color y el z para el control de profundidad a la 
		//hora del render a nivel pixel.
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		GLfloat LightAmb[] = { 0.0, 0.0,0.0, 0.0 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb);
		glLoadIdentity();
		/*
				Vector3 cam_position=MainCamera->GetPosition();
				float terrain_altitude=piso2->GetAltitude(cam_position.x,cam_position.z);
				MainCamera->SetAltitudPosition(t0errain_altitude);
				MainCamera->Update();*/
		ControledCamera();

	/*neblina();
	x++;*/

	a++;
	//a=a+2;
	z++;
	z=z+2;
	c++;
	//c=c+2;

	//Piso
		glPushMatrix();
		glTranslatef(0,-50,-3800);
		glScalef(50,-10,50);
		piso->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-800,-250,-3800);
		glScalef(50,10,50);
		piso2->Draw();
		glPopMatrix();
		
	//Domo
		glPushMatrix();
		glTranslatef(0,-350,0);
		glScalef(20,20,25);

		if(wuh<=360){
			glRotatef(wuh,0,1,0);
			wuh+=0.15;
		}
		else {wuh=0;}

		Domito->Draw();
		glPopMatrix();
		
	//Agua
		glPushMatrix();
		glColor4f(1,1,1,1);
		glTranslatef(0,-90,-0);
		glScalef(180,180,180);
		agua->Draw();
		glColor4f(1,1,1,1);
		glPopMatrix();


	/*Modelos
		-------------------------------------------------------------------------------*/
		//Palmeras
		glPushMatrix();
		glTranslatef(-1000,-60,-3000);
			glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1990,-65,-3170);
			glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1500,-60,-2500);
			glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1500,-60,-2000);
			glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-1000,-60,-1000);
			glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1500,-60,-1000);
			glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();
		//---
		glPushMatrix();
		glTranslatef(-800,-60,-300);
			glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-400,-60,-300);
			glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(400,-60,-1500);
			glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(200,-60,-300);
			glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2000,30,-1500);
		glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2000,30,-1500);
		glScalef(5,5,5);
		palm->Draw();
		glPopMatrix();
		//_________________________

		//cosazelda
		glPushMatrix();
		glTranslatef(0,-70,70);
		glScalef(15,15,15);
		makar->Draw();
		glPopMatrix();

		//cosapiedra
		glPushMatrix();
		glTranslatef(1200,-70,-700);
		glRotatef(-30,0,1,0);
		glScalef(0.5,0.5,0.5);
		piedra->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1200,-70,-2700);
		glRotatef(30,0,1,0);
		glScalef(0.5,0.5,0.5);
		piedra->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1200,-70,-1700);
		glRotatef(-90,0,1,0);
		glScalef(0.5,0.5,0.5);
		piedra->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1300,-70,-1700);
		glScalef(0.5,0.5,0.5);
		piedra->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1300,-70,-2700);
		glRotatef(-30,0,1,0);
		glScalef(0.5,0.5,0.5);
		piedra->Draw();
		glPopMatrix();

		//isla
		glPushMatrix();
		glTranslatef(0,-100,1500);
		glRotatef(180,0,1,0);
		glScalef(13,13,13);
		isla->Draw();
		glPopMatrix();

		 //Casa 
		glPushMatrix();
		glTranslatef(-700,0,-370);
		glScalef(30,30,30);
		casa->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-700,0,-1370);
		glRotatef(90,0,1,0);
		glScalef(30,30,30);
		casa->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-700,-50,-3170);
		glRotatef(90,0,1,0);
		casa2->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1000,-65,-1400);
		glRotatef(-90,0,1,0);
		glScalef(50,30,50);
		casa3->Draw();
		glPopMatrix();
		//objs dentro de casa
		glPushMatrix();
		glTranslatef(1400,-25,-1110);
		glRotatef(-90,0,1,0);
		glScalef(30,30,30);
		cama->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1450,-50,-1070);
		glRotatef(-90,0,1,0);
		glScalef(10,10,10);
		buro->Draw();
		glPopMatrix();

		//la madrinola esa
		glPushMatrix();
		glTranslatef(-400,-50,-350);
		glRotatef(90,0,1,0);
		glScalef(30,30,30);
		fen->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-400,-50,-250);
		glRotatef(90,0,1,0);
		glScalef(30,30,30);
		fen->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-400,-50,-450);
		glRotatef(90,0,1,0);
		glScalef(30,30,30);
		fen->Draw();
		glPopMatrix();

		//umbrella
		glPushMatrix();
		glTranslatef(-100,-90,-100);
		glRotatef(10,0,0,1);
		glScalef(10,10,10);
		umbre->Draw();
		glPopMatrix();

		//sillaplaya
		glPushMatrix();
		glTranslatef(-100,-20,-300);
		glRotatef(-90,0,1,0);
		glScalef(20,20,20);
		silla2->Draw();
		glPopMatrix();

		//silla
		glPushMatrix();
		glTranslatef(300,-60,-500);
		glRotatef(-90,0,1,0);
		glScalef(7,7,7);
		silla1->Draw();
		glPopMatrix();

		//puente
		glPushMatrix();
		glTranslatef(1800,20,-1500);
		glScalef(4,4,4);
		glRotatef(20,0,1,0);
		puente->Draw();
		glPopMatrix();

		//calle
		glPushMatrix();
		glTranslatef(-100,-60,-1000);
		glRotatef(90,0,1,0);
		glScalef(7,7,7);
		calle->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-800,-60,-1000);
		glRotatef(90,0,1,0);
		glScalef(7,7,7);
		calle->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(500,-60,-1000);
		glRotatef(90,0,1,0);
		glScalef(7,7,7);
		calle->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(900,-60,-1400);
		glScalef(7,7,7);
		calle->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(900,-60,-1900);
		glScalef(7,7,7);
		calle->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(900,-60,-2600);
		glScalef(7,7,7);
		calle->Draw();
		glPopMatrix();

		 //Carros
		glPushMatrix();
		glTranslatef(500,-50,-700);
		glScalef(80,80,80);
		glRotatef(180,0,1,0);
		if (c <= 20)
		{
		glTranslatef(0, 0, c);
		}

		else
		{
			c = 0;
		}
		car1->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1400,-50, -1000);
		glScalef(80,80,80);
		glRotatef(90,0,1,0);
		if (c <= 20)
		{
		glTranslatef(0, 0, c);
		}

		else
		{
			c = 0;
		}
		car2->Draw();
		glPopMatrix();


		//Barco
		glPushMatrix();
		glTranslatef(0, -100, 350);
		if (z <= 800)
		{
		glTranslatef(z, 0, 0);
		}

		else
		{
			z = 0;
		}
		pato->Draw();
		glPopMatrix();
		
		//avion
		glPushMatrix();
		glTranslatef(0,600,-1500);
		glScalef(2,2,2);
		if (a <= 1100)
		{
		glRotatef(z,1,0,0);
		
		}
		else
		{
			a = 0;
		}
		ovni->Draw();
		glPopMatrix();

		SwapBuffers(hDC);
	}

	void ControledCamera(){
		MainCamera->Update();
		if (GetKeyState(VK_UP) & 8000) {MainCamera->MoveForward(-(8*velocidad));}
		if (GetKeyState(VK_DOWN) & 8000) {MainCamera->MoveForward(8*velocidad);}
		if (GetKeyState(VK_RIGHT) & 8000) {MainCamera->RotateY(-1.5f);} /*{ MainCamera->StrafeRight(velocidad/2);MainCamera->RotateY(-velocidad/2);}*/
		if (GetKeyState(VK_LEFT) & 8000) {MainCamera->RotateY(1.5f);} /* { MainCamera->StrafeRight(-velocidad/2);MainCamera->RotateY(+velocidad/2);}*/
		

		///*if (GetKeyState('W') & 8000){MainCamera->RotateX(+velocidad/2);}
		//if (GetKeyState('S') & 8000){MainCamera->RotateX(-velocidad/2);}*/
		//if (GetKeyState('D') & 8000){MainCamera->RotateY(-1.5f);}
		//if (GetKeyState('A') & 8000){MainCamera->RotateY(1.5f);}
	}
	
	/*void neblina()
	{
		glPushMatrix();
		float fogColor[]={0.5,0.5,0.5,0.2};
		glFogfv(GL_FOG_COLOR,fogColor);
		glFogi(GL_FOG_MODE,GL_LINEAR);
		glFogf(GL_FOG_START,0.0f);
		glFogf(GL_FOG_END,5000.0f);
		glPopMatrix();

	}*/
};
#endif 