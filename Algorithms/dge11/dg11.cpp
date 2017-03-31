//dg11
//Author: Axel Junestrand (C04)


/*
P: N > 1
Q: p = max i: -1 <= i < N and zeros(A,i) = ones(A,i)
I: Q[N/n] and 0 <= n <= N and z = zeros(A,n) and o = ones(A,n)
B: n < N
*/

#include<iostream>
using namespace std;

int main(){
	int n, p , o, z;
	int nCases, N;
	
	//Get number of cases
	cin >> nCases;
	for(int i = 0; i < nCases; i++){
		//Get array size
		cin >> N;
		n = 0, p = -1, o = 0, z = 0;
		int vector[N];
		while(n < N){
			//Get array element
			cin >> vector[n];
			//Check if element is equal to one or zero
			if(vector[n] == 1)
				o++;
			else if(vector[n] == 0)
				z++;
			//Check if position is balanced
			if(o == z)
				p = n;
			n++;
		}
		cout << p << endl;
	}
	
	return 0;
}
