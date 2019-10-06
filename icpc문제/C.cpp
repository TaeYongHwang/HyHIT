#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int W;

int cache[2][20];

int coin_price[20];

int max_coin(int day, int W, int coin) {	
	if (day == n) {
		return W + coin * coin_price[day];
	}

	if (coin == 0) {
		//int &ret = cache[0][day];
		int coin_buying = W / coin_price[day];
		
		//if (ret != -1)
		//	return ret;

		return max(max_coin(day + 1, W, coin), max_coin(day + 1, W - coin_buying * coin_price[day], coin_buying));
	}
	else {/*
		int &ret = cache[1][day];

		if (ret != -1) {
			return ret;
		}
		*/
		return max(max_coin(day + 1, W, coin), max_coin(day + 1, W + coin * coin_price[day], 0));
	}
}

int main() {
	cin >> n >> W;
	
	memset(cache[0], -1, sizeof(cache[0]));
	memset(cache[1], -1, sizeof(cache[1]));

	for (int i = 1; i <= n; i++) {
		cin >> coin_price[i];
	}

	cout << max_coin(1, W, 0) << endl;

	return 0;
}

