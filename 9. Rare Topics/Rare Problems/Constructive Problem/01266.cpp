#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	bool first = true;
	while (cin >> n) {
		if (first) {
			first = false;
		}
		else {
			cout << endl;
		}
		vector<vector<int>> square(n, vector<int>(n, 0));
		int row = 0;
		int col = n/2;
		for (int i = 1; i <= n*n; i++) {
			square[row][col] = i;
			if (square[(row+n-1) % n][(col+1)%n] == 0) {
				row = (row + n - 1) % n;
				col = (col + 1) % n;
			}
			else {
				row = (row + 1) % n;
			}
		}
		int digits = 0;
		for (int nn = n*n; nn > 0; nn /= 10) {
			digits++;
		}
		int sum = 0;
		for (size_t j = 0; j < n; j++) {
			sum += square[0][j];
		}
		// cout << digits << endl;
		printf("n=%d, sum=%d\n", n, sum);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << " " << setw(digits) << square[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
