#include "ejercicio3.h"
#include "ArchivoTxt.h"
#include <iostream>

using namespace std;

void ejercicio3::programa()
{
	ArchivoTxt* archivo = new ArchivoTxt("data_ejercicio3.txt");
	Lista* l1 = new Lista();
	Pila* p = new Pila();
	Cola* c = new Cola();
	archivo->leer(l1);//lee y carga la lista desde archivo una lista
	delete archivo;
	//recorre la lista
	//carga los pares en una pila y los impares en una cola
	int dato = l1->getRaiz()->info, aux;
	while (l1->buscar(dato)->sig != nullptr) {
		aux = l1->buscar(dato)->sig->info;
		if (dato != 0) {
			if (dato % 2 == 0)
				p->insertar(dato);
			else
				c->insertar(dato);
		}
		l1->eliminar(dato);//voy eliminando datos de la lista, para no tener problemas de nodos con el mismo dato
		dato = aux;
	}
	//hace lo mismo con el ultimo elemento
	dato = l1->getLast()->info;
	if (dato != 0) {
		if (dato % 2 == 0)
			p->insertar(dato);
		else
			c->insertar(dato);
	}
	cout << "Pila:\n";
	while (!p->pilaVacia()) {
		cout << "Nodo: " << p->extraer()->info<<endl;
	}
	cout << "Cola:\n";
	while (!c->colaVacia()) {
		cout << "Nodo: " << c->extraer()->info << endl;
	}
}
