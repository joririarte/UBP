#pragma once
#include<vector>
#include<iostream>
template <typename T>
//La clase Template debe definir los operadores
//Operadores: >, <, ==, <<
class Monticulo
{
private:
	std::vector<T>* monticulo;

	//Devuelve la posición del padre
	int Padre(int pos_nodo);
	//Devuelve la posición del nodo hijo izquierdo
	int Izquierdo(int pos_nodo);
	//Devuelve la posición del nodo hijo derecho
	int Derecho(int pos_nodo);

	//Sube un nodo por el montículo (aplica en inserción)
	void Subir(int pos_nodo);
	//Baja un nodo por el montículo (aplica en borrado)
	void Bajar(int pos_nodo);
	//Intercambia la posición de dos nodos
	void Intercambiar(int pos_1, int pos_2);
public:
	//Constructor
	Monticulo();
	//Destructor
	~Monticulo();
	//Devuelve True si está vacío, False si no
	bool Vacio();
	//Devuelve True si se logra la inserción
	bool Insertar(T valor);
	//Devuelve True si se logra el borrado
	bool Borrar(T valor);
	//Devuelve True si existe el valor en el montículo
	bool Existe(T valor);
	//Devuelve la posición de un valor en el montículo
	int BuscarPos(T valor);
	//Devuelve un nodo de una posición
	T getNodo(int pos);
	//Muestra el contenido del montículo
	void Mostrar();
	//Devuelve el valor máximo del montículo y lo extrae
	T ExtraerMaximo();
};