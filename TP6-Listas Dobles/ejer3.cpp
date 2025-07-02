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
	if(nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}

void AgregarInicio(tlista &lista, pnodo nuevo) {
	if(lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.fin = nuevo;
	} else {
		nuevo->sig = lista.inicio;
		lista.inicio->ant = nuevo;
		lista.inicio = nuevo;
	}
}
void DecimalABinario(tlista &lista, int numero) {
	pnodo nuevo;
	while (numero > 0) {
		CrearNodo(nuevo, numero % 2);
		AgregarInicio(lista, nuevo);
		numero /= 2;
	}
}
void MostrarLista(tlista lista) {
	pnodo i;
	for (i = lista.inicio; i != NULL; i = i->sig) {
		cout << i->dato;
	}
	cout << endl;
}

int main() {
	tlista binario;
	int numero;
	IniciarLista(binario);
	
	cout << "Ingrese un numero decimal: ";
	cin >> numero;
	
	DecimalABinario(binario, numero);
	
	cout << "Numero en binario: ";
	MostrarLista(binario);
	
	return 0;
}
