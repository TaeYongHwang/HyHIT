#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

//#define max(a, b) a > b ? a : b

using namespace std;

int N;
int triangle[100][100];
int cache[100][100];

int check(int y, int x);

int main() {
	int cases;
	int i, j, k;
	
	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> N;
		for(j = 0; j < N; j++) {
			memset(cache[j], -1, sizeof(int)*100);
			for(k = 0; k <= j; k++) {
				cin >> triangle[j][k];
			}
		}
		cout << check(0, 0) << endl;
	}
}

int check(int y, int x) {
	if(y == N-1) {
		return triangle[y][x];
	}
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	return ret = max(check(y+1,x), check(y+1,x+1)) + triangle[y][x];
}