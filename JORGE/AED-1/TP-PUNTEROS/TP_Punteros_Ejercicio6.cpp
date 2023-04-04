/*
*
* AED 1 2023
* TP Punteros Ejercicio 6
* Iriarte Jorge
*
* 6. Realizar un programa que ingrese una cadena de caracteres de máximo 50
* elementos y la envíe como parámetro a una función que maneje punteros
* de modo que la función invierta la cadena.
* 
*/
#include<iostream>
#include<string>
using namespace std;
void invertir(string& cad);
int main() {
	string cadena;
	cout << "Ingrese una cadena: ";
	getline(cin,cadena);
	cadena = cadena.size() > 50 ? cadena.substr(0, 50) : cadena;
	invertir(cadena);
	cout << "La cadena invertida es: " << cadena;
}

void invertir(string& cad)
{
	char* aux = new char[cad.size()];
	for (int i = 0; i < cad.size(); i++) {
		aux[cad.size() - 1 - i] = cad[i];
	}
	for (int i = 0; i < cad.size(); i++) {
		cad[i] = aux[i];
	}
	delete[] aux;
}
