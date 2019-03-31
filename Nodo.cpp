#include "Nodo.h"



Nodo::Nodo(Punto esq_sup,Punto esq_inf)
{
	esquina_superior_izq = esq_sup;
	esquina_inferior_der = esq_inf;
	hoja = true;
	NOSE[0] = NOSE[1] = NOSE[2] = NOSE[3] = 0;

}


Nodo::~Nodo()
{
}
