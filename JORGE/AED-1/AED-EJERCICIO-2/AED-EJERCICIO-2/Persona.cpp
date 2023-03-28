#include "Persona.h"
#include <cmath>
#include <ctime>

Persona::Persona()
{
    dni = generaDNI();
}

Persona::Persona(std::string n, unsigned int e, char s)
{
    nombre = n;
    edad = e;
    sexo = toupper(s);
    dni = generaDNI();
}

Persona::Persona(std::string n, unsigned int e, char s, double p, double h)
{
    nombre = n;
    edad = e;
    dni = generaDNI();
    sexo = s;
    peso = p;
    altura = h;
}

std::string Persona::getNombre()
{
    return nombre;
}

void Persona::setNombre(std::string n)
{
    nombre = n;
}

unsigned int Persona::getEdad()
{
    return edad;
}

void Persona::setEdad(unsigned int e)
{
    edad = e;
}

unsigned int Persona::getDNI()
{
    return dni;
}

char Persona::getSexo()
{
    return sexo;
}

void Persona::setSexo(char s)
{
    sexo = s;
}

double Persona::getPeso()
{
    return peso;
}

void Persona::setPeso(double p)
{
    peso = p;
}

double Persona::getAltura()
{
    return altura;
}

void Persona::setAltura(double h)
{
    altura = h;
}

int Persona::imc()
{
    int imc = peso / pow(altura, 2);
    int resultado = imc < 20 ? -1 : imc >= 20 && imc <= 25 ? 0 : 1;
    return resultado;
}

bool Persona::esMayorDeEdad()
{
    return edad>=18;
}

unsigned int Persona::generaDNI()
{
    srand(time(NULL));
    return rand() % 30000001 + 10000000;
}
