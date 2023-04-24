#include "Cuenta.h"

Cuenta::Cuenta()
{
	nroCuenta = 0;
	saldo = 0.f;
}

Cuenta::Cuenta(unsigned int n)
{
	nroCuenta = n;
	saldo = 0.f;
}

void Cuenta::setNroCuenta(unsigned int n)
{
	nroCuenta = n;
}

unsigned int Cuenta::getNroCuenta()
{
	return nroCuenta;
}

void Cuenta::ingresar(float s)
{
	saldo += s;
}

bool Cuenta::retirar(float s)
{
	if (saldo - s < 0)
		return false;
	else
		saldo -= s;
	return true;
}

float Cuenta::getSaldo()
{
	return saldo;
}
