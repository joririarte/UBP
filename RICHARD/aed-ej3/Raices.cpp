//
// Created by raugu on 25/3/2023.
//

#include "Raices.h"
#include <iostream>
#include <cmath>


namespace std {

    Raices::Raices(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double Raices::getDiscriminante() {
        return (b * b) - (4 * a * c);
    }

    bool Raices::tieneRaices() {
        return getDiscriminante() > 0;
    }

    bool Raices::tieneRaiz() {
        return getDiscriminante() == 0;
    }

    void Raices::obtenerRaices() {
        double x1 = (-b + sqrt(getDiscriminante()) ) / (2 * a);
        double x2 = (-b - sqrt(getDiscriminante()) ) / (2 * a);

        std::cout << "Las raíces son: \n X1= " << x1 << "\n X2= "<< x2 << std::endl;
    }

    void Raices::obtenerRaiz() {
        double x = -b / (2 * a);
        std::cout << "La raíz es: \n X=" << x << std::endl;
    }

    void Raices::calcular() {
        if(tieneRaices()) { obtenerRaices();}
        else if (tieneRaiz()) {obtenerRaiz();}
        else { std::cout << "El sistema no tiene soluciones en el dominio R" << std::endl; }
    }




} // std