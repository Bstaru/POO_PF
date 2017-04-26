#pragma once
#ifndef _OBJETOS_H_
#define _OBJETOS_H_
#include "Model.h"

class Objetos
{
public:
	Model*ovni;
	Model*carretilla;
	Model*pato;
	

	Objetos()
	{
	ovni = new Model("modelos//avonds.obj","Texturas//avondstext.bmp");
	carretilla = new Model("modelos//carreta.obj","Texturas//wood2.bmp");
	pato = new Model("modelos//barcozelda.obj","Texturas//barcofome.bmp");
	
	};

	void Draw();
	~Objetos()
	{
		delete ovni;
		delete carretilla;
		delete pato;
	
	}
};
#endif
