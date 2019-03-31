#include "QuadTree.h"
#include <GL/glut.h>



Quadtree::Quadtree(Punto esq_sup,Punto esq_inf,int maximo)
{
	
	head = new Nodo(esq_sup,esq_inf);
	max_puntos = maximo;
	
}


Quadtree::~Quadtree()
{

}

bool Quadtree::buscar(Punto point,Nodo *&P)
{
	int le_hijo;
	for (P = head;P->hoja!=true;P=P->NOSE[le_hijo])
	{
		if (point.x > P->esquina_inferior_der.x	)
		{
			if (point.y > P->esquina_inferior_der.y)
			{
				le_hijo = 1;
			}
			else
			{
				le_hijo = 3;
			}
	
		}
		else if (point.y > P->esquina_superior_izq.y)
		{
			le_hijo = 0;

		}
		else
		{
			le_hijo = 2;
		}
	}

	for (int i = 0; i < P->num_puntos.size(); i++)
	{
		P->num_puntos[i] = point;
	}
	return 1;

}

bool Quadtree::insertar(Punto point)
{
	Nodo *P;
	if (buscar(point, P))
	{
		return 0;
	}

	if (P->num_puntos.size() == max_puntos)
	{
		subdivision(P);
	}

	P->num_puntos.push_back(point);

}

void Quadtree::dibujar(Nodo *P)
{
	if (P->hoja)
	{
		for (int i = 0; P->num_puntos.size()<i; i++)
		{
			glPointSize(5.0);
			glBegin(GL_POINTS);
			glColor3f(0,0,200);
			glVertex2d(P->num_puntos[i].x,P->num_puntos[i].y);
			glEnd();
		}
		return;
	}

	double midx, midy;
	

}



void Quadtree::subdivision(Nodo *&P)
{
	int le_hijo;
	Punto medio;
	medio.x = (P->esquina_superior_izq.x + P->esquina_superior_izq.x) / 2;
	medio.y = (P->esquina_superior_izq.y + P->esquina_superior_izq.y) / 2;


	//Nodo *nuevo = new Nodo(P->esquina_superior_izq,P->esquina_inferior_der);
	//Instanciar las esquinas de los nodos


	P->NOSE[0] = new Nodo(P->esquina_superior_izq, medio);
	P->NOSE[1] = new Nodo(Punto(medio.x, P->esquina_superior_izq.y), Punto(P->esquina_inferior_der.x, medio.y));
	P->NOSE[2] = new Nodo(Punto(P->esquina_superior_izq.x, medio.y), Punto(medio.x, P->esquina_inferior_der.y));
	P->NOSE[3] = new Nodo(medio, P->esquina_inferior_der);

	//para distribuir los puntos es los if del buscar y luego los distribuyo los puntos en las hojas
	//luego para finalizar se tienen que borrar los datos
	
	for (int i = 0 ;i < P->num_puntos.size(); i++)
	{
		if (P->num_puntos[i].x>medio.x)
		{
			if (P->num_puntos[i].y > medio.y)
			{
				le_hijo = 1;
			}
			else
			{
				le_hijo = 3;
			}
		}

		else if (P->num_puntos[i].y > medio.y)
		{
			le_hijo = 0;
		}
		else
		{

			le_hijo = 2;
		}

		P->NOSE[le_hijo]->num_puntos.push_back(P->num_puntos[i]);

	}
	P->num_puntos.erase(P->num_puntos.begin(), P->num_puntos.end());



}





