#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int binarySearch(vector<int> arr, int value);

int main() {
	vector<int> arr;
	srand((unsigned int)time(NULL));

	//////////////////////////////////
	//
	// test1. single element array test
	//
	cout << "test1...   ";
	arr.push_back(5);
	if(binarySearch(arr, 5) != 0) {
		cout << "failed" << endl;
		return 0;
	}	
	cout << "passed" << endl;
	arr.clear();
	//////////////////////////////////
	//
	// test2. two elements array test
	//
	arr.push_back(3);
	arr.push_back(7);
	cout << "test2...   ";
	if(binarySearch(arr, 3) != 0) {
		cout << "failed" << endl;
		return 0;
	}
	if(binarySearch(arr, 7) != 1) {
		cout << "failed" << endl;
		return 0;
	}
	cout << "passed" << endl;
	arr.clear();
	//////////////////////////////////
	//
	// test3. odd number elements array test
	//
	cout << "test3...   ";
	for(int i = 0; i < 9; i++) {
		arr.push_back(i*5 + (rand()%3));
	}
	for(int i = 0; i < 9; i++) {
		if(binarySearch(arr, arr[i]) != i) {
			cout << "failed" << endl;
			return 0;
		}
	}
	cout << "passed" << endl;
	arr.clear();
	//////////////////////////////////
	//
	// test4. even number elements array test
	//
	cout << "test4...   ";
	for(int i = 0; i < 10; i++) {
		arr.push_back(i*5 + (rand()%3));
	}
	for(int i = 0; i < 10; i++) {
		if(binarySearch(arr, arr[i]) != i) {
		cout << "failed" << endl;
		return 0;
		}
	}
	cout << "passed" << endl;
	arr.clear();
}

////////////////////////////////////////
//
// �־��� �迭���� ����Ž���� �̿��� value�� ã�� index�� ��ȯ
// ���� value�� �������� �ʴ´ٸ� -1�� ��ȯ
// �迭�� ������������ ���ĵǾ��ִ�
// �ߺ��Ǵ� ���Ҵ� ����
//
////////////////////////////////////////

int binarySearch(vector<int> arr, int value) {
	int left = 0;
	int right = arr.size();
	int mid = left + (right - left) / 2;

	while(right >= left) {
		if(arr[mid] == value) {
			return mid;
		} else if(arr[mid] > value) {
			right = mid - 1;
			mid = left + (right - left) / 2;
		} else if(arr[mid] < value) {
			left = mid + 1;
			mid = left + (right - left) / 2;
		}
	}
	return -1;
}