#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

#define DIVISOR 1000000007

using namespace std;

int N;

int main() {
	int cases;
	int i, j;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		int base1 = 1;
		int base2 = 2;
		
		int result = 0;
		
		int sym1 = base1;
		int sym2 = base1+base2;

		cin >> N;

		if(N == 1 || N == 2) {
			cout << 0 << endl;
			continue;
		}

		for(j = 0; j < N; j++) {			
			if(j == 0) {
				result = base1;
			} else if(j == 1) {
				result = base2;
			} else {
				result = (base1+base2) % DIVISOR;
				base1 = base2;
				base2 = result;
			}
			if((j+1)*2+1 == N) {
				sym1 = result;
			} else if((j+2)*2 == N) {
				sym2 = result;
			} else if((j+1)*2 == N) {
				sym2 += result;
				sym2 %= DIVISOR;
				sym1 = sym2;
			}
		}

		if((result-sym1) > 0) {
			cout << result-sym1 << endl;
		} else {
			cout << DIVISOR - (sym1-result) << endl;
		}
	}
}