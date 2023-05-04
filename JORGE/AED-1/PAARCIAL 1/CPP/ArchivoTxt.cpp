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
//agregado en parcial
void ArchivoTxt::leerOrdenado(Lista* l)
{
	int a;
	if (openArchivo()) {
		do {
			//lee un dato
			fArchivo >> a;
			//si la lista esta vacia inserta el primer elemento
			if (l->listaVacia())
				l->insertar(a);
			//si no esta vacia, si el dato leido es menor
			//a la info del primer elemento
			//si es así lo inserta primero
			else if (a < l->getRaiz()->info) {
				l->insertarAntes(a);
			}
			//si no esta vacia, si el dato leido es mayor
			//a la info del último elemento
			//si es así lo inserta al final
			else if (a > l->getLast()->info)
				l->insertar(a);
			//si no pasa nada de lo anterior el dato esta entre medio
			else {
				//recorre la lista
				int aux = l->getRaiz()->info;
				while (l->buscar(aux)->sig != nullptr) {
					//si hay un dato en la lista mayor al leído
					//inserta ese dato antes (o después del anterior)
					if (aux > a) {
						l->insertarEntre(a, l->buscar(l->buscar(aux))->info);
						//el segundo parámetro del método, es un "truco"
						//para buscar el anterior a partir del siguiente
						//tengo un método que busca el anterior de un Nodo*
						//definido en la clase
						break;
					}
					aux = l->buscar(aux)->sig->info;
				}
				//inserta el último elemento
				if (l->buscar(aux)->sig == nullptr && aux > a) {
					l->insertarEntre(a, l->buscar(l->buscar(aux))->info);
				}
			}
		} while (!fArchivo.eof());
		closeArchivo();
	}
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
