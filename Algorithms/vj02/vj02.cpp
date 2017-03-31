//vj02: Axel Junestrand

//---------------------------------------
//P={(1 < n < 10000) and (0 < p < 9999)}
//I={(0 <= i < p) and (i <= maxLeftl) and (p <= j < n) and (j > minRight)}
//Q={(maxLeft < minRight) and (maxLeftl = max(V[0]...V[p]) and (minRight = min(V[p+1]...V[n-1])}
//B={n < N}
//---------------------------------------

#include <iostream>
#include <climits>
using namespace std;

void appropriate(int V[], int n, int p);

int main(){
	int nCases;
	int n, p;
	cin >> nCases;
	for(int i = 0; i < nCases; i++){
		cin >> n >> p;
		int V[n];
		//Fill the array with given elements
		for(int j = 0; j < n; j++)
			cin >> V[j];
		appropriate(V, n, p);
	}

	return 0;
}

void appropriate(int V[], int n, int p){
	bool app = false;
	int maxLeft = INT_MIN, minRight = INT_MAX;
	for(int i = 0; i < n; i++){
		if(i <= p)
			maxLeft = (V[i] > maxLeft) ? V[i] : maxLeft;
		else
			minRight = (V[i] < minRight) ? V[i] : minRight;
	}
	//Check if array is in the appropriate order
	if(maxLeft < minRight)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
}
