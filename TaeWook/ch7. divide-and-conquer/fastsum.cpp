#include <iostream>

using namespace std;

int fastsum(int n);

int main() {
	int num;
	cin >> num;
	cout << fastsum(num) << endl;
}

int fastsum(int n) {
	if(n == 1) return 1;
	if(n % 2 == 1) return fastsum(n - 1) + n;
	return 2*fastsum(n/2) + (n/2)*(n/2);
}