#include <iostream>
#include <vector>

#define min(a, b) a > b ? b : a
#define max(a, b) a < b ? b : a

using namespace std;

vector<int> fence;

int area_of_fence(int start, int end);

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
		cout << area_of_fence(0, num_of_fences-1) << endl;
		fence.clear();
	}
}
int area_of_fence(int start, int end) {
	int mid;		// mid는 왼쪽 배열의 end와 같음
	int ret;
	int left, right;
	int height;

	if(start >= end) {
		return fence[start];
	}

	mid = (start+end) / 2;
	ret = 0;

	ret = max(area_of_fence(start, mid), area_of_fence(mid+1, end));

	left = mid;
	right = mid+1;
	height = min(fence[left], fence[right]);

	while(1) {
		ret = max(ret, (right-left+1)*height);

		if(left == start && right == end) {
			break;
		} else if(left == start) {
			right++;
			height = min(height, fence[right]);
		} else if(right == end) {
			left--;
			height = min(height, fence[left]);
		} else {
			if(fence[left-1] < fence[right+1]) {
				right++;
				height = min(height, fence[right]);
			} else {
				left--;
				height = min(height, fence[left]);
			}
		}
	}
	return ret;
}