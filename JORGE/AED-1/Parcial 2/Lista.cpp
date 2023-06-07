#include "Lista.h"
#include <iostream>

//constructor de lista
Lista::Lista()
{
	raiz = nullptr;
}

//destructor
Lista::~Lista()
{
	
}

//Inserta un dato al final de la lista
void Lista::insertar(Mediciones* data)
{
	//si la lista esta vacia 
	//el puntero raiz apuntará al nuevo nodo
	if (raiz == nullptr)
		raiz = new Nodo(data);
	//si la lista no está vacia
	//se obtiene el último elemento y se hace que apunte al nuevo elemento
	else
		getLast()->sig = new Nodo(data);
}
//check
//muestra la lista
void Lista::mostrar()
{
	//muestra la lista si no esta vacia
	if (raiz != nullptr) {
		//Se utiliza un puntero para recorrer la lista
		//se lo inicializa en la raiz
		Nodo* recorrido = raiz;
		int i = 1;
		//se recorre la lista hasta que recorrido apunte a nullptr 
		//(final de la lista)
		std::cout << "Material \t\t ComponenteID \t\t Medicion \n";
		while (recorrido != nullptr) {
			recorrido->info->mostrar();
			i++;
			//se cambia el puntero hacia el siguiente en la lista
			recorrido = recorrido->sig;
		}
	}
	else std::cout << "\nLista vacia!\n";
}

//Obtiene el ultimo nodo en la lista
Lista::Nodo* Lista::getLast()
{
	//Recorro la lista con un puntero hasta el último no vacío
	Nodo* recorrido = raiz;
	while (recorrido->sig != nullptr)
		recorrido = recorrido->sig;
	return recorrido;
}

//Obtiene la raiz de la lista
Lista::Nodo* Lista::getRaiz()
{
	return raiz;
}

//Obtiene el tamaño de la lista
int Lista::size()
{
	//Recorre la lista contando cada nodo hasta el final
	Nodo* recorrido = raiz;
	int cant = 0;
	while (recorrido != nullptr) {
		cant++;
		recorrido = recorrido->sig;
	}
	return cant;
}

//busca el nodo que contiene un dato
Lista::Nodo* Lista::buscar(char material)
{
	Nodo* rec = raiz;
	//recorre la lista hasta encontrar el nodo
	while (rec != nullptr) {
		if (rec->info->getMaterial() == material)
			return rec;
		rec = rec->sig;
	}
	//si termina toda la lista sin retornar, 
	//entonces retorna nullptr, no encontro el dato
	return nullptr;
}

//busca el nodo anterior
Lista::Nodo* Lista::buscar(Nodo* n)
{
	Nodo* rec = raiz;
	//recorre la lista hasta encontrar el nodo anterior
	while (rec != nullptr) {
		if (rec->sig == n)
			return rec; //retorna el nodo anterior
		rec = rec->sig;
	}
	//si no hay nodo anterior retorna nullptr
	return nullptr;
}

//elimina un nodo retorna true en caso de exito, false en caso de error
bool Lista::eliminar(char material)
{
	//busca el nodo que contiene el dato
	Nodo* n = buscar(material);
	//si lo encuentra
	if (n != nullptr) {
		//si el nodo es distinto a la raiz
		//el anterior apuntará al siguiente
		if (n != raiz)
			buscar(n)->sig = n->sig;
		else
			//si el nodo es el primero, la raiz apuntará al que seguía
			raiz = n->sig;
		return true;
	}
	return false;
}

bool Lista::listaVacia()
{
	return raiz == nullptr;
}

void Lista::recorrer(void(*func)(Mediciones*,HashTable*), HashTable*hsh)
{
	Nodo* rec = raiz;
	//recorre la lista hasta encontrar el nodo anterior
	while (rec != nullptr) {
		func(rec->info,hsh);
		rec = rec->sig;
	}
}

//Constructor de nodo con parametro data
Lista::Nodo::Nodo(Mediciones* data)
{
	info = data;
	sig = nullptr;
}

Lista::Nodo::Nodo(){}
