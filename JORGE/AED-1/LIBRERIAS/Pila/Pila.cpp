#include "Pila.h"

Pila::Nodo::Nodo()
{

}

Pila::Nodo::Nodo(int data)
{
	info = data;
}

Pila::Nodo::Nodo(int data, Nodo* nxt)
{
	info = data;
	sig = nxt;
}

Pila::Pila()
{
}

Pila::Pila(unsigned int max)
{
	tope = max;
}

Pila::~Pila()
{
}

void Pila::insertar(int data)
{
	if (cima == nullptr) {
		cima = new Nodo(data);
		enUso++;
	}
	else {
		if (enUso + 1 <= tope) {
			cima = new Nodo(data, cima);
			enUso++;
		}
	}
}

Pila::Nodo* Pila::extraer()
{
	Nodo* n = cima;
	cima = n->sig;
	if (enUso - 1 >= 0)
		enUso--;
	return n;
}

unsigned int Pila::size()
{
	return enUso;
}

bool Pila::pilaLlena()
{
	return enUso>=tope;
}

bool Pila::pilaVacia()
{
	return cima==nullptr;
}
