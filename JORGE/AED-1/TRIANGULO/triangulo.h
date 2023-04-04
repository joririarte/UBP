#pragma once
class triangulo
{
private:
	float lado1, lado2, lado3;
public:
	triangulo();
	triangulo(float l1, float l2, float l3);
	void setLado1(float l);
	void setLado2(float l);
	void setLado3(float l);
	float getSuperficie();
};

