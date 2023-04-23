#include "ejercicio4.h"
#include "ejercicio1.h"
#include <iostream>
#include <ctime>
using namespace std;
void ejercicio4::ejercicio()
{
	//semilla nro aleatorio
	srand(time(NULL));

	//instancia dos listas
	Lista* lista = new Lista();
	Lista* lista2 = new Lista();
	unsigned int cant;
	int factor;
	
	//crea una lista con numeros aleatorios(1-100) de tamaño cant
	cout << "Cantidad de elementos en la lista";
	cant = ejercicio1::ingresarDatos();
	for (int i = 0; i < cant; i++) {
		lista->insertar(rand() % 100 + 1);
	}
	lista->mostrar();
	
	//ingreso del factor
	cout << "\n\nFactor";
	factor = ejercicio1::ingresarDatos();
	
	//	RECORDATORIO: 
	//	ALGORITMO PARA RECORRER UNA LISTA DESDE AFUERA DE ELLA
	// 
	//	NO SE PUEDE ESTABLECER UN APUNTADOR NODO* YA QUE
	//	ES UNA CLASE PRIVADA PERTENECIENTE A LA CLASE LISTA.
	//	PERO, PUEDO OBTENER EL CONTENIDO DE LOS NODOS 
	//	Y DE ESTA MANERA ITERAR ENTRE ELLOS

	//Tomo el primer elemento de la lista
	int dato = lista->getRaiz()->info;
	//inserto el elemento
	lista2->insertar(factor * dato);
	//recorro la lista
	while (lista->buscar(dato)->sig != nullptr) {
		//tomo el siguiente dato
		dato = lista->buscar(dato)->sig->info;
		//inserto en la lista 2 el dato de la lista 1
		//multiplicado por el factor
		lista2->insertar(factor * dato);
	}
	lista2->mostrar();
}
