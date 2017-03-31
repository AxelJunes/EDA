//Author: Axel Junestrand
#include <iostream>
#include <list>
using namespace std;

//Cabeceras de funci�n
void duplicarPicos(list<int> &lista, int &contador);
void mostrarLista(list<int> lista);

//Programa principal
int main() {
	int nCasos;
	list<int> lista;
	cin >> nCasos;//N�mero de casos de prueba
	for (int i = 0; i < nCasos; i++) {
		char c; int n, contador = 0;

		cin.get(c);
		c = cin.peek();
		while (c != '\n') {
			cin >> n; // como sabemos que no viene el salto de l�nea leemos el siguiente entero
			lista.push_back(n);//A�adimos el elemento le�do a la lista
			c = cin.peek();
		}
		//Llamamos a la funci�n para duplicar los picos
		duplicarPicos(lista, contador);
		cout << contador << ": ";
		mostrarLista(lista);
		//Limpiamos el contenido de la lista
		lista.clear();
	}
	return 0;
}

/*
Duplica los elementos de la lista que sean suma de los anteriores, y devuelve el
n�mero de elementos que cumplan dicha condici�n
*/
void duplicarPicos(list<int> &lista, int &contador) {
	int suma = 0;

	for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
		if (*it == suma) {
			lista.insert(it, *it);
			contador++;
		}
		suma += *it;
	}
}

void mostrarLista(list<int> lista) {
	for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}