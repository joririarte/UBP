/*
* 
* AED 1 2023
* Iriarte Jorge
* Realizar el calculo de la superficie de un triangulo
* 
*/
#include<iostream>
#include "triangulo.h"
using namespace std;
int main() {
	float lados[3];
	cout << "Calculo del area de un triangulo\n";
	for (int i = 0; i < 3; i++) {
		cout << "\nIngrese lado " << i+1 << ": ";
		cin >> lados[i];
	}
	triangulo* t = new triangulo(lados[0], lados[1], lados[2]);
	cout << "\n\nLa superficie del triangulo es: " << t->getSuperficie()<<endl<<endl;
	delete t;
}