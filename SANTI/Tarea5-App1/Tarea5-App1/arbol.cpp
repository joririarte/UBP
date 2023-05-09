#include <iostream>
#include "arbol.h"
using namespace std;

ArbolBinario::ArbolBinario()
{
	raiz = NULL;
}
ArbolBinario::~ArbolBinario()
{
	borrar(raiz);
}
void ArbolBinario::borrar(Nodo* reco)
{
	if (reco != NULL)
	{
		borrar(reco->izq);
		borrar(reco->der);
		delete reco;
	}
}
void ArbolBinario::insertar(int x)
{
	system("cls");
	int dato = 0;
	Nodo* nuevo;
	nuevo = new Nodo();
	nuevo->info = x;
	nuevo->izq = NULL;
	nuevo->der = NULL;

	if (raiz == NULL)
		raiz = nuevo;
	else
	{
		Nodo* anterior, * reco;
		anterior = NULL;
		reco = raiz;
		while (reco != NULL)
		{
			anterior = reco;
			if (x < reco->info)
				reco = reco->izq;
			else
				reco = reco->der;
		}
		if (x < anterior->info)
			anterior->izq = nuevo;
		else
			anterior->der = nuevo;
	}
	cout << "Dato ingresado correctamente" << endl << endl;
	system("pause");
}
void ArbolBinario::imprimirPre()
{
	system("cls");
	imprimirPre(raiz);
	cout << "\n";
	system("pause");
}
void ArbolBinario::imprimirPre(Nodo* reco)
{
	if (reco != NULL)
	{
		cout << reco->info << "-";
		imprimirPre(reco->izq);
		imprimirPre(reco->der);
	}
}
void ArbolBinario::imprimirEntre()
{
	imprimirEntre(raiz);
	cout << "\n";
}
void ArbolBinario::imprimirEntre(Nodo* reco)
{
	if (reco != NULL)
	{
		imprimirEntre(reco->izq);
		cout << reco->info << "-";
		imprimirEntre(reco->der);
	}
}
void ArbolBinario::imprimirPost()
{
	imprimirPost(raiz);
	cout << "\n";
}
void ArbolBinario::imprimirPost(Nodo* reco)
{
	if (reco != NULL)
	{
		imprimirPost(reco->izq);
		imprimirPost(reco->der);
		cout << reco->info << "-";
	}
}

