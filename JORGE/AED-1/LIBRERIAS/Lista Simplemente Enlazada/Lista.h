#pragma once
class Lista
{
private:
	class Nodo {
	public:
		int info;
		Nodo* sig;
		Nodo();
		Nodo(int data);
		Nodo(int data, Nodo* n);
	};
	Nodo* raiz;
public:
	Lista();
	~Lista();
	void insertar(int data);
	void insertarAntes(int data);
	void insertarEntre(int data, int anterior);
	void mostrar();
	Nodo* getLast();
	Nodo* getRaiz();
	int size();
	Nodo* buscar(int dato);
	Nodo* buscar(Nodo* n);
	void modificar(int datoViejo,int datoNuevo);
	bool eliminar(int dato);
	bool listaVacia();
};