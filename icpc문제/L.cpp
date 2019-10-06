#include <iostream>

using namespace std;

int work[251][2];

int a, b;



int n;

int main() {
	int a = 0;
	int b = 0;
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> work[i][0] >> work[i][1];
	}

	for (int i = 1; i <= n; i++) {
		int temp_a = a + work[i][0];
		int temp_b = b + work[i][1];

		if (temp_a >= temp_b) {
			b += work[i][1];
		}
		else {
			a += work[i][0];
		}
	}

	if (a > b) {
		cout << a << endl;
	}
	else {
		cout << b << endl;
	}

	return 0;
}