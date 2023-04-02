//
// Created by raugu on 25/3/2023.
//

#include "Persona.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

namespace std {

    Persona::Persona() {
        this->nombre = "";
        this->edad = 0;
        this->sexo = 'H';
        this->peso = 0;
        this->altura = 0;
        generaDNI();
    }

    Persona::Persona(std::string nombre, int edad, char sexo) {
        this->nombre = nombre;
        this->edad = edad;
        this->sexo = comprobarSexo(sexo);
        this->peso = 0;
        this->altura = 0;
        generaDNI();
    }

    Persona::Persona(std::string nombre, int edad, char sexo, float peso, float altura) {
        this->nombre = nombre;
        this->edad = edad;
        this->sexo = comprobarSexo(sexo);
        this->peso = peso;
        this->altura = altura;
        generaDNI();
    }

    char Persona::comprobarSexo(char sexo) {
        if (sexo == 'H' || sexo == 'M') {
            return sexo;
        } else {
            return 'H';
        }
    }


    int Persona::calcularIMC() {
        if (altura == 0) {
            return -1;
        } else {
            float imc = peso / (altura * altura);
            if (imc < 20) {
                return -1;
            } else if (imc >= 20 && imc <= 25) {
                return 0;
            } else {
                return 1;
            }
        }
    }

    bool Persona::esMayorDeEdad() {
        return edad >= 18;
    }

    void Persona::generaDNI() {
        srand(time(NULL));
        int prefijo = rand() % 1000;
        int num = rand() % 1000000;
        DNI = std::to_string(prefijo) + std::to_string(num);
    }

/*
    void Persona::generaDNI() {
        std::srand(std::time(nullptr));
        int num = std::rand() % 90000000 + 10000000;
        DNI = std::to_string(num);
    }
*/

    void Persona::setNombre(std::string nombre) {
        this->nombre = nombre;
    }

    void Persona::setEdad(int edad) {
        this->edad = edad;
    }

    void Persona::setSexo(char sexo) {
        this->sexo = comprobarSexo(sexo);
    }

    void Persona::setPeso(float peso) {
        this->peso = peso;
    }

    void Persona::setAltura(float altura) {
        this->altura = altura;
    }

   /* std::string Persona::getNombre() {
        return nombre;
    }

    int Persona::getEdad() {
        return edad;
    }

    char Persona::getSexo() const {
        return sexo;
    }

    float Persona::getPeso() const {
        return peso;
    }

    float Persona::getAltura() const {
        return altura;
    }

    std::string Persona::getDNI() const {
        return DNI;
    }*/


   void Persona::mostrarDatos() {
       cout << "Nombre: " << nombre << endl;
       cout << "Edad: " << edad << endl;
       cout << "DNI: " << DNI << endl;
       cout << "Sexo: " << sexo << endl;
       cout << "Peso: " << peso << " kg" << endl;
       cout << "Altura: " << altura << " m" << endl;
   }

} // std