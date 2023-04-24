#include "Administrativo.h"

Administrativo::Administrativo() : Cliente()
{
    //se llama al constructor por defecto del padre
    //se inicializa por defecto el atributo puesto
    puesto = "sindatos";
}

Administrativo::Administrativo(unsigned long d, std::string n,
                               std::string m, std::string p) : Cliente(d, n, m)
{
    //se llama al constructor del padre 
    //con los datos ingresador por parametro
    //y se inicializa el atributo propio de Administrativo
    puesto = p;
}

void Administrativo::setPuesto(std::string p)
{
    puesto = p;
}

std::string Administrativo::getPuesto()
{
    return puesto;
}