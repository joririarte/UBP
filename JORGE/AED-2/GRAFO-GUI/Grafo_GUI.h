#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vertice_GUI.h"
#include "Arista_GUI.h"
class Grafo_GUI
{
private:
    const float rad_circle = 30.f;
    const int wSize = 500;
    unsigned int cant_vertices = 0;
    unsigned int cant_aristas = 0;
    Vertice_GUI** vertices;
    Arista_GUI** aristas;
    std::string init_etiqueta = "A";
    sf::RenderWindow* window;

    void focus(Vertice_GUI*);
    void focus(Arista_GUI*);
    /*sf::CircleShape* Clicked();
    void Released(sf::CircleShape*);*/
public:
    Grafo_GUI(int** Ady, int tam, bool** _resaltadas,std::string nombreVentana);
    ~Grafo_GUI();
    void run();
};

