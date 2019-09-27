#include <iostream>
#include <vector>

#define INF 99999999

using namespace std;

int main(int argc, char const *argv[]) {
	int c, n;
	int case_ = 1;
	for (cin >> c >> n; c != 0 or n != 0; cin >> c >> n) {
		printf("Election #%d\n", case_);
		vector<vector<int>> pref(n, vector<int>(c, 0));
		vector<bool> valid(n, true);
		vector<bool> alive(c, true);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < c; j++) {
				cin >> pref[i][j];
				if (pref[i][j] <= 0 or pref[i][j] > c) {
					valid[i] = false;
				}
				pref[i][j]--;
			}
			for (int j = 0; j < c; j++) {
				for (int k = j + 1; k < c; k++) {
					if (pref[i][j] == pref[i][k]) {
						valid[i] = false;
					}
				}
			}
		}
		int bad = 0;
		for (auto x: valid) {
			bad += not x;
		}
		if (bad > 0) {
			printf("   %d bad ballot(s)\n", bad);
		}
		int half = (n - bad) / 2;
		while (true) {
			vector<int> votes(c, 0);
			for (int i = 0; i < n; i++) {
				if (valid[i]) {
					int j = 0;
					for ( ; not alive[pref[i][j]]; j++) {
					}
					votes[pref[i][j]]++;
				}
			}
			// for (auto x: votes) {
			// 	cout << x << " ";
			// }
			bool tie = true;
			for (int i = 0; i < c; i++) {
				for (int j = i + 1; j < c; j++) {
					if (alive[i] and alive[j] and votes[i] != votes[j]) {
						// printf("%d %d\n", i, j);
						tie = false;
					}
				}
			}
			if (tie) {
				vector<int> ans;
				for (int i = 0; i < c; i++) {
					if (alive[i]) {
						ans.push_back(i);
					}
				}
				if (ans.size() != 1) {
					printf("   The following candidates are tied:");
					for (auto x: ans) {
						printf(" %d", x+1);
					}
					printf("\n");
					break;
				}
			}

			int winner = -1;
			int loser = -1;
			for (int i = 0; i < c; i++) {
				if (votes[i] > half) {
					winner = i;
					printf("   Candidate %d is elected.\n", winner+1);
					break;
				}
			}
			if (winner != -1) {
				break;
			}
			int min = INF;
			int eliminated = -1;
			for (int i = 0; i < c; i++) {
				if (alive[i] and votes[i] < min) {
					min = votes[i];
					eliminated = i;
				}
			}
			if (eliminated != -1) {
				alive[eliminated] = false;
			}
			// cout << endl;
		}
		case_++;
	}
	return 0;
}
