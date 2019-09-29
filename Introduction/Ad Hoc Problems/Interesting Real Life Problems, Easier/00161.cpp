#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// 5*60*60
#define MAX (18000+1)
#define INF 99999999
// #define MAX 100
using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	int zeros = 0;
	while (true) {
		// cout << zeros << endl;
		vector<int> v;
		int minimum = INF;
		for (cin >> n; n != 0; cin >> n) {
			minimum = min(minimum, n);
			v.push_back(n);
		}
		if (v.empty()) {
			zeros++;
			if (zeros == 3) {
				break;
			}
			else {
				continue;
			}
		}
		else {
			zeros = 0;
		}
		// vector<int> t(MAX, 0);
		// for (int i = 0; i < MAX; i++) {
		// 	cout << t[i];
		// }
		// vector<bool> t(MAX, false);
		vector<int> t(MAX, 0);
		for (auto x: v) {
			int start = x == minimum ? 2*x : 0;
			// int start = 2*x;
			for (int i = start; i < MAX; i += 2*x) {
				for (int j = i; j < i+x-5 and j < MAX; j++) {
					// cout << j << endl;
					// t[j] = t[j] or true;
					t[j]++;
					// t[j] += 1;
					// t[j] |= 1;
				}
			}
		}
		int ans = -1;
		for (int i = 0; i < MAX; i++) {
			// cout << t[i];
			if (t[i] == v.size()) {
				ans = i;
				break;
			}
		}
		// for (int i = 0; i < 60; i++) {
		// 	if (i % 10 == 0) {
		// 		cout << "-";
		// 	}
		// 	cout << t[i];
		// }
		// cout << endl;

		if (ans != -1) {
			// ans++;
			int hh = ans / 3600;
			int mm = (ans / 60) % 60;
			int ss = ans % 60;
			printf("%02d:%02d:%02d\n", hh, mm, ss);
		}
		else {
			puts("Signals fail to synchronise in 5 hours");
		}
		v.clear();
	}
	return 0;
}
