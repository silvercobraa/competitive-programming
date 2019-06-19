#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		int n;
		cin >> n;
		map<string, int> m;
		bool duplicates = false;
		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			// cout << s << endl;
			cin >> s;
			string number = "";
			for (auto c: s) {
				if (c == 'A' or c == 'B' or c == 'C') {
					number += '2';
				}
				else if (c == 'D' or c == 'E' or c == 'F') {
					number += '3';
				}
				else if (c == 'G' or c == 'H' or c == 'I') {
					number += '4';
				}
				else if (c == 'J' or c == 'K' or c == 'L') {
					number += '5';
				}
				else if (c == 'M' or c == 'N' or c == 'O') {
					number += '6';
				}
				else if (c == 'P' or c == 'R' or c == 'S') {
					number += '7';
				}
				else if (c == 'T' or c == 'U' or c == 'V') {
					number += '8';
				}
				else if (c == 'W' or c == 'X' or c == 'Y') {
					number += '9';
				}
				else if ('0' <= c and c <= '9') {
					number += c;
				}
			}
			m[number]++;
			if (m[number] > 1) {
				duplicates = true;
			}
		}
		if (!duplicates) {
			cout << "No duplicates." << endl;
			continue;
		}
		for (auto p: m) {
			if (p.second > 1) {
				for (int i = 0; i < 3; i++) {
					cout << p.first[i];
				}
				cout << "-";
				for (int i = 3; i < p.first.size(); i++) {
					cout << p.first[i];
				}
				cout << " " << p.second << endl;
			}
		}
	}
	return 0;
}
