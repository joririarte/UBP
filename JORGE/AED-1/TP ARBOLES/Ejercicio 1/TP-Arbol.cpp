#include <iostream>
#include "Arbol.h";
#include "CrearDatos.h"
#include "ArchivoTxt.h"
#include "Lista.h"

int main()
{
	Lista* l = new Lista();
	ArchivoTxt* arch = new ArchivoTxt("data.txt");
	//carga un archivo con n datos aleatorios
	//std::crearDatos(arch,1000);
	
	//lee el archivo y carga la lista 
	//sin los errores sin los repetidos
	arch->leer(l);
	//l->mostrar();

	//crea un arbol e inserta los datos de la lista en el
	Arbol* groot = new Arbol();
	int data = l->getRaiz()->info;
	int finalData = l->getLast()->info;
	while (data != finalData) {
		groot->insertar(data);
		data = l->buscar(data)->sig->info;
	}
	groot->insertar(finalData);
	//imprime en pantalla el arbol
	groot->imprimir_In_Orden(std::cout);
	//cambia el nombre del archivo
	arch->setNombreArchivo("data_procesada.txt");
	//escribe en arbol en el nuevo archivo
	arch->escribir(groot);
}
