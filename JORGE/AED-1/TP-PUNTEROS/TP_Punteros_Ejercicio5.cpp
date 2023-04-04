/*
*
* AED 1 2023
* TP Punteros Ejercicio 5
* Iriarte Jorge
*
* 5. Ingresar una cadena de caracteres de longitud máxima 10, enviarla como
* parámetro a una función que maneje punteros de modo que retorne la misma
* cadena de caracteres, pero en mayúsculas.
*
*/
#include <iostream>
using namespace std;
void toUpperString(char* cadena,short tam);
int main() {
	char cadena[10];
	cout << "Ingrese texto: ";
	cin.getline(cadena, 10);
	cout << "\nCadena sin procesar: " << cadena;
	cout << "\nCadena procesada: ";
	toUpperString(cadena, 10);
}

void toUpperString(char* cadena, short tam)
{
	for (int i = 0; i < tam; i++){
		cout << (char)toupper(cadena[i]);
	}
}
