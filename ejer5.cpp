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

void ordenar_seleccion(pnodo &lista) {
	pnodo i, j, min;
	int aux;
	
	for (i = lista; i != NULL && i->siguiente != NULL; i = i->siguiente) {
		min = i;
		for (j = i->siguiente; j != NULL; j = j->siguiente) {
			if (j->dato < min->dato) {
				min = j;
			}
		}
		if (min != i) {
			aux = i->dato;
			i->dato = min->dato;
			min->dato = aux;
		}
	}
}

void combinar_listas(pnodo &lista1, pnodo lista2) {
	if (lista1 == NULL) {
		lista1 = lista2;
	} else {
		pnodo i = lista1;
		while (i->siguiente != NULL) {
			i = i->siguiente;
		}
		i->siguiente = lista2;
	}
}

pnodo combinar_listas_ordenadas(pnodo l1, pnodo l2) {
	pnodo resultado = NULL;
	pnodo nuevo;
	
	while (l1 != NULL && l2 != NULL) {
		if (l1->dato < l2->dato) {
			crear_nodo(nuevo, l1->dato);
			agregar_final(resultado, nuevo);
			l1 = l1->siguiente;
		} else {
			crear_nodo(nuevo, l2->dato);
			agregar_final(resultado, nuevo);
			l2 = l2->siguiente;
		}
	}
	
	while (l1 != NULL) {
		crear_nodo(nuevo, l1->dato);
		agregar_final(resultado, nuevo);
		l1 = l1->siguiente;
	}
	
	while (l2 != NULL) {
		crear_nodo(nuevo, l2->dato);
		agregar_final(resultado, nuevo);
		l2 = l2->siguiente;
	}
	
	return resultado;
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
	
	cout << "Lista antes de ordenar: " << endl;
	mostrar_lista(lista);
	
	ordenar_seleccion(lista);
	
	cout << "Lista luego de ordenar: " << endl;
	mostrar_lista(lista);
	
	pnodo lista2;
	iniciar_lista(lista2);
	
	int otros_valores[] = {8, 2, 6};
	for (int i = 0; i < 3; i++) {
		pnodo nuevo;
		crear_nodo(nuevo, otros_valores[i]);
		agregar_final(lista2, nuevo);
	}
	
	cout << "Segunda lista: " << endl;
	mostrar_lista(lista2);
	
	combinar_listas(lista, lista2);
	
	cout << "Lista combinada (sin importar orden): " << endl;
	mostrar_lista(lista);
	
	// respeta orden
	pnodo lista_ordenada1, lista_ordenada2;
	iniciar_lista(lista_ordenada1);
	iniciar_lista(lista_ordenada2);
	
	int l1[] = {1, 4, 6};
	int l2[] = {2, 3, 5};
	
	for (int i = 0; i < 3; i++) {
		pnodo nuevo;
		crear_nodo(nuevo, l1[i]);
		agregar_final(lista_ordenada1, nuevo);
	}
	for (int i = 0; i < 3; i++) {
		pnodo nuevo;
		crear_nodo(nuevo, l2[i]);
		agregar_final(lista_ordenada2, nuevo);
	}
	
	cout << "Lista ordenada 1: " << endl;
	mostrar_lista(lista_ordenada1);
	
	cout << "Lista ordenada 2: " << endl;
	mostrar_lista(lista_ordenada2);
	
	pnodo combinada_ordenada = combinar_listas_ordenadas(lista_ordenada1, lista_ordenada2);
	cout << "Lista combinada ordenada: " << endl;
	mostrar_lista(combinada_ordenada);
	
	return 0;
}

