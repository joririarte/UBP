#include "Cola.h"

Cola::Nodo::Nodo()
{
}

Cola::Nodo::Nodo(int data)
{
	info = data;
}

Cola::Cola()
{
}

Cola::~Cola()
{
}

void Cola::insertar(int data)
{
	if (colaVacia()) {
		frente = final = new Nodo(data);
		enUso++;
	}
	else {
		if (enUso + 1 <= tope) {
			final->sig = new Nodo(data);
			final = final->sig;
			enUso++;
		}

	}
}

Cola::Nodo* Cola::extraer()
{
	Nodo* n = frente;
	frente = frente->sig;
	if (enUso - 1 >= 0)
		enUso--;
	return n;
}

Cola::Nodo* Cola::getFrente()
{
	return frente;
}

Cola::Nodo* Cola::getFinal()
{
	return final;
}

bool Cola::colaLlena()
{
	return enUso >= tope;
}

bool Cola::colaVacia()
{
	return frente == nullptr;
}

unsigned int Cola::size()
{
	return enUso;
}
