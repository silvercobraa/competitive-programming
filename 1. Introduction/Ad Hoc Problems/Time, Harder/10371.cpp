#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map<string, int> offset = {
	{"UTC", 0*60},
	{"GMT", 0*60},
	{"BST", 1*60},
	{"IST", 1*60},
	{"WET", 0*60},
	{"WEST", 1*60},
	{"CET", 1*60},
	{"CEST", 2*60},
	{"EET", 2*60},
	{"EEST", 3*60},
	{"MSK", 3*60},
	{"MSD", 4*60},
	{"AST", -4*60},
	{"ADT", -3*60},
	{"NST", -210},
	{"NDT", -150},
	{"EST", -5*60},
	{"EDT", -4*60},
	{"CST", -6*60},
	{"CDT", -5*60},
	{"MST", -7*60},
	{"MDT", -6*60},
	{"PST", -8*60},
	{"PDT", -7*60},
	{"HST", -10*60},
	{"AKST", -9*60},
	{"AKDT", -8*60},
	{"AEST", 10*60},
	{"AEDT", 11*60},
	{"ACST", 570},
	{"ACDT", 630},
	{"AWST", 8*60},
};

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		int h, m;
		string s;
		cin >> s;
		if (s == "midnight") {
			h = 0;
			m = 0;
		}
		else if (s == "noon") {
			h = 12;
			m = 0;
		}
		else {
			stringstream ss(s);
			char colon;
			ss >> h >> colon >> m;
			cin >> s;
			if ((s[0] == 'p' and h != 12) or (s[0] == 'a' and h == 12)) {
				h = (h + 12) % 24;
			}
		}
		string tz1, tz2;
		cin >> tz1 >> tz2;
		// printf("%d %d\n", h, m);
		int t = 60*h + m + offset[tz2] - offset[tz1];
		// printf("%d\n", offset[tz2] - offset[tz1]);
		while (t < 0) {
			t += 24*60;
		}
		t %= 24*60;
		// printf("%d\n", t);
		h = t / 60;
		m = t % 60;
		// printf("%d %d\n", h, m);
		if (m == 0) {
			if (h == 0) {
				printf("midnight\n");
				continue;
			}
			else if (h == 12) {
				printf("noon\n");
				continue;
			}
		}
		if (13 <= h and h <= 23) {
			printf("%d:%02d p.m.\n", h - 12, m);
		}
		else if (h == 12) {
			printf("12:%02d p.m.\n", m);
		}
		else if (h == 0) {
			printf("12:%02d a.m.\n", m);
		}
		else {
			printf("%d:%02d a.m.\n", h, m);
		}

	}
	return 0;
}
