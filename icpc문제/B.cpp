#include <iostream>
#include <vector>
using namespace std;
#define DIV 16769023


int N;
int cache[100001][3]; //0 : 0이더많, 1: 같음, 2: 1이더많

int findAns(int idx, int num) {
	int & ret = cache[idx][num];

	//cout << "idx :" << idx << endl;

	if (ret != -1)
		return ret;

	//basecase
	if (idx == 1) {
		if (num == 0 || num == 2)
			return ret = 1;
		else if (num == 1)
			return ret = 0;
	}
	else if (idx == 2) {
		if (num == 0 || num == 2)
			return ret = 0;
		else if (num == 1)
			return ret = 2;

	}

	//기본계산

	if (num == 0) {
		int temp = findAns(idx - 1, 1);
		return ret = temp%DIV;
	} 
	else if (num == 1) {
		int temp = (findAns(idx - 1, 0) % DIV + findAns(idx - 1, 2) % DIV)%DIV;
		return ret = temp ;
	}
	else if (num == 2) {
		int temp = findAns(idx - 1, 1);
		return ret = temp % DIV;
	}
	return ret;

}




int main()
{
	cin >> N;

	for (int i = 0; i <= N; i++) {
		for(int j = 0 ; j<3; j++)
			cache[i][j] = -1;
	}
	
	int ans = 0;

	int count = N/500;

	for (int i = 1; i <= count; i++) {
		for(int j = 0 ; j<3; j++)
			findAns(500 * i, j);
	}

	for (int i = 0; i < 3; i++) {
		ans += findAns(N, i);
	}

	ans %= DIV;





	cout << ans << endl;


	return 0;
}