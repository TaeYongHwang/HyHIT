#include <iostream>
#include <vector>

#define min(left, right) left < right ? left : right
#define max(left, right) left > right ? left : right

using namespace std;

vector<int> fence;

int area_of_fence(int num_of_fences);

int main() {
	int cases;
	int num_of_fences;
	int i, j;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> num_of_fences;
		for(j = 0; j < num_of_fences; j++) {
			int temp;
			cin >> temp;
			fence.push_back(temp);
		}
		cout << area_of_fence(num_of_fences) << endl;

		fence.clear();
	}
}

int area_of_fence(int num_of_fences) {
	int left, right;
	int height;
	int area = 0;

	for(left = 0; left < num_of_fences; left++) {
		height = fence[left];
		for(right = left; right < num_of_fences; right++) {
			height = min(height, fence[right]);
			area = max(area, (right-left+1)*height);
		}
	}
	return area;
}