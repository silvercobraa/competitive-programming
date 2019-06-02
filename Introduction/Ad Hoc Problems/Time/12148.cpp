#include <iostream>
#include <vector>

using namespace std;

vector<int> d;
vector<int> m;
vector<int> y;
vector<int> c;

bool leap(int year) {
	return year%4 == 0 and not (year%100 == 0) or year%400 == 0;
}

bool consecutive(int d1, int m1, int y1, int d2, int m2, int y2) {
	bool l = leap(y1);
	int last = l ? 29 : 28;
	if ((d1 == last and m1 == 2) or (d1 == 30 and (m1 == 4 or m1 == 6 or m1 == 9 or m1 == 11)) or (d1 == 31)) {
		d1 = 1;
		if (m1 == 12) {
			m1 = 1;
			y1++;
		}
		else {
			m1++;
		}
	}
	else {
		d1++;
	}

	return d1 == d2 and m1 == m2 and y1 == y2;
}


int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		d = vector<int>(n);
		m = vector<int>(n);
		y = vector<int>(n);
		c = vector<int>(n);
		for (size_t i = 0; i < n; i++) {
			cin >> d[i] >> m[i] >> y[i] >> c[i];
			// cout << d[i] << m[i] << y[i] << c[i] << endl;
		}
		int days = 0;
		int total = 0;
		for (int i = 1; i < n; i++) {
			if (consecutive(d[i-1], m[i-1], y[i-1], d[i], m[i], y[i])) {
				total += c[i] - c[i - 1];
				days++;
			}
		}
		cout << days << " " << total << endl;
	}
	return 0;
}
