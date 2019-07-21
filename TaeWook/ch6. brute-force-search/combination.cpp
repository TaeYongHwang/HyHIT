#include <vector>
#include <iostream>

using namespace std;

void get_combi(int n, int r, int left, int start);
void print_combi();

vector<int> list;
int sum;

int main() {
	int n, r;
	cin >> n >> r;
	get_combi(n, r, 0, 0); 
	cout << "total : " << sum << endl;
}

void print_combi() {
	vector<int>::iterator iter;
	for(iter = list.begin(); iter != list.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	sum++;
}

void get_combi(int n, int r, int count, int start) {
	if(count == r) {
		print_combi();
	}
	for(int i = start; i < n; i++) {
		list.push_back(i);
		get_combi(n, r, count+1, i+1);
		list.pop_back();
	}
}