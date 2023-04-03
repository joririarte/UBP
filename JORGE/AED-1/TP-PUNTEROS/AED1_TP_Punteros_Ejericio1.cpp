/*
*
* AED 1 2023
* TP Punteros Ejercicio 1
* Iriarte Jorge
*
*/
#include <iostream>
using namespace std;

int main()
{
    int var1 = 23, var2 = 5,*puntero;
    puntero = &var1;
    cout << "La direccion de memoria de var1 es: " << puntero;
    cout << "\nEl contenido de var1 es: " << *puntero;
    puntero = &var2;
    cout << "\n\nLa direccion de memoria de var2 es: " << puntero;
    cout << "\nEl contenido de var2 es: " << *puntero;
}
