#pragma once
#include <string>
class Persona
{
private:
	std::string nombre = "";
	unsigned int edad = 0;
	unsigned int dni;
	char sexo = 'H';
	double peso = 0.f;
	double altura = 0.f;
public:
	Persona();
	Persona(std::string n, unsigned int e, char s);
	Persona(std::string n, unsigned int e, char s, double p, double h);
	std::string getNombre();
	void setNombre(std::string n);
	unsigned int getEdad();
	void setEdad(unsigned int e);
	unsigned int getDNI();
	char getSexo();
	void setSexo(char s);
	double getPeso();
	void setPeso(double p);
	double getAltura();
	void setAltura(double h);
	int imc();
	bool esMayorDeEdad();
private:
	//comprobarSexo(char s);
	unsigned int generaDNI();
};

