#pragma once
#include<string>
#include "Cuenta.h";
class Cliente
{
private:
	unsigned long dni;
	std::string nombre;
	std::string mail;
	bool estado;
	Cuenta* cuenta;
public:
	//Constructor, inicializa los atributos por defecto
	Cliente();
	//Contructor, incializa los atributos segun los parametros
	Cliente(unsigned long d, std::string n, std::string m);
	//Setea el dni segun d
	void setDni(unsigned long d);
	//obtiene el dni
	unsigned long getDni();
	//setea el nombre segun n
	void setNombre(std::string n);
	//obtiene el nombre
	std::string getNombre();
	//Setea el mail segun m
	void setMail(std::string m);
	//obtiene el mail
	std::string getMail();
	//setea el estado segun e
	void setEstado(bool e);
	//obtiene el estado
	bool getEstado();
	//setea el puntero cuenta segun c
	void setCuenta(Cuenta* c);
	//obtiene el puntero cuenta
	Cuenta* getCuenta();
};