#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

int pi[10000];
int cache[10000];
int pi_size;

int check(int start);
int difficulty(int start, int count);

int main() {
	int cases;
	int i, j;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		string temp;
		memset(cache, -1, sizeof(cache));
		cin >> temp;
		pi_size = temp.length();
		for(j = 0; j < pi_size; j++) {
			pi[j] = temp[j]-48;
		}
		cout << check(0) << endl;
	}
}

int check(int start) {	
	int i;
	int& ret = cache[start];

	if(start >= pi_size) {
		return 0;
	}

	if(ret != -1) {
		return ret;
	}
	ret = 987654321;

	for(i = 3; i <= 5; i++) {
		if(start+i > pi_size) {
			break;
		}
		ret = min(ret, check(start+i) + difficulty(start, i));
	}

	return ret;
}

int difficulty(int start, int count) {
	// 같은지
	int same = pi[start];
		
	for(int i = start+1; i < start+count; i++) {
		if(pi[i] != same) {
			same = -1;
			break;
		}
	}
	if(same != -1) {
		return 1;
	}

	// 등차수열
	int mul = pi[start+1] - pi[start];
	int seq = 0;

	for(int i = start+2; i < start+count; i++) {
		if(pi[i] != pi[start] + (i-start)*mul) {
			seq = -1;
			break;
		}
	}

	if(seq != -1 && (mul == 1 || mul == -1)) {
		return 2;
	}

	// 번갈아
	int a, b;
	a = pi[start];
	b = pi[start+1];
	for(int i = start+2; i < start+count; i++) {
		if((i-start) % 2 == 0 && pi[i] != a) {
			a = -1;
			break;
		} else if((i-start) % 2 == 1 && pi[i] != b) {
			a = -1;
			break;
		}
	}

	if(a != -1) {
		return 4;
	}

	// 등차수열
	if(seq != -1) {
		return 5;
	}

	// 그 외
	return 10;
}