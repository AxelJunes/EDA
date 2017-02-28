//a09
//Author: Axel Junestrand (C04)

/*
P: {dayCounter < N}
Q: {(gatheredCents = SUM(n) : (FORALL(i) : 0 <= i < N : array[i] >= 1) : n = array[i]) ^ (dayCounter = NUM(i) : 0 <= i < N : array[i] >= 1)}
I: {(dayCounter < N) ^ (gatheredCents = SUM(n) : (FORALL(i) : 0 <= i < N : array[i] >= 1) : n = array[i]) ^ (dayCounter = NUM(i) : 0 <= i < N : array[i] >= 1)}
B: {gatheredCents < totalCents}
*/

#include<iostream>
using namespace std;

#define MAX 10000

int main(){
       /*
	N -> maximum array length
	nCases -> number of cases to consider
	gatheredCents -> amount of gathered cents
	totalCents -> number of cents
	dayCounter -> number of days it takes to gather amount of cents
	*/
        int nCases, gatheredCents;
	int totalCents, dayCounter;
	
	//Get number of cases
	cin >> nCases;
	for(int i = 0; i < nCases; i++){
		cin >> totalCents;
		int array[MAX];
		dayCounter = 0;	
		gatheredCents=0;
		while(gatheredCents < totalCents){
			if(dayCounter == 0 || dayCounter == 1){
				array[dayCounter] = 1;
			}
			else{
				array[dayCounter] = (2 * array[dayCounter-2]) + array[dayCounter-1];
			}
			gatheredCents += array[dayCounter];
			dayCounter++;
		}
		cout << dayCounter << endl;
	}
	return 0;
}
