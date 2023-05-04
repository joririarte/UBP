/*
* PARCIAL 1 AED 2023
* IRIARTE JORGE
* 
* EJERCICIO 1
* 
* Realizar un programa que permita:
* Cargar una Pila con los siguientes datos: [23,22,45,40,76,44,39,41,17]
* Determinar el promedio de los elementos cargados en la pila. 
* (La pila se debe mantener) 
* Cargar una lista con los elementos de la pila que superen el promedio en +-10% . 
* (Dejar en la pila los elementos que quedan fuera de rango)
* Mostrar Pila y Lista después de realizar las operaciones detalladas. 
* 
*/
#include "ejercicio1.h"
#include <iostream>
#include <cmath>
using namespace std;

void ejercicio1::programa()
{
	ArchivoTxt* archivo = new ArchivoTxt("data_ejercicio1.txt");
	Pila* p = new Pila();
	Lista* l = new Lista();
	//Se leen los datos desde archivo y se cargan en la pila
	archivo->leer(p);
	delete archivo;
	//se crea la lista teniendo en cuenta el promedio
	cargarLista(p, l);

	//se muestra la pila y la lista
	cout << "PILA\n";
	while (!p->pilaVacia()) {
		cout << "Nodo: " << p->extraer()->info<<endl;
	}
	cout << "\n\nLISTA\n";
	l->mostrar();
}

//calcula el promedio
float ejercicio1::promedio(Pila* p)
{
	Pila* pAux = new Pila();
	int dato, suma = 0, cant = p->size();
	while (!p->pilaVacia()) {
		dato = p->extraer()->info;
		suma += dato;			//suma los elementos de la pila y calcula el promedio
		pAux->insertar(dato);	//salva los elementos de la pila en una pila auxiliar
	}
								//vuelca la pila auxiliar sobre la pila original
	while (!pAux->pilaVacia()) {
		p->insertar(pAux->extraer()->info);
	}
	delete pAux;
	return (float)suma/cant;	//devuelve el promedio
}
//carga la lista
void ejercicio1::cargarLista(Pila* p, Lista* l)
{
	//usa una pila auxiliar para salvar datos de la pila original
	Pila* pAux = new Pila();
	int dato;
	float prom = promedio(p);
	while (!p->pilaVacia()) {
		dato = p->extraer()->info;
		//inserta en la pila los datos fuera del rango del 10% del promedio
		if (abs(dato - prom) > prom * 0.1f) {
			l->insertar(dato);
		}
		else//salva el resto en la pila auxiliar
			pAux->insertar(dato);
	}
	//vuelca la pila auxiliar sobre la original
	while (!pAux->pilaVacia()) {
		p->insertar(pAux->extraer()->info);
	}
	delete pAux;
}
