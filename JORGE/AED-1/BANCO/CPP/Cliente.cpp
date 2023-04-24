#include "Cliente.h"

Cliente::Cliente()
{
	dni = 0;
	nombre = "Sin Datos";
	mail = "sinDatos@sindatos";
	estado = false;
	cuenta = nullptr;
}

Cliente::Cliente(unsigned long d, std::string n, std::string m)
{
	dni = d;
	nombre = n;
	mail = m;
	estado = true;
}

void Cliente::setDni(unsigned long d)
{
	dni = d;
}

unsigned long Cliente::getDni()
{
	return dni;
}

void Cliente::setNombre(std::string n)
{
	nombre = n;
}

std::string Cliente::getNombre()
{
	return nombre;
}

void Cliente::setMail(std::string m)
{
	mail = m;
}

std::string Cliente::getMail()
{
	return mail;
}

void Cliente::setEstado(bool e)
{
	estado = e;
}

bool Cliente::getEstado()
{
	return estado;
}

void Cliente::setCuenta(Cuenta* c)
{
	cuenta = c;
}

Cuenta* Cliente::getCuenta()
{
	return cuenta;
}