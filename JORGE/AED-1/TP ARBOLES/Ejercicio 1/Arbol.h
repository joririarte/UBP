#pragma once
class Arbol
{
protected:
	class Nodo {
	public:
		int info;
		Nodo* izq;
		Nodo* der;
		Nodo(int d);
		~Nodo();
	};
	Nodo* raiz;
	Nodo* buscar(int d, Nodo* rec);
	Nodo* buscarAnterior(int d, Nodo* rec);
	bool borrarHoja(int d, Nodo* r);
	void imprimir_Pre_Orden(Nodo* rec);
	void imprimir_Pos_Orden(Nodo* rec);
	void imprimir_In_Orden(Nodo* rec,std::basic_ostream<char>& stream);
public:
	Arbol();
	~Arbol();
	Nodo* getRaiz();
	void insertar(int d);
	bool borrar(int d);
	Nodo* buscar(int d);
	void imprimir_Pre_Orden();
	void imprimir_Pos_Orden();
	void imprimir_In_Orden(std::basic_ostream<char>& stream);
};

