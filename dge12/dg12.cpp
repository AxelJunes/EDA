//dg12
//Author: Axel Junestrand (C04)

/*
P: {N > 1}
Q: {(s = max i : 0 <= i < N : array[i] > h) ^ (end = i : 0 <= i < N : array[i] = s) ^ (begin = end - s + 1)}
I: {(0 <= n < N) ^ (s = max i : 0 <= i < N : array[i] > h)}
B: {n < N}
*/

#include<iostream>
using namespace std;

int main(){
	/*
	h => maximum building heigth
	N => number of buildings
	n => array position
	s => subarray length
	array[] => array with building heigths
	*/
	int nCases, N;
	int b, h, n, s, k;
	int begin, end, beginTemp;

	cin >> nCases;
	for(int i = 0; i < nCases; i++){
		//Init phase
		h = 0, n = 0, s = 0, k = 0, begin = 0, end = 0, beginTemp = 0;
		//User input
		cin >> N;
		cin >> h;
		int array[N];
		while(n < N){
			cin >> array[n];
			if(array[n] > h){
				k++;
				//If equal length, first one prevails
				if(k > s){
					//begin = beginTemp;
					s = k;
					end = n;
					begin = end - s + 1;
				}
			}
			else
				k = 0;
			n++;
		}
		cout << begin << " " << end << endl;
	}
	
	return 0;
}
