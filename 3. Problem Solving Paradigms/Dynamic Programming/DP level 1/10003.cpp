#include <iostream>
#include <vector>

using namespace std;

int result(vector<vector<int>>& DP, vector<int>& point, int i, int j) {
	// cout << i << ' ' << j << endl;
	int length = j - i + 1;
	if (DP[i][j] != -1) {
		return DP[i][j];
	}
	if (length == 2) {
		// return point[j] - point[i];
		DP[i][j] = 0;
		return 0;
	}
	int min = 999999999;
	for (int k = i + 1; k < j; k++) {
		int left = result(DP, point, i, k);
		int right = result(DP, point, k, j);
		min = std::min(point[j] - point[i] + left + right, min);
	}
	DP[i][j] = min;
	return min;
}

int main(int argc, char const* argv[])
{
	int l;
	for (cin >> l; l != 0; cin >> l) {
		int n;
		cin >> n;
		vector<int> point(n + 2);
		vector<vector<int>> DP(n + 2, vector<int>(n + 2, - 1));
		point[0] = 0;
		point[n + 1] = l;
		for (size_t i = 0; i < n; i++) {
			cin >> point[i + 1];
		}
		// for (auto val: point) {
		// 	cout << val << endl;
		// }
		// vector<vector<int>> DP(n + 1, vector<int>(n + 1, 0));
		cout << "The minimum cutting is " << result(DP, point, 0, n + 1) << '.' << endl;
	}
	return 0;
}
