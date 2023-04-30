#pragma once
#include <fstream>
#include "Lista.h"
#include "ListaDoble.h"
#include "ListaCircular.h"
#include "Pila.h"
#include "Cola.h"
class ArchivoTxt
{
private:
	std::string nombre_archivo;
	std::ifstream fArchivo;
public:
	ArchivoTxt(std::string n);
	~ArchivoTxt();
	void setNombreArchivo(std::string n);
	std::string getNombreArchivo();
	void leer(Lista* l);
	void leer(ListaDoble* l);
	void leer(ListaCircular* l);
	void leer(Pila* p);
	void leer(Cola* c);
private:
	bool openArchivo();
	bool closeArchivo();
};