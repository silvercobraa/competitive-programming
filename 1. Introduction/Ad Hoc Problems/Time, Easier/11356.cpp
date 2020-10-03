#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int d, y;
string m;

map<string, string> next_month = {
	{"January", "February"},
	{"February", "March"},
	{"March", "April"},
	{"April", "May"},
	{"May", "June"},
	{"June", "July"},
	{"July", "August"},
	{"August", "September"},
	{"September", "October"},
	{"October", "November"},
	{"November", "December"},
	{"December", "January"},
};

bool leap() {
	return y%4==0 and not (y%100==0) or y%400==0;
}

void nextday() {
	bool l = leap();
	int last = l ? 29 : 28;
	if ((d == last and m == "February") or (d == 30 and (m == "April" or m == "June" or m == "September" or m == "November")) or (d == 31)) {
		d = 1;
		if (m == "December") {
			y++;
		}
		m = next_month[m];
	}
	else {
		d++;
	}
	// cout << y << "-" << m << "-" << d << endl;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 1; i <= n; i++) {
		char hyphen;
		int k;
		cin >> y >> hyphen;
		getline(cin, m, '-');
		cin >> d >> k;
		for (int i = 0; i < k; i++) {
			nextday();
		}
		cout << "Case " << i << ": " <<  y << "-" << m << "-";
		printf("%02d\n", d);
	}
	return 0;
}
