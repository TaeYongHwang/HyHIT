#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

#define MAX_SUM 0
#define NUM_OF_ROUTES 1

using namespace std;

int cache[100][100][2];
int triangle[100][100];

int N;

void tripath(int x, int y);

int main() {
	int cases;
	int i, j, k;

	cin >> cases;
	
	for(i = 0; i < cases; i++) {
		cin >> N;
		for(j = 0; j < N; j++) {
			for(k = 0; k <= j; k++) {
				cin >> triangle[j][k]; 
			}
		}
		for(j = 0; j < N; j++) {
			for(k = 0; k <= j; k++) {
				cache[j][k][MAX_SUM] = 0;
				cache[j][k][NUM_OF_ROUTES] = 0;
			}
		}
		tripath(0, 0);
		cout << cache[0][0][NUM_OF_ROUTES] << endl;
	}
}

void tripath(int x, int y) {
	int& sum = cache[y][x][MAX_SUM];
	int& route = cache[y][x][NUM_OF_ROUTES];
	
	if(y == N-1) {
		sum = triangle[y][x];
		route = 1;
		return;
	}

	if(route != 0) {
		return;
	}

	tripath(x, y+1);
	tripath(x+1, y+1);

	if(cache[y+1][x][MAX_SUM] > cache[y+1][x+1][MAX_SUM]) {
		sum = cache[y+1][x][MAX_SUM] + triangle[y][x];
		route = cache[y+1][x][NUM_OF_ROUTES];
	} else if(cache[y+1][x][MAX_SUM] == cache[y+1][x+1][MAX_SUM]) {
		sum = cache[y+1][x][MAX_SUM] + triangle[y][x];
		route = cache[y+1][x][NUM_OF_ROUTES] + cache[y+1][x+1][NUM_OF_ROUTES];
	} else {
		sum = cache[y+1][x+1][MAX_SUM] + triangle[y][x];
		route = cache[y+1][x+1][NUM_OF_ROUTES];
	}
}