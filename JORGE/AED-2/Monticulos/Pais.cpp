#include "Pais.h"

Pais::Pais(std::string _nombre, long int _poblacion, long int _PBI)
{
	setNombre(_nombre);
	setPoblacion(_poblacion);
	setPBI(_PBI);
}

Pais::~Pais()
{

}

std::string Pais::getNombre()
{
	return nombre;
}

long int Pais::getPoblacion()
{
	return poblacion;
}

long int Pais::getPBI()
{
	return PBI;
}

void Pais::setNombre(std::string _nombre)
{
	nombre = _nombre;
}

void Pais::setPoblacion(long int _poblacion)
{
	poblacion = _poblacion;
}

void Pais::setPBI(long int _PBI)
{
	PBI = _PBI;
}

//Sobrecarga de operadores logicos para comparacion
bool Pais::operator>(Pais p)
{
	return poblacion > p.getPoblacion();
}

bool Pais::operator<(Pais p)
{
	return poblacion < p.getPoblacion();
}

bool Pais::operator==(Pais p)
{
	return	nombre == p.getNombre();
}

//sobrecarga de operacion de flujo para muestra de datos
std::ostream& operator<<(std::ostream& os, Pais p)
{
	std::cout.imbue(std::locale("es_AR.UTF-8"));
	std::cout << "\n\nPais: " << p.nombre;
	std::cout << "\nPoblacion: " << p.poblacion;
	std::cout << "\nPBI: U$D " << p.PBI<<" Millones\n\n";
	return os;
}
