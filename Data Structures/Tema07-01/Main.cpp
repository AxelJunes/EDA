#include <iostream>
#include "Error.h"
#include "SetOfInts3.h"

//Function and procedure headers
void lowestSet(int A[], int len, int k, SetOfInts3& set);

#define MAX_LENGTH 100
//Main program
int main(){
	int elem, k, A[MAX_LENGTH], i;
	SetOfInts3 set;
	/*
	SetOfInts3 set1;
	cin >> set1;
	SetOfInts3 set2;
	cin >> set2;

	if (set1 == set2)
		cout << "Son iguales";
	else
		cout << "No son iguales";
	if (set1 < set2)
		cout << "Es subconjunto" << endl;
	else
		cout << "No es subconjunto" << endl;
	*/
	cin >> k;
	while (k != 0) {
		i = 0;
		cin >> elem;
		while (elem != -1) {
			A[i] = elem;
			i++;
			cin >> elem;
		}
		//Method call
		lowestSet(A, i, k, set);
		//Print elements of the set
		set.print();
		cout << endl;
		//Reset set
		set.reset();
		cin >> k;
	}


	return 0;
}

/*
P={(0 < k <= 50) && (k <= len)}
*/
void lowestSet(int A[], int len, int k, SetOfInts3& set) {
	//We add high values to the set so we can compare them later
	for (int i = 0; i < k; i++) {
		set.add(MAX_LENGTH + i);
	}
	for (int i = 0; i < len; i++) {
		if ((!set.contains(A[i])) && (A[i] < set.getMax())) {
			set.removeMax();
			set.add(A[i]);
		}
	}
}