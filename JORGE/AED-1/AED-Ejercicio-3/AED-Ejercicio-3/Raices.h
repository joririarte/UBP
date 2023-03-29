#pragma once
class Raices
{
private:
	double a, b, c;
	
	void obtenerRaices();
	void obtenerRaiz();
	double getDiscriminante();
	bool tieneRaices();
	bool tieneRaiz();
public:
	Raices(double A, double B, double C);
	void calcular();
	void setA(double A);
	void setB(double B);
	void setC(double C);
	double getA();
	double getB();
	double getC();
};