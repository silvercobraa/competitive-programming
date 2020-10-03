#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int N, B;
	for (cin >> N >> B; N != 0 or B != 0; cin >> N >> B) {
		vector<bool> v(N, false);
		vector<int> x(B);
		int count = 0;
		for (int i = 0; i < B; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < B; i++) {
			for (int j = i + 1; j < B; j++) {
				int diff = x[i] - x[j];
				if (diff < 0) {
					diff = -diff;
				}
				if (diff <= N and not v[diff - 1]) {
					// cout << x[i] << " " << x[j] << ": " << diff << endl;
					v[diff - 1] = true;
					count++;
				}
			}
		}
		if (count == v.size()) {
			puts("Y");
		}
		else {
			puts("N");
		}
	}

	return 0;
}
