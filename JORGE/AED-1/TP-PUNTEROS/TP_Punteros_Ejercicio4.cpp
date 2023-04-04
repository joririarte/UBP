/*
*
* AED 1 2023
* TP Punteros Ejercicio 4
* Iriarte Jorge
* 
* 4. Realizar un programa que rellene de forma aleatoria con los primeros 100
* números un arreglo de 15 elementos. Mostrar por medio de punteros los valores
* en el vector y la dirección de memoria de cada uno.
*
*/
#include <iostream>
#include <ctime>
using namespace std;
int main() {
	srand(time(NULL));
	int num[15];
	cout.width(10);
	cout << "Posicion";
	cout.width(10);
	cout << "Valor";
	cout.width(20);
	cout << "Direccion Memoria"<<endl;
	for (int i = 0; i < 15; i++) {
		num[i] = rand() % 100 + 1;
		cout.width(10);
		cout << i;
		cout.width(10);
		cout << *(num + i);
		cout.width(20);
		cout << num + i<<endl;
	}
}