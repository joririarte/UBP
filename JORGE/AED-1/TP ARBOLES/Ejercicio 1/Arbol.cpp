#include <iostream>
#include "Arbol.h"

Arbol::Nodo* Arbol::buscar(int d, Nodo* rec)
{
	if (rec != nullptr)
		if (d > rec->info)
			rec = buscar(d, rec->der);
	if (rec != nullptr)
		if (d < rec->info)
			rec = buscar(d, rec->izq);
	if (rec != nullptr)
		if (d == rec->info)
			return rec;
	return nullptr;
}

Arbol::Nodo* Arbol::buscarAnterior(int d, Nodo* rec)
{
	Nodo* r = rec;
	if (rec->der != nullptr)
		if (d == rec->der->info)
			return rec;
		else
			rec = buscarAnterior(d, rec->der);
	rec = r;
	if (rec->izq != nullptr)
		if (d == rec->izq->info)
			return rec;
		else
			rec = buscarAnterior(d, rec->izq);
	return nullptr;
}

bool Arbol::borrarHoja(int d, Nodo* r)
{
	if (r != nullptr) {
		Nodo* a = buscarAnterior(d, raiz);
		if (d == a->der->info)
			a->der = nullptr;
		else
			a->izq = nullptr;
		delete r;
		return true;
	}
	return false;
}

void Arbol::imprimir_Pre_Orden(Nodo* rec)
{
	if (rec != nullptr) {
		std::cout << "Nodo: " << rec->info << std::endl;
		imprimir_Pre_Orden(rec->izq);
		imprimir_Pre_Orden(rec->der);
	}
}

void Arbol::imprimir_Pos_Orden(Nodo* rec)
{
	if (rec != nullptr) {
		imprimir_Pos_Orden(rec->izq);
		imprimir_Pos_Orden(rec->der);
		std::cout << "Nodo: " << rec->info << std::endl;
	}
}

void Arbol::imprimir_In_Orden(Nodo* rec,std::basic_ostream<char>& stream)
{
	if (rec != nullptr) {
		imprimir_In_Orden(rec->izq,stream);
		stream << rec->info << std::endl;
		imprimir_In_Orden(rec->der,stream);
	}
}

Arbol::Arbol()
{
}

Arbol::~Arbol()
{
	raiz = nullptr;
}

Arbol::Nodo* Arbol::getRaiz()
{
	return raiz;
}

void Arbol::insertar(int d)
{
	if (raiz == nullptr)
		raiz = new Nodo(d);
	else{
		Nodo* rec, * ant;
		ant = nullptr;
		rec = raiz;
		while (rec != nullptr) {
			ant = rec;
			if (d > rec->info)
				rec = rec->der;
			else if (d < rec->info)
				rec = rec->izq;
			else return;//no se pueden ingresar datos duplicados
		}
		if (d > ant->info)
			ant->der = new Nodo(d);
		else if (d < ant->info)
			ant->izq = new Nodo(d);
	}
}

bool Arbol::borrar(int d)
{
	Nodo* n = buscar(d);
	if (n->izq != nullptr || n->der != nullptr)
		return borrarHoja(d, n);
	else {
		std::cout << "No se pueden borrar nodos con hijos!\n";
		return false;
	}
}

Arbol::Nodo* Arbol::buscar(int d)
{
	return buscar(d, raiz);
}

void Arbol::imprimir_Pre_Orden()
{
	imprimir_Pre_Orden(raiz);
}

void Arbol::imprimir_Pos_Orden()
{
	imprimir_Pos_Orden(raiz);
}

void Arbol::imprimir_In_Orden(std::basic_ostream<char>& stream)
{
	imprimir_In_Orden(raiz,stream);
}

Arbol::Nodo::Nodo(int d)
{
	info = d;
}

Arbol::Nodo::~Nodo()
{
	info = NULL;
	izq = nullptr;
	der = nullptr;
}
