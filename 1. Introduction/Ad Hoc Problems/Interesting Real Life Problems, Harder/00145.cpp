#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

map<char,double> day = {
	{'A', 0.10},
	{'B', 0.25},
	{'C', 0.53},
	{'D', 0.87},
	{'E', 1.44},
};

map<char,double> evening = {
	{'A', 0.06},
	{'B', 0.15},
	{'C', 0.33},
	{'D', 0.47},
	{'E', 0.80},
};

map<char,double> night = {
	{'A', 0.02},
	{'B', 0.05},
	{'C', 0.13},
	{'D', 0.17},
	{'E', 0.30},
};


int main(int argc, char const *argv[]) {
	char c;
	for (cin >> c; c != '#'; cin >> c) {
		string number;
		int h1, m1, h2, m2;
		cin >> number >> h1 >> m1 >> h2 >> m2;
		// cout << h1 << " " << m1 << " " << h2 << " " << m2 << " " << endl;
		int t1 = 60*h1 + m1;
		int t2 = 60*h2 + m2;
		int count_day = 0;
		int count_evening = 0;
		int count_night = 0;
		for (int i = 1; ; i++) {
			int t = (t1 + i) % (24*60);
			// cout << (t1+i)/60 << " " << (t1+i)%60 << endl;
			if (8*60 < t and t <= 18*60) {
				count_day++;
			}
			else if (18*60 < t and t <= 22*60) {
				count_evening++;
			}
			else if ((22*60 < t and t <= 24*60) or (0 <= t and t <= 8*60)) {
				count_night++;
			}
			if (t == t2) {
				break;
			}
		}
		double ans = day[c]*count_day + evening[c]*count_evening + night[c]*count_night;
		// cout << count_day << " " << count_evening << " " << count_night << endl;
		cout << setw(10) << number << setw(6) << count_day << setw(6) << count_evening << setw(6) << count_night << setw(3) << c;
		printf("%8.2lf\n", ans);
	}
	return 0;
}
