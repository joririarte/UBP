#pragma once
#include<string>
class TarjetaCredito
{
private:
	unsigned long nroTarjeta;
	float limiteCompra;
	std::string tipo;
public:
	//Constructor por defecto, incializa los atributos por defecto
	TarjetaCredito();
	//Constructor, inicializa nroTarjeta segun n
	TarjetaCredito(unsigned long n);
	//Obtiene el nro de Tarjeta
	unsigned long getNroTarjeta();
	//Setea el nro de tarjeta
	void setNroTarjeta(unsigned long n);
	//obtiene el limite de compra
	float getLimiteCompra();
	//Setea el limite de compra segun l
	void setLimiteCompra(float l);
	//Setea el limite de compra segun el tipo
	void setLimiteCompra();
	//Setea el tipo segun el sueldo declarado
	void setTipo(float sueldo);
	//obtiene el tipo de tarjeta
	std::string getTipo();
};