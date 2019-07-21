#include <vector>
#include <iostream>

using namespace std;

vector<int> clock_list;
vector<vector<int>> switch_list;
vector<int> switch_click;

int result;

void switch_init();
void num_of_case(int clock_num);
void check();

int main() {
	int cases;
	int i, j;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		switch_init();
		result = -1;
		for(j = 0; j < 16; j++) {
			int time;
			cin >> time;
			clock_list.push_back(time % 12);
		}
		num_of_case(0);
		cout << result << endl;
		clock_list.clear();
		switch_list.clear();
		switch_click.clear();
	}
}

void switch_init() {
	int i;
	
	for(i = 0; i < 10; i++) {
		switch_click.push_back(0);
	}

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

void num_of_case(int switch_num) {
	int i;
	vector<int>::iterator iter;

	if(switch_num == 10) {
		check();
		return;
	}

	for(i = 0; i < 4; i++) {
		switch_click[switch_num] = i;

		for(iter = switch_list[switch_num].begin(); iter != switch_list[switch_num].end(); iter++) {
			clock_list[*iter] = (clock_list[*iter] + 3*i) % 12;
		}

		num_of_case(switch_num+1);

		for(iter = switch_list[switch_num].begin(); iter != switch_list[switch_num].end(); iter++) {
			clock_list[*iter] = (clock_list[*iter] + (12 - 3*i)) % 12;
		}
	}
}

void check() {
	int num = 0;
	vector<int>::iterator iter;

	for(iter = clock_list.begin(); iter != clock_list.end(); iter++) {
		if(*iter != 0) {
			return;
		}
	}
	for(iter = switch_click.begin(); iter != switch_click.end(); iter++) {
		num += *iter;
	}

	if(result == -1) {
		result = num;
	} else if(num < result) {
		result = num;
	}
}