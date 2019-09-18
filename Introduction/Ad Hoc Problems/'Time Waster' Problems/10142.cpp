#include <iostream>
#include <vector>
#include <sstream>

#define INF 99999999

using namespace std;


int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		// cout << "case: " << t << endl;
		int n;
		cin >> n;
		vector<string> names(n);
		getline(cin, names[0]);
		for (size_t i = 0; i < n; i++) {
			getline(cin, names[i]);
		}
		string line;
		vector<vector<int>> M;
		for (getline(cin, line); line != ""; getline(cin, line)) {
			vector<int> v(n);
			stringstream ss(line);
			for (int j = 0; j < n; j++) {
				ss >> v[j];
				v[j]--;
			}
			M.push_back(v);
		}
		int m = M.size();// votantes
		vector<int> votes(n, 0);
		vector<bool> alive(n, true);
		int winner = -1;
		for (int round = 0; true; round++) {
			// cout << "ronda " << round << endl;
			for (int i = 0; i < m; i++) {
				int cand = 0;
				for ( ; not alive[M[i][cand]]; cand++) {}
				// printf("%d vota por %d\n", i+1, M[i][cand]+1);
				votes[M[i][cand]]++;
			}
			winner = -1;
			for (int i = 0; i < n; i++) {
				// cout << "votes " << i << ": " << votes[i] << endl;
				if (alive[i] and votes[i] > m/2) {
					// cout << "winner " << i << endl;
					winner = i;
					break;
				}
			}
			if (winner != -1) {
				break;
			}
			int loser = -1;
			int worst = INF; // a lo mas hay 20 votos
			for (int i = 0; i < n; i++) {
				if (alive[i] and votes[i] < worst) {
					loser = i;
					worst = votes[i];
				}
			}
			bool all_equal = true;
			for (int i = 0; i < n; i++) {
				if (alive[i] and votes[i] != worst) {
					all_equal = false;
					break;
				}
			}
			if (all_equal) {
				winner = loser;
				break;
			}
			for (int i = 0; i < n; i++) {
				if (votes[i] == worst) {
					alive[i] = false;
					// cout << "muere " << i+1 << endl;
				}
			}
			votes = vector<int>(n, 0);
		}
		for (int i = 0; i < n; i++) {
			if (votes[i] == votes[winner]) {
				cout << names[i] << endl;
			}
		}
	}
	return 0;
}
