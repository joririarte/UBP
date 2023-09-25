#pragma once
#include "Vertice.h"
#include "Arista.h"
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <unordered_set>


class Grafo
{
private:
	Vertice* primero;
	int tamano;
	bool ponderado;
public:
	Grafo();
	void SetPonderado(bool p);
	// Retorna true si el grafo está vacío
	bool EstaVacio();
	// Retorna el número de vertices en el grafo 
	int ObtenerTamano();
	// Retornar el vertice que tenga el nombre especificado
	Vertice* ObtenerVertice(std::string nombre);
	// Inserta un vertice al grafo
	void InsertaVertice(std::string nombre);
	//si el grafo no es ponderado puede omitirse la insercion del precio
	// Inserta arista entre los dos vertices especificados con el precio especificado
	void InsertaArista(std::string ori, std::string dest, int precio = 1);
	// Mostrar todos los vertices con sus aristas y precios
	void MostrarListaAdyacencia();
	// Elimina el vertice con el nombre especificado
	void EliminarVertice(std::string nombre);
	// Elimina la arista entre los dos vertices especificados
	void EliminarArista(std::string ori, std::string dest);
	// Elimina todos los vertices y aristas del grafo
	void EliminarTodo();
	// Elimina las aristas del vertice especificado
	void EliminarAristas(Vertice* vertice);
	// Elimina las aristas que tienen como destino el vertice especificado
	void EliminarAristasDestino(std::string dest);
	//Toma un arreglo bidimensional para crear un grafo
	void importarMatrizAdyacencia(int** m, int tam);

	bool** AristasResaltadas();
	void desmarcarAristas();

	// Recorre el grafo con el algoritmo de anchura
	void RecorridoAnchura(std::string origen); 
	// Recorre el grafo con el algoritmo de profundidad
	void RecorridoProfundidad(std::string origen);
	// Despliega la ruta entre los dos vertices especificados con el algoritmo de primero en anchura
	void PrimeroEnAnchura(std::string origen, std::string destino);
	// Despliega la ruta entre los dos vertices especificados con el algoritmo de primero en profundidad
	void PrimeroEnProfundidad(std::string origen, std::string destino);
	// Despliega la ruta entre los dos vertices especificados con el algoritmo de primero el mejor
	void PrimeroElMejor(std::string origen, std::string destino);
	// Despliega la ruta encontrada
	void MostrarRutaEncontrada(std::stack<std::pair<Vertice*, Vertice*>> pilaPar, Vertice* vdest);
	// Despliega la ruta más corta entre el origen y los demás vertices
	void Dijkstra(std::string origen);
	// Genera el arbol recubridor minimo con el algoritmo de kruskal
	void Kruskal();
	// Genera el arbol recubridor minimo con el algoritmo de Prim
	void Prim(std::string origen);
};
