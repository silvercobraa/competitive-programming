#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>

#define MAX 6000

using namespace std;

vector<long> coins = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
vector<vector<long>> result = vector<vector<long>>(coins.size(), vector<long>(MAX + 1, 0));


int main(int argc, char const* argv[])
{
	double n;
	for (size_t j = 0; j <= MAX; j++) {
		result[0][j] = 1;
	}
	for (size_t i = 0; i < coins.size(); i++) {
		result[i][0] = 1;
	}
	for (int i = 1; i < coins.size(); i++) {
		for (int j = 1; j <= MAX; j++) {
			if (j - coins[i] >= 0) {
				result[i][j] += result[i][j - coins[i]];
			}
			result[i][j] += result[i - 1][j];
			// cout << result[i][j] << ' ';
		}
		// cout << endl;
	}
	for (cin >> n; n != 0.00; cin >> n) {
		long amount = long(100.0 * n + 0.5) / 5;
		if (n < 100.0) {
			cout << ' ';
		}
		if (n < 10.0) {
			cout << ' ';
		}
		printf("%.2lf", n);
		// printf("%.2lf ", 100.0 * n);
		// printf("%ld ", long(100.0 * n + 0.5));
		// printf("%ld ", amount);
		// printf("%.2lf", n);
		cout << setw(17) << result[coins.size() - 1][amount] << endl;
	}
	return 0;
}
