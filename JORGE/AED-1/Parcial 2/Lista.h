#pragma once
#include "Mediciones.h"
#include "HashTable.h"
class Lista
{
private:
	class Nodo {
	public:
		Mediciones* info;
		Nodo* sig;
		Nodo();
		Nodo(Mediciones* data);
	};
	Nodo* raiz;
public:
	Lista();
	~Lista();
	void insertar(Mediciones* data);
	void mostrar();
	Nodo* getLast();
	Nodo* getRaiz();
	int size();
	Nodo* buscar(char material);
	Nodo* buscar(Nodo* n);
	bool eliminar(char material);
	bool listaVacia();
	void recorrer(void (*func)(Mediciones*,HashTable*),HashTable* hsh);
};