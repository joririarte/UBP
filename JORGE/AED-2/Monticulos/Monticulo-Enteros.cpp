#include<iostream>
#include "Monticulo-Enteros.h"
#include"Monticulo.h"
#include"Monticulo.cpp"

int enteros::programa()
{
    Monticulo<int>* M = new Monticulo<int>();

    M->Insertar(4);
    M->Insertar(2);
    M->Insertar(1);
    M->Insertar(5);
    M->Insertar(6);
    M->Insertar(3);
    M->Insertar(9);
    M->Insertar(7);
    M->Insertar(8);

    std::cout << "\n\nElementos de la estructura\n\n";
    M->Mostrar();
    std::cout << "\n\nBorrar 6\n\n";
    M->Borrar(6);

    std::cout << "\n\nElementos de la estructura\n\n";
    M->Mostrar();

    std::cout << std::endl;
    std::cout << "\n\nExtrae elementos de la estructura:\n";

    while (!M->Vacio()) {
        std::cout << M->ExtraerMaximo() << std::endl;
    }
    return 0;
}
