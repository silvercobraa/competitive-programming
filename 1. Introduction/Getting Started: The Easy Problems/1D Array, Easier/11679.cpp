// fijarse bien en los indices...
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int B, N;
	for (cin >> B >> N; B != 0 or N != 0; cin >> B >> N) {
		vector<int> R(B, 0);
		vector<int> D(B, 0);
		vector<int> C(B, 0);
		for (size_t i = 0; i < B; i++) {
			cin >> R[i];
		}
		bool ans = true;
		for (size_t i = 0; i < N; i++) {
			int d, c, v;
			cin >> d >> c >> v;
			D[d - 1] += v;
			C[c - 1] += v;
			// R[d - 1] -= v;
			// R[c - 1] += v;
			// if (R[d - 1] < 0) {
			// 	ans = false;
			// }
		}
		// for (size_t i = 0; i < B; i++) {
		// 	cout << R[i] << " " << C[i] << " " << D[i] << endl;
		// }
		for (size_t i = 0; i < B; i++) {
			if (R[i] + C[i] < D[i]) {
				ans = false;
				break;
			}
		}
		if (ans) {
			puts("S");
		}
		else {
			puts("N");
		}
	}
	return 0;
}
