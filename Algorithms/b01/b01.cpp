//Author: Axel Junestrand (C04)

/*
  P : {N > 1}
  Q : {p = # i : 1 <= i < N - 1 : A[i-1] < A[i] > A[i+1] and
      v = # i : 1 <= i < N - 1 : A[i-1] > A[i] < A[i+1]}
  I : {Q[N-1/n] and 1 <= n <= N-1}
  B : {n < N}
*/


#include<iostream>
using namespace std;

int valleys(int array[], int N);
int peaks(int array[], int N);

int main(){
	int nCases, N;//Array length
	cin >> nCases;
	for(int i = 0; i < nCases; i++){
		cin >> N;
		int A[N], temp;
		for(int j = 0; j < N; j++){
			cin >> temp;
			A[j] = temp;
		}
		cout << peaks(A, N) << " " << valleys(A, N) << endl;
		
	}
	return 0;
}

//Number of peaks registered in temperature
int peaks(int A[], int N){
	int p = 0;
	for(int i = 1; i < N-1; i++){
		if((A[i-1] < A[i]) && (A[i] > A[i+1]))
			p++;
	}
	return p;
}

//Number of valleys registered in temperature
int valleys(int A[], int N){
	int v = 0;
	for(int i = 1; i < N-1; i++){
		if((A[i-1] > A[i]) && (A[i] < A[i+1]))
			v++;
	}
	return v;
}


