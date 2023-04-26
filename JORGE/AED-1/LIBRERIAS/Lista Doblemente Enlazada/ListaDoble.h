#pragma once
class ListaDoble
{
private:
	class Nodo {
	public:
		int info;
		Nodo* sig;
		Nodo* ant;
		Nodo();
		Nodo(int d);
		Nodo(int data, Nodo* nxt, Nodo* lst);
	};
	Nodo* lista;
public:
	ListaDoble();
	~ListaDoble();
	void insertarFinal(int data);
	void insertarAntes(int data);
	void insertarEntre(int data, int ant, int sig);
	void eliminar(int data);
	Nodo* getLast();
	Nodo* getFirst();
	Nodo* getRaiz();
	Nodo* buscar(int data);
	void modificar(int dataAnt, int dataN);
	void mostrar();
};

