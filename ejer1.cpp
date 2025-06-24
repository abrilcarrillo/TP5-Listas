#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

void iniciar_lista(pnodo &lista) {
	lista = NULL;
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

void agregar_inicio(pnodo &lista, pnodo nuevo) {
	nuevo->siguiente = lista;
	lista = nuevo;
}

void agregar_final(pnodo &lista, pnodo nuevo) {
	if (lista == NULL) {
		lista = nuevo;
	} else {
		pnodo i;
		for (i = lista; i->siguiente != NULL; i = i->siguiente);
		i->siguiente = nuevo;
	}
}

void mostrar_lista(pnodo lista) {
	pnodo i;
	if (lista != NULL) {
		for (i = lista; i != NULL; i = i->siguiente) {
			cout << i->dato << " -> ";
		}
		cout << "NULL" << endl;
	} else {
		cout << "Lista vacía" << endl;
	}
}

int minimo(pnodo lista) {
	if (lista == NULL) {
		cout << "Lista vacía. No hay mínimo." << endl;
		return -999;
	}
	int min = lista->dato;
	pnodo i;
	for (i = lista->siguiente; i != NULL; i = i->siguiente) {
		if (i->dato < min) {
			min = i->dato;
		}
	}
	return min;
}

pnodo eliminar_inicio(pnodo &lista) {
	pnodo borrado;
	if (lista == NULL) {
		borrado = NULL;
	} else {
		borrado = lista;
		lista = lista->siguiente;
		borrado->siguiente = NULL;
	}
	return borrado;
}

int main() {
	pnodo lista;
	iniciar_lista(lista);
	
	char opcion;
	do {
		cout << "--- MENU ---" << endl;
		cout << "1. Agregar al inicio" << endl;
		cout << "2. Agregar al final" << endl;
		cout << "3. Mostrar lista" << endl;
		cout << "4. Mostrar mínimo" << endl;
		cout << "5. Salir" << endl;
		cout << "Opción: ";
		cin >> opcion;
		
		switch(opcion) {
		case '1': {
			pnodo nuevo;
			crear_nodo(nuevo);
			agregar_inicio(lista, nuevo);
			break;
		}
		case '2': {
			pnodo nuevo;
			crear_nodo(nuevo);
			agregar_final(lista, nuevo);
			break;
		}
		case '3': {
			mostrar_lista(lista);
			break;
		}
		case '4': {
			int min = minimo(lista);
			if (min != -999)
				cout << "El valor mínimo es: " << min << endl;
			break;
		}
		case '5': {
			cout << "Saliendo..." << endl;
			break;
		}
		default:
			cout << "Opción inválida" << endl;
		}
		
	} while (opcion != '5');
	
	return 0;
}
