#include "Lista.h"
#include <iostream>

Lista::Lista()
{
	raiz = nullptr;
}

Lista::~Lista()
{
	
}

void Lista::insertar(int data)
{
	if (raiz == nullptr)
		raiz = nuevoNodo(data);
	else
		getLast()->sig = nuevoNodo(data);
}

void Lista::insertarAntes(int data)
{
	if (raiz == nullptr)
		insertar(data);
	else {
		Nodo* nuevo = nuevoNodo(data);
		nuevo->sig = raiz;
		raiz = nuevo;
	}
}

void Lista::mostrar()
{
	Nodo* recorrido = raiz;
	int i = 1;
	while (recorrido != nullptr){
		std::cout << "Nodo " << i << ": " << recorrido->info << std::endl;
		i++;
		recorrido = recorrido->sig;
	}
}

Lista::Nodo* Lista::nuevoNodo(int data)
{
	Nodo* nuevo = new Nodo();
	nuevo->info = data;
	return nuevo;
}

Lista::Nodo* Lista::getLast()
{
	Nodo* recorrido = raiz;
	while (recorrido->sig != nullptr)
		recorrido = recorrido->sig;
	return recorrido;
}

Lista::Nodo* Lista::getRaiz()
{
	return raiz;
}

int Lista::size()
{
	Nodo* recorrido = raiz;
	int cant = 0;
	while (recorrido->sig != nullptr) {
		recorrido = recorrido->sig;
		cant++;
	}
	return cant;
}

int Lista::sumar()
{
	Nodo* rec = raiz;
	int sum = 0;
	while (rec->sig != nullptr) {
		sum += rec->info;
		rec = rec->sig;
	}
	return sum;
}

float Lista::media()
{
	return sumar()/size();
}

int Lista::max()
{
	Nodo* rec = raiz;
	int maximo = raiz->info;
	while (rec->sig != nullptr) {
		maximo = rec->info > maximo ? rec->info : maximo;
		rec = rec->sig;
	}
	return maximo;
}

int Lista::min()
{
	Nodo* rec = raiz;
	int minimo = raiz->info;
	while (rec->sig != nullptr) {
		minimo = rec->info < minimo ? rec->info : minimo;
		rec = rec->sig;
	}
	return minimo;
}

Lista::Nodo* Lista::buscar(int dato)
{
	Nodo* rec = raiz;
	while (rec->sig != nullptr || rec->info != dato)
		rec = rec->sig;
	return rec = rec->info == dato ? rec : nullptr;
}

void Lista::modificar(int datoViejo,int datoNuevo)
{
	Nodo* n = buscar(datoViejo);
	if (n != nullptr) 
		n->info = datoNuevo;
}

void Lista::eliminar(int dato)
{
}
