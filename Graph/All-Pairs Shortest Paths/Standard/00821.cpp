#include <iostream>
#include <vector>
#include <utility>

#define INF 99999999

using namespace std;

int main(int argc, char const *argv[]) {
	int a, b;
	int case_ = 1;
	for (cin >>a>>b; a!=0 or b!= 0; cin >>a>>b) {
		vector<vector<int>> dist(100, vector<int>(100, INF));
		for ( ; a != 0 or b != 0; cin >> a >> b) {
			dist[a-1][b-1] = 1;
		}
		for (int k = 0; k < 100; k++) {
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		int total = 0;
		int count = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (dist[i][j] != INF and i != j) {
					total += dist[i][j];
					count++;
				}
			}
		}
		printf("Case %d: average length between pages = %.3lf clicks\n", case_, double(total)/count);
		case_++;
	}
	return 0;
}
