#pragma once
#include <fstream>
#include "Lista.h"
#include "HashTable.h"
class ArchivoTxt
{
private:
	std::string nombre_archivo;
	std::ifstream fLectura;
	std::ofstream fEscritura;
public:
	ArchivoTxt(std::string n);
	~ArchivoTxt();
	void setNombreArchivo(std::string n);
	std::string getNombreArchivo();
	void leer(Lista* l);
	void leer(HashTable* hsh);
	void escribir(char mat, int compID,int cant);
private:
	bool openLectura();
	bool openEscritura();
	bool closeArchivo();
};