#include <iostream>
#include "arbol.h"
using namespace std;

int main()
{
    int opcion = 0, num = 0, cantidad = 0, respuesta = 0;
    ArbolBinario* arbol = new ArbolBinario();

    do
    {
        system("cls");
        cout << "1 - Insertar en arbol " << endl;
        cout << "2 - Mostrar arbol 'post'" << endl;
        cout << "3 - Mostrar arbol 'pre'" << endl;
        cout << "4 - Mostrar arbol 'entre" << endl;
        cout << "5 - Salir... " << endl;
        cout << "Ingrese opcion : ";


        cin >> opcion;
        switch (opcion)
        {
        case 1:
            do
            {
                int dato = 0;

                system("cls");
                cout << "Ingrese dato : ";
                cin >> dato;
                arbol->insertar(dato);
                system("cls");
                cout << " Decea ingresar un dato mas ? " << endl;
                cout << "1 - Si" << endl;
                cout << "2 - No" << endl;
                cin >> respuesta;

                respuesta == 1 ? cantidad = 1 : cantidad = 0;

            } while (respuesta == 1);
            break;
        case 2:
            system("cls");
            cout << "Listado post de datos : " << endl << endl;
            arbol->imprimirPost();
            cout << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Listado post de datos : " << endl << endl;
            arbol->imprimirPre();
            cout << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Listado post de datos : " << endl << endl;
            arbol->imprimirEntre();
            cout << endl;
            system("pause");
            break;
        case 5:
            exit(1);
            break;
        }
    } while (opcion != 5);

    cout << "Impresion preorden: ";
    arbol->imprimirPre();
    cout << "Impresion entreorden: ";
    arbol->imprimirEntre();
    cout << "Impresion postorden: ";
    arbol->imprimirPost();
    delete arbol;

    return 0;
}