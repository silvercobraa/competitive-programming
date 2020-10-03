#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	int t = 1;
	for (cin >> n; n != 0; cin >> n, t++) {
		int count = 0;
		int tmp;
		int seconds = 0;
		vector<int> v;
		for (cin >> tmp; count < n; cin >> tmp) {
			v.push_back(tmp);
			count += tmp;
			seconds++;
			if (count == n) {
				break;
			}
		}
		count = 0;
		printf("Output for data set %d, %d bytes:\n", t, n);
		for (int i = 0; i < v.size() / 5; i++) {
			printf("   Time remaining: ");
			int transferred = v[5*i+0] + v[5*i+1] + v[5*i+2] + v[5*i+3] + v[5*i+4];
			count += transferred;
			double r = transferred / 5.0;
			if (transferred == 0) {
				printf("stalled\n");
			}
			else {
				int ans = (5*(n - count) + transferred - 1)/transferred;
				// printf("%d seconds\n", int(ceil((n - count)/r)));
				printf("%d seconds\n", ans);
				// printf("%d seconds\n", (n - count)/(transferred / 5));
				// printf("%d seconds\n", (n - count)/((transferred+4) / 5));
			}
		}
		printf("Total time: %d seconds\n\n", seconds);
	}
	return 0;
}
