#include <iostream>
#include <string.h>
#include <algorithm>

#define N 0
#define M 1
#define BASE 2

using namespace std;

int n, m;
int seq[2][100];

int cache[2][100][100];

int lis(int flag, int pos_n, int pos_m);

int main() {
	int c;
	int i;

	cin >> c;

	while(c-- > 0) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> m;
		for(i = 0; i < n; i++) {
			cin >> seq[N][i];
		}
		for(i = 0; i < m; i++) {
			cin >> seq[M][i];
		}

		int result = 0;
		for(i = 0; i < n; i++) {
			result = max(result, lis(N, i, 0));
		}
		for(i = 0; i < m; i++) {
			result = max(result, lis(M, 0, i));
		}
		cout << result << endl;
	}
}

int lis(int flag, int pos_n, int pos_m) {
	int i, j;
	int pivot;
	int &ret = cache[flag][pos_n][pos_m];

	if(ret != -1) return ret;

	ret = 1;

	if(flag == N) {
		pivot = seq[flag][pos_n];
		i = pos_n+1;
		j = pos_m;
	} else if(flag == M) {
		pivot = seq[flag][pos_m];
		i = pos_n;
		j = pos_m+1;
	}

	for(; i < n; i++) {
		if(pivot < seq[N][i]) ret = max(ret, lis(N, i, pos_m)+1);
	}

	for(; j < m; j++) {
		if(pivot < seq[M][j]) ret = max(ret, lis(M, pos_n, j)+1);
	}

	return ret;
}