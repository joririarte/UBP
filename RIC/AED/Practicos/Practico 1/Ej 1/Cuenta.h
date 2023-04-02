//
// Created by raugu on 23/3/2023.
//

#ifndef AED_CLASE2_CUENTA_H
#define AED_CLASE2_CUENTA_H
#include <iostream>

using namespace std;

class Cuenta {
    private:
        string titular;
        double cantidad;
    public:
    Cuenta(const string &titular, double cantidad);
    explicit Cuenta(const string &titular);

    const string &getTitular() const;

    void setTitular(const string &titular);

    double getCantidad() const;

    void setCantidad(double cantidad);

    void ingresar(double cantidad);

    void retirar(double cantidad);


};


#endif //AED_CLASE2_CUENTA_H
