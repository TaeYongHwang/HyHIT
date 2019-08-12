#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

int n;	// 우물의 깊이
int m;	// 제한시간

double cache[1000][2000];

double snail(int day, int height);

int main() {
	int cases;
	int i, j, k;
	double result;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		for(j = 0; j < 1000; j++) {
			for(k = 0; k < 2000; k++) {
				cache[j][k] = -1;
			}
		}
		cin >> n >> m;
		cout.precision(10);
		cout << snail(0, 0) << endl;
	}
}

double snail(int day, int height) {
	if(day == m) {
		return height >= n ? 1 : 0;
	}
	double& ret = cache[day][height];

	if(ret != -1) {
		return ret;
	}

	return ret = (3*snail(day+1, height+2) + snail(day+1, height+1)) / 4;
}
