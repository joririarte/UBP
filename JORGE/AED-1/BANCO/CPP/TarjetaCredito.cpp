#include "TarjetaCredito.h"

TarjetaCredito::TarjetaCredito()
{
    nroTarjeta = 0;
    limiteCompra = 0.f;
    tipo = "sin datos";
}

TarjetaCredito::TarjetaCredito(unsigned long n)
{
    nroTarjeta = n;
    limiteCompra = 0.f;
    tipo = "sin datos";
}

unsigned long TarjetaCredito::getNroTarjeta()
{
    return nroTarjeta;
}

void TarjetaCredito::setNroTarjeta(unsigned long n)
{
    nroTarjeta = n;
}

float TarjetaCredito::getLimiteCompra()
{
    return limiteCompra;
}

void TarjetaCredito::setLimiteCompra(float l)
{
    limiteCompra = l;
}

void TarjetaCredito::setLimiteCompra()
{
    if (tipo == "Oro")
        limiteCompra = 400000.f;
    else if (tipo == "Plata")
        limiteCompra = 200000.f;
    else if (tipo == "Bronce")
        limiteCompra = 100000.f;
}

void TarjetaCredito::setTipo(float sueldo)
{
    if (sueldo >= 100000)
        tipo = "Oro";
    else if (sueldo >= 50000 && sueldo < 100000)
        tipo = "Plata";
    else if (sueldo < 50000)
        tipo = "Bronce";
}

std::string TarjetaCredito::getTipo()
{
    return tipo;
}