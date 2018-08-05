#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
	int A, B;
	for (cin >> A >> B; A != 0 or B != 0; cin >> A >> B) {
		set<int> alice;
		set<int> betty;
		for (size_t i = 0; i < A; i++) {
			int x;
			cin >> x;
			alice.insert(x);
		}
		for (size_t i = 0; i < B; i++) {
			int x;
			cin >> x;
			betty.insert(x);
		}
		set<int> diff1;
		set<int> diff2;
		set_difference(alice.begin(), alice.end(), betty.begin(), betty.end(), inserter(diff1, diff1.begin()));
		set_difference(betty.begin(), betty.end(), alice.begin(), alice.end(), inserter(diff2, diff2.begin()));
		cout << min(diff1.size(), diff2.size()) << endl;
	}

	return 0;
}
