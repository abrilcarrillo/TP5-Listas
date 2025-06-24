#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

typedef struct {
	pnodo inicio;
	pnodo final;
	int cantidad;
} tlista;

void iniciar_lista(tlista &lista) {
	lista.inicio = NULL;
	lista.final = NULL;
	lista.cantidad = 0;
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

pnodo eliminar_inicio(tlista &lista) {
	pnodo borrado = NULL;
	if (lista.inicio != NULL) {
		borrado = lista.inicio;
		lista.inicio = borrado->siguiente;
		if (lista.inicio == NULL) {
			lista.final = NULL;
		}
		borrado->siguiente = NULL;
		lista.cantidad--;
	}
	return borrado;
}

pnodo eliminar_final(tlista &lista) {
	pnodo borrado = NULL, i;
	if (lista.inicio != NULL) {
		if (lista.inicio == lista.final) {
			borrado = lista.inicio;
			lista.inicio = NULL;
			lista.final = NULL;
		} else {
			for (i = lista.inicio; i->siguiente != lista.final; i = i->siguiente);
			borrado = lista.final;
			i->siguiente = NULL;
			lista.final = i;
		}
		lista.cantidad--;
	}
	return borrado;
}

void mostrar_lista(tlista lista) {
	pnodo i;
	if (lista.inicio != NULL) {
		for (i = lista.inicio; i != NULL; i = i->siguiente) {
			cout << i->dato << " -> ";
		}
		cout << "NULL" << endl;
	} else {
		cout << "Lista vacia" << endl;
	}
}

int cantidad_elementos(tlista lista) {
	return lista.cantidad;
}

int main() {
	tlista lista;
	iniciar_lista(lista);
	char opcion;
	do {
		cout << "--- MENU ---" << endl;
		cout << "1. Agregar al final" << endl;
		cout << "2. Mostrar lista" << endl;
		cout << "3. Mostrar cantidad de elementos" << endl;
		cout << "4. Eliminar del inicio" << endl;
		cout << "5. Eliminar del final" << endl;
		cout << "6. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1': {
			pnodo nuevo;
			crear_nodo(nuevo);
			agregar_final(lista, nuevo);
			break;
		}
		case '2':
			mostrar_lista(lista);
			break;
		case '3':
			cout << "Cantidad de elementos: " << cantidad_elementos(lista) << endl;
			break;
		case '4': {
			pnodo eliminado = eliminar_inicio(lista);
			if (eliminado != NULL) {
				cout << "Se elimino: " << eliminado->dato << endl;
				delete eliminado;
			} else {
				cout << "Lista vacia. No se pudo eliminar." << endl;
			}
			break;
		}
		case '5': {
			pnodo eliminado = eliminar_final(lista);
			if (eliminado != NULL) {
				cout << "Se elimino: " << eliminado->dato << endl;
				delete eliminado;
			} else {
				cout << "Lista vacia. No se pudo eliminar." << endl;
			}
			break;
		}
		case '6':
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
		}
		
	} while (opcion != '6');
	
	return 0;
}
