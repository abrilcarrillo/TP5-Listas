#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;

struct tnodo {
	int dato;
	pnodo siguiente;
};

//pila
void iniciar_pila(pnodo &pila) {
	pila = NULL;
}

bool es_vacia_pila(pnodo pila) {
	return pila == NULL;
}

void apilar(pnodo &pila, pnodo nuevo) {
	nuevo->siguiente = pila;
	pila = nuevo;
}

pnodo desapilar(pnodo &pila) {
	pnodo borrado;
	if (pila == NULL) {
		borrado = NULL;
	} else {
		borrado = pila;
		pila = pila->siguiente;
		borrado->siguiente = NULL;
	}
	return borrado;
}

void mostrar_pila(pnodo pila) {
	pnodo i;
	for (i = pila; i != NULL; i = i->siguiente) {
		cout << i->dato << endl;
	}
}

//cola
typedef struct {
	pnodo frente;
	pnodo final;
	int cantidad;
} cola;

void iniciar_cola(cola &c) {
	c.frente = NULL;
	c.final = NULL;
	c.cantidad = 0;
}

bool es_vacia_cola(cola c) {
	return c.frente == NULL;
}

void encolar(cola &c, pnodo nuevo) {
	if (c.frente == NULL) {
		c.frente = nuevo;
		c.final = nuevo;
	} else {
		c.final->siguiente = nuevo;
		c.final = nuevo;
	}
	c.cantidad++;
}

pnodo desencolar(cola &c) {
	pnodo borrado;
	if (c.frente == NULL) {
		borrado = NULL;
	} else {
		borrado = c.frente;
		c.frente = c.frente->siguiente;
		if (c.frente == NULL) {
			c.final = NULL;
		}
		borrado->siguiente = NULL;
		c.cantidad--;
	}
	return borrado;
}

int cantidad_elementos(cola c) {
	return c.cantidad;
}

void crear_nodo(pnodo &nuevo) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		cout << "Ingrese valor: ";
		cin >> nuevo->dato;
		nuevo->siguiente = NULL;
	} else {
		cout << "Memoria insuficiente" << endl;
	}
}

int main() {
	pnodo nuevo;
	cola c;
	pnodo pila;
	
	iniciar_cola(c);
	iniciar_pila(pila);
	
	for (int i = 0; i < 3; i++) {
		crear_nodo(nuevo);
		encolar(c, nuevo);
	}
	
	cout << "Elementos en cola:" << endl;
	pnodo temp = c.frente;
	while (temp != NULL) {
		cout << temp->dato << endl;
		temp = temp->siguiente;
	}
	
	cout << "Cantidad en cola: " << cantidad_elementos(c) << endl;
	
	for (int i = 0; i < 2; i++) {
		crear_nodo(nuevo);
		apilar(pila, nuevo);
	}
	
	cout << "Elementos en pila:" << endl;
	mostrar_pila(pila);
	
	return 0;
}
