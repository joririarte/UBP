#include "ArchivoTxt.h"

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
	int a;
	if (openLectura()) {
		do {
			//lee y carga en a
			fLectura >> a;
			//se fija que no sea un dato error
			if (a >= 0) {
				//se fija que el dato no este repetido
				if (l->buscar(a) == nullptr)
					//carga el dato si no esta repetido
					l->insertar(a);
				//si el dato esta repetido 
				//lo carga en otro archivo
				else {
					ArchivoTxt* rep = new ArchivoTxt("data_repetida.txt");
					rep->escribir(a);
					delete rep;
				}
			}
			else {//si es error lo carga en un archivo
				ArchivoTxt* err = new ArchivoTxt("data_error.txt");
				err->escribir(a);
				delete err;
			}
		} while (!fLectura.eof());
	}
	closeArchivo();
}

void ArchivoTxt::escribir(int d)
{
	if (openEscritura()) {
		fEscritura << d << std::endl;
	}
	closeArchivo();
}

void ArchivoTxt::escribir(Arbol* a)
{
	if (openEscritura()) {
		a->imprimir_In_Orden(fEscritura);
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
