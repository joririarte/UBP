#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

void mostrar(Persona p);
string decodeIMC(int imc);

int main()
{
	string nombre;
	unsigned int edad;
	char sexo;
	double peso, altura;
	Persona *personas[3];
	for (int i = 0; i < 3; i++) {
		system("cls");
		cout << "Persona " << i+1;
		cout << "\n\nIngrese nombre: ";
		getline(cin, nombre);
		cout << "\nIngrese edad: ";
		cin >> edad;
		cout << "\nIngrese sexo (H/M): ";
		cin >> sexo;
		cout << "\nIngrese peso (Kg): ";
		cin >> peso;
		cout << "\nIngrese altura (M): ";
		cin >> altura;
		personas[i] = new Persona(nombre, edad, sexo, peso, altura);
		cin.ignore();
	}
	system("cls");
	cout.width(10);
	cout << "DNI";
	cout.width(30);
	cout << "Nombre";
	cout.width(10);
	cout << "Edad";
	cout.width(10);
	cout << "Peso";
	cout.width(10);
	cout << "Altura";
	cout.width(15);
	cout << "IMC";
	cout << endl;
	for (int i = 0; i < 3; i++) {
		mostrar(*personas[i]);
	}
}

void mostrar(Persona p)
{
	cout.width(10);
	cout << p.getDNI();
	cout.width(30);
	cout << p.getNombre();
	cout.width(10);
	cout << p.getEdad();
	cout.width(10);
	cout << p.getPeso();
	cout.width(10);
	cout << p.getAltura();
	cout.width(15);
	cout << decodeIMC(p.imc());
	cout << endl;
}

string decodeIMC(int imc)
{
	string val = imc < 0 ? "Bajo Peso" : imc > 0 ? "Sobrepeso" : "Peso Ideal";
	return val;
}
