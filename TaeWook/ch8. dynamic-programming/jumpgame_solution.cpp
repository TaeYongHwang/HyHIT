#include <iostream>

using namespace std;

int n, board[100][100];
int cache[100][100];

int jump(int a, int b);

int main() {
	int cases;
	int i, j, k;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> n;
		for(j = 0; j < n; j++) {
			for(k = 0; k < n; k++) {
				int temp;
				cin >> temp;
				board[j][k] = temp;
				cache[j][k] = -1;
			}
		}
		if(jump(0, 0) == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

int jump(int a, int b) {
	if(a >= n || b >= n) {
		return 0;
	}
	if(a == n-1 && b == n-1) {
		return 1;
	}

	int& ret = cache[a][b];
	
	if(ret != -1) {
		return ret;
	}

	int jump_size = board[a][b];

	return ret = (jump(a, b+jump_size)) || (jump(a+jump_size, b));
};