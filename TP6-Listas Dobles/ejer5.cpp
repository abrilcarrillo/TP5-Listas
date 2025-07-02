#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
} tnodo;

typedef struct tlista {
	pnodo inicio;
	pnodo fin;
};

void IniciarLista(tlista &lista) {
	lista.inicio = NULL;
	lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}

void AgregarFinal(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.fin = nuevo;
	} else {
		lista.fin->sig = nuevo;
		nuevo->ant = lista.fin;
		lista.fin = nuevo;
	}
}

void MostrarLista(tlista lista) {
	pnodo i = lista.inicio;
	while (i != NULL) {
		cout << i->dato << " ";
		i = i->sig;
	}
	cout << endl;
}

void EliminarMultiplosDeTres(tlista &lista) {
	pnodo actual = lista.inicio;
	while (actual != NULL) {
		pnodo siguiente = actual->sig;
		if (actual->dato % 3 == 0) {
			if (actual->ant != NULL)
				actual->ant->sig = actual->sig;
			else
				lista.inicio = actual->sig;
			
			if (actual->sig != NULL)
				actual->sig->ant = actual->ant;
			else
				lista.fin = actual->ant;
			
			delete actual;
		}
		actual = siguiente;
	}
}
