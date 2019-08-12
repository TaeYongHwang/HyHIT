#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int sequence[500];
int cache[500];
int max_length;

int check(int start);

int main() {
	int cases;
	int i, j, k;
	int max_length;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		max_length = -1;
		memset(cache, -1, sizeof(int)*500);
		cin >> N;
		for(j = 0; j < N; j++) {
			cin >> sequence[j];
		}
		for(j = 0; j < N; j++) {
			max_length = max(max_length, check(j));
		}
		cout << max_length << endl;
	}
}

int check(int start) {
	int i;
	int& ret = cache[start];

	if(ret != -1) {
		return ret;
	}

	ret = 1;

	for(i = start+1; i < N; i++) {
		if(sequence[start] < sequence[i]) {
			ret = max(ret, check(i)+1);
		}
	}
	return ret;
}