#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
	T dato;
	Nodo<T>* siguiente;
};

template <typename T>
void iniciar_lista(Nodo<T>*& lista) {
	lista = NULL;
}

template <typename T>
	void crear_nodo(Nodo<T>*& nuevo, T valor) {
	nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->siguiente = NULL;
}
	
	template <typename T>
		void agregar_final(Nodo<T>*& lista, Nodo<T>* nuevo) {
		if (lista == NULL) {
			lista = nuevo;
		} else {
			Nodo<T>* i = lista;
			while (i->siguiente != NULL) {
				i = i->siguiente;
			}
			i->siguiente = nuevo;
		}
	}
		
		template <typename T>
			void mostrar_lista(Nodo<T>* lista) {
			Nodo<T>* i = lista;
			while (i != NULL) {
				cout << i->dato << " -> ";
				i = i->siguiente;
			}
			cout << "NULL" << endl;
		}
			
			bool es_primo(int n) {
				if (n <= 1) return false;
				for (int i = 2; i*i <= n; i++) {
					if (n % i == 0) return false;
				}
				return true;
			}
			
			int contar_primos(Nodo<int>* lista) {
				int contador = 0;
				Nodo<int>* i = lista;
				while (i != NULL) {
					if (es_primo(i->dato)) {
						contador++;
					}
					i = i->siguiente;
				}
				return contador;
			}
			
			int main() {
				Nodo<int>* lista;
				iniciar_lista(lista);
				
				int valores[] = {2, 7, 8, 9, 11, 13, 16, 18};
				for (int i = 0; i < 8; i++) {
					Nodo<int>* nuevo;
					crear_nodo(nuevo, valores[i]);
					agregar_final(lista, nuevo);
				}
				
				cout << "Lista de enteros: " << endl;
				mostrar_lista(lista);
				
				int cantidad_primos = contar_primos(lista);
				cout << "Cantidad de numeros primos: " << cantidad_primos << endl;
				
				return 0;
			}
			
