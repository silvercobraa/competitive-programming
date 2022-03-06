#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 1; t <= T; t++) {
		int N, K, P;
		cin >> N >> K >> P;
		int ans = (K - 1 + P) % N + 1;
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
