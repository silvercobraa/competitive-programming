#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int n;
		cin >> n;
		int ans = 0;
		for (size_t i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			ans = max(ans, tmp);
		}
		printf("Case %d: %d\n", t+1, ans);
	}

	return 0;
}
