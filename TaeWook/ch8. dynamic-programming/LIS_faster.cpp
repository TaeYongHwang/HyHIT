#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int sequence[500];
int max_length[501];

int check();

int main() {
	int cases;
	int i, j, k;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> N;
		
		for(j = 0; j < N+1; j++) {
			max_length[j] = 1234567;
		}		

		for(j = 0; j < N; j++) {
			cin >> sequence[j];
		}
		cout << check() << endl;
	}
}

int check() {
	int i, j;
	
	for(i = 0; i < N; i++) {
		for(j = 1; j < N+1; j++) {
			if(max_length[j] > sequence[i]) {
				max_length[j] = sequence[i];
				break;
			}
		}
	}
	for(i = 1; i < N+1; i++) {
		if(max_length[i] == 1234567) {
			return i-1;
		}
	}
	return N;
}