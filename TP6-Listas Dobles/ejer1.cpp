#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
} tnodo;

void IniciarLista(pnodo &inicio) {
	inicio = NULL;
}

void CrearNodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}
void AgregarInicio(pnodo &inicio, pnodo nuevo) {
	if (inicio == NULL) {
		inicio = nuevo;
	} else {
		nuevo->sig = inicio;
		inicio->ant = nuevo;
		inicio = nuevo;
	}
}
void AgregarFinal(pnodo &inicio, pnodo nuevo) {
	pnodo i;
	if (inicio == NULL) {
		inicio = nuevo;
	} else {
		for (i = inicio; i->sig != NULL; i = i->sig);
		i->sig = nuevo;
		nuevo->ant = i;
	}
}
void AgregarOrden(pnodo &inicio, pnodo nuevo) {
	pnodo i;
	if (inicio == NULL) {
		inicio = nuevo;
	} else if (nuevo->dato < inicio->dato) {
		nuevo->sig = inicio;
		inicio->ant = nuevo;
		inicio = nuevo;
	} else {
		for (i = inicio; i->sig != NULL && (i->sig)->dato < nuevo->dato; i = i->sig);
		if (i->sig != NULL) {
			nuevo->sig = i->sig;
			nuevo->ant = i;
			(i->sig)->ant = nuevo;
			i->sig = nuevo;
		} else {
			i->sig = nuevo;
			nuevo->ant = i;
		}
	}
}
