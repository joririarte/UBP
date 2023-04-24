#pragma once
#include "Cliente.h"
#include "TarjetaCredito.h"
//Hereda de cliente
class Profesional : public Cliente
{
private:
	//Define atributos propios
	std::string titulo;
	std::string actividad;
	unsigned short antiguedad;
	TarjetaCredito* tarjeta;
public:
	//Constructor por defecto, inicializa atributos por defecto
	Profesional();
	//Constructor, inicializa atributos segun parametros
	Profesional(unsigned long int d,std::string n,std::string m,
				std::string t,std::string act, unsigned short ant);
	//Setea el atributo Titulo
	void setTitulo(std::string t);
	//Devueve un string con el valor del atributo Titulo
	std::string getTitulo();
	//Setea el atributo Actividad
	void setActividad(std::string a);
	//Devueve un string con el valor del atributo Actividad
	std::string getActividad();
	//Setea el atributo Antiguedad
	void setAntiguedad(unsigned short a);
	//Devueve un entero corto sin signo con el valor del atributo Antiguedad
	unsigned short getAntiguedad();
	//Setea el atributo Tarjeta de Credito
	void setTarjetaCredito(TarjetaCredito* t);
	//Devueve un puntero a objeto de la tarjeta de credito
	TarjetaCredito* getTarjetaCredito();
};