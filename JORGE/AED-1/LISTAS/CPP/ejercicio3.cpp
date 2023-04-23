#include "ejercicio3.h"
#include "Lista.h"
#include "ejercicio1.h"
#include <iostream>

using namespace std;

void ejercicio3::ejercicio()
{
	Lista* lista = new Lista();
	unsigned short op;
	do {
		system("cls");
		cout << "Menu\n";
		cout << "\n1 - Insertar al final";
		cout << "\n2 - Insertar al inicio";
		cout << "\n3 - Insertar entre";
		cout << "\n4 - Buscar";
		cout << "\n5 - Modificar";
		cout << "\n6 - Eliminar";
		cout << "\n7 - Mostrar lista";
		cout << "\n8 - Salir";
		cout << "\n\nOpcion: ";
		cin >> op;
		if (op == 8) break;
		else
			switch (op)
			{
			case 1://Insertar al final	
				//Se invoca al ingresarDatos del ejercicio 1
				lista->insertar(ejercicio1::ingresarDatos());
				break;
			case 2://Insertar Antes
				//Se invoca al ingresarDatos del ejercicio 1
				lista->insertarAntes(ejercicio1::ingresarDatos());
				break;
			case 3://Insertar Entre
			//se define un scope entre llaves 
			//para declarar variables que solo servirán aquí
			{
				int* dato = new int;
				int* anterior = new int;

				//ingresa un par de datos
				ingresarDatos(anterior, dato);

				//inserta el dato despues del anterior y antes del nuevo
				lista->insertarEntre(*dato, *anterior);
				delete dato, anterior;
				break;
			}
			case 4://Buscar
			//se define un scope entre llaves 
			//para declarar variables que solo servirán aquí
			{
				int* dato = new int;
				
				//Se invoca al ingresarDatos del ejercicio 1
				*dato = ejercicio1::ingresarDatos();
				
				//Busca el dato y si lo encuentra lo muestra
				if (lista->buscar(*dato) != nullptr)
					cout << "\nSe encontro el numero: " << lista->buscar(*dato)->info << endl;
				else
					cout << "\nEl nodo no existe!\n";
				delete dato;
				break;
			}
			case 5://Modificar
			//se define un scope entre llaves 
			//para declarar variables que solo servirán aquí
			{
				int* n = new int;
				int* v = new int;
				//ingresa un par de datos
				ingresarDatos(v, n);
				//modifica el dato en la lista
				lista->modificar(*v, *n);
				delete n, v;
				break;
			}
			case 6://Eliminar
				//Intenta eliminar el dato, 
				//si el método devuelve false muestra un error
				if (!lista->eliminar(ejercicio1::ingresarDatos()))
					cout << "\nError al eliminar el elemento!\n";
				break;
			case 7://Mostrar
				//muestra la lista
				lista->mostrar();
				break;
			default:
				cout << "\nIngrese una opcion correcta!\n";
				break;
			}
		system("pause");
	} while (op > 0 && op < 8);
	delete lista;
}

//Ingresa un par de datos
void ejercicio3::ingresarDatos(int* datoV, int* datoN)
{
	cout << "\nNumero Anterior:";
	//Se invoca al ingresarDatos del ejercicio 1
	*datoV = ejercicio1::ingresarDatos();
	cout << "\nNumero Nuevo:";
	//Se invoca al ingresarDatos del ejercicio 1
	*datoN = ejercicio1::ingresarDatos();
}
