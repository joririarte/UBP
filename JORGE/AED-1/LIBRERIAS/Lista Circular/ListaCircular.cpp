#include "ListaCircular.h"
#include <iostream>

ListaCircular::ListaCircular()
{
}

ListaCircular::~ListaCircular()
{
}

//Inserta un dato en la lista
void ListaCircular::insertar(int data)
{
	//Si la lista esta vacia, solamente inserta el dato
	if (lista == nullptr) {
		lista = new Nodo(data);
		//pero hace que el siguiente apunte a sí mismo (circular)
		lista->sig = lista;
	}
	//Si la lista no está vacía
	else {
		//apunta la lista->sig al nuevo nodo
		//nuevo nodo punta a lista->sig
		lista->sig = new Nodo(data, lista->sig);
		//corro el puntero lista 
		//para que se pare en el nuevo nodo
		//asi cada nuevo nodo, va a apuntar al primero que ingresó
		lista = lista->sig;
	}
}

//inserta un nodo entre 2 ya existentes
void ListaCircular::insertarDespuesDe(int data, int ant)
{
	Nodo* n = buscar(ant);
	/*
	* si existe el nodo,
	* se inserta el dato despues de ese nodo
	*/
	if (n != nullptr)
		n->sig = new Nodo(data, n->sig);
}

void ListaCircular::eliminar(int data)
{
	Nodo* n = buscar(data);
	//si existe el nodo
	if (n != nullptr) {
		//recorro la lista para buscar el anterior
		do {
			lista = lista->sig;
		} while (lista->sig != n);
		//el nodo anterior, ahora apunta al que seguia
		//del que quiero eliminar
		lista->sig = n->sig;
	}
}

//retorna el nodo donde esta parado el puntero raiz
ListaCircular::Nodo* ListaCircular::getRaiz()
{
	return lista;
}

//busca un nodo
ListaCircular::Nodo* ListaCircular::buscar(int data)
{
	//marco el nodo de inicio de la busqueda
	Nodo* inicio = lista;
	do{
		lista = lista->sig;
		//recorro nodo a nodo hasta encontrar el dato
		//o hasta que vuelva al inicio
	} while (lista->info != data && lista != inicio);
	//retorna el nodo encontrado
	//o nullptr si no encontró nada
	if (lista->info == data)
		return lista;
	else
		return nullptr;
}

//modifica un dato
void ListaCircular::modificar(int dataAnt, int dataN)
{
	Nodo* n = buscar(dataAnt);
	//si el nodo existe modifica el contenido
	if (n != nullptr)
		n->info = dataN;
}

//muestra la lista
void ListaCircular::mostrar()
{
	//marco el nodo de inicio
	Nodo* inicio = lista;
	int i = 1;
	do{
		//itera entre los nodos hasta que da la vuelta
		std::cout << "Nodo " << i << ": "
			<< lista->info << std::endl;
		lista = lista->sig;
		i++;
	} while (lista != inicio);
}

//CONSTRUCTORES DE NODOS
ListaCircular::Nodo::Nodo()
{
}

ListaCircular::Nodo::Nodo(int d)
{
	info = d;
}

ListaCircular::Nodo::Nodo(int data, Nodo* nxt)
{
	info = data;
	sig = nxt;
}
