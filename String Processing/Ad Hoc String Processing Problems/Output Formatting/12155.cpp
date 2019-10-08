#include <iostream>
#include <cmath>

using namespace std;

int manhattan_distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void print_char(int i, int j, int n) {
	int mid = (n + n - 1) / 2;
	int row = i % (2*n - 1);
	int col = j % (2*n - 1);
	int dist = manhattan_distance(mid, mid, row, col);
	if (dist < n) {
		cout << char('a' + (dist%26));
	}
	else {
		cout << '.';
	}
}

int main(int argc, char const *argv[]) {
	int n, row1, col1, row2, col2;
	int case_ = 1;
	for (cin>>n>>row1>>col1>>row2>>col2; n != 0; cin>>n>>row1>>col1>>row2>>col2) {
		printf("Case %d:\n", case_);
		for (int i = row1; i <= row2; i++) {
			for (int j = col1; j <= col2; j++) {
				print_char(i, j, n);
			}
			cout << endl;
		}
		case_++;
	}
	return 0;
}
