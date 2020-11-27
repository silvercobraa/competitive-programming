#include <iostream>
#include <map>

using namespace std;

void count(map<char,int>& m, int n) {
	if (n == 100) {
		m['c']++;
		return;
	}
	switch (n / 10) {
		case 3: m['x']++;
		case 2: m['x']++;
		case 1: m['x']++; break;
		case 8: m['x']++;
		case 7: m['x']++;
		case 6: m['x']++;
		case 5: m['l']++; break;
		case 9: m['x']++; m['c']++; break;
		case 4: m['x']++; m['l']++; break;
	}
	switch (n % 10) {
		case 3: m['i']++;
		case 2: m['i']++;
		case 1: m['i']++; break;
		case 8: m['i']++;
		case 7: m['i']++;
		case 6: m['i']++;
		case 5: m['v']++; break;
		case 9: m['i']++; m['x']++; break;
		case 4: m['i']++; m['v']++; break;
	}
}

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		map<char, int> m;
		for (int i = 1; i <= n; i++) {
			count(m, i);
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, m['i'], m['v'], m['x'], m['l'], m['c']);
	}
	return 0;
}
