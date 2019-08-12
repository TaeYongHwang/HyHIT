#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> board;
vector<vector<int>> board_flag;

int board_check(int a, int b);

int main() {
	int cases;
	int i, j, k;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> n;
		board.assign(n, vector<int>(n, -1));
		board_flag.assign(n, vector<int>(n, -1));

		for(j = 0; j < n; j++) {
			for(k = 0; k < n; k++) {
				int temp;
				cin >> temp;
				board[j][k] = temp;
			}
		}
		if(board_check(0, 0) == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		board.clear();
		board_flag.clear();
	}
}

int board_check(int a, int b) {
	if(a < 0 || b < 0 || a >=n || b >= n) {
		return 0;
	}
	if(a == n-1 && b == n-1) {
		return 1;
	}
	int num = board[a][b];

	if(board_flag[a][b] == 0) {
		return 0;
	}
	if(board_check(a+num, b) == 0 && board_check(a, b+num) == 0) {
		board_flag[a][b] = 0;
		return 0;
	} else {
		return 1;
	}
}