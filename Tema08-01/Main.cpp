//Author: Axel Junestrand
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Cabeceras de funcion
bool equilibrada(stack<char> pila, string cadena);
char opuesto(char elem);

//Programa principal
int main(){
	string cadena;
	stack<char> pila;

	getline(cin, cadena);
	while (cadena != "."){
		if (equilibrada(pila, cadena))
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
		getline(cin, cadena);
	}

	return 0;
}

/*
Devuelve "true" si la cadena está equilibrada y "false" en caso contrario
*/
bool equilibrada(stack<char> pila, string cadena){
	bool eq = true;
	int n = 0;
	while (eq && (n < cadena.length())){
		if (cadena[n] == '{' || cadena[n] == '(' || cadena[n] == '['){
			pila.push(cadena[n]);
		}
		else if (cadena[n] == '}' || cadena[n] == ')' || cadena[n] == ']'){
			//Si la pila esta vacia y llega una apertura, no estaría equilibrada la cadena
			if (pila.empty()){
				eq = false;
			}
			else{
				if (cadena[n] == opuesto(pila.top()))
					pila.pop();
				else
					eq = false;
			}
		}
		n++;
	}
	//Si sigue habiendo elementos en la pila no se han cerrado todos
	if (pila.size() > 0)
		eq = false;
	return eq;
}

char opuesto(char elem){
	char el;
	switch (elem){
	case '{':
		el = '}'; break;
	case '(':
		el = ')'; break;
	case '[':
		el = ']'; break;
	}
	return el;
}