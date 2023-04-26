#include "ListaDoble.h"
#include <iostream>

ListaDoble::ListaDoble()
{
}

ListaDoble::~ListaDoble()
{

}

void ListaDoble::insertarFinal(int data)
{
	if (lista == nullptr)
		lista = new Nodo(data);
	else 
		lista->sig = new Nodo(data, nullptr, getLast());
}

void ListaDoble::insertarAntes(int data)
{
	if (lista == nullptr)
		lista = new Nodo(data);
	else
		lista = new Nodo(data, getFirst(), nullptr);
}

void ListaDoble::insertarEntre(int data, int ant, int sig)
{
	Nodo* lst = buscar(ant);
	Nodo* nxt = buscar(sig);
	Nodo* nuevo = new Nodo(data,nxt,lst);
	lst->sig = nuevo;
	nxt->ant = nuevo;
}

void ListaDoble::eliminar(int data)
{
	Nodo* n = buscar(data);
	if (n != nullptr) {
		Nodo* lst = n->ant;
		Nodo* nxt = n->sig;
		lst->sig = nxt;
		nxt->ant = lst;
	}
}

ListaDoble::Nodo* ListaDoble::getLast()
{
	while (lista->sig != nullptr)
		lista = lista->sig;
	return lista;
}

ListaDoble::Nodo* ListaDoble::getFirst()
{
	while (lista->ant != nullptr)
		lista = lista->ant;
	return lista;
}

ListaDoble::Nodo* ListaDoble::getRaiz()
{
	return lista;
}

ListaDoble::Nodo* ListaDoble::buscar(int data)
{
	while (lista->info != data && lista->sig != nullptr)
		lista = lista->sig;
	while (lista->info != data && lista->ant != nullptr)
		lista = lista->ant;
	if (lista->info == data)
		return lista;
	else
		return nullptr;
}

void ListaDoble::modificar(int dataAnt, int dataN)
{
	Nodo* n = buscar(dataAnt);
	if (n != nullptr) n->info = dataN;
}

void ListaDoble::mostrar()
{
	getFirst();
	int i = 1;
	while (lista->sig != nullptr) {
		std::cout << "Nodo " << i << ": " 
				  << lista->info << std::endl;
		lista = lista->sig;
		i++;
	}
}

ListaDoble::Nodo::Nodo()
{
}

ListaDoble::Nodo::Nodo(int d)
{
	info = d;
}

ListaDoble::Nodo::Nodo(int data, Nodo* nxt, Nodo* lst)
{
	info = data;
	sig = nxt;
	ant = lst;
}
