#include <iostream>
#include "ArbolAVL.h"
#include "Lista.h"

//muestra un dato
void Mostrar(int& d, int FE);
//actualiza el arbol
void actualizarArbol(Lista* l, ArbolAVL* AVL, int& updates);
int main()
{
	//Creacion del arbolAVL
	srand(time(NULL));
	ArbolAVL* groot = new ArbolAVL();
	for (int i = 0; i < 50; i++) {
		groot->Insertar(rand() % 100 + 1);
	}
	std::cout << "Arbol Inicial\n";
	std::cout<<"Nodos: "<<groot->NumeroNodos()<<std::endl<<std::endl;
	groot->InOrden(Mostrar);
	
	//Creacion de un lote de claves
	Lista* lista_lote_claves = new Lista();
	//creo un lote de hasta entre 1 y 50 claves para actualizar
	for (int i = 0; i < rand() % 50 + 1; i++) {
		lista_lote_claves->insertar(rand() % 100 + 1, rand() % 2 + 1);
	}
	std::cout << "\n\nLote de claves\n\n";
	lista_lote_claves->mostrar();
	
	//actualizacion del arbol a partir de la lista
	int cant_updates = 0;
	actualizarArbol(lista_lote_claves, groot,cant_updates);
	std::cout << "\n\nArbol Actualizado\n\n";
	std::cout << "Nodos: " << groot->NumeroNodos() << std::endl;
	std::cout << "Cantidad de Actualizaciones: " << cant_updates << std::endl;
	groot->InOrden(Mostrar);
}

//muestra un dato
//esta funcion la utiliza el arbol
void Mostrar(int& d, int FE)
{
	std::cout << d << std::endl;
}

//actualiza un arbol segun una lista
void actualizarArbol(Lista* l, ArbolAVL* AVL, int& updates) {
	//obtiene la primer clave y operacion
	int clave = l->getRaiz()->info;
	int op = l->getRaiz()->operacion;
	//recorre la lista
	while (l->buscar(clave, op)->sig != nullptr) {
		//busca la calve de la lista en el arbol
		if (!AVL->Buscar(clave)) {
			//si no esta en el arbol y la operacion asociada a esa clave es 1
			//inserta el dato en el arbol
			if (op == 1) {
				AVL->Insertar(clave);
				updates++;
			}
		}
		//si la clave esta en el arbol y la operacion asociada a esa clave es 2,
		//elimina el dato
		else if (op == 2) {
			AVL->Borrar(clave);
			updates++;
		}
		//guarda la clave de la iteracion actual
		int claveAux = clave;
		//obtiene la clave siguiente
		clave = l->buscar(clave, op)->sig->info;
		//obtiene la operacion siguiente
		op = l->buscar(claveAux, op)->sig->operacion;
	}
	//actualiza con el ultimo elemento de la lista
	if (!AVL->Buscar(clave))
		if (op == 1)
			AVL->Insertar(clave);
		else if (op == 2)
			AVL->Borrar(clave);
}

