#include "CrearDatos.h"
#include <ctime>

void std::crearDatos(ArchivoTxt* ar, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		ar->escribir(rand() % 102 - 1);
	}
}
