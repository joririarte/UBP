#include <iostream>
#include"ArchivoTxt.h"
#include"Lista.h"
#include "Mediciones.h";

void analisis(Mediciones* m, HashTable* hsh);

int main()
{
	//lectura archivo de mediciones y carga de lista de mediciones
	ArchivoTxt* archivo_mediciones = new ArchivoTxt("mediciones.txt");
	Lista* lista_mediciones = new Lista();
	archivo_mediciones->leer(lista_mediciones);
	std::cout << "Mediciones\n\n";
	lista_mediciones->mostrar();

	//lectura de archivo de componentes
	//carga en hash table de componentes
	ArchivoTxt* archivo_componentes = new ArchivoTxt("componentes.txt");
	HashTable* hash_componentes = new HashTable();
	archivo_componentes->leer(hash_componentes);
	std::cout << "\n\nComponentes\n\n";
	hash_componentes->imprimir();
	
	//recorrido de lista de mediciones y analisis
	std::cout << "\n\nAnalisis\n\n";
	lista_mediciones->recorrer(analisis,hash_componentes);
}

void analisis(Mediciones* m, HashTable* hsh)
{
	//archivos para escritura
	ArchivoTxt* correcciones = new ArchivoTxt("correcciones.txt");
	ArchivoTxt* cant_fabricacion = new ArchivoTxt("cantidad_fabricacion.txt");
	
	int cant_comp, desvio;
	//obtiene la cantidad de componente para el id
	hsh->buscar(m->getComponenteId(), cant_comp);
	//desvio entre la medicion y el que debe ir
	desvio = cant_comp - m->getMedicion();

	//si el desvio es superior a +- 5% se escribe la correccion
	if (std::abs(desvio) > cant_comp * 0.05) {
		std::cout << "\n\nMaterial: "<<m->getMaterial();
		std::cout << "\nComponente ID: "<<m->getComponenteId();
		std::cout << "\nMedicion: "<<m->getMedicion();
		std::cout << "\nCorreccion: "<<desvio;
		correcciones->escribir(m->getMaterial(), m->getComponenteId(), desvio);
	}
	//escritura de la configuracion de los materiales
	cant_fabricacion->escribir(m->getMaterial(), m->getComponenteId(), cant_comp);
	delete correcciones, cant_fabricacion;
}
