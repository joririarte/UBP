/*
* 
* AED 1 2023
* TP Punteros Ejercicio 2 y 3
* Iriarte Jorge
* 
* 2. Escribir un programa que declare un arreglo de 5 enteros, y un puntero a entero.
* Comprobar que los elementos del arreglo ocupan posiciones sucesivas en
* memoria, escribiendo sus direcciones.
* 3. Para el arreglo del ejercicio anterior, declare dos punteros a entero y asigneles
* las direcciones del primer y último elemento del arreglo. Imprima la diferencia
* entre ambos punteros.

*/
#include <iostream>
using namespace std;
int main() {
	// Ejercicio 2
	int arreglo[5], * puntero;
	cout << "El tipo int tiene 4 bytes de tamanio\n";
	cout << "Por lo tanto a continuacion se veran saltos \nde a 4 bytes en las direcciones de memoria\n\n";
	for (int i = 0; i < 5; i++) {
		puntero = &arreglo[i];
		cout << "La direccion de memoria del elemento " << i << " del arreglo es: " << puntero<<endl;
	}
	// Ejercicio 3
	int* p1, * p2;
	p1 = &arreglo[0];
	p2 = &arreglo[4];
	cout << "\n\nLa diferencia entre el primer elemento y el ultimo elemento del arreglo es de " << p2 - p1 << " bytes\n\n";
}