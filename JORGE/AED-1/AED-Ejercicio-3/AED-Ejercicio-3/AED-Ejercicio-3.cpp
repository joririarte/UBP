#include <iostream>
#include <iostream>
#include "Raices.h"

using namespace std;

int main()
{
	double a, b, c;
	cout << "Ingrese coeficientes de ecuacion de 2do grado";
	cout << "\nA: ";
	cin >> a;
	cout << "\nB: ";
	cin >> b;
	cout << "\nC: ";
	cin >> c;
	Raices ecuacion(a,b,c);
	ecuacion.calcular();
}
