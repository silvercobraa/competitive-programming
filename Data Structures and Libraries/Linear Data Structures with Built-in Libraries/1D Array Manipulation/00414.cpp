#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool all_valid(vector<int>& left, vector<int>& right) {
	for (size_t i = 0; i < left.size(); i++) {
		if (right[i] - left[i] < 0 or (right[i] == -1 and left[i] == -1)) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		string line;
		getline(cin, line);
		vector<int> left(n);
		vector<int> right(n);
		for (size_t i = 0; i < n; i++) {
			getline(cin, line);
			left[i] = line.find_first_of(' ');
			right[i] = line.find_last_of(' ');
			// cout << left[i] << " " << right[i] << endl;
		}
		while (all_valid(left, right)) {
			for (size_t i = 0; i < n; i++) {
				right[i]--;
			}
		}
		int ans = 0;
		for (size_t i = 0; i < n; i++) {
			if (right[i] - left[i] < 0 or (right[i] == -1 and left[i] == -1)) {
				continue;
			}
			ans += right[i] - left[i] + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
