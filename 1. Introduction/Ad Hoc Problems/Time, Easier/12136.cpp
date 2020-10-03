#include <iostream>

using namespace std;

bool compare(int h1, int m1, int h2, int m2) {
	return h1 < h2 or (h1 == h2 and m1 < m2);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 1; i <= n; i++) {
		int h1, m1, h2, m2, h3, m3, h4, m4;
		scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
		scanf("%d:%d %d:%d", &h3, &m3, &h4, &m4);
		bool overlap = compare(h4, m4, h1, m1) or compare(h2, m2, h3, m3);
		printf("Case %d: %s Meeting\n", i, overlap ? "Hits" : "Mrs");
	}
	return 0;
}
