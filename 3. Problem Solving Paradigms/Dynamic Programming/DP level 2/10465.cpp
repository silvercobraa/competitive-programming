#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
	int n, m ,t;
	while (cin >> n >> m >> t) {
		int min = std::min(n, m);
		int max = std::max(n, m);
		if (min > t) {
			cout << 0 << ' ' << t << endl;
			continue;
		}
		if (max > t) {
			max = min;
		}
		vector<int> DP = vector<int>(t + 1, 0);
		vector<int> beer = vector<int>(t + 1, 0);
		DP[min] = 1;
		for (size_t i = 0; i < min; i++) {
			beer[i] = i;
		}
		for (size_t i = min + 1; i < max; i++) {
			DP[i] = 1 + DP[i - min];
			beer[i] = beer[i - min];
		}
		for (size_t i = max; i < DP.size(); i++) {
			if (beer[i - min] == 0) {
				if (beer[i - max] == 0) {
					DP[i] = std::max(1 + DP[i - min], 1 + DP[i - max]);
				}
				else {
					DP[i] = 1 + DP[i - min];
				}
				beer[i] = 0;
			}
			else {
				if (beer[i - max] == 0) {
					DP[i] = 1 + DP[i - max];
					beer[i] = 0;
				}
				else {
					if (beer[i - max] < beer[i - min]) {
						DP[i] = 1 + DP[i - max];
						beer[i] = beer[i - max];
					}
					else if (beer[i - min] < beer[i - max]) {
						DP[i] = 1 + DP[i - min];
						beer[i] = beer[i - min];
					}
					else {
						DP[i] = std::max(1 + DP[i - min], 1 + DP[i - max]);
						beer[i] = beer[i - min]; // cualquiera sirve
					}
				}
			}
		}
		// for (size_t i = 0; i < DP.size(); i++) {
		// 	cout << DP[i] << ' ';
		// }
		// cout << endl;
		// for (size_t i = 0; i < beer.size(); i++) {
		// 	cout << beer[i] << ' ';
		// }
		// cout << endl;
		cout << DP[t];
		if (beer[t] != 0) {
			cout << ' ' << beer[t];
		}
		cout << endl;
	}
	return 0;
}
