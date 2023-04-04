/*
* 
* AED 1 2023
* TP Punteros
* Iriarte Jorge
* 
* 10. Se pide crear un programa que haciendo uso de la reserva dinámica de memoria
* almacene un número determinado de valores (n) obtenidos de forma aleatoria,
* entre 0 y 100 y los ordene de mayor a menor
* 
*/
#include <iostream>
using namespace std;
void ordenar(int* arr,int tam);
void mostrar(int* arr, int tam);

int main()
{
    srand(time(NULL));
    int* arreglo, cant;
    cout << "Ingrese cantidad de elementos: ";
    cin >> cant;
    arreglo = new int[cant];
    for (int i = 0; i < cant; i++) {
        arreglo[i] = rand() % 101;
    }
    cout << "Arreglo sin ordenar\n\n";
    mostrar(arreglo, cant);
    ordenar(arreglo, cant);
    cout << "\nArreglo ordenado\n\n";
    mostrar(arreglo, cant);
}

void ordenar(int* arr, int tam)
{
    int* aux = new int;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam-1; j++) {
            if (arr[j] < arr[i]) {
                //ordenar arr
                *aux = arr[i];
                arr[i] = arr[j];
                arr[j] = *aux;
            }
        }
    }
    delete aux;
}

void mostrar(int* arr, int tam)
{
    for (int i = 0; i < tam; i++)
        cout << i << " " << arr[i] << endl;
}
