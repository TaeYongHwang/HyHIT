#include <iostream>
#include <vector>

using namespace std;

void merge(int start, int mid, int end);
void divide(int start, int end);
void print_arr();

vector<int> arr;

int main() {
	int size;
	int i;
	int num;
	cin >> size;
	for(i = 0; i < size; i++) {
		cin >> num;
		arr.push_back(num);
	}
	cout << "before sorting" << endl;
	print_arr();
	divide(0, size-1);
	cout << "after sorting" << endl;
	print_arr();
}

void merge(int start, int mid, int end) {
	vector<int> arr_tmp;
	
	int left = start;
	int right = mid+1;
	int i;

	while(left != mid+1 || right != end+1) {
		if(left == mid+1) {
			arr_tmp.push_back(arr[right]);
			right++;
		} else if(right == end+1) {
			arr_tmp.push_back(arr[left]);
			left++;
		} else {
			if(arr[left] > arr[right]) {
				arr_tmp.push_back(arr[right]);
				right++;
			} else {
				arr_tmp.push_back(arr[left]);
				left++;
			}
		}
	}	
	for(i = start; i < end+1; i++) {
		arr[i] = arr_tmp[i-start];
	}
}

void divide(int start, int end) {
	if(start == end) {
		return;
	}
	divide(start, (start+end) / 2);
	divide((start+end) / 2 + 1, end);
	// mid의 값은 left의 end값
	merge(start, (start+end) / 2, end);
}

void print_arr() {
	vector<int>::iterator iter;

	for(iter = arr.begin(); iter != arr.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}