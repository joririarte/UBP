#pragma once
#include <iostream>
class Vertice;

class Arista
{
    int precio;
    Arista* sig;
    Vertice* dest;
    bool resaltada = false;

    friend class Grafo;
public:
    Arista(Vertice* _dest, int precio);
};

 // namespace std