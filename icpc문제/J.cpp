#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dist[100001];
int delay[100001];
int speed[100001];
long long  cache[100001]; //i번쨰에서 행성에서 최솟값.


long long  findMin(int idx) {
	long long  & ret = cache[idx];

	if (ret != -1)
		return ret;



	//basecase
	if (idx == N - 1) {
		return cache[idx] = 0;
	}

	int totalDist = dist[idx];

	const int curSpeed = speed[idx], curDelay = delay[idx];

	long long minV = findMin(idx + 1) + curDelay + totalDist * curSpeed;




	for (int i = idx + 2; i <= N - 1; i++) {
		totalDist += dist[i - 1];
		minV = min(minV, findMin(i) + curDelay + totalDist * curSpeed);
	}

	return ret = minV;
}




int main()
{
	cin >> N;

	for (int i = 0; i < N-1; i++) {
		cin >> dist[i];
		cache[i] = -1;

	}
	for (int i = 0; i < N-1; i++) {
		cin >> delay[i] >> speed[i];
	}

	cout << findMin(0) << endl;


	return 0;
}