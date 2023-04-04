#include "triangulo.h"
#include <cmath>

triangulo::triangulo()
{
	lado1 = 1;
	lado2 = 1;
	lado3 = 1;
}

triangulo::triangulo(float l1, float l2, float l3)
{
	lado1 = l1;
	lado2 = l2;
	lado3 = l3;
}

void triangulo::setLado1(float l)
{
	lado1 = l;
}

void triangulo::setLado2(float l)
{
	lado2 = l;
}

void triangulo::setLado3(float l)
{
	lado3 = l;
}

float triangulo::getSuperficie()
{
	/*
	* area=(sp*(sp-l1)*(sp-l2)*(sp-l3))^1/2
	* sp: semiperimetro
	* sp=(l1+l2+l3)/2
	*/
	float sp = (lado1 + lado2 + lado3) / 2;
	return sqrt(sp * (sp - lado1) * (sp - lado2) * (sp - lado3));
}