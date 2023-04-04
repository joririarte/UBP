/*
* 
* AED 1 2023
* TP Punteros Ejercicio 7
* Iriarte Jorge
* 
* Obtener una función copia que utilice punteros para copiar una cadena en otra.
* 
*/
#include<iostream>
#include<string>
using namespace std;
string copia(string* cad);
int main() {
	string txt, txt_copia;
	cout << "ingrese texto: ";
	getline(cin,txt);
	txt_copia = copia(&txt);
	cout << txt_copia;
}

string copia(string* cad)
{
	return *cad;
}
