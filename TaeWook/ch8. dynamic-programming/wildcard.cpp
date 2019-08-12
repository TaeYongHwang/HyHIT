#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string wildcard;
string filename;
vector<string> file_list;
int cache[100][100];

int check(int w_index, int f_index);

int main() {
	int cases;
	int i, j, k;
	vector<string>::iterator iter;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> wildcard;
		cin >> N;
		for(j = 0; j < N; j++) {
			for(k = 0; k < 100; k++) {
				memset(cache[k], 0, sizeof(int)* 100);
			}
			cin >> filename;
			if(check(0, 0) == 1) {
				file_list.push_back(filename);
			}
		}
		sort(file_list.begin(), file_list.end());
	
		for(iter = file_list.begin(); iter != file_list.end(); iter++) {
			cout << *iter << endl;
		}
		file_list.clear();
	}
}

// two arguments, index of wildcard and index of file name 
// return 1, if wildcard matches the file name
// the cache has a value of zero, if the search is not completed
// the cache has a value of negative one, if the wildcard does not match the file name
// the cache has a value of one, if the wildcard matches the file name
// if the wildcard has character excepted '*' at given index, increase index of wildcard and filename
// if the wildcard has character '*', branch off

int check(int w_index, int f_index) {
	if(w_index >= wildcard.length() && f_index >= filename.length()) {
		return 1;
	}	

	if(w_index >= wildcard.length() && f_index < filename.length()) {
		return -1;
	}

	if(wildcard[w_index] == '*' && f_index >= filename.length()) {
		return check(w_index+1, f_index);
	} else if(f_index >= filename.length()) {
		return -1;
	}	

	if(cache[w_index][f_index] == -1) {
		return -1;
	} else if(cache[w_index][f_index] == 1) {
		return 1;
	}
	
	if(wildcard[w_index] == '*') {
		int i;
		for(i = f_index; i <= filename.length(); i++) {
			if(check(w_index+1, i) == 1) {
				return cache[w_index][f_index] = 1;
			}
		}
		return cache[w_index][f_index] = -1;
	} else if((wildcard[w_index] == '?') || (wildcard[w_index] == filename[f_index])) { 
		return cache[w_index][f_index] = check(w_index+1, f_index+1);
	} else {
		return cache[w_index][f_index] = -1;
	}
}













