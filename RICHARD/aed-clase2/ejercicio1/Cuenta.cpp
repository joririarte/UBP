//
// Created by raugu on 23/3/2023.
//

#include "Cuenta.h"

Cuenta::Cuenta(const string &titular, double cantidad) : titular(titular), cantidad(cantidad) {}

Cuenta::Cuenta(const string &titular) : titular(titular) {}

const string &Cuenta::getTitular() const {
    return titular;
}

void Cuenta::setTitular(const string &titular) {
    Cuenta::titular = titular;
}

double Cuenta::getCantidad() const {
    return cantidad;
}

void Cuenta::setCantidad(double cantidad) {
    Cuenta::cantidad = cantidad;
}

void Cuenta::ingresar(double cantidad) {
    if (cantidad >= 0 ) {
        this->cantidad = this->cantidad + cantidad;
    } else
        ::printf("La cantidad ingresada debe ser positiva \n" );
}

void Cuenta::retirar(double cantidad) {
    if ((this->cantidad - cantidad) < 0 ) {
        this->cantidad = 0;
        ::printf("La cantidad retirada excede a la disponible \n" );

    } else
        this->cantidad = this->cantidad - cantidad;
}


