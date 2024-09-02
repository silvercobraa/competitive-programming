#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int R, N;
	int t = 1;
	for (cin >> R >> N; R != 0 or N != 0; cin >> R >> N) {
		int ans = (R + N - 1) / N - 1;
		if (ans > 26) {
			printf("Case %d: impossible\n", t);
		}
		else {
			printf("Case %d: %d\n", t, ans);
		}
		++t;
	}
	return 0;
}
