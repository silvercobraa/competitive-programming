#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

constexpr int INF = 99999999;

using namespace std;

double dist(pair<int, int> p, pair<int, int> q) {
	return sqrt((p.first - q.first)*(p.first - q.first) + (p.second - q.second)*(p.second - q.second));
}

int main(int argc, char const *argv[]) {
	int n;
	int count = 1;
	for (cin >> n; n != 0; cin >> n) {
		vector<pair<int, int>> points;
		for (size_t i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			points.push_back({x, y});
		}
		double minimum = double(INF);
		sort(points.begin(), points.end());
		vector<pair<int, int>> ans;
		do {
			double sum = 0.0;
			for (int i = 1; i < points.size(); i++) {
				sum += dist(points[i-1], points[i]);
			}
			if (sum < minimum) {
				minimum = min(minimum, sum);
				ans = points;
			}
		} while(next_permutation(points.begin(), points.end()));
		printf("**********************************************************\n");
		printf("Network #%d\n", count);
		for (int i = 1; i < ans.size(); i++) {
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", ans[i-1].first, ans[i-1].second, ans[i].first, ans[i].second, dist(ans[i-1], ans[i])+16);
		}
		printf("Number of feet of cable required is %.2lf.\n", minimum + 16*(points.size()-1));
		count++;
	}
	return 0;
}
