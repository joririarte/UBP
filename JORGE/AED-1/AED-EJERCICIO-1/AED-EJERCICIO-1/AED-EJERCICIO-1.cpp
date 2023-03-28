#include <iostream>
#include "Cuenta.h"
using namespace std;
int main()
{
    int titular,op;
    double monto;
    cout << "Ingrese Titular: ";
    cin >> titular;
    Cuenta* cta1 = new Cuenta(titular);
    do {
        system("cls");
        cout << "Titular: " << cta1->getTitular();
        cout << "\n\n1. Ingresar Dinero";
        cout << "\n2. Retirar Dinero";
        cout << "\n3. Mostrar Saldo";
        cout << "\n4. Salir";
        cout << "\n\nIngrese una opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "\n\nIngresar Dinero: ";
            cin >> monto;
            cta1->ingresar(monto);
            break;
        case 2:

            cout << "\n\nRetirar Dinero: ";
            cin >> monto;
            cta1->retirar(monto);
            break;
        case 3:
            cout << "\n\nCuenta: " << cta1->getTitular();
            cout << "\nSaldo: " << cta1->getSaldo() << endl << endl;
            break;
        }
        system("pause");
    } while (op != 4);

    delete cta1;
}