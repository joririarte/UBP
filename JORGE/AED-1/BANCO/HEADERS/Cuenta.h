#pragma once
class Cuenta
{
private:
	//Atributos
	unsigned int nroCuenta;
	float saldo;//siempre se inicializa en cero
public:
	//Constructor por defecto, inicializa atributos por defecto
	Cuenta();
	//Constructor, inicializa el numero de la cuenta
	Cuenta(unsigned int n);
	//Setea el numero de la cuenta
	void setNroCuenta(unsigned int n);
	//Obtiene el numero de la cuenta
	unsigned int getNroCuenta();
	//Ingresa dinero a la cuenta
	void ingresar(float s);
	//retira dinero de la cuenta
	bool retirar(float s);
	//obtiene el valor del atributo saldo
	float getSaldo();
};