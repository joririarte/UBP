#pragma once
#include "Cliente.h"
//Hereda de Cliente
class Administrativo : public Cliente
{
private:
	//Define un atributo propio
	std::string puesto;
public:
	//Constructor por Defecto inicializa atributos por defecto
	Administrativo();
	//Constructor con parametros, inicializa atributos segun parametros
	Administrativo(unsigned long d, std::string n, std::string m, std::string p);
	//Setea el puesto segun un string por parametro
	void setPuesto(std::string p);
	//devuelve un string con el valor del atributo puesto
	std::string getPuesto();
};