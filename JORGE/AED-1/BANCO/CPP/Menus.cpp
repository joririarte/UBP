#include "Menus.h"
#include <iostream>
#include <string>
using namespace std;

//muestra el menu principal y devuelve un valor para usar en el programa
int menu::showMainMenu()
{
	int op=0;
	do {
		system("cls");
		cout << "Menu Principal\n";
		cout << "\n1 - Alta Cliente";
		cout << "\n2 - Baja Cliente";
		cout << "\n3 - Crear Cuenta Sueldo";
		cout << "\n4 - Tarjeta Credito";
		cout << "\n5 - Mostrar Cliente";
		cout << "\n6 - Salir";
		cout << "\n\nOpcion: ";
		cin >> op;
		switch (op)
		{
		case 1:
			op = 1;
			break;
		case 2:
			op = 2;
			break;
		case 3:
			op = 3;
			break;
		case 4:
			op = 4;
			break;
		case 5:
			op = 5;
			break;
		case 6:
			break;
		default:
			cout << "Ingresa una opcion correcta!\n";
			system("pause");
			break;
		}
	} while (op < 1 || op > 6);
	return op;
}

bool menu::opcionAoP()
{
	char op;
	do {
		system("cls");
		cout << "\nA: Administrativo";
		cout << "\nP: Profesional";
		cout << "\nIngrese A o P: ";
		cin >> op;
	} while (toupper(op) != 'A' && toupper(op) != 'P');
	return toupper(op)=='A';
}

void menu::error()
{
	cout << "\n\nError! ";
	cout << "\nPuede deberse a: ";
	cout << "\n1 - No hay clientes (de este tipo) dados de alta";
	cout << "\n2 - No hay Cuenta asociada\n\n";
	system("pause");
}

//Da de alta un Administrativo
void menu::altaCliente(Administrativo* adm)
{
	unsigned long dni;
	std::string nombre;
	std::string mail;
	std::string puesto;

	//pide por teclado los datos 
	cout << "\nIngrese dni: ";
	cin >> dni;
	cin.ignore();
	cout << "\nIngrese Nombre: ";
	getline(cin, nombre);
	cout << "\nIngrese Mail: ";
	cin >> mail;
	cin.ignore();
	cout << "\nIngrese Puesto: ";
	getline(cin, puesto);

	//setea los atributos 
	//con los datos ingresados por teclado
	adm->setDni(dni);
	adm->setNombre(nombre);
	adm->setMail(mail);
	adm->setPuesto(puesto);
	adm->setEstado(true);
}

//Da de alta un Profesional
void menu::altaCliente(Profesional* pro)
{
	unsigned long dni;
	std::string nombre;
	std::string mail;
	std::string titulo;
	std::string actividad;
	unsigned short antiguedad;

	//pide por teclado los datos
	cout << "\nIngrese dni: ";
	cin >> dni;
	cin.ignore();
	cout << "\nIngrese Nombre: ";
	getline(cin, nombre);
	cout << "\nIngrese Mail: ";
	cin >> mail;
	cin.ignore();
	cout << "\nIngrese Titulo: ";
	getline(cin, titulo);
	cout << "\nIngrese Actividad: ";
	getline(cin, actividad);
	cout << "\nIngrese Antiguedad: ";
	cin >> antiguedad;

	//setea los atributos 
	//con los datos ingresados por teclado
	pro->setDni(dni);
	pro->setNombre(nombre);
	pro->setMail(mail);
	pro->setTitulo(titulo);
	pro->setActividad(actividad);
	pro->setAntiguedad(antiguedad);
	pro->setEstado(true);
}

//Da de baja un Administrativo
void menu::bajaCliente(Administrativo* adm)
{
	//cambia la badera de estado a false
	adm->setEstado(false);
}

//Da de baja un Profesional
void menu::bajaCliente(Profesional* pro)
{
	//cambia la badera de estado a false
	pro->setEstado(false);
}

//"crea" la cuenta para un administrativo
void menu::crearCuenta(Administrativo* adm)
{
	unsigned int nroCta;
	float saldo;
	char op;

	//Pide los datos de la cuenta por teclado
	cout << "\nIngrese nro Cuenta: ";
	cin >> nroCta;
	//setea el numero de la cuenta
	adm->getCuenta()->setNroCuenta(nroCta);

	//Deposito inicial
	cout << "\n\nDesea hacer un deposito inicial?";
	cout << "\nS: si";
	cout << "\nN: no";
	cout << "\n\nIngrese S o N: ";
	cin >> op;
	if (toupper(op) == 'S') {
		cout << "\n\nIngrese monto: ";
		cin >> saldo;
		//ingresa dinero a la cuenta
		adm->getCuenta()->ingresar(saldo);
	}
}
//"crea" la cuenta para un Profesional
void menu::crearCuenta(Profesional* pro)
{
	unsigned int nroCta;
	float saldo;
	char op;

	//Pide los datos de la cuenta por teclado
	cout << "\nIngrese nro Cuenta: ";
	cin >> nroCta;
	//setea el numero de la cuenta
	pro->getCuenta()->setNroCuenta(nroCta);

	//Deposito inicial
	cout << "\n\nDesea hacer un deposito inicial?";
	cout << "\nS: si";
	cout << "\nN: no";
	cout << "\n\nIngrese S o N: ";
	cin >> op;
	if (toupper(op) == 'S') {
		cout << "\n\nIngrese monto: ";
		cin >> saldo;
		//ingresa dinero a la cuenta
		pro->getCuenta()->ingresar(saldo);
	}
}

//Otorga Tarjeta de Credito
void menu::darTarjeta(Profesional* pro)
{
	unsigned long nroTarj;
	float sueldo;

	//Pide los datos de la tarjeta por teclado
	cout << "Ingrese sueldo";
	cin >> sueldo;
	cout << "Ingrese nro de Tarjeta";
	cin >> nroTarj;

	//Setea los atributos de la tarjeta
	pro->getTarjetaCredito()->setNroTarjeta(nroTarj);
	pro->getTarjetaCredito()->setTipo(sueldo);
	pro->getTarjetaCredito()->setLimiteCompra();
}

//Muestra por pantalla un administrativo
void menu::mostrar(Administrativo* adm)
{
	show(adm);
	cout << "Puesto: " << adm->getPuesto()<<endl;
	system("pause");
}

//Muestra por pantalla un profesional
void menu::mostrar(Profesional* pro)
{
	show(pro);
	cout << "\nTitulo: " << pro->getTitulo();
	cout << "\nActividad: " << pro->getActividad();
	cout << "\nAntiguedad: " << pro->getAntiguedad();
	if (pro->getTarjetaCredito() != nullptr) {
		cout << "\nNum. Tarj. de Credito: " << pro->getTarjetaCredito()->getNroTarjeta();
		cout << "\nLimite Compra: " << pro->getTarjetaCredito()->getLimiteCompra();
		cout << "\nTipo Tarj.: " << pro->getTarjetaCredito()->getTipo();
	}
	cout << endl;
	system("pause");
}

//Muestra por pantalla un Cliente
void menu::show(Cliente* cl)
{
	cout << "\nDNI: " << cl->getDni();
	cout << "\nNombre: " << cl->getNombre();
	cout << "\nMail: " << cl->getMail();
	if (cl->getCuenta() != nullptr) {
		cout << "\nNumero Cuenta: " << cl->getCuenta()->getNroCuenta();
		cout << "\nSaldo: "<<cl->getCuenta()->getSaldo();
	}
}
