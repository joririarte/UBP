#include <iostream>
#include <iostream>
#include "Cuenta.h"

Cuenta::Cuenta(int tit)
{
    titular = tit;
    saldo = 0.f;
}

Cuenta::Cuenta(int tit,double sal) {
    titular = tit;
    saldo = sal;
}

int Cuenta::getTitular()
{
    return titular;
}

void Cuenta::setTitular(int tit)
{
    titular = tit;
}

double Cuenta::getSaldo()
{
    return saldo;
}

void Cuenta::setSaldo(double sal)
{
    saldo = sal;
}

void Cuenta::ingresar(double monto)
{
    saldo += monto > 0 ? monto : 0;
}

void Cuenta::retirar(double monto)
{
    saldo -= saldo - monto < 0 ? saldo : monto;
}

Cuenta::~Cuenta()
{
}
