#include "ArchivoTxt.h"
#include "Mediciones.h"

ArchivoTxt::ArchivoTxt(std::string n)
{
	nombre_archivo = n;
}

ArchivoTxt::~ArchivoTxt()
{
}

void ArchivoTxt::setNombreArchivo(std::string n)
{
	nombre_archivo = n;
}

std::string ArchivoTxt::getNombreArchivo()
{
	return nombre_archivo;
}

void ArchivoTxt::leer(Lista* l)
{
	char material;
	int componenteID, medicion;
	if (openLectura()) {
		do {
			//lee y carga en a
			fLectura >> material >> componenteID >> medicion;
			Mediciones* med = new Mediciones(material, componenteID, medicion);
			l->insertar(med);
		} while (!fLectura.eof());
	}
	closeArchivo();
}
void ArchivoTxt::leer(HashTable* hsh)
{
	int componenteID, cantidad;
	if (openLectura()) {
		do {
			fLectura >> componenteID >> cantidad;
			hsh->insertar(componenteID, cantidad);
		} while (!fLectura.eof());
	}
	closeArchivo();
}
//check
void ArchivoTxt::escribir(char mat, int compID, int cant)
{
	if (openEscritura()) {
		fEscritura << mat << " " << compID <<" "<< cant << std::endl;
	}
	closeArchivo();
}


bool ArchivoTxt::openLectura()
{
	fLectura.open(nombre_archivo.c_str());
	if (fLectura.fail())
		return false;
	return true;
}

bool ArchivoTxt::openEscritura()
{
	fEscritura.open(nombre_archivo.c_str(),std::ios::app);
	if (fEscritura.fail())
		return false;
	return true;
}

bool ArchivoTxt::closeArchivo()
{
	if (fLectura.is_open()) {
		fLectura.close();
		return true;
	}
	else if (fEscritura.is_open()) {
		fEscritura.close();
		return true;
	}
	return false;
}
