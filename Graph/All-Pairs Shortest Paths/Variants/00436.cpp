#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool check(vector<vector<double>>& dist) {
	int n = dist.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j]*dist[j][i] > 1.0) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[]) {
	int n;
	int case_ = 1;
	for (cin >> n; n != 0; cin >> n) {
		map<string, int> id;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			id[s] = i;
		}
		vector<vector<double>> dist(n, vector<double>(n, 0.0));
		int m;
		cin >> m;
		for (size_t i = 0; i < m; i++) {
			string a, b;
			double w;
			cin >> a >> w >> b;
			dist[id[a]][id[b]] = w;
		}
		for (size_t k = 0; k < n; k++) {
			for (size_t i = 0; i < n; i++) {
				for (size_t j = 0; j < n; j++) {
					// como default es 0, si no es posible la transicion el 0 se comera al otro valor
					dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
				}
			}
		}
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < n; j++) {
		// 		printf("%6.2lf", dist[i][j]);
		// 	}
		// 	puts("");
		// }
		printf("Case %d: ", case_);
		if (check(dist)) {
			puts("Yes");
		}
		else {
			puts("No");
		}
		case_++;
	}
	return 0;
}
