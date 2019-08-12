#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int S;
int N_sequence[100];
int S_sequence[10];

int main() {
	int cases;
	int i, j;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> N;
		cin >> S;
		for(j = 0; j < N; j++) {
			cin >> N_sequence[j];
		}
		sort(N_sequence, N_sequence+N);
	}
}

void pick(int start, int end, int count) {









}