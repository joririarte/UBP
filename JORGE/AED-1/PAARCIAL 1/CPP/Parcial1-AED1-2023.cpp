/*
* PARCIAL 1 AED 2023
* IRIARTE JORGE
*/

#include <iostream>
#include "ejercicio1.h"
#include "ejercicio2.h"
using namespace std;

int main()
{
	int op;
	do {
		system("cls");
		cout << "Menu\n";
		cout << "\n1- Ejercicio 1";
		cout << "\n2- Ejercicio 2";
		cout << "\n0- Salir";
		cout << "\n\nOpcion: ";
		cin >> op;
		cout << endl;
		switch (op)
		{
		case 1:
			ejercicio1::programa();
			break;
		case 2:
			ejercicio2::programa();
			break;
		}
		cout << endl;
		system("pause");
	} while (op != 0);
	return 0;
}