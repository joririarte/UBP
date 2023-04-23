#include "ejercicio6.h"
#include "ejercicio5.h"
#include "ejercicio1.h"
#include <iostream>

using namespace std;

void ejercicio6::ejercicio()
{
	//inicio semilla aleatoria
	srand(time(NULL));
	Lista* lista1, * lista2,*listaSuma;
	unsigned int cant;
	//ingreso de cantidad de elementos
	cout << "Cantidad de elementos de la lista";
	cant = ejercicio1::ingresarDatos();

	//se crean las listas con numeros aleatorios
	lista1 = ejercicio5::crearLista(cant);
	lista2 = ejercicio5::crearLista(cant);

	//se muestras las listas
	cout << "\n\nLista 1:\n";
	lista1->mostrar();
	cout << "\n\nLista 2:\n";
	lista2->mostrar();

	//se crea la lista suma y se muestra
	cout << "\n\nLista Suma:\n";
	sumaNodo(lista1, lista2)->mostrar();
}

Lista* ejercicio6::sumaNodo(Lista* l1, Lista* l2)
{
	//instancia una nueva lista
	Lista* res = new Lista();
	//obtiene el contenido del primer nodo de cada lista
	int d1 = l1->getRaiz()->info;
	int d2 = l2->getRaiz()->info;
	
	//los suma
	int dato = d1 + d2;

	//inserta los elementos
	res->insertar(dato);

	//recorro la lista hasta que alguna se acabe
	while (l1->buscar(d1)->sig != nullptr &&
		   l2->buscar(d2)->sig != nullptr) 
	{
		//obtengo el contenido del siguiente nodo
		d1 = l1->buscar(d1)->sig->info;
		d2 = l2->buscar(d2)->sig->info;
		//sumo los datos
		dato = d1 + d2;
		//los inserto en la nueva lista
		res->insertar(dato);
	}
	//la lista resultante tendra el tamaño de la lista mas chica
	return res;
}
