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
	if (openArchivo()) {
		do {
			fArchivo >> a;
			l->insertar(a);
		} while (!fArchivo.eof());
	}
	closeArchivo();
}

void ArchivoTxt::leer(ListaDoble* l)
{
	int a;
	if (openArchivo()) {
		do {
			fArchivo >> a;
			l->insertarFinal(a);
		} while (!fArchivo.eof());
	}
	closeArchivo();
}

void ArchivoTxt::leer(ListaCircular* l)
{
	int a;
	if (openArchivo()) {
		do {
			fArchivo >> a;
			l->insertar(a);
		} while (!fArchivo.eof());
	}
	closeArchivo();
}

void ArchivoTxt::leer(Pila* p)
{
	int a;
	if (openArchivo()) {
		do {
			fArchivo >> a;
			p->insertar(a);
		} while (!fArchivo.eof());
	}
	closeArchivo();
}

void ArchivoTxt::leer(Cola* c)
{
	int a;
	if (openArchivo()) {
		do {
			fArchivo >> a;
			c->insertar(a);
		} while (!fArchivo.eof());
	}
}

bool ArchivoTxt::openArchivo()
{
	fArchivo.open(nombre_archivo.c_str());
	if (fArchivo.fail())
		return false;
	return true;
}

bool ArchivoTxt::closeArchivo()
{
	if (fArchivo.is_open()) {
		fArchivo.close();
		return true;
	}
	return false;
}
