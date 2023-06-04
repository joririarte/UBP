#pragma once
class Lista
{
private:
	class Nodo {
	public:
		int info;
		int operacion;
		Nodo* sig;
		Nodo();
		Nodo(int data, int op);
		Nodo(int data, int op, Nodo* n);
	};
	Nodo* raiz;
public:
	Lista();
	~Lista();
	void insertar(int data, int op);
	void insertarAntes(int data, int op);
	void insertarEntre(int data, int anterior, int op);
	void mostrar();
	Nodo* getLast();
	Nodo* getNext(Nodo* n);
	Nodo* getRaiz();
	int size();
	Nodo* buscar(int dato);
	Nodo* buscar(int dato,int operacion);
	Nodo* buscar(Nodo* n);
	void modificar(int datoViejo,int datoNuevo);
	bool eliminar(int dato);
	bool listaVacia();
};