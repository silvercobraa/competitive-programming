#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int W, N;
		cin >> W >> N;
		int curr_w = 0;
		int prev_x = 0;
		int dist = 0;
		for (size_t i = 0; i < N; i++) {
			int x, w;
			cin >> x >> w;
			curr_w += w;
			if (curr_w == W) {
				// cout << "igual" << endl;
				dist += x - prev_x;
				dist += x;
				if (i + 1 != N) {
					dist += x;
				}
				curr_w = 0;
			}
			else if (curr_w > W) {
				// cout << "mayor" << endl;
				dist += x - prev_x;
				// cout << x - prev_x << endl;
				dist += 2*x;
				// cout << 2*x << endl;
				curr_w = w;
			}
			else {
				// cout << "menor" << endl;
				dist += x - prev_x;
				// cout << x - prev_x << endl;
			}
			prev_x = x;
		}
		if (curr_w > 0) {
			dist += prev_x;
		}
		cout << dist << endl;
	}
	return 0;
}
