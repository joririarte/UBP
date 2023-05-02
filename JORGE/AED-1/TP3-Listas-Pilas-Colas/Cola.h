#pragma once
class Cola
{
private:
	class Nodo {
	public:
		int info;
		Nodo* sig;
		Nodo();
		Nodo(int data);
	};
	unsigned int tope = 1000;
	unsigned int enUso = 0;
	Nodo* frente;
	Nodo* final;
public:
	Cola();
	~Cola();
	void insertar(int data);
	Nodo* extraer();
	Nodo* getFrente();
	Nodo* getFinal();
	bool colaLlena();
	bool colaVacia();
	unsigned int size();
};