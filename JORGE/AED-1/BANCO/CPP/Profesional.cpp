#include "Profesional.h"

Profesional::Profesional():Cliente()
{
	titulo = "sin datos";
	actividad = "sin datos";
	antiguedad = 0;
	tarjeta = nullptr;
}

Profesional::Profesional(unsigned long int d, std::string n, std::string m, 
						std::string t, std::string act, unsigned short ant) : Cliente(d,n,m)
{
	titulo = t;
	actividad = act;
	antiguedad = ant;
}

void Profesional::setTitulo(std::string t)
{
	titulo = t;
}

std::string Profesional::getTitulo()
{
	return titulo;
}

void Profesional::setActividad(std::string a)
{
	actividad = a;
}

std::string Profesional::getActividad()
{
	return actividad;
}

void Profesional::setAntiguedad(unsigned short a)
{
	antiguedad = a;
}

unsigned short Profesional::getAntiguedad()
{
	return antiguedad;
}

void Profesional::setTarjetaCredito(TarjetaCredito* t)
{
	tarjeta = t;
}

TarjetaCredito* Profesional::getTarjetaCredito()
{
	return tarjeta;
}