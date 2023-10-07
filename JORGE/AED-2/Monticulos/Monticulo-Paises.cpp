#include<iostream>
#include"Monticulo-Paises.h"
#include"Monticulo.h"
#include"Monticulo.cpp"
#include"Pais.h"
#include<fstream>

void leerPaises(Monticulo<Pais>* _mont);

int paises::programa() {
    Monticulo<Pais>* M = new Monticulo<Pais>();

    leerPaises(M);

    //Los paises se ordenan por poblacion
    std::cout << "\n\nElementos de la estructura\n\n";
    M->Mostrar();
    
    Pais p("Chile",0,0);
    std::cout << "\n\nBorrar Chile\n\n";
    M->Borrar(p);

    std::cout << "\n\nElementos de la estructura\n\n";
    M->Mostrar();
    std::cout << std::endl;
    std::cout << "\n\nExtrae elementos de la estructura ordenados por poblacion:\n";

    while (!M->Vacio()) {
        std::cout << M->ExtraerMaximo() << std::endl;
    }
    return 0;
}

void leerPaises(Monticulo<Pais>* _mont)
{
    std::ifstream archivo;
    archivo.open("Paises.txt");
    if (!archivo.fail()) {
        do {
            std::string _nombre;
            long int _poblacion;
            long int _PBI;
            archivo >> _nombre >> _poblacion >> _PBI;
            Pais* p = new Pais(_nombre,_poblacion,_PBI);
            _mont->Insertar(*p);
            
        } while (!archivo.eof());
    }

}
