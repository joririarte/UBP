/*
* PARCIAL 1 AED 2023
* IRIARTE JORGE
* 
* EJERCICIO 2
* 
* Se tiene un archivo con los siguientes datos: [3,12,9,6,5,11,7]
* Realizar un programa que permita: 
* Cargar los datos del archivo en una lista, de forma ordenada. 
* Cargar una Pila con los elementos pares de la lista. 
* Cargar una Cola con los elementos menores que 10 de la lista.
* Mostrar Lista, Pila y Cola resultantes. 
* 
*/
#include "ejercicio2.h"
#include <iostream>

void ejercicio2::programa()
{
	ArchivoTxt* archivo = new ArchivoTxt("data_ejercicio2.txt");
	Lista* l = new Lista();
	//se implementó el metodo en Clase ArchivoTxt
	//ver desde comentario "agregado en parcial"
	archivo->leerOrdenado(l);
	delete archivo;
	Pila* p = cargarPila(l);
	Cola* c = cargarCola(l);
	std::cout << "Lista\n";
	l->mostrar();
	std::cout << "\n\nPila\n";
	while (!p->pilaVacia()) {
		std::cout << "Nodo: " << p->extraer()->info<<std::endl;
	}
	std::cout << "\n\nCola\n";
	while (!c->colaVacia()) {
		std::cout << "Nodo: " << c->extraer()->info<<std::endl;
	}
}
//carga una pila a partir de una lista
Pila* ejercicio2::cargarPila(Lista* l)
{
	Pila* p = new Pila();
	int dato = l->getRaiz()->info;
	//recorre la lista buscando los elementos pares
	while (l->buscar(dato)->sig != nullptr) {
		//inserta los elementos pares en la pila
		if (dato % 2 == 0) {
			p->insertar(dato);
		}
		dato = l->buscar(dato)->sig->info;
	}
	//carga el ultimo elemento si es par
	if (dato % 2 == 0) {
		p->insertar(dato);
	}
	return p;
}

//carga una cola a partir de una lista
Cola* ejercicio2::cargarCola(Lista* l)
{
	Cola* c = new Cola();
	int dato = l->getRaiz()->info;
	//recorre la lista buscando valores menores a 10
	while (l->buscar(dato)->sig != nullptr) {
		//inserta los valores menores a 10
		if (dato < 10)
			c->insertar(dato);
		dato = l->buscar(dato)->sig->info;
	}
	//inserta el ultimo elemento si es menor a 10
	if (dato < 10)
		c->insertar(dato);
	return c;
}


