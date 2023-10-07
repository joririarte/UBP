#include "Monticulo.h"
template <typename T>
//Metodos Privados
int Monticulo<T>::Padre(int pos_nodo)
{
	return (pos_nodo - 1) / 2;
}

template <typename T>
int Monticulo<T>::Izquierdo(int pos_nodo)
{
	return (2 * pos_nodo) + 1;
}

template <typename T>
int Monticulo<T>::Derecho(int pos_nodo)
{
	return (2 * pos_nodo) + 2;
}

template <typename T>
void Monticulo<T>::Subir(int i)
{
	int nodoPadre = Padre(i);
	while (i > 0 && monticulo->at(i) > monticulo->at(nodoPadre)) {
		Intercambiar(i, nodoPadre);
		i = nodoPadre;
		nodoPadre = Padre(i);
	}
}

template <typename T>
void Monticulo<T>::Bajar(int pos_nodo)
{
	int pos_hijo_izq, pos_hijo_der, pos_max;
	pos_max = pos_nodo;
	do {
		pos_nodo = pos_max;
		pos_hijo_izq = Izquierdo(pos_nodo);
		pos_hijo_der = Derecho(pos_nodo);
		
		if (pos_hijo_der < monticulo->size() && 
			monticulo->at(pos_hijo_izq) > monticulo->at(pos_max))
			pos_max = pos_hijo_der;
		
		if (pos_hijo_izq < monticulo->size() && 
			monticulo->at(pos_hijo_izq) > monticulo->at(pos_max))
			pos_max = pos_hijo_izq;
		
		if (pos_nodo != pos_max) {
			Intercambiar(pos_nodo, pos_max);
		}
	} while (pos_nodo != pos_max && pos_max < (monticulo->size()-1) / 2);
}

template <typename T>
void Monticulo<T>::Intercambiar(int pos_1, int pos_2)
{
	T aux;
	aux = monticulo->at(pos_1);
	monticulo->at(pos_1) = monticulo->at(pos_2);
	monticulo->at(pos_2) = aux;
}
//FIN METODOS PRIVADOS

//METODOS PUBLICOS
template <typename T>
Monticulo<T>::Monticulo()
{
	monticulo = new std::vector<T>;
}

template <typename T>
Monticulo<T>::~Monticulo()
{
	delete monticulo;
}

template <typename T>
bool Monticulo<T>::Vacio()
{
	return monticulo->empty();
}

template <typename T>
bool Monticulo<T>::Insertar(T valor)
{
	if (!Existe(valor)) {
		monticulo->push_back(valor);
		Subir(monticulo->size() - 1);
		return true;
	}
	return false;
}

template <typename T>
bool Monticulo<T>::Borrar(T valor)
{
	if (Existe(valor)) {
		int pos_borrar = BuscarPos(valor);
		monticulo->at(pos_borrar) = monticulo->back();
		monticulo->pop_back();
		if(!Vacio())
			Bajar(pos_borrar);
	}
	return false;
}

template <typename T>
bool Monticulo<T>::Existe(T valor)
{
	auto i = std::find(monticulo->begin(), monticulo->end(), valor);
	return !(i==monticulo->end());
}

template <typename T>
int Monticulo<T>::BuscarPos(T valor)
{
	for (int i = 0; i < monticulo->size(); i++) {
		if (monticulo->at(i) == valor) {
			return i;
		}
	}
	return -1;
}

template <typename T>
T Monticulo<T>::getNodo(int pos)
{
	return monticulo->at(pos);
}

template <typename T>
void Monticulo<T>::Mostrar()
{
	for (int i = 0; i < monticulo->size(); i++) {
		std::cout << "Nodo " << i << ": " 
				  << monticulo->at(i) << std::endl;
	}
}

template <typename T>
T Monticulo<T>::ExtraerMaximo()
{
	T ret = monticulo->front();
	Borrar(ret);
	return ret;
}
