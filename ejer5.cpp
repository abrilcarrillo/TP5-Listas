#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;

struct tnodo {
	int dato;
	pnodo siguiente;
};

void iniciar_lista(pnodo &lista) {
	lista = NULL;
}

void crear_nodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	nuevo->dato = valor;
	nuevo->siguiente = NULL;
}

void agregar_final(pnodo &lista, pnodo nuevo) {
	if (lista == NULL) {
		lista = nuevo;
	} else {
		pnodo i = lista;
		while (i->siguiente != NULL) {
			i = i->siguiente;
		}
		i->siguiente = nuevo;
	}
}

void mostrar_lista(pnodo lista) {
	pnodo i = lista;
	while (i != NULL) {
		cout << i->dato << " -> ";
		i = i->siguiente;
	}
	cout << "NULL" << endl;
}

int main() {
	pnodo lista;
	iniciar_lista(lista);
	
	int valores[] = {7, 3, 9, 1, 5};
	for (int i = 0; i < 5; i++) {
		pnodo nuevo;
		crear_nodo(nuevo, valores[i]);
		agregar_final(lista, nuevo);
	}
	
	cout << "Lista original:" << endl;
	mostrar_lista(lista);
	
	return 0;
}
