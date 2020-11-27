#include <iostream>
#include <bitset>

using namespace std;

bool check(int n, int m) {
	bitset<1000000+1> bs;
	bool ans = true;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			if (bs[j]) {
				ans = false;
			}
			bs[j] = true;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int l = a, r = b; l <= 1000000; l += c, r += c) {
			for (int j = l ; j < r and j <= 1000000; j++) {
				if (bs[j]) {
					ans = false;
				}
				bs[j] = true;
			}
		}
	}
	return ans;
}
int main(int argc, char const *argv[]) {
	int n, m;
	for (cin>>n>>m; n!=0 or m!=0; cin>>n>>m) {
		// printf("%d %d\n", n, m);
		if (check(n, m)) {
			puts("NO CONFLICT");
		}
		else {
			puts("CONFLICT");
		}
	}
	return 0;
}
