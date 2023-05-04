#pragma once
class ListaCircular
{

private:
	class Nodo {
	public:
		int info;
		Nodo* sig;
		Nodo();
		Nodo(int d);
		Nodo(int data, Nodo* nxt);
	};
	Nodo* lista;
public:
	ListaCircular();
	~ListaCircular();
	void insertar(int data);
	void insertarDespuesDe(int data, int ant);
	void eliminar(int data);
	Nodo* getRaiz();
	Nodo* buscar(int data);
	void modificar(int dataAnt, int dataN);
	void mostrar();
};

