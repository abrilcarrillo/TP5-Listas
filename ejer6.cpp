#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
	T dato;
	Nodo<T>* siguiente;
};

template <typename T>
void iniciar_lista(Nodo<T>*& lista) {
	lista = nullptr;
}

template <typename T>
	void crear_nodo(Nodo<T>*& nuevo, T valor) {
	nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->siguiente = nullptr;
}
	
	template <typename T>
		void agregar_final(Nodo<T>*& lista, Nodo<T>* nuevo) {
		if (lista == nullptr) {
			lista = nuevo;
		} else {
			Nodo<T>* i = lista;
			while (i->siguiente != nullptr) {
				i = i->siguiente;
			}
			i->siguiente = nuevo;
		}
	}
		
		template <typename T>
			void mostrar_lista(Nodo<T>* lista) {
			Nodo<T>* i = lista;
			while (i != nullptr) {
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
				int cuenta = 0;
				Nodo<int>* i = lista;
				while (i != nullptr) {
					if (es_primo(i->dato)) {
						cuenta++;
					}
					i = i->siguiente;
				}
				return cuenta;
			}
			
			void contar_mayusculas_minusculas(Nodo<char>* lista, int& mayus, int& minus) {
				mayus = 0;
				minus = 0;
				Nodo<char>* i = lista;
				while (i != nullptr) {
					if (i->dato >= 'A' && i->dato <= 'Z') {
						mayus++;
					} else if (i->dato >= 'a' && i->dato <= 'z') {
						minus++;
					}
					i = i->siguiente;
				}
			}
			
			int main() {
				// enteros y primos
				Nodo<int>* lista_enteros;
				iniciar_lista(lista_enteros);
				
				int valores[] = {3, 8, 7, 4, 2, 9};
				for (int i = 0; i < 6; i++) {
					Nodo<int>* nuevo;
					crear_nodo(nuevo, valores[i]);
					agregar_final(lista_enteros, nuevo);
				}
				
				cout << "Lista de enteros: ";
				mostrar_lista(lista_enteros);
				int total_primos = contar_primos(lista_enteros);
				cout << "Cantidad de primos en la lista: " << total_primos << endl;
				
				// caracteres, mayusculas y minusculas
				Nodo<char>* lista_caracteres;
				iniciar_lista(lista_caracteres);
				
				char letras[] = {'A', 'b', 'C', 'd', 'E', 'f'};
				for (int i = 0; i < 6; i++) {
					Nodo<char>* nuevo;
					crear_nodo(nuevo, letras[i]);
					agregar_final(lista_caracteres, nuevo);
				}
				
				cout << "\nLista de caracteres: ";
				mostrar_lista(lista_caracteres);
				
				int mayusculas, minusculas;
				contar_mayusculas_minusculas(lista_caracteres, mayusculas, minusculas);
				
				cout << "Cantidad de mayusculas: " << mayusculas << endl;
				cout << "Cantidad de minusculas: " << minusculas << endl;
				
				return 0;
			}
			
