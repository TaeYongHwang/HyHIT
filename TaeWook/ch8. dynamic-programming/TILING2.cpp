#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int cache[100];
const int DIVISOR = 1000000007;

int tiling(int start);

int main() {
	int cases;
	int i;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		cout << tiling(0) << endl;
	}
}

int tiling(int start) {
	if(start == n-1) return 1;
	else if(start == n-2) return 2;	

	int& ret = cache[start];

	if(ret != -1) return ret;
	
	return ret = (tiling(start+1) + tiling(start+2)) % DIVISOR;
}