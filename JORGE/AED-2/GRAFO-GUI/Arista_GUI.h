#pragma once
#include<SFML/Graphics.hpp>
#include "Vertice_GUI.h"
class Arista_GUI
{
private:
	sf::RectangleShape* linea;
	Vertice_GUI* origen;
	Vertice_GUI* destino;
	float Dx,Dy, modulo, angulo;
	int peso;
	bool resaltada=false;
	void setModulo();
	void setAngulo();
public:
	Arista_GUI();
	void setArista(Vertice_GUI* _origen, Vertice_GUI* _destino, int _peso);
	void resaltar(bool _resaltar);
	void moverArista();
	Vertice_GUI* getOrigen();
	Vertice_GUI* getDestino();
	sf::RectangleShape* getArista();
	sf::FloatRect getColisionBox();
	void onFocus();
	void outFocus();
};

