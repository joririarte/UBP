/*
* 
* AED 1 2023
* Iriarte Jorge
* TP TAD Listas
* 
*/
#include <iostream>
#include "Lista.h"
#include "ejercicio1.h"
#include "ejercicio2.h";
#include "ejercicio3.h"
#include "ejercicio4.h"
#include "ejercicio5.h"
#include "ejercicio6.h"
#include <string>
using namespace std;

int main()
{
	do {
		system("cls");
		cout << "Menu\n";
		cout << "\n1- Ejercicio 1";
		cout << "\n2- Ejercicio 2";
		cout << "\n3- Ejercicio 3";
		cout << "\n4- Ejercicio 4";
		cout << "\n5- Ejercicio 5";
		cout << "\n6- Ejercicio 6";
		cout << "\n7- Salir\n";
		switch (ejercicio1::ingresarDatos()) {
		case 1:
			ejercicio1::ejercicio();
			break;
		case 2:
			ejercicio2::ejercicio();
			break;
		case 3:
			ejercicio3::ejercicio();
			break;
		case 4:
			ejercicio4::ejercicio();
			break;
		case 5:
			ejercicio5::ejercicio();
			break;
		case 6:
			ejercicio6::ejercicio();
			break;
		case 7:
			return 0;
			break;
		default:
			cout << "Ingrese una opcion Correcta!\n\n";
		}
		system("pause");
	} while (true);
}
