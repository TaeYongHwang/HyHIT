#include <iostream>
#include <vector>

using namespace std;

void print_arr();
void quick_sort(int start, int end);

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
	quick_sort(0, size-1);
	cout << "after sorting" << endl;
	print_arr();
}

void quick_sort(int start, int end) {
	int pivot;
	int low, high;
	int mid;

	if(start >= end) {
		return;
	} else {
		pivot = arr[start];
		low = start+1;
		high = end;
			
		while(low != high) {
			if(arr[low] < pivot) {
				low++;
			} else {
				int temp = arr[low];
				arr[low] = arr[high];
				arr[high] = temp;
				high--;
			}
		}
		if(pivot < arr[low]) {
			int temp = arr[start];
			arr[start] = arr[low-1];
			arr[low-1] = temp;
			mid = low-1;
		} else {
			int temp = arr[start];
			arr[start] = arr[low];
			arr[low] = temp;
			mid = low;
		}
	}
	quick_sort(start, mid-1);
	quick_sort(mid+1, end);
}

void print_arr() {
	vector<int>::iterator iter;

	for(iter = arr.begin(); iter != arr.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}