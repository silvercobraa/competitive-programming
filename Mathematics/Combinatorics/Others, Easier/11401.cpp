#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	int NMAX = 1000000;
	vector<long long> ans(NMAX + 1, 0);
	ans[4] = 1;
	for (int i = 5; i <= NMAX; i++) {
		ans[i] += ans[i - 1];
		long long half = (i - 3) / 2;
		ans[i] += half * (half + 1); // es 2 veces x*(x+1)/2
		if ((i - 3) % 2 == 1) {
			ans[i] += half + 1;
		}
		// cout << ans[i] << " ";
	}
	// cout << endl;
	for (cin >> n; n >= 3; cin >> n) {
		cout << ans[n] << endl;
	}
	return 0;
}
