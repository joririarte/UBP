#pragma once
#include<iostream>

class Arista;

class Vertice
{
private:
    std::string nombre;
    Vertice* sig;
    Arista* ari;

    friend class Grafo;
public:
    Vertice(std::string nombre);
};

