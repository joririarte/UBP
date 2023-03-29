#include "Raices.h"
#include <cmath>
#include <iostream>
void Raices::obtenerRaices()
{
    std::cout << "\nRaiz 1: ";
    std::cout << (-b + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
    std::cout << "\nRaiz 2: ";
    std::cout << (-b - sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
}
void Raices::obtenerRaiz()
{
    std::cout << "\nRaiz: ";
    std::cout << -b / 2 * a;
}
double Raices::getDiscriminante()
{
    return pow(b,2)-4*a*c;
}

bool Raices::tieneRaices()
{
    return getDiscriminante() > 0;
}

bool Raices::tieneRaiz()
{
    return getDiscriminante() == 0;
}

Raices::Raices(double A, double B, double C)
{
    a = A;
    b = B;
    c = C;
}

void Raices::calcular()
{
    if (tieneRaices())
        obtenerRaices();
    else if (tieneRaiz())
        obtenerRaiz();
    else
        std::cout << "\nNo tiene solucion en los numeros Reales";
}

void Raices::setA(double A)
{
    a = A;
}

void Raices::setB(double B)
{
    b = B;
}

void Raices::setC(double C)
{
    c = C;
}

double Raices::getA()
{
    return a;
}

double Raices::getB()
{
    return b;
}

double Raices::getC()
{
    return c;
}
