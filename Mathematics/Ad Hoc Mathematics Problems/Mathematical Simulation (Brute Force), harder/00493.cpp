#include <iostream>
#include <set>
#include <vector>

constexpr int MAX = 1000000;

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[]) {
	set<pair<int, int>> visited;
	int count = 0;
	int num = 0, den = 0;
	int dnum = 1;
	int dden = 1;
	vector<pair<int, int>> v;
	for (int side = 1; count < MAX; side++) {
		for (int j = 0; j < side and count < MAX; j++) {
			num += dnum;
			int num2 = den >= 0 ? num : -num;
			int den2 = den >= 0 ? den : -den;
			int g = gcd(abs(num2), abs(den2));
			num2 /= g;
			den2 /= g;
			if (den2 != 0 and visited.find({num2, den2}) == visited.end()) {
				// printf("%d/%d   %d/%d\n", num, den, num2, den2);
				visited.insert({num2, den2});
				v.push_back({num2, den2});
				count++;
			}
		}
		if (count >= MAX) {
			break;
		}
		for (int j = 0; j < side and count < MAX; j++) {
			den += dden;
			int num2 = den >= 0 ? num : -num;
			int den2 = den >= 0 ? den : -den;
			int g = gcd(abs(num2), abs(den2));
			num2 /= g;
			den2 /= g;
			if (den2 != 0 and visited.find({num2, den2}) == visited.end()) {
				// printf("%d/%d   %d/%d\n", num, den, num2, den2);
				visited.insert({num2, den2});
				v.push_back({num2, den2});
				count++;
			}
		}
		dnum = -dnum;
		dden = -dden;
	}
	int n;
	while (cin >> n) {
		printf("%d / %d\n", v[n].first, v[n].second);
	}
	return 0;
}
