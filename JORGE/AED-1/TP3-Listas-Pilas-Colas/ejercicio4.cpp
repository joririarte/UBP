#include "ejercicio4.h"
#include "ArchivoTxt.h"
#include <iostream>
using namespace std;

void ejercicio4::programa()
{
	ArchivoTxt* archivo = new ArchivoTxt("data_ejercicio4.txt");
	Pila* p = new Pila();
	ListaDoble* ld = new ListaDoble();
	archivo->leer(p);//lee y carga la pila desde archivo
	delete archivo;
	//extrae los elementos de la pila y los carga en la lista
	//de manera invertida
	while (!p->pilaVacia()) {
		ld->insertarAntes(p->extraer()->info);
	}
	ld->mostrar();
}
