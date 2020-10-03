#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		int N;
		cin >> N;
		vector<string> field(N);
		for (int i = 0; i < N; i++) {
			cin >> field[i];
		}
		vector<string> numbers = field;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] == '*') {
					continue;
				}
				int count = 0;
				for (int row = i - 1; row <= i + 1; row++) {
					if (row < 0 or row >= N) {
						continue;
					}
					for (int col = j - 1; col <= j + 1; col++) {
						if (col < 0 or col >= N or (row == i and col == j)) {
							continue;
						}
						if (field[row][col] == '*') {
							count++;
						}
					}
				}
				numbers[i][j] = char('0' + count);
			}
		}
		vector<string> touched(N);
		bool mine = false;
		for (int i = 0; i < N; i++) {
			cin >> touched[i];
			for (int j = 0; j < N; j++) {
				if (touched[i][j] == 'x' and field[i][j] == '*') {
					mine = true;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (touched[i][j] == 'x') {
					cout << numbers[i][j];
				}
				else if (field[i][j] == '*' and mine) {
					cout << '*';
				}
				else {
					cout << '.';
				}
			}
			cout << endl;
		}
	}
	return 0;
}
