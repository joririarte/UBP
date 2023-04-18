#include "Interfaces.h"
#include <iostream>
using namespace std;
void interfaces::menu()
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
				lista->insertar(ingresarDatos());
				break;
			case 2://Insertar Antes
				lista->insertarAntes(ingresarDatos());
				break;
			case 3://Insertar Entre
				break;
			case 4://Buscar
				lista->buscar(ingresarDatos());
				break;
			case 5://Modificar
				break;
			case 6://Eliminar
				break;
			case 7://Mostrar
				lista->mostrar();
				break;
			default:
				cout << "\nIngrese una opcion correcta!\n";
				break;
			}
		system("pause");
	} while (op > 0 && op < 8);
}

int interfaces::ingresarDatos()
{
	int dato;
	cout << "\nIngrese un numero: ";
	cin >> dato;
	return dato;
}
