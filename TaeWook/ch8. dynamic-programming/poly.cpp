#include <iostream>
#include <string.h>

using namespace std;

const int DIVISOR = 10000000;	// 10,000,000

int n;
int cache[101][101];

int poly(int square, int square_left);

int main() {
	int cases;
	int i, j;

	cin >> cases;
	memset(cache, -1, sizeof(cache));
	for(i = 0; i < cases; i++) {
		int sum = 0;
		
		cin >> n;
		cout << poly(0, n) << endl;
	}
}

int poly(int square, int square_left) {
	int sum = 0;
	int i;

	if(square_left == 0) return 1;

	int& ret = cache[square][square_left];

	if(ret != -1) {
		return ret;
	}

	ret = 0;

	for(i = 1; i <= square_left; i++) {
		int num_of_case = square+i-1;
		if(square == 0) num_of_case = 1;

		sum += num_of_case * poly(i, square_left-i);
		sum %= DIVISOR;
	}
	return ret = sum;
}