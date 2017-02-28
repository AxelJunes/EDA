//dge03: Axel Junestrand

#include<iostream>
using namespace std;

//Function headers
int xxxx(int A[], int n);

//Main program
int main(){
	int nCases;
	int n;
	cin >> nCases;
	for(int i = 0; i < nCases; i++){
		cin >> n;
		int A[n];
		//Fill the array with user input
		for(int j = 0; j < n; j++)
			cin >> A[j];
		//Final function call
		cout << xxxx(A, n) << endl;
	}

	return 0;
}


int xxxx(int A[], int n){
	int p=0, s=A[0], m=A[0];

	for(int i = 1; i < n; i++){
		s = max(s, A[i]);
		if(A[i] <= m){
			p = i;
			m = max(m,s);
		}
	}
	return p;
}
