#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// int josephus(int n, int step) {
// 	vector<int> regions(n);
// 	vector<int> left(n);
// 	vector<int> right(n);
// 	iota(regions.begin(), regions.end(), 1);
// 	iota(right.begin(), right.end(), 1);
// 	right[n - 1] = 0;
// 	iota(left.begin(), left.end(), -1);
// 	left[0] = n - 1;
// 	int pos = 0;
// 	for (int i = 0; i < n; ++i) {
// 		// int k = pos;
// 		// do {
// 		// 	cout << regions[k] << " ";
// 		// 	k = right[k];
// 		// } while (k != pos);
// 		// cout << endl;
// 		right[left[pos]] = right[pos];
// 		left[right[pos]] = left[pos];
// 		for (int j = 0; j < step; ++j) {
// 			pos = right[pos];
// 		}
// 		if (i == n - 1) {
// 			if (regions[pos] == 13) {
// 				return step;
// 			}
// 		}
// 	}
// 	return -1;
// }

int main() {
	// int N;
	// for (int i = 13; i <= 100; ++i) {
	// // for (int i = 17; i <= 17; ++i) {
	// 	for (int j = 1; ; ++j) {
	// 		if (josephus(i, j) != -1) {
	// 			cout << j << endl;
	// 			break;
	// 		}
	// 	}
	// }
	// for (cin >> N; N != 0; cin >> N) {

	// }
	vector<int> precomputed_answer {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 21, 13, 26, 14, 11, 23, 22, 9, 73, 17, 42, 7, 98, 15, 61, 22, 84, 24, 30, 9, 38, 15, 54, 27, 9, 61, 38, 22, 19, 178, 38, 53, 79, 68, 166, 20, 9, 22, 7, 21, 72, 133, 41, 10, 82, 92, 64, 129, 86, 73, 67, 19, 66, 115, 52, 24, 22, 176, 10, 57, 137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 49, 5, 22, 54, 52, 113, 15, 66};
	int N;
	for (cin >> N; N != 0; cin >> N) {
		cout << precomputed_answer[N] << endl;
	}
}