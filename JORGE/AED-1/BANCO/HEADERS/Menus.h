#pragma once
#include"Cliente.h";
#include"Profesional.h";
#include "Administrativo.h"
#include "TarjetaCredito.h"
#include "Cuenta.h";

namespace menu {
	//Muestra el menu principal y devuelve un valor para usar en el programa
	int showMainMenu();
	bool opcionAoP();
	void error();

	//Da de alta un Administrativo
	void altaCliente(Administrativo* adm);
	//Da de alta un Profesional
	void altaCliente(Profesional* pro);
	//Da de baja un Administrativo
	void bajaCliente(Administrativo* adm);
	//Da de baja un Profesional
	void bajaCliente(Profesional* pro);
	//"crea" la cuenta para un Administrativo
	void crearCuenta(Administrativo* adm);
	//"crea" la cuenta para un Profesional
	void crearCuenta(Profesional* pro);
	//Otorga Tarjeta de Credito
	void darTarjeta(Profesional* pro);
	//Muestra por pantalla un Administrativo
	void mostrar(Administrativo* adm);
	//Muestra por pantalla un profesional
	void mostrar(Profesional* pro);
	//Muestra por pantalla un Cliente
	void show(Cliente* cl);
};