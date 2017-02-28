/*
Author: Axel Junestrand (C04)
/*

/*
----------------------------------------------------------
P: V[0..N)=A[0..N)
Q: forall i : 0 <= i < N : V[i]= sum j: 0 <= j <= i : A[j]
I: I[N/n]
B: n < N
Init: n = 1
Step: n = n + 1
Restore: V[n]=V[n-1]+A[n]
Quote: N - n
----------------------------------------------------------
*/

#include<iostream>
using namespace std;

#define MAX 1000

void fib(int V[], int N);

int main(){
	int A[MAX];
	int n, elem;
	
	cin >> elem;
	while(elem != 0){
		n=0;
		while(elem != 0){
			A[n] = elem;
			n++;
			cin >> elem;
		}
		//Fibonacci function call
		fib(A,n+1);
		
		cin >> elem;
	}

	return 0;
}

/*
Represents the sum of all the elements before the current, except
for the first element, which doesn't have anything before to add.
*/
void fib(int V[], int N){
	for (int i = 1; i < N; i++){
		V[i] += V[i-1];
		cout << V[i-1] << " ";
	}
	cout << endl;
}

		


