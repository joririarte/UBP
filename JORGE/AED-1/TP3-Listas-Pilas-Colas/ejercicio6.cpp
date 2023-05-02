#include "ejercicio6.h"
#include <iostream>
using namespace std;

void ejercicio6::programa()
{
	ArchivoTxt* archivo = new ArchivoTxt("data_ejercicio6.txt");
	Lista* l1 = new Lista();
	Lista* l2 = new Lista();
	archivo->leer(l1);//lee y carga una lista desde archivo
	delete archivo;
	cout << "Lista 1\n";
	l1->mostrar();
	//recorre l1 y carga invertida l2
	int dato = l1->getRaiz()->info;
	while (l1->buscar(dato)->sig != nullptr) {
		l2->insertarAntes(dato);
		dato = l1->buscar(dato)->sig->info;
	}
	//carga el ultimo elemento
	l2->insertarAntes(l1->getLast()->info);
	cout << "\nLista 2\n";
	l2->mostrar();
}
