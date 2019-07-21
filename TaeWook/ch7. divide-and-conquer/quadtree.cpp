#include <iostream>
#include <vector>
#include <string>

using namespace std;

string quadtree;

void reverse_quadtree(int start, int end);

int main() {
	int cases;
	int i;

	cin >> cases;

	for(i = 0; i < cases; i++) {
		cin >> quadtree;
		reverse_quadtree(0, quadtree.length()-1);
		cout << endl;
		quadtree = "";
	}
}

void reverse_quadtree(int start, int end) {	
	int pos[4][2];
	int start_tmp;
	int end_tmp;
	int index;
	int i;

	if(quadtree[start] != 'x') {	
		cout << quadtree[start];
	} else {
		start++;
		index = start;
		start_tmp = start;
		end_tmp = start;
		i = 0;

		while(index <= end) {
			if(quadtree[index] == 'x') {
				end_tmp += 4;
			}
			if(index == end_tmp) {
				pos[i][0] = start_tmp;
				pos[i][1] = end_tmp;
				i++;
				end_tmp++;
				start_tmp = end_tmp;
				index = start_tmp;
			} else {
				index++;
			}
		}
		cout << "x";
		reverse_quadtree(pos[2][0], pos[2][1]);
		reverse_quadtree(pos[3][0], pos[3][1]);
		reverse_quadtree(pos[0][0], pos[0][1]);
		reverse_quadtree(pos[1][0], pos[1][1]);
	}
}