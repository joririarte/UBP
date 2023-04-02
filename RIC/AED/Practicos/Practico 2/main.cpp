#include <iostream>
#include <cstring>

using namespace std;



char* aMayuscula(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

char* invierteCadena(char* str) {
    int len = strlen(str) - 1; // Saco el caracter nulo
    char aux = ' ';
    for (int i = 0; i < (len / 2) ; i++) {
        aux = str[i];
        str[i] = str[len - i];
        str [len - i] = aux;
    }
    str[len + 1] = '\0';

    return str;
}

void copiarCadena(char* copia, const char* original) {
    while (*original != '\0') {
        *copia = *original;
        copia++;
        original++;
    }
    *copia = '\0';
}

int contadorVocalesMinuscula(char* str) {
    int contador = 0;
    while (*str != '\0'){
        if (*str == 'a' ||
           *str == 'e' ||
           *str == 'i' ||
           *str == 'o' ||
           *str == 'u')
        contador ++;
        str++;
    }
    return contador;
}


/*1. Escribir un programa que declare e inicialice dos variables enteras y un puntero a entero.
 * A continuación, asigne al puntero la dirección de la primera variable e
 * imprima la dirección de memoria apuntada y su contenido.
 * Repetir la operación para la segunda variable.
        */

int main() {

/*    // ej 1
 *
 * /*1. Escribir un programa que declare e inicialice dos variables enteras y un puntero a entero.
 * A continuación, asigne al puntero la dirección de la primera variable e
 * imprima la dirección de memoria apuntada y su contenido.
 * Repetir la operación para la segunda variable.
 *
    int a = 10;
    int b = 20;
    int* p;

    p = &a;
    cout << "La dirección de memoria que apunta p es: " << p << endl;
    cout << "El contenido al que apunta p es: " << *p << endl;*/


// ***********************************************************************************************

    // ej 2
/*2. Escribir un programa que declare un arreglo de 5 enteros, y un puntero a entero.
Comprobar que los elementos del arreglo ocupan posiciones sucesivas en memoria, escribiendo sus direcciones.*/

 /*   int a[5];
    int* p;
    p = &a[0];

    cout << "El valor de memoria 0 de a es: " << &a[0] << endl;
    cout << "El valor de memoria 1 de a es: " << &a[1] << endl;
    cout << "El valor de memoria 2 de a es: " << &a[2] << endl;
    cout << "El valor de memoria 3 de a es: " << &a[3] << endl;
    cout << "El valor de memoria 4 de a es: " << &a[4] << endl;
    cout << "El valor de memoria 5 de a es: " << &a[5] << endl;

    cout << "El valor de memoria que apunta p es: " << p << endl;
    cout << "El valor de p es: " << *p << endl; */

 //***************** otra forma

/*
    int arr[5]; // declarar un arreglo de 5 enteros
    int *q; // declarar un puntero a entero

    // asignar las direcciones de memoria del arreglo al puntero
    q = arr;

    // imprimir las direcciones de memoria de cada elemento del arreglo
    for (int i = 0; i < 5; i++) {
        cout << "Direccion de memoria del elemento " << i << ": " << &arr[i] << endl;
    }
*/



// ***********************************************************************************************

//ej 3
/*
    3. Para el arreglo del ejercicio anterior, declare dos punteros a entero y asigneles
    las direcciones del primer y último elemento del arreglo. Imprima la diferencia
    entre ambos punteros.
*/

/*    int* r;
    int* l;

    r = &arr[0];
    l = &arr[5];

    cout <<"La dirección de memoria que apunta r es: " << r << endl;
    cout <<"La dirección de memoria que apunta l es: " << l << endl;
    cout <<"La diferencia entre las direcciones de memoria es: " << l - endl;*/

// ******************************************************************************************

// ej 4
/*
4. Realizar un programa que rellene de forma aleatoria con los primeros 100
números un arreglo de 15 elementos. Mostrar por medio de punteros los valores
en el vector y la dirección de memoria de cada uno.
*/

/*    int* arr = new int[14];
    srand(time(NULL));
    int nroRand= 0;


    for (int i = 0; i < 15; i++) {
        nroRand = rand() % 100;; // generamos una cifra aleatoria entre 0 y 99
        arr[i] = nroRand;
        cout << "El numero generado en la posicion " << i <<  " es: " << arr[i] << endl;
        cout << "La direccion de mem del elemento en la posicion " << i <<  " es: " << &arr[i] << endl;
    }

    delete arr ; // borramos el arreglo para liberar memoria*/




    // ******************************************************************************************

// ej 5

/*  5. Ingresar una cadena de caracteres de longitud máxima 10, enviarla como
    parámetro a una función que maneje punteros de modo que retorne la misma
    cadena de caracteres, pero en mayúsculas.*/


/*
    char str[11]; // longitud máxima 10 + 1 para el caracter nulo
    cout << "Ingresa una cadena de caracteres de longitud maxima 10: " << endl;
    cin >> str;
    strncpy(str, str, 10);
    str[10] = '\0'; // Asegurarse de que la cadena sea nula-terminada
    char* resultado = aMayuscula(str);
    cout << "La cadena en mayusculas es: " << resultado << endl;
*/



    // ******************************************************************************************

// ej 6
/*    6. Realizar un programa que ingrese una cadena de caracteres de máximo 50
    elementos y la envíe como parámetro a una función que maneje punteros
    de modo que la función invierta la cadena.*/


/*  char str[50]; // longitud max 50 + 1 para caracter nulo
    cout << "Ingrese una cadena de caracteres de longitud maxima 50: "<< endl;
    cin >> str;
    strncpy(str,str,50);
    str[50] = '\0';
    char* resultado = invierteCadena(str);
    cout << "La cadena invertida es: " << resultado << endl;*/

    // ******************************************************************************************

// ej 7

/*    7.Obtener una función copia que utilice punteros para copiar una cadena en otra.*/

/*
    char str1[21]; // 20 caracteres mas el nulo
    char str2[21];
    cout << "Ingrese la cadena de texto a copiar " << endl;
    cin >> str1 ;
    copiarCadena(str2, str1);
    cout << "La cadena copiada es: " << str2 << endl;
*/


    // ******************************************************************************************

// ej 8

/*
    8. Realice un programa que permita ingresar una cadena de caracteres de máximo
    50 elementos, la envíe como parámetro a una función que utilizando punteros y
    retorne el número de vocales minúsculas que contiene la cadena.
*/

/*
    char str[50]; // 50 caracteres mas caracter nulo
    cout << "Ingrese una cadena de caracteres para contar las vocales en minuscula" << endl;
    cin >> str;
    int contador = contadorVocalesMinuscula(str);
    cout << "El número de vocales en minuscula es: " << contador << endl;
*/


    // ******************************************************************************************

// ej 9

/*    9. Definir un arreglo unidimensional de N componentes enteras de modo que la
    gestión de memoria sea dinámica utilizando new.
    Ingresar los datos en el vector.
    Mostrar el contenido del vector en dos modos: usando notación vectorial y luego
    usando aritmética de punteros.*/

/*
    int N;
    cout << "Ingrese el tamaño del arreglo: " << endl;
    cin >> N;

    int* arr = new int [N];

    for (int i = 0; i < N; ++i) {
        cout << "Ingrese el valor " << i << " del arreglo: " << endl;
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i) {
        cout << "Los valores del arreglo usando notación vectorial son: " << arr[i] << endl;
        //cout << "Los valores del arreglo usando aritmetica son: " << arr[i]  << endl;
    }
    delete arr;
*/


    // ******************************************************************************************

// ej 10

/*  Se pide crear un programa que haciendo uso de la reserva dinámica de memoria
    almacene un número determinado de valores (n) obtenidos de forma aleatoria,
    entre 0 y 100 y los ordene de mayor a menor
*/

/*    int n;
    cout << "Ingrese el tamaño del arreglo: " << endl;
    cin >> n;

    int* arr = new int [n];

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }

    cout << "El arreglo aleatorio es el siguiente: " << endl;

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "El arreglo aleatorio ordenado es: " << endl;

    //ordenamiento con bubblesort
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            int aux = 0;
            if (arr[i] > arr[i + 1]) {
                aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
            }
        }
    }

    //imprime el arreglo
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    delete arr;*/


    // ******************************************************************************************


    return 0;
}



