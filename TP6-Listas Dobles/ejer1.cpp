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
pnodo QuitarInicio(pnodo &inicio) {
	pnodo extraido;
	if (inicio == NULL) {
		extraido = NULL;
	} else if (inicio->sig == NULL) {
		extraido = inicio;
		inicio = NULL;
	} else {
		extraido = inicio;
		inicio = inicio->sig;
		inicio->ant = NULL;
		extraido->sig = NULL;
	}
	return extraido;
}

pnodo QuitarFinal(pnodo &inicio) {
	pnodo extraido;
	if (inicio == NULL) {
		extraido = NULL;
	} else {
		pnodo i;
		for (i = inicio; i->sig != NULL; i = i->sig);
		extraido = i;
		if (i->ant != NULL) {
			(i->ant)->sig = NULL;
			i->ant = NULL;
		} else {
			inicio = NULL;
		}
	}
	return extraido;
}
pnodo QuitarNodo(pnodo &inicio, int valor) {
	pnodo extraido, i;
	if (inicio == NULL) {
		extraido = NULL;
	} else if (inicio->dato == valor) {
		extraido = inicio;
		inicio = inicio->sig;
		if (inicio != NULL) inicio->ant = NULL;
		extraido->sig = NULL;
	} else {
		for (i = inicio; i != NULL && i->dato != valor; i = i->sig);
		if (i != NULL) {
			extraido = i;
			if (i->ant != NULL) i->ant->sig = i->sig;
			if (i->sig != NULL) i->sig->ant = i->ant;
			extraido->sig = NULL;
			extraido->ant = NULL;
		} else {
			extraido = NULL;
		}
	}
	return extraido;
}
