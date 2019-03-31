#pragma once
#include "Punto.h"
#include <vector>

using namespace std;

class Nodo
{
public:
	Nodo(Punto,Punto);
	vector<Punto> num_puntos;
	bool hoja;
	Punto esquina_superior_izq, esquina_inferior_der;
	Nodo* NOSE[4];
	~Nodo();
};

