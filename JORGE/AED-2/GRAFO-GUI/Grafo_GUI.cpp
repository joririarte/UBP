#include "Grafo_GUI.h"
#include <cmath>

using namespace std;

Grafo_GUI::Grafo_GUI(int** Ady, int tam, bool** _resaltadas,std::string nombreVentana) {
    this->window = new sf::RenderWindow(sf::VideoMode(wSize, wSize), nombreVentana);

    srand(time(NULL));

    this->cant_vertices = tam;
    for (int i = 0; i < this->cant_vertices; i++) {
        for (int j = 0; j < this->cant_vertices; j++) {
            if (Ady[i][j] != 0) {
                this->cant_aristas++;
            }
        }
    }


    //Nodes
    float space = 2 * 3.1416 / cant_vertices, ang;
    this->vertices = new Vertice_GUI*[this->cant_vertices];
    for (int i = 0; i < this->cant_vertices; i++) {
        
        this->init_etiqueta[0] += i;
        this->vertices[i] = new Vertice_GUI(rad_circle, init_etiqueta);
        this->init_etiqueta = "A";
        
        ang = i * space;
        
        float x = cos(ang) * 200.f, y = sin(ang) * 200.f;
        
        this->vertices[i]->mover(x, y);
    }

    //Creo las aristas
    //Edges
    this->aristas = new Arista_GUI * [this->cant_aristas];
    for (int i = 0; i < this->cant_aristas; i++) {
        this->aristas[i] = new Arista_GUI;
    }
    int n = 0;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (Ady[i][j] != 0) {
                this->aristas[n]->setArista(this->vertices[i], this->vertices[j],Ady[i][j]);
                this->aristas[n]->resaltar(_resaltadas[i][j]);
                this->aristas[n]->resaltar(_resaltadas[j][i]);
                n++;
            }
        }
    }
}

void Grafo_GUI::focus(Vertice_GUI* node) {
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*window));
    if (node->getColisionBox().contains(mousePos)) {
        node->onFocus();
    }
    else {
        node->outFocus();
    }
}

void Grafo_GUI::focus(Arista_GUI* edge)
{
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*window));
    if (edge->getColisionBox().contains(mousePos)) {
        edge->onFocus();
    }
    else {
        edge->outFocus();
    }
}

void Grafo_GUI::run() {
    sf::CircleShape* click=0;
    while (window->isOpen())
    {
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
        }
        this->window->clear();

        //Draw Edges
        for (int i = 0; i < this->cant_aristas; i++) {
            this->window->draw(*this->aristas[i]->getArista());
        }

        //Draw Nodes & Labels
        for (int i = 0; i < this->cant_vertices; i++) {
            this->focus(vertices[i]);
            this->window->draw(*this->vertices[i]->getForma());
            this->window->draw(this->vertices[i]->getEtiqueta());
        }

        this->window->display();

    }

}

Grafo_GUI::~Grafo_GUI() {
}
