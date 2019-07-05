#include <vector>
#include <iostream>

using namespace std;

// List M elements of N

vector<int> combination;

void
print_combination()
{
	vector<int>::iterator iter = combination.begin();

	cout << "(" << *iter;
	iter++;

	for(; iter != combination.end(); iter++) {
		cout << ", " << *iter; 
	}
	cout << ")" << endl;
}

void
pick_element(int N, int left_to_pick) 
{
	if(left_to_pick == 0) {
		print_combination();
	} else {
		for(int i = 0; i < N; i++) {
			combination.push_back(i);
			left_to_pick--;
			pick_element(N, left_to_pick);
			combination.pop_back();
			left_to_pick++;
		}
	}
}

int main() {
	int N;				
	int M;				
	int i;

	cin >> N >> M;

	i = 0;
	cout << "{" << i;
	i++;
	for(; i < N; i++) {
		cout << ", " << i;
	}
	cout << "}" << endl;

	pick_element(N, M);
}

