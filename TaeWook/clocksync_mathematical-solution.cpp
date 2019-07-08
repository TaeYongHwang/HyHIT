#include <vector>
#include <iostream>

using namespace std;

vector<int> clock_list;
vector<vector<int>> switch_list;
int result;

void switch_init();
void num_of_case();
void switch_clock(int switch_num, int click);
void check();

int main() {
	int cases;
	int i, j;

	cin >> cases;
	switch_init();

	for(i = 0; i < cases; i++) {
		result = 0;
		for(j = 0; j < 16; j++) {
			int time;
			cin >> time;
			clock_list.push_back(time % 12);
		}
		num_of_case();
		check();
		cout << result << endl;
		clock_list.clear();
	}
}

void switch_init() {
	switch_list.assign(10, vector<int>(0,0));

	switch_list[0].push_back(0);
	switch_list[0].push_back(1);
	switch_list[0].push_back(2);

	switch_list[1].push_back(3);
	switch_list[1].push_back(7);
	switch_list[1].push_back(9);
	switch_list[1].push_back(11);

	switch_list[2].push_back(4);
	switch_list[2].push_back(10);
	switch_list[2].push_back(14);
	switch_list[2].push_back(15);

	switch_list[3].push_back(0);
	switch_list[3].push_back(4);
	switch_list[3].push_back(5);
	switch_list[3].push_back(6);
	switch_list[3].push_back(7);

	switch_list[4].push_back(6);
	switch_list[4].push_back(7);
	switch_list[4].push_back(8);
	switch_list[4].push_back(10);
	switch_list[4].push_back(12);

	switch_list[5].push_back(0);
	switch_list[5].push_back(2);
	switch_list[5].push_back(14);
	switch_list[5].push_back(15);

	switch_list[6].push_back(3);
	switch_list[6].push_back(14);
	switch_list[6].push_back(15);

	switch_list[7].push_back(4);
	switch_list[7].push_back(5);
	switch_list[7].push_back(7);
	switch_list[7].push_back(14);
	switch_list[7].push_back(15);

	switch_list[8].push_back(1);
	switch_list[8].push_back(2);
	switch_list[8].push_back(3);
	switch_list[8].push_back(4);
	switch_list[8].push_back(5);

	switch_list[9].push_back(3);
	switch_list[9].push_back(4);
	switch_list[9].push_back(5);
	switch_list[9].push_back(9);
	switch_list[9].push_back(13);
}

void num_of_case() {
	int click;
	// 11�� �ð踦 1�� ����ġ�� �̿��� ����
	click = ((12 - clock_list[11]) % 12) / 3;
	switch_clock(1, click);
	result += click;
	// 8�� �ð踦 4�� ����ġ�� �̿��� ����
	click = ((12 - clock_list[8]) % 12) / 3;
	switch_clock(4, click);
	result += click;
	// 9�� �ð踦 9�� ����ġ�� �̿��� ����
	click = ((12 - clock_list[9]) % 12) / 3;
	switch_clock(9, click);
	result += click;
	// 10�� �ð踦 2�� ����ġ�� �̿��� ����
	click = ((12 - clock_list[10]) % 12) / 3;
	switch_clock(2, click);
	result += click;
	// 6�� �ð踦 3�� ����ġ�� �̿��� ����
	click = ((12 - clock_list[6]) % 12) / 3;
	switch_clock(3, click);
	result += click;
	// 7�� �ð踦 7�� ����ġ�� �̿��� ����
	click = ((12 - clock_list[7]) % 12) / 3;
	switch_clock(7, click);
	result += click;
	// 4�� �ð踦 8�� ����ġ�� �̿��� ����
	click = ((12 - clock_list[4]) % 12) / 3;
	switch_clock(8, click);
	result += click;
	// 1�� �ð踦 0�� ����ġ�� �̿��� ����
	click = ((12 - clock_list[1]) % 12) / 3;
	switch_clock(0, click);
	result += click;
	// 3�� �ð踦 6�� ����ġ�� �̿��� ����
	click = ((12 - clock_list[3]) % 12) / 3;
	switch_clock(6, click);
	result += click;
	// 0�� �ð踦 5�� ����ġ�� �̿��� ����
	click = ((12 - clock_list[0]) % 12) / 3;
	switch_clock(5, click);
	result += click;
}

void switch_clock(int switch_num, int click) {
	vector<int>::iterator iter;
	for(iter = switch_list[switch_num].begin(); iter != switch_list[switch_num].end(); iter++) {
		clock_list[*iter] = (clock_list[*iter] + 3 * click) % 12;
	}
}

void check() {
	vector<int>::iterator iter;

	for(iter = clock_list.begin(); iter != clock_list.end(); iter++) {
		if(*iter != 0) {
			result = -1;
			break;
		}
	}
}