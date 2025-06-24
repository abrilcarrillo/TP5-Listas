#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

typedef struct tlista {
	pnodo inicio;
	pnodo final;
	int cantidad;
};

void iniciar_lista(tlista &lista) {
	lista.inicio = NULL;
	lista.final = NULL;
	lista.cantidad = 0;
}

pnodo crear_nodo(int valor) {
	pnodo nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->siguiente = NULL;
	}
	return nuevo;
}

void agregar_final(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.final = nuevo;
	} else {
		lista.final->siguiente = nuevo;
		lista.final = nuevo;
	}
	lista.cantidad++;
}

void mostrar_lista(tlista lista) {
	pnodo i;
	if (lista.inicio != NULL) {
		for (i = lista.inicio; i != NULL; i = i->siguiente) {
			cout << i->dato << " ";
		}
		cout << endl;
	} else {
		cout << "Lista vacia" << endl;
	}
}

int buscar_indice(tlista lista, int valor) {
	pnodo i = lista.inicio;
	int indice = 0;
	while (i != NULL) {
		if (i->dato == valor) {
			return indice;
		}
		i = i->siguiente;
		indice++;
	}
	return -1;
}

pnodo buscar_por_indice(tlista lista, int indice) {
	if (indice < 0 || indice >= lista.cantidad) {
		return NULL;
	}
	pnodo i = lista.inicio;
	int contador = 0;
	while (i != NULL && contador < indice) {
		i = i->siguiente;
		contador++;
	}
	return i;
}

int main() {
	tlista lista;
	iniciar_lista(lista);
	int valor;
	pnodo nodo;
	
	for (int j = 0; j < 5; j++) {
		cout << "Ingrese un valor: ";
		cin >> valor;
		nodo = crear_nodo(valor);
		agregar_final(lista, nodo);
	}
	
	cout << "Contenido de la lista: ";
	mostrar_lista(lista);
	
	cout << "Buscar por valor. Ingrese numero: ";
	cin >> valor;
	int pos = buscar_indice(lista, valor);
	if (pos != -1) {
		cout << "El valor se encuentra en la posicion: " << pos << endl;
	} else {
		cout << "Valor no encontrado" << endl;
	}
	
	cout << "Buscar por indice. Ingrese posicion logica: ";
	cin >> pos;
	nodo = buscar_por_indice(lista, pos);
	if (nodo != NULL) {
		cout << "El dato en esa posicion es: " << nodo->dato << endl;
	} else {
		cout << "Indice invalido" << endl;
	}
	
	return 0;
}
