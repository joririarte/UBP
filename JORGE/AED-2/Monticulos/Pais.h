#pragma once
#include<iostream>
class Pais
{
private:
	std::string nombre="NO NAME";
	long int poblacion=0.f;
	long int PBI=0.0f;
public:
	Pais() {};
	Pais(std::string _nombre, long int _poblacion, long int _PBI);
	~Pais();
	std::string getNombre();
	long int getPoblacion();
	long int getPBI();
	void setNombre(std::string _nombre);
	void setPoblacion(long int _poblacion);
	void setPBI(long int _PBI);
	
	//Sobrecarga de operadores logicos para comparacion
	bool operator>(Pais p);
	bool operator<(Pais p);
	bool operator==(Pais p);
	
	//sobrecarga de operacion de flujo para muestra de datos
	friend std::ostream& operator<<(std::ostream& os, Pais p);
};