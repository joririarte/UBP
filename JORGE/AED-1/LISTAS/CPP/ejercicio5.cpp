#include "ejercicio5.h"
#include "ejercicio1.h"
#include<iostream>
using namespace std;
void ejercicio5::ejercicio()
{
	//semilla para numeros aleatorios
	srand(time(NULL));
	//Punteros a listas
	Lista* lista;

	//cantidad de elementos de la lista
	cout << "Cantidad de elementos de la lista: ";
	//crea la lista 1 de elementos
	lista = crearLista(ejercicio1::ingresarDatos());
	//muestra la lista
	cout << "\n\nLista 1:\n\n";
	lista->mostrar();

	//Crea la lista invertida y la muestra
	cout << "\n\nLista 2 (lista 1 invertida)\n\n";
	invertir(lista)->mostrar();
}

//Crea una lista de n elementos
Lista* ejercicio5::crearLista(unsigned int n)
{
	Lista* li = new Lista();
	for (int i = 0; i < n; i++) {
		//inserta un numero aleatorio entre 1 y 100 en la lista
		li->insertar(rand() % 100 + 1);
	}
	return li;
}

Lista* ejercicio5::invertir(Lista* li)
{
	//Instancio una lista
	Lista* inv = new Lista();
	//obtengo el contenido del primer nodo
	int dato = li->getRaiz()->info;
	//inserto antes el primer nodo
	inv->insertarAntes(dato);
	//recorro la lista hasta el ultimo nodo
	while (li->buscar(dato)->sig != nullptr) {
		//obtengo el contenido del siguiente elemento
		dato = li->buscar(dato)->sig->info;
		//inserto el dato
		inv->insertarAntes(dato);
	}
	return inv;
}
