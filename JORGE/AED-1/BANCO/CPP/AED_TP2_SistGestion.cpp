/*
* 
* AED 1 2023
* TP 2 Sistema Gestion
* Iriarte Jorge
*
*/
#include <iostream>
#include <fstream>
#include "Menus.h"
#include "Cliente.h"
#include "Administrativo.h"
#include "Profesional.h"
#include "TarjetaCredito.h"

using namespace std;
using namespace menu;

int main()
{
	Administrativo* admin = new Administrativo();
	Profesional* prof = new Profesional();
	Cuenta* ctaAdmin=new Cuenta(), * ctaProf = new Cuenta();
	TarjetaCredito* tarjProf = new TarjetaCredito();
	bool salir = false;
	while (!salir) {
		switch (showMainMenu()) {
		case 1:
			//dar de alta un cliente
			if (opcionAoP())
				if (admin != nullptr)
					altaCliente(admin);
				else error();
			else if (prof != nullptr)
				altaCliente(prof);
			else error();
			break;
		case 2:
			//dar de baja un cliente
			if (opcionAoP())
				if (admin != nullptr)
					bajaCliente(admin);
				else error();
			else if (prof != nullptr)
				bajaCliente(prof);
			else error();
			break;
		case 3:
			//Crear Cuenta Bancaria
			//Solo si existen clientes dados de alta
			if (opcionAoP()) {
				if (admin->getEstado()) {
					admin->setCuenta(ctaAdmin);
					crearCuenta(admin);
				}
				else error();
			}
			else if (prof->getEstado()) {
				prof->setCuenta(ctaProf);
				crearCuenta(prof);
			}
			else error();
			break;
		case 4:
			//Otorgar Tarjeta de Credito
			//Solo si el profesional posee una cuenta bancaria
			if (prof->getEstado() && prof->getCuenta() != nullptr) {
				prof->setTarjetaCredito(tarjProf);
				darTarjeta(prof);
			}
			else error();
			break;
		case 5:
			//Mostrar Cliente
			//Solo si existen dados de alta
			if (opcionAoP()) {
				if (admin->getEstado()) {
					mostrar(admin);
				}
			}
			else if (prof->getEstado()) {
				mostrar(prof);
			}
			else error();
			break;
		case 6:
			salir = true;
			break;
		}
	}
	delete admin, prof, ctaAdmin, ctaProf, tarjProf;
	return 0;
}