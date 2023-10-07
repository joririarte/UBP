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

	//Devuelve la posici�n del padre
	int Padre(int pos_nodo);
	//Devuelve la posici�n del nodo hijo izquierdo
	int Izquierdo(int pos_nodo);
	//Devuelve la posici�n del nodo hijo derecho
	int Derecho(int pos_nodo);

	//Sube un nodo por el mont�culo (aplica en inserci�n)
	void Subir(int pos_nodo);
	//Baja un nodo por el mont�culo (aplica en borrado)
	void Bajar(int pos_nodo);
	//Intercambia la posici�n de dos nodos
	void Intercambiar(int pos_1, int pos_2);
public:
	//Constructor
	Monticulo();
	//Destructor
	~Monticulo();
	//Devuelve True si est� vac�o, False si no
	bool Vacio();
	//Devuelve True si se logra la inserci�n
	bool Insertar(T valor);
	//Devuelve True si se logra el borrado
	bool Borrar(T valor);
	//Devuelve True si existe el valor en el mont�culo
	bool Existe(T valor);
	//Devuelve la posici�n de un valor en el mont�culo
	int BuscarPos(T valor);
	//Devuelve un nodo de una posici�n
	T getNodo(int pos);
	//Muestra el contenido del mont�culo
	void Mostrar();
	//Devuelve el valor m�ximo del mont�culo y lo extrae
	T ExtraerMaximo();
};