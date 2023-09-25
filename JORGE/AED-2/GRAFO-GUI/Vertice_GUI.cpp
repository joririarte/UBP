#include "Vertice_GUI.h"

Vertice_GUI::Vertice_GUI()
{

}

Vertice_GUI::Vertice_GUI(float rad, std::string nombre)
{
	forma = new sf::CircleShape(rad);
	forma->setOrigin(rad, rad);
	forma->setFillColor(sf::Color::Black);
	forma->setOutlineThickness(2.f);
	forma->setOutlineColor(sf::Color::White);

	etiqueta = new sf::Text;
	fuente = new sf::Font;
	if (!fuente->loadFromFile("ARCAMAJORA3-BOLD.OTF")) {
		exit(1);
	}
	etiqueta->setFont(*fuente);
	etiqueta->setString(nombre);
	etiqueta->setCharacterSize(24);
	etiqueta->setFillColor(sf::Color::White);
	etiqueta->setStyle(sf::Text::Bold);
	etiqueta->setOrigin(sf::Vector2f(8.f, 15.f));

	ubicar(250.f, 250.f);
}

sf::CircleShape* Vertice_GUI::getForma()
{
	return forma;
}

sf::Text Vertice_GUI::getEtiqueta()
{
	return *etiqueta;
}

void Vertice_GUI::onFocus()
{
	forma->setFillColor(sf::Color::Blue);
}

void Vertice_GUI::outFocus()
{
	forma->setFillColor(sf::Color::Black);
}

sf::FloatRect Vertice_GUI::getColisionBox()
{
	return forma->getGlobalBounds();
}

void Vertice_GUI::mover(float x, float y)
{
	forma->move(x, y);
	etiqueta->move(x, y);
}

void Vertice_GUI::ubicar(float x, float y)
{
	forma->setPosition(x, y);
	etiqueta->setPosition(x, y);
}
