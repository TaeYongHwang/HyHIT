#include <iostream>
#include <math.h>
using namespace std;


int find(int input_num, int first, int count) {

	int tmp;
	int ans;
	int a = first * first;
	input_num = input_num - a;
	count++;

	if (input_num == 0)
		return count;
	else {
	
		tmp = sqrt(input_num);
		ans = find(input_num, tmp, count);
	
	}

	return ans;
}


int main() {

	int input_num, first,check;

	cin >> input_num;
	first = sqrt(input_num);

	while (1) {
	
		check = find(input_num, first, 0);

		if (check <= 4)
			break;
		else {
		
			first = first - 1;
	
		}
	
	}

	cout << check << endl;

	return 0;
}