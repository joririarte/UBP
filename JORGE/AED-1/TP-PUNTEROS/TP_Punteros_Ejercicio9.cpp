/*
* 
* AED 1 2023
* TP Punteros
* Iriarte Jorge
* 
* Definir un arreglo unidimensional de N componentes enteras de modo que la
* gestión de memoria sea dinámica utilizando new. Ingresar los datos en el vector.
* Mostrar el contenido del vector en dos modos: usando notación vectorial y luego
* usando aritmética de punteros.
* 
*/
#include <iostream>
#include<ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	int* arreglo, n;
	cout << "Ingrese cantidad de elementos: ";
	cin >> n;
	arreglo = new int[n];
	for (int i = 0; i < n; i++) {
		arreglo[i] = rand() % 100 + 1;
	}
	cout << "\nNotacion vectorial\n\n";
	for (int i = 0; i < n; i++) {
		cout << i << " " << arreglo[i]<<endl;
	}
	cout << "\nNotacion aritmetica de punteros\n\n";
	for (int i = 0; i < n; i++) {
		cout << i << " " << *(arreglo + i) << endl;
	}
}