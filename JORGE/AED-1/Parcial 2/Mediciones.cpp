#include "Mediciones.h"
#include <iostream>

Mediciones::Mediciones(char m, int comp, int med)
{
	material = m;
	idComponente = comp;
	medicion = med;
}

Mediciones::~Mediciones()
{
}

char Mediciones::getMaterial()
{
	return material;
}

int Mediciones::getComponenteId()
{
	return idComponente;
}

int Mediciones::getMedicion()
{
	return medicion;
}

bool Mediciones::operator==(Mediciones* m)
{
	return	material == m->getMaterial() &&
			idComponente == m->getComponenteId() &&
			medicion == m->getMedicion();
}

void Mediciones::mostrar()
{
	std::cout	<< material 
				<< "\t\t\t\t" << idComponente 
				<< "\t\t\t" << medicion 
				<< std::endl;
}
