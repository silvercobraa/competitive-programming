#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int p, a, b, c, d, n;
	while (cin>>p>>a>>b>>c>>d>>n) {
		vector<double> v(n, 0.0);
		for (int k = 1; k <= n; k++) {
			v[k-1] = p * (sin(a*k + b) + cos(c*k + d) + 2);
		}
		double cummax = v[0];
		double best_diff = 0.0;
		for (int k = 1; k < n; k++) {
			best_diff = max(best_diff, cummax - v[k]);
			cummax = max(cummax, v[k]);
		}
		printf("%lf\n", best_diff);
	}
	return 0;
}
