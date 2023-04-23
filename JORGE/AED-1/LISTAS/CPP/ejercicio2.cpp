#include "ejercicio2.h"
#include "ejercicio1.h";
#include <iostream>

void ejercicio2::ejercicio()
{
	//Crea la lista con el procedimiento del ejercicio 1
	Lista* lista = ejercicio1::CargarLista();
	std::cout << "\n\nLISTA\n\n";
	lista->mostrar();
	std::cout << "\n\nESTADISTICAS\n\n";
	std::cout << "\nLa suma de los elementos es: " << suma(lista);
	std::cout << "\nLa media de los elementos es: " << media(lista);
	std::cout << "\nEl maximo elemento en la lista es: " << maxElement(lista);
	std::cout << "\nEl minimo elemento en la lista es: " << minElement(lista) << std::endl;
}

//Suma los elementos de la lista
int ejercicio2::suma(Lista* li)
{
	//uso la informacion de cada nodo para recorrer la lista
	int nodo = li->getRaiz()->info;
	int sum = nodo;
	//recorro la lista buscando por la informacion si el nodo apunta a nada
	while (li->buscar(nodo)->sig != nullptr) {
		nodo = li->buscar(nodo)->sig->info;
		sum += nodo;
	}
	return sum;
}

//Saco la media de la lista
float ejercicio2::media(Lista* li)
{
	return (float)suma(li)/li->size();
}

//busco el elemento maximo
int ejercicio2::maxElement(Lista* li)
{
	int max = li->getRaiz()->info;
	int siguiente = max;
	while (li->buscar(siguiente)->sig != nullptr) {
		siguiente = li->buscar(siguiente)->sig->info;
		//si el elemento siguiente es mayor al maximo actual
		//cambio el maximo actual
		max = siguiente > max ? siguiente : max;
	}
	return max;
}

//busco el elemento minimo
int ejercicio2::minElement(Lista* li)
{
	int min = li->getRaiz()->info;
	int siguiente = min;
	while (li->buscar(siguiente)->sig != nullptr) {
		siguiente = li->buscar(siguiente)->sig->info;
		//si el elemento siguiente es mayor al minimo actual
		//cambio el minimo actual
		min = siguiente < min ? siguiente : min;
	}
	return min;
}
