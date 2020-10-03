#include <iostream>

using namespace std;


bool valid(int d1, int m1, int y1, int d2, int m2, int y2) {
	// printf("%d | (%d & (%d | (%d & %d)))\n", y1 < y2, y1 == y2, m1 < m2, m1 == m2, d1 < d2);
	return y1 < y2 or (y1 == y2 and (m1 < m2 or (m1 == m2 and d1 <= d2)));
}

int years(int d1, int m1, int y1, int d2, int m2, int y2) {
	int ans = y2 - y1;
	if (m1 > m2 or (m1 == m2 and d1 > d2)) {
		ans--;
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	int d1, m1, y1, d2, m2, y2;
	for (size_t i = 1; i <= T; i++) {
		scanf("%02d/%02d/%04d", &d1, &m1, &y1);
		scanf("%02d/%02d/%04d", &d2, &m2, &y2);
		// printf("%d %d %d  %d %d %d\n", d1, m1, y1, d2, m2, y2);
		if (not valid(d2, m2, y2, d1, m1, y1)) {
			printf("Case #%d: Invalid birth date\n", i);
		}
		else {
			int ys = years(d2, m2, y2, d1, m1, y1);
			if (ys > 130) {
				printf("Case #%d: Check birth date\n", i);
			}
			else {
				printf("Case #%d: %d\n", i, ys);
			}
		}
	}
	return 0;
}
