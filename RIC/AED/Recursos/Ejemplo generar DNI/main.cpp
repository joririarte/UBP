#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string dni;
    char sexo;
    float peso;
    float altura;

public:
/*    Persona(string nom="", int ed=0, char sex='H', float pes=0.0, float alt=0.0) {
        nombre = nom;
        edad = ed;
        sexo = sex;
        peso = pes;
        altura = alt;
        generaDNI();
    }*/


    const string &getNombre() const {
        return nombre;
    }

    Persona(const string &nombre, int edad, const string &dni, char sexo, float peso, float altura) : nombre(nombre),
                                                                                                      edad(edad),
                                                                                                      dni(dni),
                                                                                                      sexo(sexo),
                                                                                                      peso(peso),
                                                                                                      altura(altura) {}

    void setNombre(const string &nombre) {
        Persona::nombre = nombre;
    }

    int getEdad() const {
        return edad;
    }

    void setEdad(int edad) {
        Persona::edad = edad;
    }

    char getSexo() const {
        return sexo;
    }

    void setSexo(char sexo) {
        Persona::sexo = sexo;
    }

    float getPeso() const {
        return peso;
    }

    void setPeso(float peso) {
        Persona::peso = peso;
    }

    float getAltura() const {
        return altura;
    }

    void setAltura(float altura) {
        Persona::altura = altura;
    }

    void muestraDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "DNI: " << dni << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Peso: " << peso << endl;
        cout << "Altura: " << altura << endl;
    }

private:
    void generaDNI() {
        srand(time(NULL));
        dni = "";
        for (int i = 0; i < 8; i++) {
            int cifra = rand() % 10; // generamos una cifra aleatoria entre 0 y 9
            dni += to_string(cifra); // concatenamos la cifra generada a la cadena dni
        }
    }
};


int main() {
    Persona p1("Juan Perez", 35, 'H', 75.5, 1.75);
    p1.muestraDatos();

    string name = "";
    cout << "Escribe tu nombre: \n";
    getline(cin, name);
    cout << "Hola, " << name << endl;

    Persona p2;

    string namep2 = "";
    cout << "Escribe el nombre de la persona2: \n";
    getline(cin, namep2);
    p2.setNombre(namep2);

    int edad = 0;
    std::cout << "Escribe la edad de la persona \n" << std::endl;
    cin >> edad;
    p2.setEdad(edad);

    p2.muestraDatos();




    return 0;
}
