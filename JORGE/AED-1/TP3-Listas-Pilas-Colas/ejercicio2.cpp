#include "ejercicio2.h"
#include "ArchivoTxt.h"
#include <iostream>

void ejercicio2::programa()
{
	Lista* l1 = new Lista();
	ArchivoTxt* archivo = new ArchivoTxt("data_ejercicio2.txt");
	archivo->leer(l1);//lee y carga la lista desde archivo
	delete archivo;
	l1->mostrar(); //muestra la lista
	std::cout << std::endl<<std::endl;
	//recorre la lista eliminando los pares
	int dato = l1->getRaiz()->info;
	int aux;
	while (l1->buscar(dato)->sig != nullptr) {
		aux = l1->buscar(dato)->sig->info;
		if (dato % 2 != 0) {
			l1->eliminar(dato);
		}
		dato = aux;
	}
	//como el ciclo anterior no llega a ver el último elemento
	//elimina el ultimo si es par
	dato = l1->getLast()->info;
	if (dato % 2 != 0)
		l1->eliminar(dato);
	l1->mostrar();
}
