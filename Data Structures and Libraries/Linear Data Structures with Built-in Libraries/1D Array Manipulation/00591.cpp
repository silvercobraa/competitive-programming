#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	int set = 1;
	for (cin >> n; n != 0; cin >> n) {
		vector<int> v(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			sum += v[i];
		}
		int moves = 0;
		int size = sum/n;
		for (auto x: v) {
			if (x > size) {
				moves += x - size;
			}
		}
		cout << "Set #" << set << endl;
		cout << "The minimum number of moves is " << moves << "." << endl;
		cout << endl;
		set++;
	}
	return 0;
}
