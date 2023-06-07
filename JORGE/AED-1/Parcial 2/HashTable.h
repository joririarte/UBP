#pragma once
#define ELEM_HASH 100
class HashTable
{
    int num_elementos = ELEM_HASH;       /* Número de elementos que podemos almacenar */
    int espacios_vacios = ELEM_HASH;     /* Número de espacio vacíos */
    int keys[ELEM_HASH];               /* Claves */
    int valores[ELEM_HASH] = { 0 };        /* Valores */
public:
    HashTable();
    ~HashTable();
    /* Funciones */
    void insertar(int key, int valor);
    bool buscar(int key, int& valor);
    void imprimir();
};

