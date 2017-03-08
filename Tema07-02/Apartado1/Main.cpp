//Tema07-02
//Author: Axel Junestrand
#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include "Set.h"
#include "Error.h"
using namespace std;

//Cabeceras de funciones
template<class T>
void encontrarMayores(vector<T> v, int k, Set<T> &set);

//Programa principal
int main(){
	char c;
	int k, n;

	cin >> c;

	while (!cin.fail()){
		if (c == 'P'){
			vector<std::string> v;
			Set<std::string> set;
			std::string elem;
			n = 0;
			cin >> k;
			cin >> elem;
			while (elem != "FIN"){
				v.push_back(elem);
				cin >> elem;
				n++;
			}
			//Llamada a la función del segundo apartado
			encontrarMayores(v, k, set);
			//Mostramos el conjunto
			cout << set;
		}
		else if (c == 'N'){
			vector<int> v;
			Set<int> set;
			int elem;
			n = 0;
			cin >> k;
			cin >> elem;
			while (elem != -1){
				v.push_back(elem);
				cin >> elem;
				n++;
			}
			//Llamada a la función del segundo apartado
			encontrarMayores(v, k, set);
			//Mostramos el conjunto
			cout << set;
		}
		cout << endl;
		cin >> c;
	}

	return 0;
}

// Función segundo apartado
template<class T>
void encontrarMayores(vector<T> v, int k, Set<T> &set) { //O(n log(n)) -> n = v.size()
	int fillSize = k;
	//Rellenamos el conjunto con los k primeros elementos
	for (int i = 0; i < fillSize; i++) {
		if (!set.contains(v[i]))
			set.add(v[i]);
		else
			fillSize++;
	}

	for (size_t i = v.size()-1; i >= fillSize; i--) {
		if ((!set.contains(v[i])) && (set < v)) {
			set.removeMin();
			set.add(v.back());
		}
		v.pop_back();
	}
}