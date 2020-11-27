#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// bool check(vector<int>& v) {
// 	for (int i = 0; i < v.size(); i++) {
// 		if (v[i] == i) {
// 			return false;
// 		}
// 	}
// 	return true;
// }

int main(int argc, char const *argv[]) {
	// int n = 12;
	// for (int n = 2; n <= 12; n++) {
	// 	vector<int> v(n);
	// 	for (int i = 0; i < v.size(); i++) {
	// 		v[i] = i;
	// 	}
	// 	int count = 0;
	// 	do {
	// 		if (check(v)) {
	// 			// for (auto x: v) {
	// 				// 	cout << x << " ";
	// 				// }
	// 				// cout << endl;
	// 				count++;
	// 			}
	// 		} while (next_permutation(v.begin(), v.end()));
	// 		cout << count << endl;
	// }
	// int fact = 1;
	// for (int i = 2; i <= 12; i++) {
	// 	fact *= i;
	// 	cout << fact << endl;
	// }
	vector <int> numerator = {1,2,9,44,265,1854,14833,133496,1334961,14684570,176214841};
	vector <int> denominator = {2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		n -= 2;
		printf("%d/%d\n", numerator[n], denominator[n]);
	}
	return 0;
}
