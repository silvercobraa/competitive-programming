#include <iostream>
#include <vector>
#include <string>

using namespace std;

int d, m, y;

bool leap() {
	return y%4==0 and not (y%100==0) or y%400==0;
}

void nextday() {
	bool l = leap();
	int last = l ? 29 : 28;
	if ((d == last and m == 2) or (d == 30 and (m == 4 or m == 6 or m == 9 or m == 11)) or (d == 31)) {
		d = 1;
		if (m == 12) {
			m = 1;
			y++;
		}
		else {
			m++;
		}
	}
	else {
		d++;
	}
}

vector<int> signday = {21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23};
vector<string> signname = {"capricorn", "aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius"};

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 1; i <= n; i++) {
		int date;
		cin >> date;
		y = date%10000; date/=10000;
		d = date%100; date/=100;
		m = date;
		for (int j = 0; j < 40*7; j++) {
			nextday();
		}
		printf("%d %02d/%02d/%04d ", i, m, d, y);
		int j;
		for (j = 0; j < 12; j++) {
			if (m < j+1 or (m == j+1 and d < signday[j])) {
				break;
			}
		}
		j %= 12;
		cout << signname[j] << endl;
	}
	return 0;
}
