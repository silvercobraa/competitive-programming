#include <iostream>
#include <vector>

using namespace std;

int parity(int x) {
	int sum = 0;
	vector<int> v;
	for (; x != 0; x >>= 1) {
		sum += x & 1;
		v.push_back(x & 1);
	}
	for ( ; not v.empty(); v.pop_back()) {
		printf("%d", v.back());
	}
	return sum;
}

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		printf("The parity of ");
		int ans = parity(n);
		printf(" is %d (mod 2).\n", ans);
	}
	return 0;
}
