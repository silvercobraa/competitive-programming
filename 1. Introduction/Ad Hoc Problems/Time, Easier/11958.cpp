#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 1; t <= T; t++) {
		int k, hh, mm;
		scanf("%d %d:%d", &k, &hh, &mm);
		int best = 999999999;
		for (size_t i = 0; i < k; i++) {
			int h, m, q;
			scanf("%d:%d %d", &h, &m, &q);
			if (m < mm) {m += 60; h -= 1;}
			if (h < hh) h += 24;
			int d = 60*(h - hh) + m - mm + q;
			best = min(best, d);
		}
		printf("Case %d: %d\n", t, best);
	}
	return 0;
}
