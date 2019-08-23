#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

#define INF 987654321

using namespace std;

int N;
int S;
int sequence[100];
int cache[100][11];

int quantize(int pos, int num);
int min_error(int start, int end);

int main() {
	int cases;
	int i, j;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		cin >> S;
		for(j = 0; j < N; j++) {
			cin >> sequence[j];	// 1000이하의 자연수
		}
		sort(sequence, sequence+N);
		cout << quantize(0, S) << endl;
	}
}

int quantize(int pos, int num) {
	int i;

	if(pos == N) return 0;
	else if(num == 0) return INF;

	int &ret = cache[pos][num];

	if(ret != -1) return ret;

	ret = INF;

	for(i = pos; i < N; i++) {
		ret = min(ret, min_error(pos, i)+quantize(i+1, num-1));
	}

	return ret;
}

// 줄여보기

int min_error(int start, int end) {
	int i;
	int sum;
	int avg;
	int divisor;
	int result;
	
	result = 0;
	sum = 0;
	divisor = (end-start+1);

	for(i = start; i <= end; i++) sum += sequence[i];

	avg = sum / divisor;

	if((sum%divisor)*2 >= divisor) avg++;

	for(i = start; i<= end; i++) result += (sequence[i]-avg)*(sequence[i]-avg);

	return result;
}