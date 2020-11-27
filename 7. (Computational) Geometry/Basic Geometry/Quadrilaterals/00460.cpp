#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t t = 0; t < n; t++) {
		if (t != 0) {
			cout << endl;
		}
		vector<int> v(8);
		for (size_t i = 0; i < 8; i++) {
			cin >> v[i];
		}
		vector<pair<int,int>> segments = {{v[0], v[2]}, {v[4], v[6]}};
		sort(segments.begin(), segments.end());
		int width = segments[0].second - segments[1].first;
		if (width <= 0) {
			cout << "No Overlap" << endl;
			continue;
		}
		int x1 = segments[1].first;
		int x2 = min(segments[0].second, segments[1].second);
		segments = {{v[1], v[3]}, {v[5], v[7]}};
		sort(segments.begin(), segments.end());
		int height = segments[0].second - segments[1].first;
		if (height <= 0) {
			cout << "No Overlap" << endl;
			continue;
		}
		int y1 = segments[1].first;
		int y2 = min(segments[0].second, segments[1].second);
		printf("%d %d %d %d\n", x1, y1, x2, y2);
	}
	return 0;
}
