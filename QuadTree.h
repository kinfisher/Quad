#pragma once
#include "Nodo.h"
 
class Quadtree
{
public:
	Quadtree(Punto,Punto,int);
	void subdivision(Nodo *&);
	int max_puntos;
	bool insertar(Punto);
	bool buscar(Punto,Nodo *&);
	Nodo* head;
	void dibujar(Nodo *);


	~Quadtree();
};

