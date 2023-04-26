#pragma once
class Pila
{
private:
	class Nodo {
	public:
		int info;
		Nodo* sig;
		Nodo();
		Nodo(int data);
		Nodo(int data, Nodo* nxt);
	};
	unsigned int tope = 1000;
	unsigned int enUso = 0;
	Nodo* cima;
public:
	Pila();
	Pila(unsigned int max);
	~Pila();
	void insertar(int data);
	Nodo* extraer();
	unsigned int size();
	bool pilaLlena();
	bool pilaVacia();
};

