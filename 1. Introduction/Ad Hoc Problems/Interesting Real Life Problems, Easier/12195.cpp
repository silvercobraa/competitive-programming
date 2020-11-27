#include <iostream>

using namespace std;

int length(char c) {
	if (c == 'W') return 64;
	if (c == 'H') return 32;
	if (c == 'Q') return 16;
	if (c == 'E') return 8;
	if (c == 'S') return 4;
	if (c == 'T') return 2;
	if (c == 'X') return 1;
}

int main(int argc, char const *argv[]) {
	string s;
	for (cin >> s; s != "*"; cin >> s) {
		int bars = 0;
		int count = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '/') {
				if (count == 64) {
					bars++;
				}
				count = 0;
			}
			else {
				count += length(s[i]);
			}
		}
		cout << bars << endl;
	}
	return 0;
}
