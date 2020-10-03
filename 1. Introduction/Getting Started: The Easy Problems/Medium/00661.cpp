#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, m, c;
	int count = 1;
	for (cin >> n >> m >> c; n != 0 or m != 0 or c != 0; cin >> n >> m >> c, count++) {
		bool blown = false;
		int max = 0;
		int sum = 0;
		vector<int> amp(n);
		for (size_t i = 0; i < n; i++) {
			cin >> amp[i];
			// cout << "amps: " << amp[i] << endl;
		}
		for (size_t i = 0; i < m; i++) {
			int x;
			cin >> x;
			// cout << "x: " << x << endl;
			sum += amp[x - 1];
			amp[x - 1] *= -1;
			// cout << sum << endl;
			blown |= sum > c;
			max = std::max(max, sum);
		}
		cout << "Sequence " << count << endl;
		if (blown) {
			cout << "Fuse was blown." << endl;
		}
		else {
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << max << " amperes." << endl;
		}
		cout << endl;
	}
	return 0;
}
