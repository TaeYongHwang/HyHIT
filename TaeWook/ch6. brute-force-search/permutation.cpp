#include <vector>
#include <iostream>

using namespace std;

vector<int> list;

void print_permutation();
void permutation(int size, int left);

int main() {
	int num;
	
	cout << "input : ";
	cin >> num;

	for(int i = 0; i < num; i++) {
		list.push_back(i + 1);
	}
	permutation(list.size(), 0);
}

void print_permutation() {
	vector<int>::iterator iter;

	for(iter = list.begin(); iter != list.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

void permutation(int size, int count) {
	if(count == size) {
		print_permutation();
		return;
	}
	for(int i = count; i < size; i++) {
		int temp = list[count];
		list[count] = list[i];
		list[i] = temp;
		permutation(size, count + 1);
		temp = list[count];
		list[count] = list[i];
		list[i] = temp;
	}
}

