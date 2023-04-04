/*
* 
* AED 1 2023
* TP Punteros Ejercicio 8
* Iriarte Jorge
* 
* Realice un programa que permita ingresar una cadena de caracteres de máximo
* 50 elementos, la envíe como parámetro a una función que utilizando punteros y
* retorne el número de vocales minúsculas que contiene la cadena.

*/
#include <iostream>
#include<string>
using namespace std;
int cantVocalMinusculas(string& texto);
bool isVocal(char c);
int main() {
	//char txt1[50];
	//cin.getline(txt1, 50);
	string txt;
	cout << "ingrese texto: ";
	getline(cin,txt);
	txt = txt.size() > 50 ? txt.substr(0, 50) : txt;
	cout << "La cantidad de minusculas es: " << cantVocalMinusculas(txt);
}

int cantVocalMinusculas(string& texto)
{
	int contador = 0;
	for (int i = 0; i < texto.length(); i++) {
		contador += isVocal(texto[i]);
	}
	return contador;
}

bool isVocal(char c)
{
	return c=='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
