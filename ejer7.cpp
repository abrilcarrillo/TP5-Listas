#include <iostream>
using namespace std;

class Nodo {
private:
	int dato;
	Nodo* siguiente;
	
public:
	Nodo(int valor) {
		dato = valor;
		siguiente = nullptr;
	}
	
	int getDato() {
		return dato;
	}
	
	Nodo* getSiguiente() {
		return siguiente;
	}
	
	void setSiguiente(Nodo* sig) {
		siguiente = sig;
	}
};

// funcion enigma
void enigma(Nodo* nodo) {
	if (nodo != nullptr) {
		if (nodo->getSiguiente() == nullptr)
			cout << nodo->getDato() << endl;
		else {
			enigma(nodo->getSiguiente());
			cout << nodo->getDato() << endl;
		}
	}
}

// funcion misterio
int misterio(Nodo* nodo) {
	if (nodo == nullptr)
		return 0;
	else
		return misterio(nodo->getSiguiente()) + 1;
}

// función desconocido 
Nodo* desconocido(Nodo* nodo) {
	if (nodo == nullptr || nodo->getSiguiente() == nullptr)
		return nodo;
	else
		return desconocido(nodo->getSiguiente());
}

// funcion para lista 
Nodo* crear_lista_prueba() {
	
	Nodo* n1 = new Nodo(6);
	Nodo* n2 = new Nodo(4);
	Nodo* n3 = new Nodo(9);
	Nodo* n4 = new Nodo(5);
	Nodo* n5 = new Nodo(8);
	
	n1->setSiguiente(n2);
	n2->setSiguiente(n3);
	n3->setSiguiente(n4);
	n4->setSiguiente(n5);
	
	return n1;
}

int main() {
	Nodo* lista = crear_lista_prueba();
	
	cout << "Impresion de lista en orden inverso (enigma): " << endl;
	enigma(lista);
	
	cout << "Cantidad de nodos (misterio): ";
	cout << misterio(lista) << endl;
	
	Nodo* ultimo = desconocido(lista);
	if (ultimo != nullptr) {
		cout << "Ultimo nodo (desconocido): " << ultimo->getDato() << endl;
	}
	
	return 0;
}
