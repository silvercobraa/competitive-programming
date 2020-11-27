#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		vector<vector<int>> card(5, vector<int>(5));
		vector<vector<bool>> announced(5, vector<bool>(5, false));
		card[2][2] = -1;
		vector<int> rows(5, 0);
		vector<int> cols(5, 0);
		int diag1 = 1;
		int diag2 = 1;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == 2 and j == 2) {
					continue;
				}
				cin >> card[i][j];
			}
		}
		announced[2][2] = true;
		rows[2]++;
		cols[2]++;
		vector<int> order(75);
		for (int i = 0; i < 75; i++) {
			cin >> order[i];
		}
		int ans = 76;
		for (int k = 0; k < 75; k++) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if ((not announced[i][j]) and card[i][j] == order[k]) {
						rows[i]++;
						cols[j]++;
						if (i + j == 4) {
							diag1++;
						}
						if (i - j == 0) {
							diag2++;
						}
						if (rows[i] == 5 or cols[j] == 5 or diag1 == 5 or diag2 == 5) {
							ans = std::min(ans, k + 1);
							break;
						}
					}
				}
			}
		}
		cout << "BINGO after " << ans << " numbers announced" << endl;
	}
	return 0;
}
