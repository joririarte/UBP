#include "ejercicio7.h"
#include <iostream>
using namespace std;

void ejercicio7::programa()
{
	ArchivoTxt* archivo = new ArchivoTxt("data_ejercicio7.txt");
	Pila* p = new Pila();
	Lista* l = new Lista();
	Cola* c = new Cola();
	archivo->leer(p);//lee y carga una cola desde archivo
	cout << "Pila\n";//muestra la pila (pero la vacia)
	while (!p->pilaVacia()) {
		cout << "Nodo: " << p->extraer()->info << endl;
	}
	//vuelve a cargar la misma pila
	archivo->leer(p);
	delete archivo;
	//crea la lista ordenada a partir de la pila
	crearListaOrdenada(p, l);
	//inserta la lista en la cola
	while (!l->listaVacia()) {
		c->insertar(l->getRaiz()->info);
		l->eliminar(l->getRaiz()->info);
	}
	delete l;
	cout << "\nCola\n";
	while (!c->colaVacia()) {
		cout << "Nodo: " << c->extraer()->info << endl;
	}
}

void ejercicio7::crearListaOrdenada(Pila* pil, Lista* list)
{
	int dato;
	list->insertar(pil->extraer()->info);
	while (!pil->pilaVacia()) {
		dato = pil->extraer()->info;
		if (dato < list->getRaiz()->info)
			list->insertarAntes(dato);
		else if (dato > list->getLast()->info)
			list->insertar(dato);
		else {
			int dAux = list->getRaiz()->info;
			while (list->buscar(dAux)->sig != nullptr) {
				if (dAux > dato) {
					list->insertarEntre(dato, list->buscar(list->buscar(dAux))->info);
					break;
				}
				dAux = list->buscar(dAux)->sig->info;
				if (list->buscar(dAux)->sig == nullptr && dAux > dato) {
					list->insertarEntre(dato, list->buscar(list->buscar(dAux))->info);
				}
			}
		}
	}
}
