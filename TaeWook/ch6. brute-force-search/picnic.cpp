#include <vector>
#include <iostream>

using namespace std;

const int FACT[5] = {1,2,6,24,120};

vector<vector<int>> friend_list;
vector<int> student_list;

int get_combination(int num_of_student, int count);

int main() {
	int num_of_student;
	int num_of_pair;
	int cases;
	int i, j;

	vector<int> result;
	vector<int>::iterator iter;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> num_of_student >> num_of_pair;

		for(j = 0; j < num_of_student; j++) {
			student_list.push_back(j);
		}

		friend_list.assign(num_of_student, vector<int>(num_of_student, 0));

		for(j = 0; j < num_of_pair; j++) {
			int student1;
			int student2;

			cin >> student1 >> student2;

			friend_list[student1][student2] = 1;
			friend_list[student2][student1] = 1;
		}
		if(num_of_pair < (num_of_student / 2)) { 
			cout << 0 << endl;
		} else if((num_of_student % 2) == 0 && num_of_student != 0) {
			cout << (get_combination(num_of_student, 0)) << endl;
		} else {
			cout << 0 << endl;
		}
		student_list.clear();
		friend_list.clear();
	}
}

int get_combination(int num_of_student, int count) {
	int i;
	int sum = 0;

	if(count == num_of_student) {
		return 1;
	} 

	for(i = count; i < num_of_student; i++) {
		int isOk = true;
		int temp = student_list[i];
		student_list[i] = student_list[count];
		student_list[count] = temp;
		if((count % 2) == 1) {
			if(student_list[count-1] > student_list[count]) {
				isOk = false;
			}
			int student1 = student_list[count - 1];
			int student2 = student_list[count];

			if(friend_list[student1][student2] == 0) {
				isOk = false;
			}
		} else if((count % 2) == 0 && count > 0) {
			if(student_list[count] > student_list[count-2]) {
				isOk = false;
			}
		}

		if(isOk == true) {
			sum += get_combination(num_of_student, count+1);
		}
		temp = student_list[i];
		student_list[i] = student_list[count];
		student_list[count] = temp;
	}
	return sum;
}