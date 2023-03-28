//
// Created by raugu on 25/3/2023.
//

#ifndef AED_EJ2_PERSONA_H
#define AED_EJ2_PERSONA_H

#include <string>

namespace std {

    class Persona {
    private:
        std::string nombre;
        int edad;
        char sexo;
        float peso;
        float altura;
        std::string DNI;

        char comprobarSexo(char sexo);

    public:
        Persona();
        Persona(std::string nombre, int edad, char sexo = 'H');
        Persona(std::string nombre, int edad, char sexo, float peso, float altura);

        int calcularIMC();
        bool esMayorDeEdad();
        void generaDNI();

        void setNombre(std::string nombre);
        void setEdad(int edad);
        void setSexo(char sexo);
        void setPeso(float peso);
        void setAltura(float altura);

 /*     std::string getNombre();
        int getEdad();
        char getSexo();
        float getPeso();
        float getAltura();
        std::string getDNI();*/

        void mostrarDatos();

    };

} // std

#endif //AED_EJ2_PERSONA_H
