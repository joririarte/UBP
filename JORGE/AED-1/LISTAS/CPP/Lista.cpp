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
void Lista::insertar(int data)
{
	//si la lista esta vacia 
	//el puntero raiz apuntará al nuevo nodo
	if (raiz == nullptr)
		raiz = new Nodo(data);
	//si la lista no está vacia
	//se verifica que el dato que se quiere ingresar no está en la lista
	//se obtiene el último elemento y se hace que apunte al nuevo elemento
	else if (buscar(data) == nullptr)
		getLast()->sig = new Nodo(data);
}

//Inserta un dato al principio de la lista
void Lista::insertarAntes(int data)
{
	//Si la lista está vacia
	//El puntero raiz apuntará al nuevo nodo
	if (raiz == nullptr)
		raiz = new Nodo(data);
	//si la lista no está vacia
	//se verifica que el dato que se quiere ingresar no está en la lista
	//Se cambia el puntero raíz hacia el nuevo nodo
	//y el nuevo nodo apuntará a donde apuntaba raiz
	else if (buscar(data) == nullptr)
		raiz = new Nodo(data, raiz);
}

//Inserta un dato en medio de la lista
void Lista::insertarEntre(int data, int anterior)
{
	//Solo si la lista tiene contenido
	if (raiz != nullptr)
		//se verifica que el dato que se quiere ingresar no está en la lista
		//se busca el elemento anterior de donde se quiere insertar
		//se cambia su apuntado hacia el nuevo nodo
		//y el nuevo nodo apunta hacia donde apuntaba el anterior
		if (buscar(data) == nullptr)
			buscar(anterior)->sig = new Nodo(data, buscar(anterior)->sig);
}

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
		while (recorrido != nullptr) {
			std::cout << "Nodo " << i << ": " 
					  << recorrido->info << std::endl;
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
Lista::Nodo* Lista::buscar(int dato)
{
	Nodo* rec = raiz;
	//recorre la lista hasta encontrar el nodo
	while (rec != nullptr) {
		if (rec->info == dato)
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
		if (rec->sig != n)
			return rec; //retorna el nodo anterior
		rec = rec->sig;
	}
	//si no hay nodo anterior retorna nullptr
	return nullptr;
}

//modifica un nodo
void Lista::modificar(int datoViejo,int datoNuevo)
{
	//busca el nodo que se quiere cambiar
	Nodo* n = buscar(datoViejo);
	//si lo encuentra modifica el dato
	if (n != nullptr) 
		n->info = datoNuevo;
}

//elimina un nodo retorna true en caso de exito, false en caso de error
bool Lista::eliminar(int dato)
{
	//busca el nodo que contiene el dato
	Nodo* n = buscar(dato);
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

//Constructor de nodo con parametro data
Lista::Nodo::Nodo(int data)
{
	info = data;
	sig = nullptr;
}
//Constructor de nodo con Parametro data y nodo siguiente
Lista::Nodo::Nodo(int data, Nodo* n)
{
	info = data;
	sig = n;
}


Lista::Nodo::Nodo(){}
