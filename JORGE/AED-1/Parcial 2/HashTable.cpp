#include "HashTable.h"
#include <iostream>
using namespace std;
HashTable::HashTable()
{
}
HashTable::~HashTable()
{
}
/* Función de inserción */
void HashTable::insertar(int key, int value)
{
    int index;

    // Aplicar la función hash a la clave IMPORTANTE
    index = key % num_elementos;

    // Si el espacio esta libre, se inserta el valor (Evaluamos si valores es = 0)
    if (valores[index] == 0) {
        keys[index] = key;
        valores[index] = value;
        espacios_vacios--;
    }  // Si el espacion no esta libre, se produce colisión.
    else {
        int rehash_index = index;
        // Se aplica función de rehash hasta encontrar un espacio vacío
        for (;;) {
            rehash_index = (rehash_index + 1) % num_elementos;

            // Si encuentra espacio vacío
            if (valores[rehash_index] == 0) {
                keys[rehash_index] = key;
                valores[rehash_index] = value;
                espacios_vacios--;
                break;
            }
        }
    }
}

//modificacion del ejemplo por George de la Selva
// 
//busca un elemento en la tabla hash
bool HashTable::buscar(int key, int& valor) {
    //obtiene el indice
    int index = key % num_elementos;
    //si la clave almacenada en el indice es igual a la clave requerida
    //se muestra el valor
    if (keys[index] == key) {
        valor = valores[index];
        return true;
    }
    //si no se hace un rehash del indice
    else {
        //rehashing del indice
        index = (index + 1) % num_elementos;

        //se obtiene la cantidad de elementos almacenados
        int almacenados = num_elementos - espacios_vacios;

        //se itera buscando el elemento tantas veces como elementos almacenados tenga
        //hasta encontrar el elemento
        for (int i = 0; i < almacenados; i++) {
            if (keys[index] == key) {
                valor = valores[index];
                return true;
            }
        }
    }
    //si no se encontro el elemento devuelve false
    return false;
}

/* imprimir el contenido de hashtable */
void HashTable::imprimir()
{
    int i;
    int num_elem;

    num_elem = num_elementos;

    // Iteramos sobre la tabla (Esta función solo se realiza para controlar los datos cargados)
    cout << "Index \t\t Key \t\t Valor\n";
    for (i = 0; i < num_elem; i++) {
        if (valores[i] == 0) {
            cout << i << endl; // Solo se imprime posición vacía
        }
        else {
            // Se imprmie el detalle de cada posición con los datos que la ocupan
            cout << i << "\t\t" << keys[i] << "\t\t" << valores[i] << endl;
        }
    }
}
