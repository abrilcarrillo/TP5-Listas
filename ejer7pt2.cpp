#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};
typedef struct tlista{
	pnodo inicio;
	pnodo fin;
};

void IniciarLista(tlista &lista)
{
	lista.inicio = NULL;
	lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
	nuevo = new tnodo;
	if(nuevo != NULL)
	{
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}
	else{
		nuevo->sig = lista.inicio;
		lista.inicio->ant = nuevo;
		lista.inicio = nuevo;
	}
}

void AgregarFinal(tlista &lista, pnodo nuevo){
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}
	else{
		lista.fin->sig = nuevo;
		nuevo->ant = lista.fin;
		lista.fin = nuevo;
	}
}
	
	void QuitarInicio(tlista &lista){
		pnodo borrado;
		if(lista.inicio == NULL){
			cout << "La lista esta vacia" << endl;
		}
		else{
			if(lista.inicio == lista.fin){
				borrado = lista.inicio;
				lista.inicio = NULL;
				lista.fin = NULL;
				delete borrado;
			}
			else{
				borrado = lista.inicio;
				lista.inicio = lista.inicio->sig;
				lista.inicio->ant = NULL;
				delete borrado;
			}
		}
	}
		
		void QuitarFinal(tlista &lista){
			pnodo borrado;
			if(lista.inicio == NULL){
				cout << "La lista esta vacia" << endl;
			}
			else{
				if(lista.inicio == lista.fin){
					borrado = lista.fin;
					lista.inicio = NULL;
					lista.fin = NULL;
					delete borrado;
				}
				else{
					borrado = lista.fin;
					lista.fin = lista.fin->ant;
					lista.fin->sig = NULL;
					delete borrado;
				}
			}
		}
			
			void MostrarLista(tlista lista){
				pnodo i;
				if(lista.inicio != NULL){
					for(i = lista.inicio; i != NULL; i = i->sig){
						cout << i->dato << " ";
					}
					cout << endl;
				}
				else{
					cout << "Lista vacia" << endl;
				}
			}
				
				int main(){
					tlista lista;
					pnodo nuevo;
					
					IniciarLista(lista);
					
					CrearNodo(nuevo, 10);
					AgregarInicio(lista, nuevo);
					
					CrearNodo(nuevo, 20);
					AgregarInicio(lista, nuevo);
					
					CrearNodo(nuevo, 30);
					AgregarFinal(lista, nuevo);
					
					cout << "Lista actual: ";
					MostrarLista(lista);
					
					QuitarInicio(lista);
					cout << "Despues de quitar inicio: ";
					MostrarLista(lista);
					
					QuitarFinal(lista);
					cout << "Despues de quitar final: ";
					MostrarLista(lista);
					
					return 0;
				}
					
