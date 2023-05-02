#include "ejercicio1.h"
#include "ArchivoTxt.h"

void ejercicio1::programa()
{
	int arr[3] = { 10,35,57 };
	Lista* l1 = new Lista();
	//leer y cargar una lista desde archivo
	ArchivoTxt* archivo = new ArchivoTxt("data_ejercicio1.txt");
	archivo->leer(l1);
	//agregar los valores del arreglo
	for (int i = 0; i < 3; i++)
		l1->insertar(arr[i]);
	//muestra la lista resultante
	l1->mostrar();
}
