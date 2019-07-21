#include <vector>
#include <iostream>

using namespace std;

vector<int> result;
vector<vector<char>> board;
int height;
int width;
int count;

int num_of_cases(int width, int height);

int main() {
	int cases;
	int i, j, k;
	char a;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> height >> width;

		board.assign(height, vector<char>(width, '.'));

		for(j = 0; j < height; j++) {
			for(k = 0; k < width; k++) {
				cin >> a;
				board[j][k] = a;
			}
		}
		cout << num_of_cases(0, 0) << endl;
		board.clear();
	}
}

int num_of_cases(int x, int y) {
	int sum = 0;
	int next_x = x+1;
	int next_y = y;

	if(x == width-1 && y == height-1) {
		if(board[y][x] == '#') {
			return 1;
		} else {
			return 0;
		}
	}

	if((next_x = (x + 1) % width) == 0) {
		next_y = y + 1;
	}

	if(board[y][x] == '#') {
		sum += num_of_cases(next_x, next_y);	
	} else {
		// case1 
		if(x+1 < width && y+1 < height && board[y][x+1] == '.' && board[y+1][x+1] == '.') {
			board[y][x] = '#';
			board[y][x+1] = '#';
			board[y+1][x+1] = '#';
			sum += num_of_cases(next_x, next_y);
			board[y][x] = '.';
			board[y][x+1] = '.';
			board[y+1][x+1] = '.';
		}
		// case2
		if(x+1 < width && y+1 < height && board[y][x+1] == '.' && board[y+1][x] == '.') {
			board[y][x] = '#';
			board[y][x+1] = '#';
			board[y+1][x] = '#';
			sum += num_of_cases(next_x, next_y);
			board[y][x] = '.';
			board[y][x+1] = '.';
			board[y+1][x] = '.';
		}
		// case3
		if(x+1 < width && y+1 < height && board[y+1][x] == '.' && board[y+1][x+1] == '.') {
			board[y][x] = '#';
			board[y+1][x] = '#';
			board[y+1][x+1] = '#';
			sum += num_of_cases(next_x, next_y);
			board[y][x] = '.';
			board[y+1][x] = '.';
			board[y+1][x+1] = '.';
		}		
		// case4
		if(x > 0 && y+1 < height && board[y+1][x-1] == '.' && board[y+1][x] == '.') {
			board[y][x] = '#';
			board[y+1][x-1] = '#';
			board[y+1][x] = '#';
			sum += num_of_cases(next_x, next_y);
			board[y][x] = '.';
			board[y+1][x-1] = '.';
			board[y+1][x] = '.';
		}
	}
	return sum;
}