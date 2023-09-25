#include <iostream>
#include <fstream>
#include "Grafo.h"
#include "Grafo_GUI.h"

using namespace std;

int** leerMatrizAdyacencia(string, int&);

void showGraph(int**, int, bool**, string);

int main() {
    do {
        int tam;
        int** Ady;
        std::system("cls");
        Grafo* G = new Grafo();

        string nombre;
        std::cout << "\n Elige el grafo a Representar:";
        std::cout << "\n 1- Ejercicio 2 A1";
        std::cout << "\n 2- Ejercicio 2 A3";
        std::cout << "\n 3- Ejercicio 5 A2";
        std::cout << "\n 4- Ejercicio 6";
        std::cout << "\n 5- Ejercicio 7";
        std::cout << "\n 6- Ejercicio 8";
        std::cout << "\n 7- Ejercicio 9";
        std::cout << "\n 8- Ejercicio 10";
        std::cout << "\n 0- Salir";
        std::cout << "\n\n Opcion: ";
        int op;
        cin >> op;
        switch (op) {
        case 1:
        {
            nombre = "adyacencia1.txt";
            Ady = leerMatrizAdyacencia(nombre, tam);
            G->importarMatrizAdyacencia(Ady, tam);
            showGraph(Ady, tam, G->AristasResaltadas(),"Ejercicio 2 A1");
            break;
        }
        case 2:
        {
            nombre = "adyacencia3.txt";
            Ady = leerMatrizAdyacencia(nombre, tam);
            G->importarMatrizAdyacencia(Ady, tam);
            showGraph(Ady, tam, G->AristasResaltadas(), "Ejercicio 2 A3");
            break;
        }
        case 3:
        {
            nombre = "adyacencia2.txt";
            Ady = leerMatrizAdyacencia(nombre, tam);
            G->importarMatrizAdyacencia(Ady, tam);
            showGraph(Ady, tam, G->AristasResaltadas(), "Grafo Ejercicio 5");
            break;
        }
        case 4:
        {
            nombre = "adyacencia6.txt";
            Ady = leerMatrizAdyacencia(nombre, tam);
            G->importarMatrizAdyacencia(Ady, tam);
            showGraph(Ady, tam, G->AristasResaltadas(), "Ejercicio 6");
            break;
        }
        case 5:
        {
            nombre = "adyacencia7.txt";
            Ady = leerMatrizAdyacencia(nombre, tam);
            G->importarMatrizAdyacencia(Ady, tam);

            std::cout << "\nAlgoritmo Kruskal\n";
            G->Kruskal();
            showGraph(Ady, tam, G->AristasResaltadas(), "KRUSKAL - Ejercicio 7");
            G->desmarcarAristas();

            std::cout << "\n\nAlgoritmo de Prim\n";
            G->Prim("A");
            showGraph(Ady, tam, G->AristasResaltadas(), "PRIM - Ejercicio 7");
            break;
        }
        case 6:
        {
            nombre = "adyacencia8.txt";
            Ady = leerMatrizAdyacencia(nombre, tam);
            G->importarMatrizAdyacencia(Ady, tam);
            
            std::cout << "\nAlgoritmo Kruskal\n";
            G->Kruskal();
            showGraph(Ady, tam, G->AristasResaltadas(), "KRUSKAL - Ejercicio 8");
            G->desmarcarAristas();
            
            std::cout << "\n\nDistancia mas corta entre A y E\n\n";
            G->PrimeroEnAnchura("A", "E");
            showGraph(Ady, tam, G->AristasResaltadas(), "BFS - Ejercicio 8");
            break;
        }
        case 7:
        {
            nombre = "adyacencia9.txt";
            Ady = leerMatrizAdyacencia(nombre, tam);
            G->importarMatrizAdyacencia(Ady, tam);
            
            std::cout << "\nAlgoritmo Dijkstra\n";
            G->Dijkstra("A");
            showGraph(Ady, tam, G->AristasResaltadas(), "DIJKSTRA - Ejercicio 9");
            break;
        }
        case 8:
        {
            nombre = "adyacencia10.txt";
            Ady = leerMatrizAdyacencia(nombre, tam);
            G->importarMatrizAdyacencia(Ady, tam);

            std::cout << "\nAlgoritmo Kruskal\n";
            G->Kruskal();
            showGraph(Ady, tam, G->AristasResaltadas(), "KRUSKAL - Ejercicio 10");
            G->desmarcarAristas();

            std::cout << "\n\nDistancia mas corta entre C y G\n\n";
            G->PrimeroEnAnchura("C", "G");
            showGraph(Ady, tam, G->AristasResaltadas(), "BFS - Ejercicio 10");
            break;
        }
        case 0:
            G->EliminarTodo();
            delete G;
            return 0;
            break;
        default:
            continue;
            break;
        }
        //arreglo bidimensional dinamico

        std::cout << endl;
        std::system("pause");

        G->EliminarTodo();
        delete G;
    } while (true);

}

int** leerMatrizAdyacencia(string nombre, int& tam) {
    //Abre un archivo para cargar una matriz de adyacencia
    ifstream archivo;
    archivo.open(nombre.c_str());
    //doble puntero para inicializar un
    //arreglo bidimensional dinámico
    int** _Ady=0;

    //lectura del archivo
    if (!archivo.fail()) {
        //la primer linea tiene la cantidad de vertices
        archivo >> tam;

        //Creo las filas
        _Ady = new int* [tam];
        //Creo las columnas
        for (int i = 0; i < tam; i++)
            _Ady[i] = new int[tam];

        //leo desde el archivo la matriz 
        //y la cargo al arreglo
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                archivo >> _Ady[i][j];
            }
        }
    }
    archivo.close();
    return _Ady;
}

void showGraph(int** _Ady, int _tam, bool** _Resaltadas, string _nombreGraph)
{
    Grafo_GUI* graph = new Grafo_GUI(_Ady, _tam, _Resaltadas, _nombreGraph);
    graph->run();
    delete graph;
}
