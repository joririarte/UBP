#pragma once
#include <SFML/Graphics.hpp>
class Vertice_GUI
{
private:
	float radio;
	sf::CircleShape* forma;
	sf::Text* etiqueta;
	sf::Font* fuente;
public:
	Vertice_GUI();
	Vertice_GUI(float rad, std::string nombre);
	sf::CircleShape* getForma();
	sf::Text getEtiqueta();
	void onFocus();
	void outFocus();
	sf::FloatRect getColisionBox();
	void mover(float x, float y);
	void ubicar(float x, float y);
};

