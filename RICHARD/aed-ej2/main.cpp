#include <iostream>
#include "Persona.h"

// TODO
// método generaDNI no retorna 8 cifras
// mejorar ingreso de datos


int main() {
    // Ingresar por teclado el nombre, la edad, sexo, peso y altura
    std::string nombre;
    int edad;
    char sexo;
    float peso, altura;

    std::cout << "Ingrese el nombre: ";
    getline(std::cin, nombre);

    std::cout << "Ingrese la edad: ";
    std::cin >> edad;

    std::cout << "Ingrese el sexo (H/M): ";
    std::cin >> sexo;

    std::cout << "Ingrese el peso en kg: ";
    std::cin >> peso;

    std::cout << "Ingrese la altura en metros: ";
    std::cin >> altura;

    // Crear 3 objetos de la clase Persona
    std::Persona persona1(nombre, edad, sexo, peso, altura);
    std::Persona persona2(nombre, edad, sexo);
    std::Persona persona3;

    // Comprobar si están en su peso ideal
    int imc1 = persona1.calcularIMC();
    int imc2 = persona2.calcularIMC();
    int imc3 = persona3.calcularIMC();

    // Indicar si son mayores de edad
    bool mayor1 = persona1.esMayorDeEdad();
    bool mayor2 = persona2.esMayorDeEdad();
    bool mayor3 = persona3.esMayorDeEdad();

    // Mostrar la información de cada objeto
    std::cout << "Datos de la persona 1: " << std::endl;
    persona1.mostrarDatos();
    std::cout << "IMC: " << imc1 << std::endl;
    std::cout << "Mayor de edad: " << mayor1 << std::endl;

    std::cout << "Datos de la persona 2: " << std::endl;
    persona2.mostrarDatos();
    std::cout << "IMC: " << imc2 << std::endl;
    std::cout << "Mayor de edad: " << mayor2 << std::endl;

    std::cout << "Datos de la persona 3: " << std::endl;
    persona3.mostrarDatos();
    std::cout << "IMC: " << imc3 << std::endl;
    std::cout << "Mayor de edad: " << mayor3 << std::endl;


    return 0;
}
