#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
	int T;
	cin >> T;
	while (T--) {
		int M, N, x, y, n;
		cin >> M >> N >> x >> y >> n;
		// cout << M << ' ' << N << ' '  << x << ' '  << y << ' '  << n;
		vector<pair<int,int>> v(n);
		int best = 99999999;
		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end());
		do {
			int prev_x = v[0].first;
			int prev_y = v[0].second;
			int sum = abs(prev_x - x) + abs(prev_y - y);
			// cout << "(" << v[0].first << " ";
			// cout << v[0].second << ") ";
			for (int i = 1; sum < best && i < v.size(); i++) {
				// cout << "(" << v[i].first << " ";
				// cout << v[i].second << ") ";
				sum += abs(v[i].first - prev_x) + abs(v[i].second - prev_y);
				prev_x = v[i].first;
				prev_y = v[i].second;
			}
			sum += abs(prev_x - x) + abs(prev_y - y);
			best = min(sum, best);
  		} while (next_permutation(v.begin(), v.end()));
		cout << "The shortest path has length " << best << endl;
	}
	return 0;
}
