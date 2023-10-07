#include <iostream>
#include"Monticulo-Enteros.h"
#include"Monticulo-Paises.h"
using namespace std;

int main()
{
	char op;
	do {
		system("cls");
		
		cout << "Monticulos";
		cout << "\n1 - Implementacion enteros";
		cout << "\n2 - Implementacion Paises";
		cout << "\n0 - Salir";
		cout << "\nOpcion: ";
		cin >> op;
		system("cls");
		switch (op)
		{
		case '0': break;
		case '1':
			enteros::programa();
			break;
		case '2':
			paises::programa();
			break;
		default:
			cout << "Ingresa un opcion del menu!\n\n";
			break;
		}
		
		system("pause");

	} while (op != '0');
	
	return 0;
}
