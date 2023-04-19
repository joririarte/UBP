#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    void addNode ( int data) {
        Node* newNode = new Node(data);

        if (this->head == nullptr) {
            this->head = newNode;
        }
        else{
            Node* current = this->head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertNode(int data, int position) {
        //Ingresar elemento en una posición
        Node* newNode = new Node(data);

        if(position == 0) {
            newNode->next = this->head;
            this->head = newNode;
        }
        else {
            Node* current = this->head;
            int i = 0;

            while (current != nullptr && i < position -1) {
                current = current->next;
                i++;
            }

            if (current == nullptr) {
                cout << "Error: posicion fuera de rango" << endl;
            }
            else{
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    void deleteNode(int position) {
        // Eliminar elemento
        if (this->head == nullptr) {
            cout << "Error: la lista se encuentra vacia" << endl;
        } else if (position == 0) {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        else {
            Node* current = this->head;
            int i = 0;

            while (current != nullptr && i < position -1) {
                current = current->next;
                i++;
            }

            if (current == nullptr || current->next == nullptr) {
                cout << "Error: posicion fuera de rango" << endl;
            }
            else {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }

    void printList() {
        //Listar elementos
        Node* current = this->head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    LinkedList promptList() {
        //Realizar un programa que permita cargar una lista de N números.
        LinkedList list;

        int N = 0;
        cout << "Ingrese tamaño de la lista" << endl;
        cin >> N;

        for (int i = 0; i < N; ++i) {
            int x = 0;
            cout << "Ingrese el dato en la posicion " << i << endl;
            cin >> x;
            list.addNode(x);
        }
        return list;
    }

    void addList() {
        //Suma de los elementos
        Node* current = this->head;
        int aux = 0;

        while (current != nullptr) {
            aux = aux + current->data;
            current = current->next;
        }
        cout << "El resultado de la suma de la lista es: " << aux << endl;
    }

    void meanList() {
        //Media de los elementos cargados
        Node* current = this->head;
        float aux = 0;
        int i = 0;
        float mean = 0;

        while (current != nullptr) {
            aux = aux + current->data;
            current = current->next;
            i++;
        }
        mean = aux / i;
        cout << "El valor medio de la lista es: " << mean << endl;
    }

    void highestList() {
        //Determinar mayor elemento de la lista
        Node* current = this->head;
        int aux = 0;

        while (current != nullptr) {
            if( current->data > aux) {
                aux = current->data;
            }
            current = current->next;
        }
        cout << "El numero mayor de la lista es: " << aux << endl;
    }

    void lowestList() {
        //Determinar el menor elemento de la lista
        Node* current = this->head;
        int aux;

        while (current != nullptr) {
            if( current->data < aux) {
                aux = current->data;
            }
            current = current->next;
        }
        cout << "El numero menor de la lista es: " << aux << endl;
    }

    void replaceNode(int data, int position) {
        //Reemplaza un elemento
        Node* newNode = new Node(data);

        if (position == 0) {
            newNode->next = this->head->next;
            delete this->head;
            this->head = newNode;
        }
        else {
            Node* current = this->head;
            int i = 0;

            while (current != nullptr && i < position - 1) {
                current = current->next;
                i++;
            }

            if (current == nullptr || current->next == nullptr) {
                std::cout << "Error: position out of range" << std::endl;
            }
            else {
                newNode->next = current->next->next;
                delete current->next;
                current->next = newNode;
            }
        }
    }

    LinkedList randomList(){
        //) Realizar un programa que genere una lista de N elementos. A partir de esta lista crear otra lista
        //con los valores de la primera multiplicados por un número ingresado por el usuario.
        LinkedList list;
        LinkedList list1;

        int N = 0;
        cout << "Ingrese el tamaño de la lista random: " << endl;
        cin >> N;
        srand(time(NULL));

        int x = 0;
        cout << "Ingrese el factor para multiplicar la lista generada: " << endl;
        cin >> x;

        for (int i = 0; i < N; ++i) {
            int random = rand() % 10; // generamos una random aleatoria entre 0 y 9
            list.addNode(random);
            int randXFactor = random * x;
            list1.addNode(randXFactor);
        }

        return list1;
    }

    void firstLastList(){
        // Crear una lista con N elementos. Para la creación tener en cuenta las siguientes operaciones:
        //• Ingresar elemento al final
        //• Ingresar elemento al frente
        //• Crear un proceso que permita crear una segunda lista, invirtiendo la primera lista
        LinkedList list;
        LinkedList list2;

        int N = 0;
        cout << "Ingrese el tamaño de la lista random: " << endl;
        cin >> N;
        int num = 0;
        int option = 0;

        for (int i = 0; i < N; ++i) {
            cout << "Ingrese el dato " << i << endl;
            cin >> num;

            do {
                cout << "Donde desea agregar el dato " << i << " ingrese una opcion: " << endl
                     << "1. Al principio" << endl
                     << "2. Al final de la lista " << endl;
                cin >> option;
                if (option == 1) {
                    list.insertNode(num, 0);
                }
                else if (option == 2){
                    list.insertNode(num, i);
                }
                else {
                    system("cls");
                    cout << "Ingrese una opcion valida" << endl;
                }
            } while (option != 1 && option != 2);

            cout << "---------------------------------------------------------------------------------" << endl;
            cout << "La lista hasta el momento: " << endl;
            list.printList();
            cout << "---------------------------------------------------------------------------------" << endl;
        }

        // Crea una segunda lista con los nodos de la primera invertida
        Node* current = list.head;
        while (current != nullptr) {
            list2.insertNode(current->data,0);
            current = current->next;
        }

        cout << "---------------------------------------------------------------------------------" << endl;
        cout << "La lista invertida es: " << endl;
        list2.printList();
        cout << "---------------------------------------------------------------------------------" << endl;

    }

    void add2Lists() {
        LinkedList list1;
        LinkedList list2;
        LinkedList list3;

        cout << "A continuación debe ingresar el mismo tamaño en ambas listas "
                "y el factor a multiplicar debe ser 1" << endl;
        list1 = list1.randomList();
        list2 = list2.randomList();

        cout << "---------------------------------------------------------------------------------" << endl;
        cout << "Las listas generadas son: " << endl;
        list1.printList();
        list2.printList();

        //Sumar los elementos de cada lista en la misma posición
        Node* current = list1.head;
        Node* current2 = list2.head;
        while (current != nullptr) {
            int pos = 0;
            int sum = current->data + current2->data;
            list3.addNode(sum);
            current = current->next;
            current2 = current2->next;
        }
        list3.printList();
    }




};

int main() {
/*    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(4);
    list.addNode(5);
    list.insertNode(3, 2);
    list.printList();
    list.deleteNode(2);
    list.printList();*/

    LinkedList list;
    LinkedList list1;
    LinkedList list2;
    LinkedList list3;

/*  list= list.promptList();
    list.printList();
    list.addList();
    list.meanList();
    list.highestList();
    list.lowestList();
    list.insertNode(5, 4);
    list.printList();
    list.deleteNode(4);
    list.printList();
    list.replaceNode(9,0);
    list.printList();

    list1= list1.randomList();
    list1.printList();*/

/*  list2.firstLastList();
    list2.printList();*/

    list3.add2Lists();
    

    return 0;
}
