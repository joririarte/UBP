#pragma once
class Lista
{
private:
	class Nodo {
	public:
		int info;
		Nodo* sig;
	};
	Nodo* raiz;
public:
	Lista();
	~Lista();
	void insertar(int data);
	void insertarAntes(int data);
	void mostrar();
	Nodo* nuevoNodo(int data);
	Nodo* getLast();
	Nodo* getRaiz();
	int size();
	int sumar();
	float media();
	int max();
	int min();
	Nodo* buscar(int dato);
	void modificar(int datoViejo,int datoNuevo);
	void eliminar(int dato);
};