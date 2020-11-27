#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[]) {
	int S, B;
	for (cin >> S >> B; S != 0 or B != 0; cin >> S >> B) {
		vector<int> left(S+2, 0);
		vector<int> right(S+2, 0);
		iota(left.begin(), left.end(), -1);
		iota(right.begin(), right.end(), 1);
		for (int i = 0; i < B; i++) {
			int L, R;
			cin >> L >> R;
			right[left[L]] = right[R];
			left[right[R]] = left[L];
			if (left[L] == 0) {
				cout << "* ";
			}
			else {
				cout << left[L] << " ";
			}
			if (right[R] == S+1) {
				cout << "*" << endl;
			}
			else {
				cout << right[R] << endl;
			}
		}
		puts("-");
	}

	return 0;
}
