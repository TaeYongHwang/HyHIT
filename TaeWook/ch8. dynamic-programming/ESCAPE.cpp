#include <iostream>

using namespace std;

int n;	// ������ ��
int d;	// Ż�� �� ���ݱ��� ���� �ϼ�
int p;	// �����Ұ� �ִ� ������ ��ȣ
int t;	// Ȯ���� ����� ������ ��

int deg[50];
int village[50][50];
int q[50];

double cache[50][101][50];

void escape(int pos, int day);

int main() {
	int c;
	int i, j, k;
	double *ret;

	cin >> c;

	while(c-- > 0) {
		int sum = 0;

		for(i = 0; i < 50; i++)
			for(j = 0; j < 101; j++)
				for(k = 0; k < 50; k++)
					cache[i][j][k] = (double)-1;
		cin >> n >> d >> p;
		for(i = 0; i < n; i++) {
			deg[i] = 0;
			for(j = 0; j < n; j++) {
				cin >> village[i][j];
				if(village[i][j] == 1) deg[i]++;
			}
		}
		cin >> t;
		for(i = 0; i < t; i++) {
			cin >> q[i];
		}
		escape(p, 0);
		ret = cache[p][0];

		for(i = 0; i < t; i++) {
			cout.precision(10);
			cout << ret[q[i]] << endl;
		}
	}
}

// Ż�� �� day���� ������ ��, ���� ����(pos)���� ����ģ��.
// cache[pos][day][village] : Ż�� �� day���� ������ ��, ���� ����(pos)���� �� �� �ִ� ������ ���
void escape(int pos, int day) {
	int i, j;
	double *ret = cache[pos][day];

	if(ret[0] != -1) return;

	for(i = 0; i < n; i++) {
		cache[pos][day][i] = 0;
	}
	if(day == d) {
		ret[pos] = 1;
		return;
	}

	for(i = 0; i < n; i++) {
		if(village[pos][i] == 1) {			
			escape(i, day+1);
			for(j = 0; j < n; j++) {
				ret[j] += (cache[i][day+1][j]/deg[pos]);
			}	
		}
	}
}