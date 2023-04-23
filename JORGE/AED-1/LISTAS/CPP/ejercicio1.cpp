#include "ejercicio1.h"
#include <iostream>
#include <cctype>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

#define ESC (char)27//Defino la tecla escape por su codigo ASCII

void ejercicio1::ejercicio()
{
	Lista* lista = CargarLista();
	cout << "\n\nLista:\n";
	lista->mostrar();
}

//Retorna el dato ingresado de tipo INT
int ejercicio1::ingresarDatos()
{
	string dato;
	do {
		cout << "\nIngrese un numero: ";
		try {
			cin >> dato;
			//Intenta convertir el dato a int y retornarlo
			//Si no se puede convertir arroja una excepción que la captura el catch
			return stoi(dato);
		}
		catch (exception e) {
			//Si por error no se ingresa un numero despliega el mensaje
			//Y se pide nuevamente un ingreso de datos
			cout << "\n\nSOLO NUMEROS!\n\n";
		}
	} while (true);
}

//Procedimiento para cargar una lista
Lista* ejercicio1::CargarLista()
{
	//instancio la lista
	Lista* list = new Lista();
	do {
		system("cls");//Borrar pantalla
		if (terminar()) break;//Se fija si aprieto ESC, si se aprieta termina la carga
		list->insertar(ingresarDatos());//ingresa un dato y lo inserta en la lista
	} while (true);//El ciclo solo termina si se aprieta ESC
	return list;
}

//Retorna TRUE si se aprieta ESC
bool ejercicio1::terminar()
{
	cout << "Para terminar presione ESC";

	//Muestra la cuenta regresiva
	//tiempo para apretar ESC
	for (int i = 3; i > 0; i--) {
		Sleep(333);
		cout << " "<< i;
		for (int j = 0; j < 3; j++) {
			Sleep(333);
			cout << ".";
		}
		//si durante esta cuenta se aprieta escape se retorna true
		if (_kbhit())//si se aprieta el teclado..
			if (_getch() == ESC)//si la tecla apretada es ESC
				return true;
	}
	return false;
}
