#pragma once
class ArbolAVL
{
private:
	class Nodo {
	public:
		// Constructor:
		Nodo(const int dat, Nodo* pad = nullptr, Nodo* izq = nullptr, Nodo* der = nullptr) :
			dato(dat), padre(pad), izquierdo(izq), derecho(der), FE(0) {}
		// Miembros:
		int dato;
		int FE;
		Nodo* izquierdo;
		Nodo* derecho;
		Nodo* padre;
	};
	enum { IZQUIERDO, DERECHO };
	// Punteros de la lista, para cabeza y nodo actual:
	Nodo* raiz;
	Nodo* actual;
	int contador;
	int altura;

public:
	// Constructor y destructor b�sicos:
	ArbolAVL() : raiz(nullptr), actual(nullptr) {}
	~ArbolAVL() { Podar(raiz); }
	// Insertar en �rbol ordenado:
	void Insertar(const int dat);
	// Borrar un elemento del �rbol:
	void Borrar(const int dat);
	// Funci�n de b�squeda:
	bool Buscar(const int dat);
	// Comprobar si el �rbol est� vac�o:
	bool Vacio(Nodo* r) { return r == nullptr; }
	// Comprobar si es un nodo hoja:
	bool EsHoja(Nodo* r) { return !r->derecho && !r->izquierdo; }
	// Contar n�mero de nodos:
	const int NumeroNodos();
	const int AlturaArbol();
	// Calcular altura de un dato:
	int Altura(const int dat);
	// Devolver referencia al dato del nodo actual:
	int& ValorActual() { return actual->dato; }
	// Moverse al nodo raiz:
	void Raiz() { actual = raiz; }
	// Aplicar una funci�n a cada elemento del �rbol:
	void InOrden(void (*func)(int&, int), Nodo* nodo = nullptr, bool r = true);
	void PreOrden(void (*func)(int&, int), Nodo* nodo = nullptr, bool r = true);
	void PostOrden(void (*func)(int&, int), Nodo* nodo = nullptr, bool r = true);
private:
	// Funciones de equilibrado:
	void Equilibrar(Nodo* nodo, int, bool);
	void RSI(Nodo* nodo);
	void RSD(Nodo* nodo);
	void RDI(Nodo* nodo);
	void RDD(Nodo* nodo);
	// Funciones auxiliares
	void Podar(Nodo*&);
	void auxContador(Nodo*);
	void auxAltura(Nodo*, int);
};

