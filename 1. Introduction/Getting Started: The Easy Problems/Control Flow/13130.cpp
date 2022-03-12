#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> expected1 {1, 2, 3, 4, 5};
	vector<int> expected2 {2, 3, 4, 5, 6};
	for (size_t t = 0; t < n; t++) {
		vector<int> roll {};
		for (int i = 0; i < 5; i++) {
			int x;
			cin >> x;
			roll.emplace_back(x);
		}
		if (roll == expected1 or roll == expected2) {
			cout << "Y" << endl;
		}
		else {
			cout << "N" << endl;
		}
	}
	return 0;
}
