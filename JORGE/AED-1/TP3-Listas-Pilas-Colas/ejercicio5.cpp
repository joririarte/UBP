#include "ejercicio5.h"
#include <iostream>
using namespace std;

void ejercicio5::programa()
{
	ArchivoTxt* archivo = new ArchivoTxt("data_ejercicio5.txt");
	Cola* c = new Cola();
	Lista* l = new Lista();
	archivo->leer(c);//lee ya carga una cola desde archivo
	delete archivo;
	//crea una lista ordenada
	crearListaOrdenada(c, l);
	l->mostrar();
}

void ejercicio5::crearListaOrdenada(Cola* col, Lista* list)
{
	int dato;
	//inserta el primer elemento de la cola en la lista
	list->insertar(col->extraer()->info);
	//extrae los siguientes elementos de la cola
	while (!col->colaVacia()) {
		dato = col->extraer()->info;
		//si el dato es menor que el primero de la lista
		//lo inserta al principio
		if (dato < list->getRaiz()->info)
			list->insertarAntes(dato);
		//si es mayor que el ultimo lo inserta al final
		else if (dato > list->getLast()->info)
			list->insertar(dato);
		else {//si esta en el medio recorre la lista para determinar la ubicacion
			int dAux = list->getRaiz()->info;
			while (list->buscar(dAux)->sig != nullptr) {
				//si el elemento recorrido es mas grande que el dato a ingresar
				if (dAux > dato) {
					//inserto el dato en esa posicion, el segundo parametro es el nodo anterior
					list->insertarEntre(dato, list->buscar(list->buscar(dAux))->info);
					break;
				}
				dAux = list->buscar(dAux)->sig->info;
				//si ya llegue al final de la lista, se fija de nuevo para insertarlo antes del último
				if (list->buscar(dAux)->sig == nullptr && dAux > dato) {
					list->insertarEntre(dato, list->buscar(list->buscar(dAux))->info);
				}
			}
		}
	}
}
