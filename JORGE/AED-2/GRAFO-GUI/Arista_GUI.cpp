#include "Arista_GUI.h"
#include <cmath>

void Arista_GUI::setModulo()
{
    Dx = destino->getForma()->getPosition().x - origen->getForma()->getPosition().x;
    Dy = destino->getForma()->getPosition().y - origen->getForma()->getPosition().y;
    modulo = sqrt(pow(Dx, 2) + pow(Dy, 2));
}

void Arista_GUI::setAngulo()
{
    angulo = atan(Dy / Dx) * 180.f / 3.14159265f;
    if (angulo >= 0) {
        if (Dx < 0 && Dy < 0) {
            angulo += 180.f;
        }
    }
    else {
        if (Dx < 0 && Dy>=0) {
            angulo -= 180.f;
        }
    }
}

Arista_GUI::Arista_GUI()
{

}

void Arista_GUI::setArista(Vertice_GUI* _origen, Vertice_GUI* _destino, int _peso)
{
    origen = _origen;
    destino = _destino;
    setModulo();
    linea = new sf::RectangleShape(sf::Vector2f(modulo,1.2f));
    linea->setPosition(origen->getForma()->getPosition());
    linea->setFillColor(sf::Color::White);
    moverArista();
}

void Arista_GUI::resaltar(bool _resaltar)
{
    if (_resaltar)
        linea->setFillColor(sf::Color::Red);
}

void Arista_GUI::moverArista()
{
    setAngulo();
    linea->setRotation(angulo);
}

Vertice_GUI* Arista_GUI::getOrigen()
{
    return origen;
}

Vertice_GUI* Arista_GUI::getDestino()
{
    return destino;
}

sf::RectangleShape* Arista_GUI::getArista()
{
	return linea;
}

sf::FloatRect Arista_GUI::getColisionBox()
{
    return linea->getGlobalBounds();
}

void Arista_GUI::onFocus()
{
    linea->setFillColor(sf::Color::Red);
}

void Arista_GUI::outFocus()
{
    linea->setFillColor(sf::Color::White);
}
