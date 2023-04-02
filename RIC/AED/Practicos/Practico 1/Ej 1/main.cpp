#include <iostream>
#include "ejercicio1/Cuenta.h"
#include <cstdlib>



int main() {
    //std::cout << "Hello, World!" << std::endl;}


// EJERCICIO 1
    Cuenta cuenta1 = Cuenta("ricardo", 1000);
    cuenta1.ingresar(-50);
    cuenta1.ingresar(500);

    std::cout << "El saldo de la cuenta de "+ cuenta1.getTitular()+ " " + "es: " << cuenta1.getCantidad() << std::endl;

    cuenta1.retirar(700);
    std::cout << "El saldo de la cuenta de "+ cuenta1.getTitular()+ " " + "es: " << cuenta1.getCantidad() << std::endl;

    cuenta1.retirar(1700);
    std::cout << "El saldo de la cuenta de "+ cuenta1.getTitular()+ " " + "es: " << cuenta1.getCantidad() << std::endl;


    return 0;
}
