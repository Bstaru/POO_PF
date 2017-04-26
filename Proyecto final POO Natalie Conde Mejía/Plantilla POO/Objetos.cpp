#include "Objetos.h"



void Objetos::Draw()
{
	
	int x;


	glPushMatrix();
		glTranslatef(-1400,400,-2000);
		//glTranslatef(-1000,400,-2000);
			glScalef(7,7,7);
		ovni->Draw();
		glPopMatrix();

	glPushMatrix();
	glTranslatef(450,-50, -500);
	glScalef(50, 50,50);
	glRotatef(90, 0, 1, 0);
	carretilla->Draw();
	glPopMatrix();

	
		glPushMatrix();
		glTranslatef(-300,-80,-3800);
			glScalef(2,2,2);
		pato->Draw();
		glPopMatrix();

	
}
	//Ovni
	/*glPushMatrix();
		glTranslatef(1400,400,-2000);
		//glTranslatef(-1000-x,400,-2000);
			glScalef(5,5,5);
		ovni->Draw();
		glPopMatrix();

		//Carretilla
		glPushMatrix();
		glTranslatef(-100,-50,-550);
			glRotatef(0,45,0,0);
			glScalef(60,60,60);
			carretilla->Draw();
		glPopMatrix();*/

		



/*Objetos::~Objetos()
{
}*/
