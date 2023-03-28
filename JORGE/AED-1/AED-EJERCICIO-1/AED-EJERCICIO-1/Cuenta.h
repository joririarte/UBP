#pragma once
class Cuenta {
private:
    int titular;
    double saldo;
public:
    Cuenta(int tit);
    Cuenta(int tit,double sal);
    int getTitular();
    void setTitular(int tit);
    double getSaldo();
    void setSaldo(double sal);
    void ingresar(double monto);
    void retirar(double monto);
    ~Cuenta();
};

